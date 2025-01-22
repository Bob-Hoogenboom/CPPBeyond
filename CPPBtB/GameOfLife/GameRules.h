#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class GameRules
{
	int collums;
	int rows;
	int** grid;
	int** nextGrid;
	sf::VertexArray quad;
	int tileSize = 4;

public:
	GameRules(sf::RenderWindow* window) 
	{
		float width = window->getSize().x;
		float height = window->getSize().y;

		collums = width / tileSize;
		rows = height / tileSize;

		grid = new int* [rows];
		nextGrid = new int* [rows];
		for (int row = 0; row < rows; row++)
		{
			grid[row] = new int[collums];
			nextGrid[row] = new int[collums];
			for (int  col = 0; col < collums; col++)
			{
				grid[row][col] = 0;
				if (rand() % 10 <3)
				{
					grid[row][col] = 1;
				}
				nextGrid[row][col] = grid[row][col];
			}
		}

		quad = sf::VertexArray(sf::Quads, rows * collums * 4);

		int i = 0;
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < collums; col++)
			{
				float x = 1 + col * (tileSize +1);
				float y = 1 + row * (tileSize +1);

				quad[i].position = sf::Vector2f(x, y);
				quad[i + 1].position = sf::Vector2f(x + tileSize, y);
				quad[i + 2].position = sf::Vector2f(x + tileSize, y + tileSize);
				quad[i + 3].position = sf::Vector2f(x, y + tileSize);

				quad[i].color = sf::Color::White;
				quad[i + 1].color = sf::Color::White;
				quad[i + 2].color = sf::Color::White;
				quad[i + 3].color = sf::Color::White;
				
				i += 4;
			}
		}
	}

	int countLiveNeighours(int row, int col)
	{
		int dirRow[8] = { 1, -1, 1, -1, 1, -1, 0, 0 };
		int dirCol[8] = { -1, -1, 1, 1, 0, 0, 1, -1 };

		int count = 0;
		for (int n = 0; n < 8; n++)
		{
			int neighbourRow = row + dirRow[n];
			int neighbourCol = col + dirCol[n];

			if ( neighbourRow < 0 || neighbourRow > rows - 1 || neighbourCol < 0 || neighbourCol > collums - 1 )
			{
				continue;
			}

			if ( grid[neighbourRow][neighbourCol] == 1 )
			{
				count += 1;
			}
		}
		return count;
	}

	void update() 
	{
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < collums; col++)
			{
				int liveNeighbours = countLiveNeighours( row, col );
				//game of life rules:
				//Any live cell with fewer than two live neighbours dies, as if by underpopulation
				//Any live cell with two or three live neighbours lives on to the next generation
				if ( grid[row][col] == 1 && liveNeighbours < 2 )
				{
					nextGrid[row][col] = 0;
				}
				//Any live cell with more then three live neighbours dies, as if by overpopulation
				else if ( grid[row][col] == 1 && liveNeighbours > 3 )
				{
					nextGrid[row][col] = 0;
				}
				//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
				else if ( grid[row][col] == 0 && liveNeighbours == 3 )
				{
					nextGrid[row][col] = 1;
				}
				else
				{
					nextGrid[row][col] = grid[row][col];
				}
			}
		}

		int i = 0;
		for ( int row = 0; row < rows; row++ )
		{
			for ( int col = 0; col < collums; col++ )
			{
				grid[row][col] = nextGrid[row][col];
				
				if ( grid[row][col] == 1 )
				{
					quad[i].color = sf::Color::Black;
					quad[i + 1].color = sf::Color::Black;
					quad[i + 2].color = sf::Color::Black;
					quad[i + 3].color = sf::Color::Black;
				}
				else
				{
					quad[i].color = sf::Color::White;
					quad[i + 1].color = sf::Color::White;
					quad[i + 2].color = sf::Color::White;
					quad[i + 3].color = sf::Color::White;
				}

				i += 4;
			}
		}
	}

	void draw( sf::RenderWindow* window )
	{
		window->draw(quad);
	}
};

