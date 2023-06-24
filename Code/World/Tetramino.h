#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

// class Tetramino describes a figure in tetris. There can be 7 figures, with their unique shapes and sizes.
// Every shape can be divided into 4 rows and 4 columns. Also you can rotate shape in 4 directions (see SHAPES array).
class Tetramino
{
public:
	enum class Type // Every letter shows tetramino's shape
	{
		O,
		I,
		S,
		Z,
		L,
		J,
		T,
		SIZE
	};

	static constexpr unsigned ROTATIONS_COUNT = 4; // number of all possible rotations of all tetraminos
	static constexpr unsigned MATRIX_SIZE = 4;     // size of the matrix of all tetraminos' representations

	static const unsigned int PIVOT_Y = 1;         // pivot Y coordinate in the all tetraminos' matrix
	static const unsigned int PIVOT_X = 2;         // pivot X coordinate in the all tetraminos' matrix

	static const sf::Color COLORS[int(Type::SIZE)]; // all possible colors of all tetraminos
	static const int SHAPES[int(Type::SIZE)][ROTATIONS_COUNT][MATRIX_SIZE][MATRIX_SIZE];  // there is 7 tetraminos (1st dimention), 
	                                                                                      // 4 rotations (2nd dimention), 
	                                                                                      // 4*4 size each (3d and 4th dimentions).
	Tetramino(Type type, int rotation);

	Type GetType() const;
	void SetRotation(int rotation);
	int GetRotation() const;
	void SetPosition(int x, int y);
	int GetPositionX() const;
	int GetPositionY() const;
	float GetTimeSinceLastTransform() const; // in seconds

private:
	const Type type;
	int rotation;
	int positionX;
	int positionY;
	sf::Clock clockSinceLastTransform; // transform = moving or rotating
};
