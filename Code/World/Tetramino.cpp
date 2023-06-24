#include "Tetramino.h"

#include <cassert>

const sf::Color Tetramino::COLORS[int(Type::SIZE)] =
{
	sf::Color::Blue,
	sf::Color::Red,
	sf::Color::Green,
	sf::Color::Cyan,
	sf::Color::Magenta,
	sf::Color::White,
	sf::Color(195,132,58) // dark gray
};

const int Tetramino::SHAPES[int(Type::SIZE)][ROTATIONS_COUNT][MATRIX_SIZE][MATRIX_SIZE] =
{
	// Type: O
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	},

	// Type: I
	{
		{
			{ 0, 0, 0, 0 },
			{ 1, 1, 2, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 1, 1, 2, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
		}
	},

	// Type: S
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 2, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 2, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 }
		}
	},

	// Type: Z
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 1 },
			{ 0, 0, 2, 1 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 1 },
			{ 0, 0, 2, 1 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	},

	// Type: L
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 1 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 1 },
			{ 0, 1, 2, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 1, 1, 0 },
			{ 0, 0, 2, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	},

	// Type: J
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 1 },
			{ 0, 0, 2, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 2, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	},

	// Type: T
	{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 2, 1 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 0, 2, 1 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 1, 2, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 1, 0 },
			{ 0, 1, 2, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	}
};

Tetramino::Tetramino(Type type, int rotation)
	: type(type), rotation(rotation), positionX(0), positionY(0)
{
	assert(rotation >= 0 and rotation < ROTATIONS_COUNT);
}

Tetramino::Type Tetramino::GetType() const
{
	return type;
}

void Tetramino::SetRotation(int rotation)
{
	assert(rotation >= 0 and rotation < ROTATIONS_COUNT);

	this->rotation = rotation;

	clockSinceLastTransform.restart();
}

int Tetramino::GetRotation() const
{
	return rotation;
}

void Tetramino::SetPosition(int x, int y)
{
	positionX = x;
	positionY = y;

	clockSinceLastTransform.restart();
}

int Tetramino::GetPositionX() const
{
	return positionX;
}

int Tetramino::GetPositionY() const
{
	return positionY;
}

float Tetramino::GetTimeSinceLastTransform() const
{
	return clockSinceLastTransform.getElapsedTime().asSeconds();
}