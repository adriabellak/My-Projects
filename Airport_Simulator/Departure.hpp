/*
Class for a departure

Name: Adriana Abella Kuri 
Student ID: A01329591
Date: December 2nd 2019
*/

#include <iostream>
#include <string>

using namespace std;

class Departure
{
private:
    // Attributes
    int flightNumber;
    string destination;
    int time;
    int min;
    int capacity;
    int seatsTaken;
    int seatsLeft;
    bool soldOut;
public:
    // Constructor
    Departure(int _flightNumber, string _destination, int _time, int _min, int _capacity, int _seatsTaken, int _seatsLeft, bool _soldOut);
    // Getters
    int getFlightNumber();
    string getDestination();
    int getTime();
    int getMin();
    int getCapacity();
    int getSeatsTaken();
    int getSeatsLeft();
    bool isSoldOut();
    // Methods to modify the attributes
    void takeSeat();
    void setSoldOutTrue();
    // Method to display the information of a departure
    void display();
};

Departure::Departure(int _flightNumber, string _destination, int _time, int _min, int _capacity, int _seatsTaken, int _seatsLeft, bool _soldOut)
{
    flightNumber = _flightNumber;
    destination = _destination;
    time = _time;
    min = _min;
    capacity = _capacity;
    seatsTaken = _seatsTaken;
    seatsLeft = _seatsLeft;
    soldOut = _soldOut;
}

int Departure::getFlightNumber()
{
    return flightNumber;
}

string Departure::getDestination()
{
    return destination;
}

int Departure::getTime()
{
    return time;
}

int Departure::getMin()
{
    return min;
}

int Departure::getCapacity()
{
    return capacity;
}

int Departure::getSeatsTaken()
{
    return seatsTaken;
}

int Departure::getSeatsLeft()
{
    return seatsLeft;
}

bool Departure::isSoldOut()
{
    return soldOut;
}

void Departure::setSoldOutTrue()
{
    soldOut = true;
}

void Departure::takeSeat()
{
    seatsLeft--; // Reduces seatsLeft by 1
    seatsTaken++; // Increases seatsTaken by 1
    if (seatsTaken == capacity) // Sets soldOut to true if the seats taken are the same as the capacity
    {
        setSoldOutTrue();
    }
}

void Departure::display()
{
    cout << "Flight Number: " << getFlightNumber() << endl;
    cout << "Destination: " << getDestination() << endl;
    cout << "Time: " << getTime() << ":" << getMin() << endl;
    cout << "Capacity: " << getCapacity() << endl;
    cout << "Seats Taken: " << getSeatsTaken() << endl;
    cout << "Seats Left: " << getSeatsLeft() << endl;
    if (isSoldOut()==true)
    {
        cout << "--SOLD OUT--" << endl;
    }
    cout << endl;
}