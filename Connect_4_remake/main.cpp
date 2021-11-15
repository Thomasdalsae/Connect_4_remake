
#include "player.h"
#include "header.h"
#include "position.hpp"


int position{};
int k{};
int turn{};
int count{0};
Board board;
Player player;

char answer;


int main() {

	
	
	while (true)
	{
	menu();
	}
	return 0;

}

void menu()
{
	//simple menu to select which game mode you want to play.
	while (true)
	{
		renderMenu(p);

		char b = _getch();

		switch (toupper(b))
		{
			//Player goes left
		case 'W':
			p--;
			if (p < 0 )
			{
				p = 2;
			}
			break;
			//Player goes right
		case 'S':
			p++;
			if (p >= 3)
			{
				p = 0;
			}
			break;

		case ' ':
			if (p == 0)
			{
				singlePlayer();
				return;
			}
			if (p == 1) {
				
				multiPlayer();
				return;
				
			}
			if (p == 2)
			{
				
				return;
			}
			break;

		default:
			break;
		}
	}
}

void singlePlayer() {

	//Only the playerOne needs to input the name, the playerTwo will automatically become the AI.

	std::cout << "Enter playerone name: ";
	std::cin >> playerOne.name;



	playerTwo.name = "AI";


	std::cout << "Welcome!" << std::endl << playerOne.name << " and " << playerTwo.name << std::endl;

	Sleep(1500);

	startGame();

}

void multiPlayer() {

	//playerOne and playerTwo needs to input their names.
	
	std::cout << "Enter playerone name: ";
	std::cin >> playerOne.name;
	


	std::cout << "enter playertwo name: ";
	std::cin >> playerTwo.name;
	
	
	std::cout << "Welcome!"<< std::endl << playerOne.name <<" and " << playerTwo.name << std::endl;
	
	Sleep(1500);
	
	startGame();
}

void renderMenu(int p)
{
	//This adds an visual arrow for the main menu.
	system("cls");
	for (int rows = 0; rows < 3; rows++)
	{
		
		if (p == rows) {
			std::cout << "-> :";
			std::cout << entryMenu[rows];
		}
		else
		{
			std::cout << "   :";
			std::cout << entryMenu[rows];
		}
		std::cout << std::endl;
	}

	

}	

void setting()
{
}



void startGame()
{

	turn = 0;
	position = 0;

	while (true)
	{
		std::vector<std::vector<Board>> baseBoard(board.rows, std::vector<Board>(board.columns, Board{ '*' }));
		DropPiece(position, baseBoard);

	}
}

void playerBoard()
{
	std::cout << playerOne.name << " " << playerOne.wins <<" VS " << playerTwo.wins <<" " << playerTwo.name << std::endl;
	std::cout << turn;

	return;
}

void GameBoard(std::vector<std::vector<Board>>Boardlayout)
{
	system("cls");
	std::cout << score << std::endl;
	
	playerBoard();
	
	//change to platyer choosing symbol
	if (turn % 2 == 0) {
		board.playersymbol = 'X';
	}
	else
	{
		board.playersymbol = 'O';
	}
	
	
	
	for (int columns = 0; columns < Boardlayout[0].size(); columns++)
	{
		if (position == columns) {
			std::cout << " | ";
		}
		else
		{
			std::cout << "   ";
		}
	}
	std::cout << std::endl;
	for (int columns = 0; columns < Boardlayout[0].size(); columns++)
	{
		if (position == columns) {
			std::cout  << " V " ;
		}
		else
		{
			std::cout<< "   ";
		}
	}
	std::cout << std::endl;
	for (int columns = 0; columns < Boardlayout[0].size(); columns++)
	{
		if (position == columns) {
			std::cout << "(" << board.playersymbol << ")";
		}
		else
		{
			std::cout << "(" << " " << ")";
		}	
	}
	std::cout << std::endl;
	


	for (int rows = Boardlayout.size() - 1; rows >= 0; rows--)
	{
		
		for (int columns = 0; columns < Boardlayout[0].size(); columns++)
		{


			std::cout << "[" << Boardlayout[rows][columns].tileSymbol << "]";
		}
		std::cout << std::endl;
	}
	
	
	
	
	

}

