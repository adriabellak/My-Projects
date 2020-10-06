#include<iostream>
#include<string>
using namespace std;

#pragma once
class Video
{
    protected:
    string name;
    string genre;
    int minutes;

    public:
    // Constructors
    Video()=default;
    Video(string _name, string _genre, int _minutes);
    Video(string _name, int _minutes);
    Video(string _name, string _genre);
    // Setters
    void setName(string);
    void setGenre(string);
    void setMinutes(int);
    // Getters
    string getName();
    string getGenre();
    int getMinutes();
    // Others
    virtual void printInfo() = 0;
};