#include <iostream>

struct Movie
{
    char title[31];
    unsigned int length;
    char genre;
    float rating;
};

Movie createMovie(const char title[31], const unsigned int length, const char genre, const float rating)
{
    Movie movie;
    int i = 0;
    while(title[i] != '\0')
        movie.title[i] = title[i++];
    movie.title[i] = '\0';

    movie.length = length;

    if (genre == 'c' || genre == 'a' ||
        genre == 'h' || genre == 'r')
        movie.genre = genre;
    else
        movie.genre = '?';
    
    if (rating >= 0 && rating <= 10)
        movie.rating = rating;
    else
        movie.rating = 0;
    
    return movie;
}

void printMovie(const Movie movie)
{
    std::cout << "Title: ";
    for (size_t i = 0; movie.title[i] != '\0'; i++)
        std::cout << movie.title[i];

    std::cout << "\nLength in minutes: " << movie.length;

    switch (movie.genre)
    {
    case 'c': 
        std::cout << "\nGenre: Comedy"; 
        break;
    case 'a':
        std::cout << "\nGenre: Action"; 
        break;
    case 'h':
        std::cout << "\nGenre: Horror"; 
        break;
    case 'r':
        std::cout << "\nGenre: Romance"; 
        break;
    default:
        std::cout << "\nGenre: n/a";
        break;
    }

    std::cout << "\nRating: " << movie.rating << "\n\n";
}

void sortMovies(Movie* arr, int count)
{
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i; j < count; j++)
        {
            if (arr[i].rating < arr[j].rating)
            {
                Movie temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    Movie* moviesArr= new Movie[3];
    moviesArr[0] = createMovie("Murder Mystery", 97, 'c', 6);
    moviesArr[1] = createMovie("The Notebook", 124, 'r', 7.8);
    moviesArr[2] = createMovie("Smile", 115, 'h', 6.6);

    std::cout << "Start order of the movies:\n";
    for (size_t i = 0; i < 3; i++)
        printMovie(moviesArr[i]);
    std::cout << std::endl;

    sortMovies(moviesArr, 3);
    std::cout << "Movies sorted by rating:\n";
    for (size_t i = 0; i < 3; i++)
        printMovie(moviesArr[i]);
    std::cout << std::endl;

    std::cout << "Top movie:\n";
    printMovie(moviesArr[0]);

    delete[] moviesArr;
    return 0;
}