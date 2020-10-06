#include<iostream>
using namespace std;

#pragma once
class Rateable
{
    protected:
    int max = 10;
    int min = 0;
    float rating;
    float ratingsSum;
    int numRatings;

    public:
    // Constructor
    Rateable();
    // Setters
    void setRating(float);
    void setRatingsSum(float);
    void setNumRatings(int);
    // Getters
    virtual float getRating();
    virtual float getRatingsSum();
    virtual int getNumRatings();
    // Others
    void rate(float);
};