
#include "Player.h"



int position{};
int k{};
int turn{};
int count{0};
Board board;
char answer;


int main() {
	
		std::vector<std::vector<Board>> baseBoard(board.rows, std::vector<Board>(board.columns, Board{ '*' }));

		turn = 0;
		position = 0;

		DropPiece(position, baseBoard);

	return 0;
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
		replayLoop(animboard);

	}
	
	
  }
bool replayLoop(std::vector<std::vector<Board>> &baseBoard)
{
	


	std::cout << "Looks like the game is over" << std::endl;
	std::cout << "Do you want to play again ? : Y/N" << std::endl;
	std::cin >> answer;

	position = 0;


	switch (toupper(answer))
	{
		//Player goes left
	case 'Y':
		resetBoard(baseBoard);
		break;
		//Player goes right
	case 'N':

		break;


		break;

	default:
		break;
	}
	
	
	
	return false;
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


			std::cout << "[" << baseBoard[rows][columns].tileSymbol << "]";
		}
		std::cout << std::endl;
	}


	main();
}





bool winChecker(std::vector<std::vector<Board>>animboardChecker)
{
	

	//handle side to side


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
	return false;


}





