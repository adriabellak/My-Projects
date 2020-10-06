/*
Testing project with Departure, Airline and Airport classes.

Name: Adriana Abella Kuri 
Student ID: A01329591
Date: December 2nd 2019
*/

// This file for testing the project creates an airport and displays its menu

#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>  
#include <cstdlib>
#include "Airport.hpp"

using namespace std;

int main()
{
    srand(time(0)); // This line makes it possible for the random numbers to be new every time the code is ran
    // Create the airport
    Airport airport("Aeropuerto Internacional Benito Juárez");
    // Call the airport menu for user interaction
    airport.menuAirport();

    return 0;
}