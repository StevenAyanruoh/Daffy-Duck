#include <iostream>
#include <string>
#include <time.h>
#include "Sudoku.h"
using namespace std;

int main()
{
	Sudoku game;

	Sudoku board;

	board.loadFromFile("sudoku-test1.txt");
	board.solve();

	game.loadFromFile("sudoku-test1.txt");

	board.print();
	cout << "\n";
	cout << "\n";
	cout << "\n";

	game.print(); 
	cout << "\n";
	
	cout << board.equals(game);

	cout << "\n";



	return 0;

}