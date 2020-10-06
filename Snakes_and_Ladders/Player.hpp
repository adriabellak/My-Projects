
#include<iostream>
#include "Dice.hpp"
using namespace std;


class Player
{
    private:
    int playerNum;
    int tile;

    public:
    Player();
    Player(int _num, int _tile);
    int getPlayerNum();
    int getTile();
    void setTile(int _newTile);
    void play();
};

Player::Player(int _num, int _tile)
{
    playerNum = _num;
    tile = _tile;
}

int Player::getPlayerNum()
{
    return playerNum;
}

int Player::getTile()
{
    return tile;
}

// que distinga entre N, S y L
void Player::setTile(int _newTile)
{
    tile = _newTile;
}
