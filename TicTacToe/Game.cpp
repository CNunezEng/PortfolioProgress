#include "Game.h"
namespace tictactoe
{
	void Game::setup()
	{
		mBoard = new Board();

		//retrieve player 1 icon
		std::cout << "Player 1 enter your Icon" << std::endl;
		char player1;
		std::cin >> player1;

		//retrive player 2 icon
		std::cout << "Player 2 enter your Icon" << std::endl;
		char player2;
		std::cin >> player2;
		
		mBoard->addPlayers(player1, player2);
		run();
	}

	void Game::run()
	{
		status currentStatus = mBoard->getStat();
		int x = 0;
		int y = 0;
		int player = 1;

		while (currentStatus!=status::winPlayer1 &&
			currentStatus != status::winPlayer2 &&
			currentStatus != status::CatsGame)
		{
			mBoard->printBoard();

			std::cout << "Player " << player << " your turn." << std::endl;
			std::cout << "Enter the row the column you would like to play in (a number between 1 and 3)" << std::endl;
			
			std::cin >> x;
			std::cin >> y;
			currentStatus = mBoard->changeChar(x-1, y-1, player);

			if (currentStatus != status::Replay)
			{
				if (player == 1)
				{
					player = 2;
				}
				else
				{
					player = 1;
				}
			}
		}
		end();
	}

	void Game::end()
	{
		
		char response = ' ';
		while (response != 'Y' && response != 'N')
		{
			std::cout << "Would you like to play again?(Y/N)";
			std::cin >> response;

			if (response == 'Y')
			{
				setup();
			}
			else if (response != 'N')
			{
				std::cout << "Response not recognized";
			}
		}

		std::cout << "Goodbye!";
	}
}