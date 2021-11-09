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

std::string player;
void GameBoard(std::vector<std::vector<Board>>board);
void DropPiece(int &position, std::vector<std::vector<Board>> &board);
void animDrop(int, std::vector<std::vector<Board>>&);
bool winChecker(std::vector<std::vector<Board>>animboardChecker);
void resetBoard(std::vector<std::vector<Board>> &baseBoard);
//login
int nametries{};
int passtries{};
std::string userName;
std::string passWord;
//------------------
void singlePlayer();
void multiPlayer();
void startGame();
void menu();
void renderMenu(int p);
void createAccount();
bool logIn();
std::vector<std::string>loginnUserName;
std::vector<std::string>loginPassword;
void setting();
std::vector<std::string> entryMenu{ "Single player","Multiplayer","Create account"," Exit" };