// CS270 Vanderbilt University
// Prof. Roth
//Name: Steven Ayanruoh
//Email: Steven.ayanruoh@vanderbilt.edu
//VunetID: Ayanrus
//Honor Statement: I have not received nor given any unauthorized assistance on this assignment.

#ifndef SUDOKU_CPP
#define SUDOKU_CPP


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sudoku.h"
using namespace std;



Sudoku::Sudoku()
{
	for (int row = 0; row < Msize; row++)
		for (int col = 0; col < Msize; col++)
			gameBoard[row][col] = 0;
	//creates a gameBoard that conatins all zeros
}

void Sudoku::loadFromFile(string filename)
{
	ifstream readFile(filename); // opens the input file
	string line;
	
	if (readFile.good()) // asserts that file can be oppened without errors
	{
		int x = 0;
		while (getline(readFile, line)) // reads in the first line of the input at once 
		{
			istringstream lineStream(line);
			string token;
			int y = 0;

			while (lineStream >> token) // reads in a single line of input as single tokens
			{
				int num;
				istringstream ss(token); //single digits represented as strings converted and stored as integers 
				ss >> num;
				gameBoard[x][y] = num;  //modifying the gameBoard 
				y++; //moves the gameBoard across a row
			}
			x++; // moves the gameBoard down a column 
		}

		readFile.close();
	}
	else
	{
		cout << "File unable to be opened";
	}

}

bool Sudoku::solve()
{
	return solver(0,0);
}


void Sudoku::print() const
{
	for (int row = 0; row < 9; row++)
	{
		if (row == 3 || row == 6)  //prints the line that separates the different games horizonatally 
		{
			cout << "------+--------+------\n";
		}

		for (int col = 0; col < 9; col++) // prints the line that separates the different games vertically 
		{
			if (col == 3 || col == 6)
			{
				cout << " |";
			}

			printf("%2d", gameBoard[row][col]); // prints and formats the gameBoard values 
		}
		cout << "\n";
	}

}

bool Sudoku::equals(const Sudoku & other) const
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (gameBoard[row][col] == other.gameBoard[row][col]) // checks value by value whether or not two gameBoard's are equal
			{
				//Do nothing and continue to check gameBoards
			}
			else
			{
				return false; 
			}

		}
	}

	return true;
}


bool Sudoku::checkRow(int row, int col)
{
	for (int i = 0; i < 9; i++) 
	{
		if (i != col)   // checks if the column value needs to be changed 
		{
			if (gameBoard[row][i] == gameBoard[row][col])  // checks if values are the same at any point in a row 
			{
				return false;
			}
		}
	}

	return true;
}

bool Sudoku::checkCol(int row, int col)
{
	for (int i = 0; i < 9; i++) 
	{
		if (i != row)  // checks if the row value needs to be changed 
		{
			if (gameBoard[i][col] == gameBoard[row][col])  // checks if values are the same at any point in a column
			{
				return false;
			}
		}
	}
	return true;
}

bool Sudoku::checkSquare(int row, int col)
{
	int vertHeight = row / 3; //splits the larger game board into the smaller gameBoard vertically 
	int horLength = col / 3; //splits the larger game board in the smaller gameBoard horizontally

	for (int i = vertHeight * 3; i < (vertHeight * 3 + 3); i++) 
	{
		for (int j = horLength * 3; j < (horLength * 3 + 3); j++) 
		{
			if (!(i == row && j == col))
			{ 
				if (gameBoard[row][col] == gameBoard[i][j]) // checks that row and column are not already in the smaller gameBoard 
				{ 
					return false;
				}
			}
		}
	}
	return true;
}

bool Sudoku::solver(int row, int col)
{
	
	while (gameBoard[row][col] != 0) // makes sure that we only change values that are 0s
	{
		col++;

		if (col > 8) 
		{
			col = 0;
			row++;
		}
		if (row > 8) 
		{
			return true;
		}
	}

	for (int n = 1; n < 10; n++) 
	{
		int nextRow, nextCol;

		gameBoard[row][col] = n; //value to be inserted at a point on the gameBoard

		if (checkCol(row, col) && checkRow(row, col) && checkSquare(row, col)) //checks that values set to be changed are valid for a given position on the gameBoard 
		{
			nextRow = row;
			nextCol = col;

			nextCol++;
			if (nextCol > 8) 
			{
				nextCol = 0;
				nextRow++;
			}
			if (nextCol == 0 && nextRow == 9) 
			{
				return true;
			}
			if (solver(nextRow, nextCol)) 
			{
				return true;
			}
		}
	}
	gameBoard[row][col] = 0;
	return false;
}




#endif