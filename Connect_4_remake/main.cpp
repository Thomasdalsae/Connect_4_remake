
#include "player.h"
#include "header.h"



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




}

void multiPlayer() {

	
	
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

void DropPiece(int &position, std::vector<std::vector<Board>> &TempBoard)
{
	system("cls");
	while (true)
	{
		GameBoard(TempBoard);

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
void playerBoard()
{
	std::cout << playerOne.name << playerOne.wins <<" VS " << playerTwo.wins << playerOne.name << std::endl;

	return;
}

void GameBoard(std::vector<std::vector<Board>>Boardlayout)
{
	system("cls");
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

void animDrop(int, std::vector<std::vector<Board>>&animboard)
{
	
	
	for (int row = animboard.size() - 1; row >= 0; row--)
	{
		if (animboard[row][position].tileSymbol == 'X' || animboard[row][position].tileSymbol == 'O')
		{
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
	winChecker(animboard);

	if (winChecker(animboard) == true)
	{
		if (board.playersymbol == 'X') {

			std::cout << "Congratulations" << playerOne.name << std::endl;
			playerOne.wins++;
		}
		else
		{
			std::cout << "Congratulations" << playerTwo.name << std::endl;
			playerTwo.wins++;
		}
		std::cout << "Looks like the game is over" << std::endl;
		std::cout << "Do you want to play again ? : Y/N" << std::endl;
		std::cin >> answer;

		position = 0;


		switch (toupper(answer))
		{

		case 'Y':
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

	turn = 0;
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


	
}

bool winChecker(std::vector<std::vector<Board>>animboardChecker)
{

	//checking win condition for sideways
	for (int rows = 0; rows < animboardChecker.size(); rows++)
	{
		for (int columns = 0; columns < animboardChecker[0].size() - 3; columns++)
		{
			if (rows > 0 || rows < animboardChecker.size() || columns > 0 || columns < animboardChecker.size())
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
					std::cout << "you won mf!!!" << std::endl;
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
						if (rows > 0 || rows < animboardChecker.size() || columns > 0 || columns < animboardChecker.size())
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
								std::cout << "upppppppppppppppppppp" << std::endl;
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
					if (rows > 0 || rows < animboardChecker.size() || columns > 0 || columns < animboardChecker.size())
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
								std::cout << "upppppppppppppppppppp" << std::endl;
								return true;
							}
						}
					}
				}
						//checking win condtiion for diagonally down to the right 
							for (int columns = 3; columns < animboardChecker[0].size(); columns++)

					{
							for (int rows = 0; rows < animboardChecker.size() - 3; rows++)
							{
				
								if (rows > 0 || rows < animboardChecker.size() || columns > 0 || columns < animboardChecker.size())
								{

								//if * skip the whole shaity
								if (animboardChecker[rows][columns].tileSymbol == '*')
								{
									continue;
								}
								if (animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 1][columns - 1].tileSymbol &&
									animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 2][columns - 2].tileSymbol &&
									animboardChecker[rows][columns].tileSymbol == animboardChecker[rows + 3][columns - 3].tileSymbol)

								{
									std::cout << "sideways" << std::endl;
									return true;
								}
							}
						}
					}


	return false;


}

void loadPlayer()
{
	std::vector<Player> PlayerData{};

	std::string p;
	std::ifstream i_file("playerDataBase.dat");
	std::ofstream o_file("playerDataBase.dat", std::fstream::app);

	while (std::getline(i_file,p))
	{
		Player temp{};
		temp.name = p;

		std::getline(i_file, p);
		temp.wins = std::stoi(p);

		std::getline(i_file, p);
		temp.losses = std::stoi(p);
		
		std::cout << temp.name << std::endl;
		std::cout << temp.wins << std::endl;
		std::cout << temp.losses << std::endl;
		PlayerData.push_back(temp);
	}
	
	
	

	
	manageData(PlayerData);
	for (size_t i = 0; i < PlayerData.size(); i++)
	{
		

		// Write to the file
		o_file << PlayerData[i].name << std::endl;
		o_file << PlayerData[i].wins << std::endl;
		o_file << PlayerData[i].losses << std::endl;
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
		}
	}
	if (PlayerData.size() == 0)
	{
		PlayerData.push_back(Player{});
		PlayerData[0].name = playerOne.name;
		PlayerData[0].wins = playerOne.wins;
		PlayerData[0].losses = playerOne.losses;
	}
}
void Exit(std::vector<Player>& PlayerData) {


	exit(0);



	
}


