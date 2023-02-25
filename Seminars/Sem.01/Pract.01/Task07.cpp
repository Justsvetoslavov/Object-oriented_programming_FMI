#include <iostream>

enum class Genres {
    Comedy, 
    Action,
    Horror,
    Romantic
};

const int MAX_TITLE_LEN = 100;

struct Movie {
    char title[MAX_TITLE_LEN + 1];
    unsigned int lengthInMinutes;
    Genres genre;
    double rating;
};

void createMovie(Movie& movie, const char title[MAX_TITLE_LEN], const unsigned int lengthInMinutes,
    const Genres& genre, const double rating) {
    strcpy_s(movie.title, MAX_TITLE_LEN, title);
    movie.lengthInMinutes = lengthInMinutes;
    movie.genre = genre;
    movie.rating = rating;
}

void printGenre(const Genres& genre) {
    switch (genre) {
    case Genres::Comedy: std::cout << "Comedy"; return;
    case Genres::Action: std::cout << "Action"; return;
    case Genres::Horror: std::cout << "Horror"; return;
    case Genres::Romantic: std::cout << "Romantic"; return;
    }
}

void printMovie(const Movie& movie) {
    std::cout << movie.title << " " << movie.lengthInMinutes << " ";
    printGenre(movie.genre);
    std::cout << " " << movie.rating << "\n";
}

void printMovies(const Movie* movies, const int size) {
    for (int i = 0; i < size; i++) {
        printMovie(movies[i]);
    }
}

int getTopRatedMovieIndex(const Movie* movies, const int size) {
    int topInd = 0;
    for (int i = 1; i < size; i++) {
        if (movies[i].rating > movies[topInd].rating) {
            topInd = i;
        }
    }
    return topInd;
}

int getLowestRatedMovieIndex(const Movie* movies, const int size) {
    int lowestInd = 0;
    for (int i = 1; i < size; i++) {
        if (movies[i].rating < movies[lowestInd].rating) {
            lowestInd = i;
        }
    }
    return lowestInd;
}

//I will use selection sort to minimize the number of swaps 
void sortByRating(Movie* movies, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minInd = i + getLowestRatedMovieIndex(movies + i, size - i);
        if (minInd != i) std::swap(movies[i], movies[minInd]);
    }
}

int main()
{
    const int MOVIES_COUNT = 3;
    Movie movies[MOVIES_COUNT];
    createMovie(movies[0], "Movie Title 1", 120, Genres::Comedy, 3.72);
    createMovie(movies[1], "Movie Title 2", 180, Genres::Horror, 4.28);
    createMovie(movies[2], "Movie Title 3", 200, Genres::Romantic, 2.91);

    printMovies(movies, MOVIES_COUNT);

    std::cout << "\nTop rated movie:\n";
    int topInd = getTopRatedMovieIndex(movies, MOVIES_COUNT);
    printMovie(movies[topInd]);

    sortByRating(movies, MOVIES_COUNT);
    std::cout << "\nSorted:\n";
    printMovies(movies, MOVIES_COUNT);
}

