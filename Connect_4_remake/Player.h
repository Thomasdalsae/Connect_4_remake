#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>


class GamePiece
{
public:
	
	int x = 7;
	int	y = 6;
	char tileSymbol = { '*' };
	int color;
	
public:
	char _playerSymbol = 'x';


private:

};

void GameBoard(std::vector<std::vector<GamePiece>> Board);
void DropPiece(int &position, std::vector<std::vector<GamePiece>> Board);
void animDrop(int, std::vector<std::vector<GamePiece>>&);
bool winChecker(std::vector<std::vector<GamePiece>>& animboardChecker);