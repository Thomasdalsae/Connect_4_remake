#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <random>



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

//MENUS
void startGame();
void menu();
void renderMenu(int p);
void setting();
void restart(int g);
//MODES
void singlePlayer();
void multiPlayer();
int g;
int p;
//BOARDS
int score{};
void playerBoard();
void GameBoard(std::vector<std::vector<Board>>board);
void DropPiece(int &position, std::vector<std::vector<Board>> &board);
void animDrop(int, std::vector<std::vector<Board>>&);
void resetBoard(std::vector<std::vector<Board>>& baseBoard);
//WINCHECKERS
bool winChecker(std::vector<std::vector<Board>>animboardChecker);
bool drawChecker(std::vector<std::vector<Board>>animboardChecker);
//FOR AI
bool winCheckerExtra(std::vector<std::vector<Board>>animboardChecker);
//AI
int bestPosition(std::vector<std::vector<Board>>animboardChecker);


//login
int nametries{};
int passtries{};

//DATA SORTING
void loadPlayer();
void Exit(std::vector<Player>& PlayerData);
void manageData(std::vector<Player>& PlayerData);
//VECTORS
std::vector<std::string>loginnUserName;
std::vector<std::string>loginPassword;
std::vector<std::string> entryMenu{ "Single player","Multiplayer"," Exit" };
std::vector<std::string> restartMenu{ "Try again","Exit"};