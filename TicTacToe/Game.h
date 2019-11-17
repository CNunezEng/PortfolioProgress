#pragma once
#include "Board.h"

namespace tictactoe
{
	/**
	* Runs a tictactoe game for two players in cmd or bash
	**/
	class Game
	{
	public:
		Game() { mBoard = NULL; };
		virtual ~Game() {};

		/**
		* asks each player for thier icon and sets up the board
		**/
		void setup();

		/**
		* Main loop. this function asks for the players move and updates the board 
		* exits at status != running
		**/
		void run();

		/**
		* asks user if they want to replay
		**/
		void end();

	private:
		Board* mBoard;
	};

}

