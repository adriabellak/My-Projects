#include <iostream>
#include "Series.h"
#include "Movie.h"
#include <vector>
using namespace std;

#pragma once
class StreamingService
{
private:
    vector<Series *> series;
    vector<Movie *> movies;
    int newestYear;

public:
    StreamingService();
    int getNewestYear();
    void setNewestYear(int);
    void addSeries(Series *);
    void addMovie(Movie *);
    void printMovies();
    void printSeries();
    void printAll();
    void printMoviesByYear();
    void printMoviesWithRating();
    void printSeriesWithRating();
    void printAllWithRating();
};
