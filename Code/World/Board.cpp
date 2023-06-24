#include "Board.h"

#include <cassert>

Board::Board(int rows, int columns, int cellWidth, int cellHeight)
	: rows(rows), columns(columns), CELL_WIDTH(cellWidth), CELL_HEIGHT(cellHeight)
	, width(rows* CELL_WIDTH), height(columns* CELL_HEIGHT)
{
	// Build the grid content, and set all elements to -1 (EMPTY_CELL_NUMBER).
	gridContent.resize(rows * columns);
	std::fill(gridContent.begin(), gridContent.end(), EMPTY_CELL_NUMBER);

	// Build the shape borders.
	const sf::Color GRID_COLOR(55, 55, 55); // Dark gray
	int totalLinesCount = (rows + 1 + columns + 1) * 2; // "+1" is for extra line on bottom an right. "*2" is because every line has two vertices.
	grid = sf::VertexArray(sf::Lines, totalLinesCount);

	// VertexArray is created. Let's set position and color for every its vertex.

	// Draw all horizontal lines:
	for (int rowIndex = 0; rowIndex <= rows; rowIndex++)
	{
		// We go through every two points of every line.
		// "rowIndex * 2" is the starting point.
		// "rowIndex * 2 + 1" is the ending point.

		grid[rowIndex * 2] = sf::Vertex(sf::Vector2f(0, rowIndex * CELL_HEIGHT));
		grid[rowIndex * 2 + 1] = sf::Vertex(sf::Vector2f(columns * CELL_WIDTH, rowIndex * CELL_HEIGHT));

		grid[rowIndex * 2].color = GRID_COLOR;
		grid[rowIndex * 2 + 1].color = GRID_COLOR;
	}
	// Draw all vertical lines:
	for (int columnIndex = 0; columnIndex <= columns; columnIndex++)
	{
		// We go through every two points of every line.
		// "(rows + 1) * 2 + columnIndex * 2" is the starting point.
		// "(rows + 1) * 2 + columnIndex * 2 + 1" is the ending point.

		grid[(rows + 1) * 2 + columnIndex * 2] = sf::Vertex(sf::Vector2f(columnIndex * CELL_WIDTH, 0));
		grid[(rows + 1) * 2 + columnIndex * 2 + 1] = sf::Vertex(sf::Vector2f(columnIndex * CELL_WIDTH, rows * CELL_HEIGHT));

		grid[(rows + 1) * 2 + columnIndex * 2].color = GRID_COLOR;
		grid[(rows + 1) * 2 + columnIndex * 2 + 1].color = GRID_COLOR;
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < columns; columnIndex++)
		{
			if (gridContent[rowIndex * columns + columnIndex] != EMPTY_CELL_NUMBER) // if the cell is not empty
			{
				sf::RectangleShape rectangle(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
				rectangle.setFillColor(Tetramino::COLORS[gridContent[rowIndex * columns + columnIndex]]);
				rectangle.setPosition(columnIndex * CELL_WIDTH, rowIndex * CELL_HEIGHT);
				target.draw(rectangle, states);
			}
		}
	}

	target.draw(grid, states);
}

void Board::Spawn(Tetramino& tetramino)
{
	tetramino.SetPosition(columns / 2, 0); // Set on the top row, middle horizontal position.

	ClearFrom(tetramino);

	// If there is at least one piece of other tetraminos on to top row - you will not be
	// able to spawn another tetramino on it.
	for (int columnIndex = 0; columnIndex < columns; columnIndex++)
	{
		if (gridContent[columnIndex] != EMPTY_CELL_NUMBER)
		{
			isGameOver = true;
			break;
		}
	}

	Add(tetramino);
}

