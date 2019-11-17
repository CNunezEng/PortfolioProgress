#include "Board.h"
namespace tictactoe
{
	void Board::addPlayers(char player1, char player2)
	{
		mPlayer1 = player1;
		mPlayer2 = player2;
		mStatus = status::Running;
	}

	void Board::printBoard()
	{
		std::cout << std::endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cout << mBoard[i][j];

				if (j < 2)
				{
					std::cout << '|';
				}
			}
			if (i < 2)
			{
				std::cout << std::endl << "-----" << std::endl;
			}
		}
		std::cout << std::endl;
	}

	status Board::changeChar(int x, int y, int player)
	{
		if (x >= 0 && x <= 2 &&  y <= 2 && y >= 0)
		{
			mStatus = status::Running;
			if ((mBoard[x][y] != mPlayer1) && (mBoard[x][y] != mPlayer2))
			{
				if (player==2)
				{
					mBoard[x][y] = mPlayer2;

					isWin(mPlayer2);
				}
				else
				{
					mBoard[x][y] = mPlayer1;
					isWin(mPlayer1);
				}
				std::cout << "Play successful " << std::endl;
			}
		}
		else
		{
			std::cout << "Value out of bounds 0 < x,y < 2" << std::endl;
			mStatus = Replay;
		}

		std::cout << std::endl << "The game status is ";

		switch (mStatus)
		{
		case status::Replay:
			std::cout << "Replay";
			break;
		case status::Running:
			std::cout << "Running";
			break;
		case status::Setup:
			std::cout << "Setup";
			break;
		case status::winPlayer1:
			std::cout << "Player 1 Win";
			break;
		case status::winPlayer2:
			std::cout << "Player 2 Win";
			break;
		case status::CatsGame:
			std::cout << "CatsGame";
			break;
		}
		std::cout << std::endl;
		return mStatus;
	}

	void Board::isWin(char player)
	{
		bool win = false;
		bool checkDiag = true;
		bool zeros = false;
		for (int i = 0; i < 3; i++)
		{
			if ((mBoard[0][i] != mPlayer1) &&
				(mBoard[0][i] != mPlayer2))
			{
				zeros = true;
			}
			if (mBoard[0][i] == player)
			{
				for (int j = 1; j < 3; j++)
				{
					if ((mBoard[i][j] != mPlayer1) &&
						(mBoard[i][j] != mPlayer2))
					{
						zeros = true;
					}
					if (mBoard[j][i] != player)
					{
						break;
					}
					else if (j == 2)
					{
						win = true;
					}
				}
			}
			
			if (mBoard[i][0] == player)
			{
				for (int j = 1; j < 3; j++)
				{
					if (mBoard[i][j] != player)
					{
						break;
					}
					else if (j == 2)
					{
						win = true;
					}
				}
			}

			if (mBoard[i][i] == player && checkDiag)
			{
				if (i == 2)
				{
					win = true;
				}
			}
			else
			{
				checkDiag = false;
			}
		}

		if (mBoard[1][1] == player &&
			mBoard[2][0] == player &&
			mBoard[0][2] == player)
		{
			win = true;
		}

		if (win == true)
		{
			if (player == mPlayer1)
			{
				mStatus = status::winPlayer1;
			}
			else
			{
				mStatus = status::winPlayer2;
			}
		}
		else if (zeros == false)
		{
			mStatus = status::CatsGame;
		}
	}
}