void restart(int g)
{
	system("cls");
	for (int rows = 0; rows < 3; rows++)
	{

		if (g == rows) {
			std::cout << "-> :";
			std::cout << entryMenu[rows];
		}
		else
		{
			std::cout << "   :";
			std::cout << entryMenu[rows];
		}
		std::cout << std::endl;
	}

}
void animDrop(int, std::vector<std::vector<Board>>&animboard)
{
	
	
	for (int row = animboard.size() - 1; row >= 0; row--)
	{
		
		if (animboard[row][position].tileSymbol == 'X' || animboard[row][position].tileSymbol == 'O')
		{
			if (animboard[row][position].tileSymbol == animboard[animboard.size()-1][position].tileSymbol)
			{
				std::cout << "This slot is already taken... Try somewhere else!";
				system("pause");
				turn--;
				break;
				
			}
			row++;
			animboard[row][position].tileSymbol = board.playersymbol;
			
			break;
		}
		if (animboard[row][position].tileSymbol == '*')
		{

			animboard[row][position].tileSymbol = board.playersymbol;


		}
		if (row >= 0) {
			animboard[row][position].tileSymbol = board.playersymbol;


			board.rows = row;
			board.columns = position;
			GameBoard(animboard);


			Sleep(100);
			if (row == 0)
			{
				break;

			}
			animboard[row][position].tileSymbol = '*';
		
		}
		
	}
	if (drawChecker(animboard)) {

		std::cout << "Looks like the game ended in a draw" << std::endl;
		std::cout << "Do you want to play again ? : Y/N" << std::endl;

		std::cin >> answer;
		if (answer > 0) {
			std::cout << " please write Y or N ";
			std::cin >> answer;
		}

		
		switch (toupper(answer))
		{

		case 'Y':
			turn = 0;
			position = 0;
			resetBoard(animboard);

			break;

		case 'N':

			loadPlayer();
			break;


			break;

		default:
			break;
		}
	}

	if (winChecker(animboard))
	{
		

		if (board.playersymbol == 'X') {

			std::cout << "Congratulations " << playerOne.name << std::endl;
			playerOne.wins++;
			playerTwo.losses++;
		}
		else
		{
			std::cout << "Congratulations " << playerTwo.name << std::endl;
			playerTwo.wins++;
			playerOne.losses++;
		}
		

		while (true)
		{
			
			restart(g);

			char g = _getch();

			switch (toupper(g))
			{
				//Player goes left
			case 'W':
				g--;
				if (g < 0)
				{
					g = 2;
				}
				break;
				//Player goes right
			case 'S':
				g++;
				if (g >= 3)
				{
					g = 0;
				}
				break;

			case ' ':
				if (g == 0)
				{
					
					return;
				}
				if (g == 1) {

					turn = 0;
					position = 0;
					resetBoard(animboard);

					break;

				}
				if (g == 2)
				{
					loadPlayer();
					break;

					return;
				}
				break;

			default:
				break;
			}
		}

		switch (toupper(answer))
		{

		case 'Y':
			turn = 0;
			position = 0;
			resetBoard(animboard);
			
			break;

		case 'N':
			
			loadPlayer();
			break;


			break;

		default:
			break;
		}


	}
	
	
  }

void resetBoard(std::vector<std::vector<Board>> &baseBoard)
{
	
	system("cls");
	
	
	
	for (int columns = 0; columns < baseBoard[0].size(); columns++)
	{
		if (position == columns) {
			std::cout << " | ";
		}
		else
		{
			std::cout << "   ";
		}
	}
	std::cout << std::endl;
	for (int columns = 0; columns < baseBoard[0].size(); columns++)
	{
		if (position == columns) {
			std::cout << " V ";
		}
		else
		{
			std::cout << "   ";
		}
	}
	std::cout << std::endl;
	for (int columns = 0; columns < baseBoard[0].size(); columns++)
	{
		if (position == columns) {
			std::cout << "(" << board.playersymbol << ")";
		}
		else
		{
			std::cout << "(" << " " << ")";
		}
	}
	std::cout << std::endl;



	for (int rows = baseBoard.size() - 1; rows >= 0; rows--)
	{

		for (int columns = 0; columns < baseBoard[0].size(); columns++)
		{
			baseBoard[rows][columns].tileSymbol = '*';

			std::cout << "[" << baseBoard[rows][columns].tileSymbol << "]";
		}
		std::cout << std::endl;
	}

	turn = -1;

	
}

