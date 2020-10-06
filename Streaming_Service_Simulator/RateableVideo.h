#include<iostream>
#include"Video.h"
#include"Rateable.h"
using namespace std;

#pragma once
class RateableVideo : public Video, public Rateable
{
    public:
    // Constructors
    RateableVideo()=default;
    RateableVideo(string _name, string _genre, int _minutes);
    RateableVideo(string _name, int _minutes);
    RateableVideo(string _name, string _genre);
    virtual void printRating() = 0;
};