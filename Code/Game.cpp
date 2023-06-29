#include "Game.h"

#include <thread>
#include "Tools/Random.h"

ResourceManager<sf::Font, Game::Font> Game::fonts;
ResourceManager<sf::SoundBuffer, Game::Sound> Game::sounds;
ResourceManager<sf::Music, Game::Music> Game::music;

Game::Game()
	: windowSize(sf::VideoMode::getDesktopMode())
{
	Initialize();

	// Set size of the window:
	int scaleFactor = GetScreenScaleFactor(windowSize);

	constexpr int INITIAL_WINDOW_WIDTH = 600;
	constexpr int INITIAL_WINDOW_HEIGHT = 500;

	int windowWidth = INITIAL_WINDOW_WIDTH * scaleFactor;
	int windowHeight = INITIAL_WINDOW_HEIGHT * scaleFactor;

	window.create(sf::VideoMode(windowWidth, windowHeight), WINDOW_TITLE);

	// Set size & position of world entities:
	board.setScale(scaleFactor, scaleFactor);
	statistics.setScale(scaleFactor, scaleFactor);

	int boardPositionX = 10 * scaleFactor;
	int boardPositionY = 10 * scaleFactor;

	int statsPositionX = 270 * scaleFactor;
	int statsPositionY = 10 * scaleFactor;

	board.setPosition(boardPositionX, boardPositionY);
	statistics.setPosition(statsPositionX, statsPositionY);

	CreateNewTetramino();

	// Start background music when game starts:
	sf::Music& backgroundMusic = music.Get(Music::BackgroundTheme);
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
}

void Game::Run()
{
	sf::Clock deltaTime;

	while (window.isOpen())
	{
		ProcessEvents();
		Update(deltaTime.restart().asSeconds());
		Render();
	}
}

void Game::PlaySound(Sound sound)
{
	// Start to play sound in other thread.

	std::thread soundThread([&soundBuffer = sounds.Get(sound)]()
		{
			sf::Sound sound(soundBuffer);
			sound.setAttenuation(0);
			sound.play();

			while (sound.getStatus() == sf::Sound::Playing)
				continue;
		}
	);

	soundThread.detach();
}
int Game::GetScreenScaleFactor(sf::VideoMode size) const
{
	if (size.width == 1920 && size.height == 1080)
		return 1;
	else if (size.width == 2160 && size.height == 1440)
		return 2;
	else if (size.width == 3840 && size.height == 2160)
		return 3;
	else // not supproted resolution
		return 1;
}

void Game::Initialize()
{
	InitializeFonts();
	InitializeSounds();
	InitializeMusic();
}

void Game::InitializeFonts()
{
	fonts.Load(Font::GUI, "../Assets/Fonts/trs-million.ttf");
}

void Game::InitializeSounds()
{
	sounds.Load(Sound::GameOver, "../Assets/Sounds/GameOver.ogg");
	sounds.Load(Sound::NextLevel, "../Assets/Sounds/NextLevel.ogg");
	sounds.Load(Sound::RowIsCleared, "../Assets/Sounds/RowIsCleared.ogg");
}

void Game::InitializeMusic()
{
	music.Load(Music::BackgroundTheme, "../Assets/Music/BackgroundTheme.ogg");
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				window.close();
				break;

			case sf::Keyboard::Down:
				board.Move(*currentTetramino, 0, 1);
				break;

			case sf::Keyboard::Left:
				board.Move(*currentTetramino, -1, 0);
				break;

			case sf::Keyboard::Right:
				board.Move(*currentTetramino, 1, 0);
				break;

			case sf::Keyboard::Space:
				board.Drop(*currentTetramino);
				CreateNewTetramino();
				break;

			case sf::Keyboard::A:
				board.RotateRight(*currentTetramino);
				break;

			case sf::Keyboard::D:
				board.RotateLeft(*currentTetramino);
				break;
			}
		}
	}
}

void Game::Update(float deltaTime)
{
	if (!board.IsGameOver())
	{
		int clearedRowsCount = board.ClearRows(*currentTetramino);
		statistics.AddRows(clearedRowsCount);
		if (clearedRowsCount != 0)
			PlaySound(Sound::RowIsCleared);

		if (!board.IsFallen(*currentTetramino) && currentTetramino->GetTimeSinceLastTransform() > 1.0f)
			CreateNewTetramino();

		timeToMoveTetraminoDown += deltaTime;

		// The more level you get, the harder play, because every next level tetramions automaticly move faster.
		float maxTimeToMoveTetraminoDown = std::max(0.1f, 0.6f - 0.005f * statistics.GetCurrentLevelNumber());
		while (timeToMoveTetraminoDown > maxTimeToMoveTetraminoDown)
		{
			timeToMoveTetraminoDown -= maxTimeToMoveTetraminoDown;
			board.Move(*currentTetramino, 0, 1);
		}
	}
	else
	{
		statistics.SetGameOver();

		static bool isBackgroundMusicStopped = false;
		if (!isBackgroundMusicStopped)
		{
			music.Get(Music::BackgroundTheme).stop();
			isBackgroundMusicStopped = true;
		}

		static bool isGameOverSoundPlayed = false;
		if (!isGameOverSoundPlayed)
		{
			PlaySound(Sound::GameOver);
			isGameOverSoundPlayed = true;
		}
	}
}

void Game::Render()
{
	window.clear();

	if (!board.IsGameOver())
		window.draw(board);
	window.draw(statistics);

	window.display();
}

void Game::CreateNewTetramino()
{
	Tetramino::Type type = Tetramino::Type(Random::GenerateInt(0, int(Tetramino::Type::SIZE) - 1));
	int rotation = 0;

	currentTetramino = std::make_unique<Tetramino>(type, rotation);
	board.Spawn(*currentTetramino);
}