bool winChecker(std::vector<std::vector<Board>>animboardChecker)
{

	//checking win condition for sideways
	for (int rows = 0; rows < animboardChecker.size(); rows++)
	{
		for (int columns = 0; columns < animboardChecker[0].size() - 3; columns++)
		{
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{
			    //if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows][columns + 2].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows][columns + 3].tileSymbol)
				{
					std::cout << "sideways four in a row" << std::endl;
					return true;
					
				}
			}
		}
	}
//checking win condition for up
	for (int columns = 0; columns < animboardChecker[0].size(); columns++)
	{
		for (int rows = 0; rows < animboardChecker.size() - 3; rows++)
		{
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{

				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 1][columns].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 2][columns].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 3][columns].tileSymbol)
				{
					std::cout << "upwards four in a row" << std::endl;
					return true;
				}
			}
		}
	}
				
			//checking win condition for diagonally to the right
	for (int columns = 0; columns < animboardChecker[0].size() - 3; columns++)
	{
		for (int rows = 0; rows < animboardChecker.size() - 3; rows++)
		{
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{	

				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 1][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 2][columns + 2].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 3][columns + 3].tileSymbol)
					
					{
					std::cout << "diagonally up to the right four in a row" << std::endl;
					return true;
				}
			}
		}
     }
						//checking win condtiion for diagonally down to the right 
	for (int columns = 0; columns < animboardChecker[0].size() - 3; columns++)

	{
		for (int rows = 3; rows < animboardChecker.size(); rows++)
		{
				
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{

				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows - 1][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows - 2][columns + 2].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows - 3][columns + 3].tileSymbol)

				{
					std::cout << "diagonally down to the right four in a row " << std::endl;
					return true;
				}
			}
		}
	}
	

	return false;


}

bool drawChecker(std::vector<std::vector<Board>>animboardChecker)
{
	
	for (int columns = 0; columns < animboardChecker[0].size(); columns++) {
		if (turn == 41)
		{
			return true;
		}
		
	}
	return false;
}

bool winCheckerExtra(std::vector<std::vector<Board>>animboardChecker)
{
	//checking win condition for sideways
	for (int rows = 0; rows < animboardChecker.size(); rows++)
	{
		for (int columns = 0; columns < animboardChecker[0].size() - 2; columns++)
		{
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{
				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows][columns + 2].tileSymbol)
				{
					std::cout << "Sideways 3 in a row " << std::endl;
					return true;

				}
			}
		}
	}
		//checking win condition for up
		for (int columns = 0; columns < animboardChecker[0].size(); columns++)
		{
			for (int rows = 0; rows < animboardChecker.size() - 2; rows++)
			{
				if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
				{

		
				
					if (animboardChecker[rows][columns].tileSymbol == '*')
					{
						continue;
					}
					if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 1][columns].tileSymbol &&
						animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 2][columns].tileSymbol)
					{
						std::cout << "uppppp three in a row" << std::endl;
						return true;
					}
				}
			}
		}

	//checking win condition for diagonally to the right
	for (int columns = 0; columns < animboardChecker[0].size() - 2; columns++)
	{
		for (int rows = 0; rows < animboardChecker.size() - 2; rows++)
		{
			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{

				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 1][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 2][columns + 2].tileSymbol)

				{
					std::cout << " diagonally up to the right three in a row" << std::endl;
					return true;
				}
			}
		}
	}
	//checking win condtiion for diagonally down to the right 
	for (int columns = 0; columns < animboardChecker[0].size() - 2; columns++)

	{
		for (int rows = 2; rows < animboardChecker.size(); rows++)
		{

			if ((rows >= 0 || rows < animboardChecker.size()) && (columns > 0 || columns < animboardChecker[0].size()))
			{

				//if * skip the whole shaity
				if (animboardChecker[rows][columns].tileSymbol == '*')
				{
					continue;
				}
				if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows - 1][columns + 1].tileSymbol &&
					animboardChecker[rows][columns].tileSymbol == animboardChecker[rows - 2][columns + 2].tileSymbol)

				{
					std::cout << "diagonally down to the right four in a row " << std::endl;
					return true;
				}
			}
		}
	}
	return false;
}

void DropPiece(int &position, std::vector<std::vector<Board>> &TempBoard)
{
	system("cls");
	while (true)
	{
		GameBoard(TempBoard);

		if (playerTwo.name == "AI" && board.playersymbol == 'O')
		{
			position = 0;
		
			bestPosition(position,TempBoard);
			std::cout << position << std::endl;
			
			
			animDrop(position, TempBoard);
			turn++;
			
		}

		char b = _getch();

		switch (toupper(b))
		{
			//Player goes left
		case 'A':

			position += -1;

			if (position < 0)
			{
				position = TempBoard.size();
			}

			break;
			//Player goes right
		case 'D':
			position += 1;

			if (position == TempBoard.size() + 1)
			{
				position = 0;

			}
			break;

		case ' ':

			animDrop(k, TempBoard);
			turn++;

			break;

		default:
			break;
		}
	}
	std::cout << position;
}