bool Board::Move(Tetramino& tetramino, int offsetX, int offsetY)
{
	offsetX += tetramino.GetPositionX();
	offsetY += tetramino.GetPositionY();

	ClearFrom(tetramino); // Delete the tetramino for not testing collision with itself.

	// Check if we can move tetramino in this direction:
	bool visitedCells[Tetramino::MATRIX_SIZE][Tetramino::MATRIX_SIZE] = { false };
	bool canBeMoved = true;
	PerformFloodFill(
		offsetX, offsetY,
		Tetramino::PIVOT_X, Tetramino::PIVOT_Y,
		tetramino.GetType(), tetramino.GetRotation(),
		visitedCells, canBeMoved
	);

	if (canBeMoved)
		tetramino.SetPosition(offsetX, offsetY);

	Add(tetramino); // Because we cleared grid from this tetramino, even might we can't move it, we still need to add it again to the grid.

	return canBeMoved;
}

bool Board::IsFallen(const Tetramino& tetramino)
{
	ClearFrom(tetramino); // Delete the tetramino for not testing collision with itself.

	// Check if tetramino has fallen to the bottom of the board or if there are any occupied cells beneath it:
	bool visitedCells[Tetramino::MATRIX_SIZE][Tetramino::MATRIX_SIZE] = { false };
	bool isFallen = true;
	PerformFloodFill(
		tetramino.GetPositionX(), tetramino.GetPositionY() + 1,
		Tetramino::PIVOT_X, Tetramino::PIVOT_Y,
		tetramino.GetType(), tetramino.GetRotation(),
		visitedCells, isFallen
	);

	Add(tetramino);

	return isFallen;
}

void Board::Drop(Tetramino& tetramino)
{
	// Move down the tetramino as much as we can.
	while (Move(tetramino, 0, 1))
		continue;
}

bool Board::RotateLeft(Tetramino& tetramino)
{
	int rotation = tetramino.GetRotation();
	rotation = (rotation > 0) ? rotation - 1 : Tetramino::ROTATIONS_COUNT - 1;

	return Rotate(tetramino, rotation);
}

bool Board::RotateRight(Tetramino& tetramino)
{
	int rotation = tetramino.GetRotation();
	rotation = (rotation < Tetramino::ROTATIONS_COUNT - 1) ? rotation + 1 : 0;

	return Rotate(tetramino, rotation);
}

bool Board::IsGameOver()
{
	return isGameOver;
}

bool Board::Rotate(Tetramino& tetramino, int rotation)
{
	assert(rotation >= 0 && rotation < Tetramino::ROTATIONS_COUNT);

	ClearFrom(tetramino);

	// Check if tetramino can be rotated:
	bool visitedCells[Tetramino::MATRIX_SIZE][Tetramino::MATRIX_SIZE] = { false };
	bool canBeRotated = true;
	PerformFloodFill(
		tetramino.GetPositionX(), tetramino.GetPositionY(),
		Tetramino::PIVOT_X, Tetramino::PIVOT_Y,
		tetramino.GetType(), rotation,
		visitedCells, canBeRotated
	);

	if (canBeRotated)
		tetramino.SetRotation(rotation);

	Add(tetramino);

	return canBeRotated;
}

void Board::Add(const Tetramino& tetramino)
{
	PerformFloodFill(tetramino, int(tetramino.GetType()));
}

void Board::ClearFrom(const Tetramino& tetramino)
{
	PerformFloodFill(tetramino, EMPTY_CELL_NUMBER);
}

void Board::PerformFloodFill(const Tetramino& tetramino, int value)
{
	// "Flood Fill" algorithm must know every cell which been visited, so for that purpose
	// I create the array with 4*4 dimentions (every tetramino has 4*4 dimentions).
	bool visitedCells[Tetramino::MATRIX_SIZE][Tetramino::MATRIX_SIZE] = { false };

	PerformFloodFill(
		tetramino.GetPositionX(), tetramino.GetPositionY(),
		Tetramino::PIVOT_X, Tetramino::PIVOT_Y,
		tetramino.GetType(), tetramino.GetRotation(),
		visitedCells, value
	);
}

