#include<iostream>
#include<string>
#include"RateableVideo.h"
using namespace std;

// Constructors

RateableVideo::RateableVideo(string _name, string _genre, int _minutes) : Video(_name, _genre, _minutes)
{

}

RateableVideo::RateableVideo(string _name, int _minutes) : Video(_name, _minutes)
{

}

RateableVideo::RateableVideo(string _name, string _genre) : Video(_name, _genre)
{

}
