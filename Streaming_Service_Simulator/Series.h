#include <iostream>
#include <string>
#include <vector>
#include "Episode.h"
using namespace std;

#pragma once
class Series : public RateableVideo
{
protected:
    int numEpisodes;
    int numSeasons;
    vector<Episode *> episodes;

public:
    // Constructors
    Series() = default;
    Series(string _name, string _genre);
    // Setters
    void setNumEpisodes(int);
    void setNumSeasons(int);
    // Getters
    int getNumEpisodes();
    int getNumSeasons();
    float getRating();
    // Others
    void addEpisode(Episode *);
    void printInfo();
    void printSeason(int);
    void printEpisodes();
    void updateRating();
    void printRating();
};