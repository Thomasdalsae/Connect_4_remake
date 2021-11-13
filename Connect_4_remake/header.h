#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>



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
int p;
int solving();
void bestPosition();
bool getValidLocation();
void GameBoard(std::vector<std::vector<Board>>board);
void DropPiece(int &position, std::vector<std::vector<Board>> &board);
void animDrop(int, std::vector<std::vector<Board>>&);
bool winChecker(std::vector<std::vector<Board>>animboardChecker);
bool scorePosition(std::vector<std::vector<Board>>animboardChecker);
void resetBoard(std::vector<std::vector<Board>> &baseBoard);
void playerBoard();
//login
int nametries{};
int passtries{};
int score{};


Player playerOne{};
Player playerTwo{};

//-------------------
//std::string userName;
//std::string playerOne;
//int playerOneWins;
//
//std::string playerTwo;
//int playerTwoWins;
//int playerTwoLosses;
//------------------
void singlePlayer();
void loadPlayer();
void multiPlayer();
void startGame();
void menu();
void renderMenu(int p);
void Exit(std::vector<Player>& PlayerData);
void manageData(std::vector<Player>& PlayerData);

std::vector<std::string>loginnUserName;
std::vector<std::string>loginPassword;
void setting();
std::vector<std::string> entryMenu{ "Single player","Multiplayer","Create account"," Exit" };