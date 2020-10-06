#include<iostream>
#include<string>
#include"Movie.h"
using namespace std;

// Constructors

Movie::Movie(string _name, string _genre, int _minutes, int _year) : RateableVideo(_name, _genre, _minutes), year(_year)
{

}

// Setters

void Movie::setYear(int _year)
{
    year = _year;
}

// Getters

int Movie::getYear()
{
    return year;
}

// Others

void Movie::printInfo()
{
    cout << endl;
    cout << "Movie: ";
    cout << getName() << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Minutes: " << getMinutes() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Rating: ";
    printRating();
}

void Movie::printRating()
{
    if (getNumRatings() == 0)
    {
        cout << "This movie hasn't been rated yet." << endl;
    }
    else
    {
        cout << getRating() << endl;
    }
}