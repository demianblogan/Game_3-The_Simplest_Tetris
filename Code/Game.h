#pragma once
#include <SFML/Graphics.hpp>
#include "Tools/ResourceManager.h"
#include "World/Board.h"
#include "World/Statistics.h"

class Game
{
public:
	enum class Sound
	{
		GameOver,
		NextLevel,
		RowIsCleared
	};

	Game();

	void Run();

	static void PlaySound(Sound sound);

private:
	enum class ScreenResolution
	{
		_FullHD, // 1080p
		_2K,     // 1440p
		_4K,     // 2160p
		Other    // Not supported
	};

	enum class Font
	{
		GUI // Graphical User Interface
	};

	enum class Music
	{
		BackgroundTheme
	};

	int GetScreenScaleFactor(sf::VideoMode size) const;

	static ResourceManager<sf::Font, Font> fonts;
	static ResourceManager<sf::SoundBuffer, Sound> sounds;
	static ResourceManager<sf::Music, Music> music;

	const sf::String WINDOW_TITLE = "The Simplest Tetris";
	sf::VideoMode windowSize;
	sf::RenderWindow window;

	std::unique_ptr<Tetramino> currentTetramino;
	Board board;
	Statistics statistics;
	float timeToMoveTetraminoDown;

	void Initialize();
	void InitializeFonts();
	void InitializeSounds();
	void InitializeMusic();

	void ProcessEvents();
	void Update(float deltaTime);
	void Render();

	void CreateNewTetramino();
};