int bestPosition(int &position,std::vector<std::vector<Board>>TempBoard) 
{
		bool threerow = false;
		bool blockThreeRow = false;
		for (int columns = 0; columns < TempBoard[0].size(); columns++) 
		{
				int row{};
				bool fullCol = false;

			for (row = TempBoard.size() - 1; row >= 0; row--)
			{

				if (TempBoard[row][columns].tileSymbol == 'X' || TempBoard[row][columns].tileSymbol == 'O')
				{
					if (row == TempBoard.size() - 1)
					{
						fullCol = true;
						
						break;
					}
					row++;
					break;
				}
				
			}
			if (fullCol)
			{
				continue;
			}
			else if (row < 0)
			{
				row = 0;
			}
			std::cout << row <<"  " << columns << std::endl;
			

			TempBoard[row][columns].tileSymbol = 'O';

			if (winChecker(TempBoard))
			{
				position = columns;
				return position;
			}
		
			TempBoard[row][columns].tileSymbol = 'X';

			if (winChecker(TempBoard))
			{
				position = columns;
				return position;
			}
		
			if (winCheckerExtra(TempBoard))
			{
				position = columns;
				blockThreeRow = true;
				
			}
			TempBoard[row][columns].tileSymbol = 'O';

			if (!blockThreeRow && winCheckerExtra(TempBoard))
			{

				position = columns;
				threerow = true;
				
			
			}
			TempBoard[row][columns].tileSymbol = '*';
			std::cout << position;
			system("pause");
			
		}
	if (blockThreeRow && !threerow)
	{
		return position;

	}
	if (threerow && !blockThreeRow)
	{
		return position;
	}
	if (!blockThreeRow && !threerow)
	{
		std::cout << "RAdnom time !!!";
		system("pause");
		std::random_device rd{};
		std::mt19937_64 g(rd());
		std::uniform_int_distribution<int> rng(0, TempBoard[0].size() - 1);
		position = rng(g);
		return position;
	}
		
				
}

void loadPlayer()
{

	std::vector<Player> PlayerData{};

	std::string p;
	std::ifstream i_file;
	i_file.open("playerDataBase.dat");
	

	while (std::getline(i_file, p))
	{
		
		Player temp{};
		temp.name = p;

		std::getline(i_file, p);
		std::cout << p << std::endl;
		temp.wins = std::stoi(p);

		std::getline(i_file, p);
		temp.losses = std::stoi(p);
		
		std::cout << temp.name << std::endl;
		std::cout << temp.wins << std::endl;
		std::cout << temp.losses << std::endl;
		PlayerData.push_back(temp);
	}
	 
	manageData(PlayerData);
	std::ofstream o_file("playerDataBase.dat");
	for (size_t i = 0; i < PlayerData.size(); i++)
	{
		

		// Write to the file
		o_file << PlayerData[i].name << std::endl;
		o_file << PlayerData[i].wins << std::endl;
		o_file << PlayerData[i].losses;
		if (i != PlayerData.size()-1)
		{
			o_file << std::endl;
		}
	}
	i_file.close();
	o_file.close();
	system("pause");
	Exit(PlayerData);
}

void manageData(std::vector<Player>& PlayerData)
{
	for (size_t i = 0; i < PlayerData.size(); i++)
	{


		if (PlayerData[i].name == playerOne.name)
		{
			PlayerData[i].wins += playerOne.wins;
			PlayerData[i].losses += playerOne.losses;
			break;
		}
		if (i == PlayerData.size()-1)
		{
			Player temp{};
			temp.name = playerOne.name;
			temp.wins = playerOne.wins;
			temp.losses = playerOne.losses;
			PlayerData.push_back(temp);
			break;
		}

	}
	if (PlayerData.size() == 0)
	{
		PlayerData.push_back(Player{});
		PlayerData[0].name = playerOne.name;
		PlayerData[0].wins = playerOne.wins;
		PlayerData[0].losses = playerOne.losses;
	}
	for (size_t i = 0; i < PlayerData.size(); i++)
	{


		if (PlayerData[i].name == playerTwo.name)
		{
			PlayerData[i].wins += playerTwo.wins;
			PlayerData[i].losses += playerTwo.losses;
			break;
		}
		if (i == PlayerData.size() - 1)
		{
			Player temp{};
			temp.name = playerTwo.name;
			temp.wins = playerTwo.wins;
			temp.losses = playerTwo.losses;
			PlayerData.push_back(temp);
			break;
		}

	}
	if (PlayerData.size() == 0)
	{
		PlayerData.push_back(Player{});
		PlayerData[0].name = playerTwo.name;
		PlayerData[0].wins = playerTwo.wins;
		PlayerData[0].losses = playerTwo.losses;
	}
	
}

void Exit(std::vector<Player>& PlayerData) {


	exit(0);



	
}