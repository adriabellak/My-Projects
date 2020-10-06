/*
Class for an AIRPORT

Name: Adriana Abella Kuri 
Student ID: A01329591
Date: December 2nd 2019
*/

#include <iostream>
#include <string>
#include <vector>
#include "Airline.hpp"

using namespace std;

class Airport
{
private:
    // Attributes
    string name;
    int numAirlines;
    vector<Airline> airlines;
    // Initializing vectors with the possible destinations and the airline names
    vector<string> names = {"Air Canada", "Air France", "Alitalia", "British Airways", "Iberia", "AeroMexico", "KLM", "Lufthansa", "United Airlines", "Air Europa"};
    vector<string> destinations = {"Paris", "New York", "Zurich", "Berlin", "Madrid", "Barcelona", "Chicago", "Dublin", "London", "Milan", "Rome", "Munich", "Vancouver", "Toronto", "Amsterdam", "Houston", "Los Angeles", "Basel", "Tokyo", "Dallas"};

public:
    // Constructor
    Airport(string _name);
    // Method to create an airline
    void addAirline(Airline newAirline);
    // Methods to display information
    void displayAirlines();
    void displayAirlinesAndFlights();
    void displayFlightsByDestination();
    void displayFlightsOfAirline();
    void displayDestinations();
    // Method to display the menu to access the other methods
    void menuAirport();
    // Method to sell a ticket
    void sellTicket();
    // Methods to validate inputs
    bool validateDestination(string _destination);
    bool validateAirline(string _airline);
};

Airport::Airport(string _name)
{
    name = _name;
    numAirlines = 10;
    for (int i=0; i<10; i++)
    {
        addAirline(Airline(names[i], i));
    }
}

// Method that displays a list of all the possible destinations
void Airport::displayDestinations()
{
    cout << "Possible destinations:" << endl;
    cout << endl;
    for (int i=0; i<20; i++)
    {
        cout << destinations[i] << endl;
    }
}

// Method that sells a ticket given an airline index and a flight number
void Airport::sellTicket()
{
    int _index;
    cout << "Enter an airline index: ";
    cin >> _index;
    // This while loop validates the index to make sure it exists
    while (_index < 0 || _index >= 10)
    {
        cout << "Invalid index, please enter another one: ";
        cin >> _index;
    }
    airlines[_index].sellSeat();
}

// This method makes sure there is enough space for the new airlines generated
void Airport::addAirline(Airline newAirline)
{
    airlines.push_back(newAirline);
}

// This method displays the information of the airlines (their index and the number of flights they have)
void Airport::displayAirlines()
{
    for (int i=0; i<airlines.size(); i++)
    {
        airlines[i].displayAirlineInfo();
        cout << endl;
    }
}

// This method makes sure a string exists within the vector destinations
bool Airport::validateDestination(string _destination)
{
    bool result = false;
    for (int i=0; i<20; i++)
    {
        if (_destination == destinations[i])
        {
            result = true;
        }
    }
    return result;
}

// This method makes sure a string exists within the vector names
bool Airport::validateAirline(string _airline)
{
    bool result = false;
    for (int i=0; i<10; i++)
    {
        if (_airline == names[i])
        {
            result = true;
        }
    }
    return result;
}

// This method displays the information of all flights of all airlines
void Airport::displayAirlinesAndFlights()
{
    for (int i=0; i<airlines.size(); i++)
    {
        airlines[i].displayFlights();
    }
}

// This method displays every flight with a certain destination chosen by the user
void Airport::displayFlightsByDestination()
{
    string _destination;
    cout << "---" << endl;
    displayDestinations();
    cout << endl;
    cout << "Enter the destination: ";
    cin >> _destination;
    if (validateDestination(_destination)==false)
    {
        while (validateDestination(_destination) == false)
        {
            cout << "Invalid destination, please enter another one: ";
            cin >> _destination;
        }
    }
    for (int i=0; i<airlines.size(); i++)
    {
        airlines[i].displaySameDestinationFlights(_destination);
    }
    cout << "---" << endl;
}

// This method displays the information of all the flights of a single airline chosen by the user
void Airport::displayFlightsOfAirline()
{
    int _index;
    cout << "---" << endl;
    displayAirlines();
    cout << "---" << endl;
    cout << "Enter an airline index: ";
    cin >> _index;
    while (_index < 0 || _index >= 10)
    {
        cout << "Invalid index, please enter another one: ";
        cin >> _index;
    }
    cout << endl;
    airlines[_index].displayFlights();
}

// This method helps the user access the other methods by displaying a menu containing all the choices possible
void Airport::menuAirport()
{
    int choice;
    bool loop = true;
    
    while (loop)
    {
        cout << "Search options:" << endl;
        cout << "1. Search by airline" << endl;
        cout << "2. Search by destination" << endl;
        cout << "3. Display all airlines information" << endl;
        cout << "4. Display all flights information" << endl;
        cout << "5. Buy a ticket" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1)
        {
            displayFlightsOfAirline();
        }
        else if (choice == 2)
        {
            displayFlightsByDestination();
        }
        else if (choice == 3)
        {
            displayAirlines();
        }
        else if (choice == 4)
        {
            displayAirlinesAndFlights();
        }
        else if (choice == 5)
        {
            sellTicket();
        }
        else if (choice == 6)
        {
            loop = false;
        }
        else
        {
            cout << "Invalid option, please select another one. " << endl;
        }
    }
}