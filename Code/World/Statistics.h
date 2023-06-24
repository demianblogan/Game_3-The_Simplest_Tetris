#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transformable.hpp>

// class Statistics is a UI element that shows next information:
// - Your current level
// - Your score
// - How many rows have you completed?
// - Is game over?
// It sets all this information and draws it onto the screen.
class Statistics : public sf::Transformable, public sf::Drawable
{
public:
	Statistics();

	void AddRows(int newRowsCount);
	int GetCurrentLevelNumber() const;
	void SetGameOver();

private:
	static constexpr int FONT_SIZE = 24;
	static constexpr int GAME_OVER_FONT_SIZE = 72;

	int completedRowsCount = 0;
	int score = 0;
	int currentLevel = 0;
	bool isGameOver = false;

	sf::Text textCompletedRowsCount;
	sf::Text textScore;
	sf::Text textCurrentLevel;
	sf::Text textGameOver;
	sf::Text textTutorialInfo;

	sf::Font font;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};