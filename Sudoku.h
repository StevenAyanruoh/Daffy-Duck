// CS270 Vanderbilt University
// Prof. Roth
//Name: Steven Ayanruoh
//Email: Steven.ayanruoh@vanderbilt.edu
//VunetID: Ayanrus
//Honor Statement: I have not received nor given any unauthorized assistance on this assignment.#pragma once



#ifndef SUDOKU_H
#define SUDOKU_H


#include <string>
#include <iostream>
using namespace std;

static const int Msize = 9;

class Sudoku {


private: 

	int gameBoard[Msize][Msize];
	bool checkRow(int row, int col);
	bool checkCol(int row, int col);
	bool checkSquare(int row, int col);
	bool solver(int row, int col);
	

public: 

	Sudoku();
	void loadFromFile(string filename);
	bool solve();
	void print() const;
	bool equals(const Sudoku &other) const;









};







#endif