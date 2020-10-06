#include<iostream>
#include<string>
#include"Video.h"
using namespace std;

// Constructors

Video::Video(string _name, string _genre, int _minutes)
{
    name = _name;
    genre = _genre;
    minutes = _minutes;
}

Video::Video(string _name, int _minutes)
{
    name = _name;
    minutes = _minutes;
}

Video::Video(string _name, string _genre)
{
    name = _name;
    genre = _genre;
    minutes = 0;
}

// Setters

void Video::setName(string _name)
{
    name = _name;
}

void Video::setGenre(string _genre)
{
    genre = _genre;
}

void Video::setMinutes(int _minutes)
{
    minutes = _minutes;
}

// Getters

string Video::getName()
{
    return name;
}

string Video::getGenre()
{
    return genre;
}

int Video::getMinutes()
{
    return minutes;
}

// Others