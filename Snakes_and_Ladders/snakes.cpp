// Tarea 1: Programación Orientada a Objetos

#include<iostream>
#include <string>
#include <vector>
#include <random>
#include "Player.hpp"

using namespace std;

#pragma once

// g++ -std=c++11 snakes.cpp -o snakes
// ./snakes

class MyGame
{
    private:
    Dice* dice;
    int maxTurns = 50;
    int numTiles = 30;
    vector<string> tiles;
    vector<Player> players;

    public:
    MyGame();
    void start();
    void end(int _turns);
    void generateBoard();
    ~MyGame();

};

MyGame::~MyGame()
{
    delete dice;
}

MyGame::MyGame()
{
    Player player1(1, 1);
    Player player2(2, 1);
    players.push_back(player1);
    players.push_back(player2);
}


void MyGame::end(int _turns)
{
    cout << "Game over." << endl;
    // if para cada caso: ganador, limite de turnos, o tecla E
    if (players[0].getTile() == numTiles)
    {
        cout << "Player 1 is the winner!" << endl;
    }
    else if (players[1].getTile() == numTiles)
    {
        cout << "Player 2 is the winner!" << endl;
    }
    else if (_turns == maxTurns+1)
    {
        cout << "The maximum number of turns has been reached." << endl;
    }
    else
    {
        cout << "Thanks for playing!" << endl;
    }
}

// hacer que sea un tablero aleatorio diferente en cada partida
void MyGame::generateBoard()
{
    for (int i=0; i<numTiles; i++)
    {
        if (i >= 3 && i < 6)
        {
            tiles.push_back("S");
        }
        else if (i >= 6 && i < 9)
        {
            tiles.push_back("L");
        }
        else
        {
            tiles.push_back("N");
        }
    }
    random_shuffle(tiles.begin()+3, tiles.end()-1);
}

void MyGame::start()
{
    generateBoard();
    srand(time(0));
    Dice dice(6);
    cout << "Press C to continue, or E to end the game:" << endl;
    bool loop = true;
    string choice;
    const string c = "C";
    const string e = "E";
    int player = 1;
    int turn = 1;
    while (loop == true && turn <= maxTurns)
    {
        cin >> choice;
        if (choice == c)
        {
            int roll = dice.roll();
            int oldTile = players[player-1].getTile();
            int newTile = players[player-1].getTile()+roll;
            string tileType = tiles[newTile-1];
            if (tileType == "S")
            {
                newTile = newTile - 3;
            }
            else if (tileType == "L")
            {
                newTile = newTile + 3;
            }
            if (newTile >= numTiles)
            {
                newTile = numTiles;
                tileType = tiles[newTile-1];
                loop = false;
            }
            players[player-1].setTile(newTile);

            // displaying turn info
            cout << turn << " " << player << " " << oldTile << " " << roll << " " << tileType << " " << newTile <<endl;
            //changing player for next turn
            if (player == 1)
            {
                player = 2;
            }
            else if (player == 2)
            {
                player = 1;
            }
            // increasing turns
            turn++;
        }
        else if (choice == e)
        {
            loop = false;
        }
        else
        {
            cout << "Invalid option, please press C to continue or E to end the game." << endl;
        }
        
    }

    end(turn);

}

int main()
{
    MyGame* g = new MyGame();
    g->start();
    delete g;
    return 0;
}