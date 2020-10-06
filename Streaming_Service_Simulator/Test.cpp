#include <iostream>
#include <string>
#include "StreamingService.h"
using namespace std;

// g++ -std=c++11 *.cpp
// ./a.out

int main()
{
    StreamingService nf;

    // Creación y calificación de películas

    Movie others("The Others", "Thriller", 104, 2001);
    others.rate(9.6);
    others.rate(7.8);
    nf.addMovie(&others);

    Movie fightclub("Fight Club", "Thriller", 151, 1999);
    fightclub.rate(8);
    fightclub.rate(9.5);
    fightclub.rate(9.2);
    nf.addMovie(&fightclub);

    Movie notebook("The Notebook", "Drama", 123, 2004);
    notebook.rate(8.2);
    notebook.rate(9.4);
    notebook.rate(9.1);
    nf.addMovie(&notebook);

    Movie chihiro("Spirited Away", "Fantasy", 125, 2001);
    chihiro.rate(8.5);
    chihiro.rate(9);
    chihiro.rate(9.3);
    nf.addMovie(&chihiro);
    chihiro.printInfo();

    Movie basterds("Inglourious Basterds", "Drama", 153, 2009);
    basterds.rate(8.9);
    basterds.rate(10);
    basterds.rate(9);
    nf.addMovie(&basterds);

    Movie psycho("Psycho", "Horror", 109, 1960);
    psycho.rate(8.7);
    psycho.rate(9.6);
    psycho.rate(9.5);
    nf.addMovie(&psycho);

    Movie jojo("Jojo Rabbit", "Drama", 108, 2019);
    jojo.rate(9.7);
    jojo.rate(9);
    nf.addMovie(&jojo);

    Movie coraline("Coraline", "Fantasy", 100, 2009);
    coraline.rate(8);
    coraline.rate(8.6);
    nf.addMovie(&coraline);

    Movie orfanato("El Orfanato", "Horror", 100, 2007);
    orfanato.rate(8.8);
    orfanato.rate(8.7);
    nf.addMovie(&orfanato);

    Movie warrior("Warrior", "Drama", 140, 2011);
    warrior.rate(8.8);
    warrior.rate(8.7);
    nf.addMovie(&warrior);

    Movie alice("Alice in Wonderland", "Fantasy", 75, 1951);
    alice.rate(8.8);
    alice.rate(8.7);
    nf.addMovie(&alice);

    Movie tarzan("Tarzan", "Adventure", 88, 1999);
    tarzan.rate(8.8);
    tarzan.rate(8.7);
    nf.addMovie(&tarzan);

    Movie shawshank("Shawshank Redemption", "Drama", 142, 1994);
    shawshank.rate(8.8);
    shawshank.rate(8.7);
    nf.addMovie(&shawshank);

    Movie jack("The Nightmare Before Christmas", "Fantasy", 76, 1993);
    jack.rate(8.2);
    jack.rate(8.7);
    nf.addMovie(&jack);

    // Creación de series y episodios

    Series goodplace("The Good Place", "Comedy");
    nf.addSeries(&goodplace);

    Episode fine("Everything Is Fine", 42, 1);
    fine.rate(8.4);
    fine.rate(9.2);
    goodplace.addEpisode(&fine);

    Episode flying("Flying", 45, 1);
    flying.rate(8.7);
    flying.rate(9.1);
    goodplace.addEpisode(&flying);

    Episode cockroach("Team Cockroach", 41, 2);
    cockroach.rate(8.9);
    cockroach.rate(9.6);
    goodplace.addEpisode(&cockroach);

    Episode answer("The Answer", 48, 4);
    answer.rate(7.5);
    answer.rate(8.4);
    goodplace.addEpisode(&answer);

    Series fmab("Fullmetal Alchemist Brotherhood", "Anime");
    nf.addSeries(&fmab);

    Episode firstday("The First Day", 23, 1);
    firstday.rate(8);
    firstday.rate(9.8);
    fmab.addEpisode(&firstday);

    Episode fifthlab("The Fifth Laboratory", 23, 1);
    fifthlab.rate(8);
    fifthlab.rate(9.2);
    fmab.addEpisode(&fifthlab);

    Episode belly("Inside the Belly", 23, 2);
    belly.rate(8.9);
    belly.rate(9.5);
    fmab.addEpisode(&belly);

    Episode reunion("Reunion", 23, 2);
    reunion.rate(8.1);
    reunion.rate(9);
    fmab.addEpisode(&reunion);

    Episode ishval("The Ishval War of Extermination", 23, 3);
    ishval.rate(8.2);
    ishval.rate(9.6);
    fmab.addEpisode(&ishval);

    Episode fampor("Family Portrait", 23, 3);
    fampor.rate(8);
    fampor.rate(9.3);
    fmab.addEpisode(&fampor);

    Episode homun("The First Homunculus", 23, 3);
    homun.rate(8.5);
    homun.rate(9.4);
    fmab.addEpisode(&homun);

    Series blackm("Black Mirror", "Thriller");
    nf.addSeries(&blackm);

    Episode natanth("The National Anthem", 44, 1);
    blackm.addEpisode(&natanth);

    Episode fift("Fifteen Million Merits", 62, 1);
    blackm.addEpisode(&fift);

    Episode enthis("The Entire History of You", 49, 1);
    blackm.addEpisode(&enthis);

    Episode brb("Be Right Back", 48, 2);
    blackm.addEpisode(&brb);

    Episode whiteb("White Bear", 42, 2);
    blackm.addEpisode(&whiteb);

    Episode waldom("The Waldo Moment", 43, 2);
    blackm.addEpisode(&waldom);

    Episode wxmas("White Christmas", 73, 2);
    blackm.addEpisode(&wxmas);

    Episode vipers("Striking Vipers", 62, 5);
    blackm.addEpisode(&vipers);

    Episode smith("Smithereens", 70, 5);
    blackm.addEpisode(&smith);

    Episode ashley2("Rachel, Jack and Ashley Too", 67, 5);
    blackm.addEpisode(&ashley2);

    Series casapa("La Casa de Papel", "Action");
    nf.addSeries(&casapa);
    casapa.rate(8.5);

    Series himym("How I Met Your Mother", "Comedy");
    nf.addSeries(&himym);
    himym.rate(7.5);

    Series dark("Dark", "Mystery");
    nf.addSeries(&dark);

    Series granhotel("El Gran Hotel", "Romance");
    nf.addSeries(&granhotel);
    granhotel.rate(7.8);

    Series rickm("Rick and Morty", "Comedy");
    nf.addSeries(&rickm);
    rickm.rate(8.2);

    // Para imprimir todas las series y películas
    //nf.printAll();

    // Para imprimir todas las películas
    //nf.printMovies();

    // Para imprimir todas las películas con su calificación
    //nf.printMoviesWithRating();

    // Para imprimir todas las películas por año
    //nf.printMoviesByYear();

    // Para imprimir todas las series
    //nf.printSeries();

    // Para imprimir todas las series con su calificación
    //nf.printSeriesWithRating();

    // Para imprimir todas las películas y series con su calificación
    nf.printAllWithRating();

    // Para imprimir la información de una serie en específico
    //fmab.printInfo();

    // Para imprimir todos los episodios de una serie en específico
    //fmab.printEpisodes();

    // Para imprimir una temporada en específico de una serie en específico
    //fmab.printSeason(1);

    // Para imprimir la información de un capítulo en específico
    //firstday.printInfo();

    // Para imprimir la información de una película en específico
    //basterds.printInfo();

    cout << endl;
    return 0;
}