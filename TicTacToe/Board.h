#pragma once
#include <iostream>
namespace tictactoe
{
	enum class status { winPlayer1, winPlayer2, Running, Setup, Replay, CatsGame };


	/**
	*
	* @class Board This class keeps track of the game board for tictactoe
	*
	**/
	class Board
	{
	public:
		Board() : mPlayer1(' '),
			mPlayer2(' '),
			mStatus(status::Setup),
			mBoard() {};
		virtual ~Board() {};
		status getStat() { return mStatus; };

		void addPlayers(char player1, char player2);

		/**
		* print board will print a tictactoe game board populated with the charectors in mBoard
		*/
		void printBoard();

		/**
		* Change char will check if a spot at x,y is occupied
		* and place a player charector in that spot then calls isWin
		**/
		status changeChar(int x, int y, int player);

		/**
		* Is Win wiil check if there has been a win or loss in the game and will update mStatus
		**/
		void isWin(char player);

	private:

		// the array of played moves
		char mBoard[3][3];

		// the status of the game
		status mStatus;

		char mPlayer1;
		char mPlayer2;
	};
}//end namespace
