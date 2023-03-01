//Gabriela Mladenova
//SI
//Group 1
//FN: 3MI0600225
#include <iostream>

const int SIZEOFARRAYS = 30;
enum MovieGenre
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

        if (MovieGenre::Comedy)
        {
            std::cout << "Comedy" << std::endl;
        }
        else if (MovieGenre::Action)
        {
            std::cout << "Action" << std::endl;
        }
        else if (MovieGenre::Horror)
        {
            std::cout << "Horror" << std::endl;
        }
        else if (MovieGenre::Romantic)
        {
            std::cout << "Romantic" << std::endl;
        }
        else
        {
            std::cout << "No genre" << std::endl;
        }

        std::cout << "Movie rating: " << movies[i].rating << std::endl;
        std::cout << std::endl;
    }
}
void PrintTopMovie(const Movie movies[], const int SIZE)
{
    int topMovieIndex = 0;
    int topRating = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        if (movies[i].rating > topRating)
        {
            topRating = movies[i].rating;
            topMovieIndex = i;
        }
    }
    for (int j = 0; j < SIZE; ++j)
    {
        if (j == topMovieIndex)
        {
            std::cout << movies[j].movieName << " " << movies[j].duration
                << " " << movies[j].movieGenre << " " << movies[j].rating;
        }
    }
}
void swapMovies(Movie movies[], const int firstIndex, const int secondIndex)
{
    Movie temp = movies[firstIndex];
    movies[firstIndex] = movies[secondIndex];
    movies[secondIndex] = temp;
}
void sortMoviesByRating(Movie movies[], const int SIZE)
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - i - 1; ++j)
        {
            if (movies[j].rating < movies[j + 1].rating)
            {
                swapMovies(movies, j, j + 1);
            }
        }
    }
}
int main()
{
    const int SIZE = 3;
    Movie movies[SIZE] = { "movieName1", 150, Comedy, 5,
    "movieName2", 100, Action, 20,
    "movieName3", 120, Horror, 9};
    std::cout << "The top movie is: ";
    PrintTopMovie(movies, SIZE);
    std::cout << std::endl;
    std::cout << std::endl << "The sorted movie list is: " << std::endl;
    std::cout << std::endl;
    sortMoviesByRating(movies, SIZE);
    printMovies(movies, SIZE);

    return 0;
}
