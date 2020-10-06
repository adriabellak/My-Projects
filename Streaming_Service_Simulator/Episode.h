#include<iostream>
#include<string>
#include"RateableVideo.h"
using namespace std;

#pragma once
class Episode : public RateableVideo
{
    protected:
    int season;

    public:
    // Constructors
    Episode()=default;
    Episode(string _name, int _minutes, int _season);
    // Setters
    void setSeason(int);
    // Getters
    int getSeason();
    // Others
    void printInfo();
    void printRating();
};