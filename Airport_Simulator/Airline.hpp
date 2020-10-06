/*
Class for an airline

Name: Adriana Abella Kuri 
Student ID: A01329591
Date: December 2nd 2019
*/

#include <iostream>
#include <string>
#include <vector>
#include "Departure.hpp"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>

using namespace std;

class Airline
{
private:
    // Attributes
    string name;
    int index;
    int numDepartures;
    vector<Departure> departures;
    // Initialize a vector with the possible destinations
    vector<string> destinations = {"Paris", "New York", "Zurich", "Berlin", "Madrid", "Barcelona", "Chicago", "Dublin", "London", "Milan", "Rome", "Munich", "Vancouver", "Toronto", "Amsterdam", "Houston", "Los Angeles", "Basel", "Tokyo", "Dallas"};

public:
    // Constructor
    Airline(string _name, int _index);
    // Getters
    string getName();
    int getIndex();
    int getNumDepartures();
    // Method to create a new departure
    void addDeparture(Departure newDeparture);
    // Method to sell a seat that selects an airline and a flight number
    void sellSeat();
    // Methods to display information
    void displayFlights();
    void displayAirlineInfo();
    void displaySameDestinationFlights(string _destination);
};

Airline::Airline(string _name, int _index)
{
    // Creating an airline
    name = _name;
    index = _index;
    // Assigning it a random number of departures
    numDepartures = rand()%20+1;
    for (int i=0; i<numDepartures; i++)
    {
        // Inside this for loop we assign random characteristics to each departure within an airline
        int randIndex = rand()%20;
        string randomDestination = destinations[randIndex];
        int randomTime = rand()%23;
        int randomMin = rand()%59;
        int randomCapacity = rand()%21+20;
        int randomSeatsTaken = rand()%randomCapacity;
        int _seatsLeft = randomCapacity - randomSeatsTaken;
        addDeparture(Departure(i, randomDestination, randomTime, randomMin, randomCapacity, randomSeatsTaken, _seatsLeft, false));
    }
}

// This method makes sure there is enough space for the new departures generated
void Airline::addDeparture(Departure newDeparture)
{
    departures.push_back(newDeparture);
}

string Airline::getName()
{
    return name;
}

int Airline::getNumDepartures()
{
    return numDepartures;
}

int Airline::getIndex()
{
    return index;
}

void Airline::sellSeat()
{
    int _flightNumber;
    cout << "Enter flight number to buy a ticket: ";
    cin >> _flightNumber;
    // This while loop validates the received flight number to make sure it exists
    while (_flightNumber < 0 || _flightNumber >= getNumDepartures())
    {
        cout << "Invalid flight number, please enter another one: ";
        cin >> _flightNumber;
    }
    // If the flight is not sold out the purchase is permitted
    if (departures[_flightNumber].isSoldOut()==true)
    {
        cout << endl;
        cout << "Sorry, the flight number " << _flightNumber << " to " << departures[_flightNumber].getDestination() << " of the airline " << getName() << " is sold out." << endl;
        cout << endl;
    }
    // If the flight is sold out the purchase is denied
    else
    {
        departures[_flightNumber].takeSeat();
        cout << endl;
        cout << "Purchase successful! This is your flight information: " << endl;
        cout << endl;
        departures[_flightNumber].display();
    }
    
}

// This method displays every flight within an airline
void Airline::displayFlights()
{
    for (int i=0; i<departures.size(); i++)
    {
        cout << "Airline: " << getName() << endl;
        cout << "Airline index: " << getIndex() << endl;
        departures[i].display();
    }
}

// This method displays the departures that have the same destination within an airline
void Airline::displaySameDestinationFlights(string _destination)
{
    for (int i=0; i<departures.size(); i++)
    {
        if (departures[i].getDestination() == _destination)
        {
            cout << "Airline: " << getName() << endl;
            cout << "Airline index: " << getIndex() << endl;
            departures[i].display();
        }
    }
}

// This method allows the user to see how many flights each airline contains
void Airline::displayAirlineInfo()
{
    cout << getName() << endl;
    cout << "Index: " << getIndex() << endl;
    cout << "Number of flights: " << getNumDepartures() << endl;
}