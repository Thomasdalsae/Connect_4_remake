
#include "Player.h"
GamePiece rows;
GamePiece columns;
GamePiece player;

int position{};
int k{};
int turn{};
int count{0};

int main() {
	rows.y;
	columns.x;
	
	std::vector<std::vector<GamePiece>> Board(rows.y, std::vector<GamePiece>(columns.x, GamePiece{ '*' }));
	
	DropPiece(position,Board);


	return 0;
}


void GameBoard(std::vector<std::vector<GamePiece>> Boardlayout)
{
	if (turn % 2 == 0) {
		player._playerSymbol = 'x';
	}
	else
	{
		player._playerSymbol = 'o';
	}
	
	system("cls");
	std::cout << player._playerSymbol;
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
			std::cout << "(" << player._playerSymbol << ")";
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

void DropPiece(int &position, std::vector<std::vector<GamePiece>> TempBoard)
{

	system("cls");
	
	while (true)
	{

		GameBoard(TempBoard);


		char b = _getch();

		switch (b)
		{
			//Player goes left
		case 'a': case 'A':

			position += -1;

			if (position < 0)
			{
				position = TempBoard.size();
			}

			break;
			//Player goes right
		case 'd': case 'D':
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

void animDrop(int, std::vector<std::vector<GamePiece>>& animboard)
{
	
	
	for (int row = animboard.size() - 1; row >= 0; row--)
	{
		if (animboard[row][position].tileSymbol == 'x' || animboard[row][position].tileSymbol == 'o')
		{
			row++;
			animboard[row][position].tileSymbol = player._playerSymbol;

			break;
		}
		if (animboard[row][position].tileSymbol == '*')
		{

			animboard[row][position].tileSymbol = player._playerSymbol;


		}
		if (row >= 0) {
			animboard[row][position].tileSymbol = player._playerSymbol;


			rows.y = row;
			columns.x = position;
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
	
	
	
}

bool winChecker(std::vector<std::vector<GamePiece>>& animboardChecker)
{
	
	

	//handle side to side
		for (int rows = animboardChecker.size() - 1; rows >= 0; rows--)
		{
			for (int columns = 0; columns < animboardChecker[0].size(); columns++)
			{
				
					

					if (animboardChecker[rows][columns].tileSymbol == player._playerSymbol)
					{
						count++;
						std::cout << count;
						system("pause");

						if (animboardChecker[rows][columns].tileSymbol != player._playerSymbol) {

							break;
						}
							 if (count > 3)
							{
								std::cout << "reeeeeeeeeeeeeeeeeee";
								system("pause");
								return false;
					
							}

					

						 if (rows < 0 || rows >= animboardChecker.size()) {
							// handle edge in x direction
							break;
						}
					
					
					
					}
					
			}
			count = 0;
			 
		}
	

		//handle up
	//	for (int columns = 0; columns < animboardChecker[0].size(); columns++)
	//	{
	//		for (int rows = animboardChecker.size() - 1; rows >= 0; rows--)
	//		{
	//		


	//				if (animboardChecker[rows][columns].tileSymbol == player._playerSymbol)
	//				{
	//					count++;

	//					if (count > 2)
	//					{
	//						std::cout << "upppppp";
	//						return false;

	//					}
	//					
	//					}
	//					if (columns < 0 || columns >= animboardChecker[0].size()) {
	//						// handle edge in y direction
	//						break;
	//					}


	//				}
	//			}

	//		
	//
	//std::cout << std::endl;
	



}



