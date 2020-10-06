#include "StreamingService.h"

StreamingService::StreamingService() : newestYear(0)
{
}

int StreamingService::getNewestYear()
{
    return newestYear;
}

void StreamingService::setNewestYear(int _year)
{
    newestYear = _year;
}

void StreamingService::addSeries(Series *_series)
{
    series.push_back(_series);
}

void StreamingService::addMovie(Movie *_movie)
{
    movies.push_back(_movie);
    if (_movie->getYear() > getNewestYear())
    {
        setNewestYear(_movie->getYear());
    }
}

void StreamingService::printMovies()
{
    cout << "\nAll movies:\n-------------\n";
    for (int i = 0; i < movies.size(); i++)
    {
        cout << movies[i]->getName() << endl;
    }
    cout << "-------------\n";
}

void StreamingService::printSeries()
{
    cout << "\nAll series:\n-------------\n";
    for (int i = 0; i < series.size(); i++)
    {
        cout << series[i]->getName() << endl;
    }
    cout << "-------------\n";
}

void StreamingService::printAll()
{
    printMovies();
    printSeries();
}

void StreamingService::printMoviesByYear()
{
    cout << "\nMovies (year)\n-------------\n";
    for (int j = 1850; j <= newestYear; j++)
    {
        for (int i = 0; i < movies.size(); i++)
        {
            if (movies[i]->getYear() == j)
            {
                cout << movies[i]->getName() << " (" << movies[i]->getYear() << ")" << endl;
            }
        }
    }
    cout << "-------------\n";
}

void StreamingService::printMoviesWithRating()
{
    cout << "\nMovies (rating)\n-------------\n";
    for (int i = 0; i < movies.size(); i++)
    {
        cout << movies[i]->getName() << ": ";
        movies[i]->printRating();
    }
    cout << "-------------\n";
}

void StreamingService::printSeriesWithRating()
{
    cout << "\nSeries (rating)\n-------------\n";
    for (int i = 0; i < series.size(); i++)
    {
        cout << series[i]->getName() << ": ";
        series[i]->printRating();
    }
    cout << "-------------\n";
}

void StreamingService::printAllWithRating()
{
    printMoviesWithRating();
    printSeriesWithRating();
}