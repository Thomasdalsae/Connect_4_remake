#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>


class Board
{
public:
	
	int columns = 7;
	int	rows = 6;
	char tileSymbol = { '*' };
	
	
public:
	char playersymbol = 'X';

private:

};
void GameBoard(std::vector<std::vector<Board>>board);
void DropPiece(int &position, std::vector<std::vector<Board>> &board);
void animDrop(int, std::vector<std::vector<Board>>&);
bool winChecker(std::vector<std::vector<Board>>animboardChecker);
bool replayLoop(std::vector<std::vector<Board>> &baseBoard);
void resetBoard(std::vector<std::vector<Board>> &baseBoard);