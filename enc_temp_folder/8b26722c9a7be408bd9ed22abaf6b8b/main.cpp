
#include "Player.h"



int position{};
int k{};
int turn{};
int count{0};
Board board;
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
				createAccount();
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
	for (size_t i = 0; i < 2; i++)
	{
		logIn();
	}
	
		
	

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
void createAccount()
{
	char t;
	std::cout << "Welcome new player!" << std::endl;
	std::cout << "Enter username :";
	std::cin >> userName;
	std::cout << "Enter password :";
	std::cin >> passWord;
	
	std::ofstream outf{ "newUser.dat" };
	if (!outf)
	{
		// Print an error and exit
		std::cerr << "Looks like there is no file to open" << std::endl;
		return;
	}
	outf << "_n " << userName << '\n';
	outf << "_p " << passWord << '\n';
	outf << "#" << '\n';

	outf.close();
	
	
	std::ifstream i_file("newUser.dat");
	std::ofstream o_file("playerDataBase.dat",std::fstream::app);

	while (i_file.get(t)) 
	{

		o_file.put(t);
	}
	i_file.close();
	o_file.close();
	std::cout << "Thanks for joining us " << userName << std::endl;
	return;
	
}
bool logIn()
{
	std::string tempname;
	std::string temppass;
	while (true)
	{
		std::cout << "Username: ";
		std::cin >> tempname;
		std::cout << "password: ";
		std::cin >> temppass;
		
		
		
		
		std::ifstream infile("playerDataBase.dat");
		std::string line{};

		while (std::getline(infile, line))
		{
			
			std::string line1 = line.substr(3);
			std::cout << line << std::endl;
			
			

			
				if (tempname == line1)
				{
					std::cout << "reee";
					break;
				}
			
		}

		


		
	}
	
	

	//while (true)
	//{
	//	loginnUserName.clear();
	//	loginPassword.clear();
	//	nametries = 0;
	//	passtries = 0;


	//	//saves the attempts to the templogin
	//		//checks the text file
	//		//take one and one line from the txt
	//		//after the 9th char it will start the check.
	//	std::string tempLogin;
	//	std::ifstream infile("playerDataBase.dat");
	//	std::string line{};
	//	
	//	while (std::getline(infile, line))
	//	{
	//		std::cout << line << std::endl;
	//	
	//	}

	//	std::string line1 = line.substr(3);


	//	std::cout << "Username: ";
	//	std::cin >> tempLogin;
	//	loginnUserName.push_back(tempLogin);

	//	std::cout << line1 << std::endl;;
	//	std::cout << loginnUserName[nametries] << std::endl;
	//	//if the username matches the line from the txt file it will give them the chance to write inn the password
	//	tempLogin
	//	if (loginnUserName[nametries] == line1)
	//	{
	//		player = line1;
	//		std::getline(infile, line);
	//		std::string line2 = line.substr(3);
	//		std::cout << "password: ";
	//		std::cin >> tempLogin;
	//		loginPassword.push_back(tempLogin);

	//		std::cout << line2 << std::endl;;
	//		std::cout << loginPassword[passtries] << std::endl;

	//		if (loginPassword[passtries] == line2)
	//		{
	//			std::cout << "Welcome " << loginnUserName[nametries] << std::endl;
	//			Sleep(500);
	//			return { true };

	//		}
	//		std::cout << "Password was not correct...Try again" << std::endl;
	//		passtries++;

	//	}

	//	std::cout << "User not found...Try again or create a account inn the menu" << std::endl;
	//	nametries++;
	//}


	//

	//return {};
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

void GameBoard(std::vector<std::vector<Board>>Boardlayout)
{
	
	//change to platyer choosing symbol
	if (turn % 2 == 0) {
		board.playersymbol = 'X';
	}
	else
	{
		board.playersymbol = 'O';
	}
	
	
	system("cls");
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


	
}

bool winChecker(std::vector<std::vector<Board>>animboardChecker)
{

	//checking win condition for sideways
	for (int rows = 0; rows < animboardChecker.size(); rows++)
	{
		for (int columns = 0; columns < animboardChecker[0].size() - 3; columns++)
		{
			if (columns > 0 || columns < animboardChecker[0].size())
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
						if (rows > 0 || rows < animboardChecker.size())
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
							for (int columns = 3; columns < animboardChecker[0].size() - 3; columns++)

					{
						for (int rows = 3; rows < animboardChecker.size(); rows++)
						{
				
							if (rows > 3 || rows < animboardChecker.size() || columns > 3 || columns < animboardChecker[0].size())
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
									std::cout << "sideways" << std::endl;
									return true;
								}
							}
						}
					}


	return false;


}





