// clase y métodos de un dado

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>

using namespace std;

class Dice
{
    private:
    int numFaces;
    int outcome;

    public:
    Dice();
    Dice(int _numFaces);
    int roll();
};

Dice::Dice(int _numFaces)
{
    numFaces = _numFaces;
}

int Dice::roll()
{
    outcome = rand()%numFaces+1;
    return outcome;
}