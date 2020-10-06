#include <iostream>
#include <string>
#include <vector>
#include "Series.h"
using namespace std;

// Constructors

Series::Series(string _name, string _genre) : RateableVideo(_name, _genre), numEpisodes(0), numSeasons(0)
{
}

// Setters

void Series::setNumEpisodes(int _num)
{
    numEpisodes = _num;
}

void Series::setNumSeasons(int _num)
{
    numSeasons = _num;
}

// Getters

int Series::getNumEpisodes()
{
    return numEpisodes;
}

int Series::getNumSeasons()
{
    return numSeasons;
}

float Series::getRating()
{
    updateRating();
    return rating;
}

// Others

void Series::addEpisode(Episode *_epi)
{
    if (_epi->getSeason() > getNumSeasons())
    {
        setNumSeasons(_epi->getSeason());
    }
    _epi->setGenre(getGenre());
    episodes.push_back(_epi);
    setNumEpisodes(getNumEpisodes() + 1);
    setMinutes(getMinutes() + _epi->getMinutes());
    updateRating();
}

void Series::printInfo()
{
    cout << endl;
    cout << "Series: ";
    cout << getName() << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Seasons: " << getNumSeasons() << endl;
    cout << "Episodes: " << getNumEpisodes() << endl;
    cout << "Minutes: " << getMinutes() << endl;
    cout << "Rating: ";
    printRating();
}

void Series::printSeason(int _season)
{
    if (getNumSeasons() == 0)
    {
        cout << endl;
        cout << "No seasons to show." << endl;
    }
    else if (_season > getNumSeasons() || _season < 1)
    {
        cout << endl;
        cout << "The series " << getName() << " doesn't have a season " << _season << "." << endl;
    }
    else
    {
        int eps = 0;
        cout << endl;
        cout << getName() << ", Season " << _season << endl;
        for (int i = 0; i < getNumEpisodes(); i++)
        {
            if (episodes[i]->getSeason() == _season)
            {
                episodes[i]->printInfo();
                eps++;
            }
        }
        if (eps == 0)
        {
            cout << "This season doesn't have any episodes yet." << endl;
        }
    }
}

void Series::printEpisodes()
{
    for (int i = 1; i <= getNumSeasons(); i++)
    {
        printSeason(i);
    }
}

void Series::updateRating()
{
    if (getNumEpisodes()>0)
    {
        float s = getRatingsSum();
        float n = getNumRatings();
        for (int i = 0; i < getNumEpisodes(); i++)
        {
            s += episodes[i]->getRatingsSum();
            n += episodes[i]->getNumRatings();
        }
        setRatingsSum(s);
        setNumRatings(n);
        setRating(s / n);
    }
}

void Series::printRating()
{
    if (getNumRatings() == 0)
    {
        cout << "This series hasn't been rated yet." << endl;
    }
    else
    {
        cout << getRating() << endl;
    }
}