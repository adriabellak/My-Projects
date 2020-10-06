#include<iostream>
#include<string>
#include"RateableVideo.h"
using namespace std;

#pragma once
class Movie : public RateableVideo
{
    protected:
    int year;

    public:
    // Constructors
    Movie()=default;
    Movie(string _name, string _genre, int _minutes, int _year);
    // Setters
    void setYear(int);
    // Getters
    int getYear();
    // Others
    void printInfo();
    void printRating();
};