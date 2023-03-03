//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225

#include <iostream>

const int SIZEOFARRAYS = 30;
enum class MovieGenre
{
    Comedy,
    Action,
    Horror,
    Romantic
};

struct Movie
{
    char movieName[SIZEOFARRAYS + 1];
    int duration;
    MovieGenre movieGenre;
    double rating;
};

void printMovies(const Movie movies[], const int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << "Movie name: " << movies[i].movieName << std::endl;
        std::cout << "Duration of the movie: " << movies[i].duration << std::endl;
        std::cout << "Movie genre: ";

        switch(movies[i].movieGenre)
        {
        case MovieGenre::Comedy:
            std::cout << "Comedy" << std::endl;
            break;

        case MovieGenre::Action:
            std::cout << "Action" << std::endl;
            break;

        case MovieGenre::Horror:
            std::cout << "Horror" << std::endl;
            break;

        case MovieGenre::Romantic:
            std::cout << "Romantic" << std::endl;
            break;
        }

        std::cout << "Movie rating: " << movies[i].rating << std::endl;
        std::cout << std::endl;
    }
}

void PrintTopMovie(const Movie movies[], const int SIZE)
{
    int topMovieIndex = 0;
    double topRating = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        if (movies[i].rating > topRating)
        {
            topRating = movies[i].rating;
            topMovieIndex = i;
        }
    }
    std::cout << movies[topMovieIndex].movieName << " " << movies[topMovieIndex].duration;
}

void swapMovies(Movie movies[], const int firstIndex, const int secondIndex)
{
    Movie temp = movies[firstIndex];
    movies[firstIndex] = movies[secondIndex];
    movies[secondIndex] = temp;
}

void sortMoviesByRating(Movie movies[], const int SIZE)
{
    int i, j, minIndex;
    for (i = 0; i < SIZE - 1; ++i)
    {
        minIndex = i;

        for (j = i + 1; j < SIZE; ++j)
        {
            if (movies[j].rating > movies[minIndex].rating)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapMovies(movies, minIndex, i);
        }
    }
}

int main()
{
    const int SIZE = 3;
    Movie movies[SIZE] = { "movieName1", 150, MovieGenre::Comedy, 5,
    "movieName2", 100, MovieGenre::Action, 20,
    "movieName3", 120, MovieGenre::Horror, 9};
    std::cout << "The top movie is: ";
    PrintTopMovie(movies, SIZE);
    std::cout << std::endl;
    std::cout << std::endl << "The sorted movie list is: " << std::endl;
    std::cout << std::endl;
    sortMoviesByRating(movies, SIZE);
    printMovies(movies, SIZE);

    return 0;
}
