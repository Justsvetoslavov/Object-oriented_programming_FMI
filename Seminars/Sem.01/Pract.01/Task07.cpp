// Bozhidar, Group 1, practicum date 22.02.2023

// highest rating  => 5 (stars)
// lowest rating   => 1 (star)

#include <iostream>

const int NAME_MAX_CHARS = 31;

enum Genre
{
    Comedy,
    Action,
    Horror,
    Romantic
};

struct Movie
{
    char name[NAME_MAX_CHARS] = {'\0'};
    int duration = 0;
    int rating = 0;
    Genre genre;
};

void initName(Movie &movie, const char name[])
{
    for (int i = 0; i < NAME_MAX_CHARS; ++i)
    {
        movie.name[i] = name[i];
    }
}

Movie initMovie(const char name[], const int &duration, const int &rating, const Genre &genre)
{
    Movie newMovie;

    initName(newMovie, name);

    newMovie.duration = duration;
    newMovie.genre = genre;
    newMovie.rating = rating;

    return newMovie;
}

void printMovieList(Movie movieList[], int movieListSize)
{
    for (int i = 0; i < movieListSize; ++i)
    {
        std::cout << "Name: " << movieList[i].name << "\n"
                  << "Duration: " << movieList[i].duration << "\n"
                  << "Genre: ";

        switch (movieList[i].genre)
        {
        case Genre::Action:
        {
            std::cout << "Action";
            break;
        }
        case Genre::Comedy:
        {
            std::cout << "Comedy";
            break;
        }
        case Genre::Horror:
        {
            std::cout << "Horror";
            break;
        }
        case Genre::Romantic:
        {
            std::cout << "Romantic";
            break;
        }
        default:
        {
            std::cout << "No genre available";
            break;
        }
        }

        std::cout << std::endl;
        std::cout << "Rating: " << movieList[i].rating << "\n";

        std::cout << std::endl;
    }
}

Movie getTopMovie(Movie movieList[], int movieListSize)
{
    int currMaxRating = -1;
    int idxTopMovie = -1;

    for (int i = 0; i < movieListSize; ++i)
    {
        if (movieList[i].rating > currMaxRating)
        {
            currMaxRating = movieList[i].rating;
            idxTopMovie = i;
        }
    }

    return movieList[idxTopMovie];
}

void swap(Movie movieList[], const int &i, const int &j)
{
    Movie temp = movieList[i];
    movieList[i] = movieList[j];
    movieList[j] = temp;
}

void sortMoviesByRating(Movie movieList[], const int &movieListSize)
{
    int idxCurrTopMovie = 0;

    for (int i = 0; i < movieListSize - 1; ++i)
    {
        for (int j = i + 1; j < movieListSize; ++j)
        {
            if (movieList[i].rating < movieList[j].rating)
            {
                idxCurrTopMovie = j;
            }
        }
        swap(movieList, idxCurrTopMovie, i);
    }
}

int main()
{
    Movie movieList[4] = {
        {"title 1", 136, 3, Genre::Comedy},
        {"title 2", 120, 2, Genre::Horror},
        {"title 3", 98, 5, Genre::Action},
        {"title 4", 73, 1, Genre::Comedy}};

    Movie topMovie = initMovie("title 1", 136, 3, Genre::Comedy);

    topMovie = getTopMovie(movieList, 4);

    sortMoviesByRating(movieList, 4);

    printMovieList(movieList, 4);

    return 0;
}