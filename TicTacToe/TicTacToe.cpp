// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
using namespace tictactoe;
int main()
{
    std::cout << "Welcome to TicTacToe!\n";
	Game *theGame=new Game;
	theGame->setup();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