void Board::PerformFloodFill(
	int gridX, int gridY,
	int tetraminoX, int tetraminoY,
	Tetramino::Type type, int rotation,
	bool visitedCells[][Tetramino::MATRIX_SIZE], int value)
{
	// Check limits (stop for recursive call):
	if (tetraminoX < 0 || tetraminoX >= Tetramino::MATRIX_SIZE || tetraminoY < 0 || tetraminoY >= Tetramino::MATRIX_SIZE // is cell position is out of tetramino's bounds
		|| gridX < 0 || gridX >= columns || gridY < 0 || gridY >= rows                                                   // if the current position on the game grid is outside the valid range
		|| visitedCells[tetraminoY][tetraminoX] == true                                                                  // if the current position of the tetramino has already been visited. 
		|| Tetramino::SHAPES[int(type)][rotation][tetraminoY][tetraminoX] == 0)                                          // if the cell is empty
		return;

	visitedCells[tetraminoY][tetraminoX] = true;

	gridContent[gridY * columns + gridX] = value;

	// Do the same for bottom, right, top, and left cells:
	PerformFloodFill(gridX, gridY - 1, tetraminoX, tetraminoY - 1, type, rotation, visitedCells, value);
	PerformFloodFill(gridX + 1, gridY, tetraminoX + 1, tetraminoY, type, rotation, visitedCells, value);
	PerformFloodFill(gridX, gridY + 1, tetraminoX, tetraminoY + 1, type, rotation, visitedCells, value);
	PerformFloodFill(gridX - 1, gridY, tetraminoX - 1, tetraminoY, type, rotation, visitedCells, value);
}

void Board::PerformFloodFill(
	int gridX, int gridY,
	int tetraminoX, int tetraminoY,
	Tetramino::Type type, int rotation,
	bool visitedCells[][Tetramino::MATRIX_SIZE], bool& hasCollision)
{
	// Check limits (stop for recursive call):
	if (tetraminoX < 0 || tetraminoX >= Tetramino::MATRIX_SIZE || tetraminoY < 0 || tetraminoY >= Tetramino::MATRIX_SIZE // is cell position is out of tetramino's bounds
		|| visitedCells[tetraminoY][tetraminoX] == true                                                                  // if the current position of the tetramino has already been visited. 
		|| Tetramino::SHAPES[int(type)][rotation][tetraminoY][tetraminoX] == 0)                                          // if the cell is empty
		return;

	visitedCells[tetraminoY][tetraminoX] = true;

	if (gridX < 0 || gridX >= columns || gridY < 0 || gridY >= rows    // if the current position on the game grid is outside the valid range
		|| gridContent[gridY * columns + gridX] != EMPTY_CELL_NUMBER)  //
	{
		hasCollision = false;
		return;
	}

	// Do the same for bottom, right, top, and left cells:
	PerformFloodFill(gridX, gridY - 1, tetraminoX, tetraminoY - 1, type, rotation, visitedCells, hasCollision);
	PerformFloodFill(gridX + 1, gridY, tetraminoX + 1, tetraminoY, type, rotation, visitedCells, hasCollision);
	PerformFloodFill(gridX, gridY + 1, tetraminoX, tetraminoY + 1, type, rotation, visitedCells, hasCollision);
	PerformFloodFill(gridX - 1, gridY, tetraminoX - 1, tetraminoY, type, rotation, visitedCells, hasCollision);
}

void Board::ShiftRowsDown(int bottomRowIndex)
{
	assert(bottomRowIndex < rows);

	for (int row = bottomRowIndex; row > 0; row--) // going to bottom row
		for (int columnIndex = 0; columnIndex < columns; columnIndex++)
			gridContent[row * columns + columnIndex] = gridContent[(row - 1) * columns + columnIndex];
}

int Board::ClearRows(const Tetramino& tetramino)
{
	int deletedRowsCount = 0;

	ClearFrom(tetramino);

	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		// Find column with empty cell:
		int emptyCellColumnIndex = 0;
		for (; emptyCellColumnIndex < columns && gridContent[rowIndex * columns + emptyCellColumnIndex] != EMPTY_CELL_NUMBER; emptyCellColumnIndex++)
			continue;

		if (emptyCellColumnIndex == columns) // if all cells in the row are occupied, the row should be cleared.
		{
			ShiftRowsDown(rowIndex);
			deletedRowsCount++;
		}
	}

	Add(tetramino);

	return deletedRowsCount;
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}
