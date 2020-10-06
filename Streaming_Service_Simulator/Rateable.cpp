#include<iostream>
#include"Rateable.h"
using namespace std;

// Constructors

Rateable::Rateable()
{
    rating = 0;
    ratingsSum = 0;
    numRatings = 0;
}

// Setters

void Rateable::setRating(float _rating)
{
    rating = _rating;
}

void Rateable::setRatingsSum(float _sum)
{
    ratingsSum = _sum;
}

void Rateable::setNumRatings(int _num)
{
    numRatings = _num;
}

// Getters

float Rateable::getRating()
{
    return rating;
}

float Rateable::getRatingsSum()
{
    return ratingsSum;
}

int Rateable::getNumRatings()
{
    return numRatings;
}

// Others

void Rateable::rate(float _new)
{
    if (_new > max)
    {
        _new = 10;
    }
    if (_new < min)
    {
        _new = 0;
    }
    setRatingsSum(getRatingsSum() + _new);
    setNumRatings(getNumRatings() + 1);
    setRating(getRatingsSum()/getNumRatings());
}