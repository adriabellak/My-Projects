#include<iostream>
#include<string>
#include"Episode.h"
using namespace std;

// Constructors

Episode::Episode(string _name, int _minutes, int _season) : RateableVideo(_name, _minutes), season(_season)
{

}

// Setters

void Episode::setSeason(int _season)
{
    season = _season;
}

// Getters

int Episode::getSeason()
{
    return season;
}

// Others

void Episode::printInfo()
{
    cout << endl;
    cout << "Episode: ";
    cout << getName() << endl;
    cout << "Season: " << getSeason() << endl;
    cout << "Minutes: " << getMinutes() << endl;
    cout << "Rating: ";
    printRating();
}

void Episode::printRating()
{
    if (getNumRatings() == 0)
    {
        cout << "This episode hasn't been rated yet." << endl;
    }
    else
    {
        cout << getRating() << endl;
    }
}