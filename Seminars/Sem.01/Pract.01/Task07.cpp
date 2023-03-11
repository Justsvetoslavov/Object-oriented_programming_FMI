#include <iostream>
using std:: cout;
using std:: cin;

const int MAX_LENGHT = 30;

enum class Genre
{
    Comedy,
    Thriller,
    Drama, 
    Horror
};

struct Movie
{
    char movieName[MAX_LENGHT];
    int time;
    Genre genre;
    double rating;
};

void saveName(const char* name, char* movieName)
{
    int br = 0;
    while(name[br] != '\0')
    {
        movieName[br] = name[br];
        br++;
    }

    movieName[br] = '\0';

}

void createMovie(Movie& movie, const char* name, const int& time, const Genre& genre, const double& rating)
{
    saveName(name, movie.movieName);
    movie.time = time;
    movie.genre = genre;
    movie.rating = rating;
}

void printName(const Movie& movie)
{
    int i = 0;
    cout << "Name: ";
    while(movie.movieName[i] != '\0')
    {
        cout << movie.movieName[i];
        i++;

    }
    cout << "; ";
}

void printGenre(const Movie& movie)
{
    if(movie.genre == Genre::Comedy)
    {
        cout << "Genre: Comedy; ";
    }
    else if(movie.genre == Genre::Drama)
    {
        cout << "Genre: Drama; ";
    }
    else if(movie.genre == Genre::Horror)
    {
        cout << "Genre: Horror; ";
    }
    else if(movie.genre == Genre::Thriller)
    {
        cout << "Genre: Thriller; ";
    }
}

void printMovieArr(const Movie* movieArr, const size_t size)
{
    for(int i = 0; i<size; ++i)
    {
        cout << i+1 << ". ";
        printName(movieArr[i]);
        cout << "Duration: " << movieArr[i].time << "; ";
        printGenre(movieArr[i]);
        cout << "Rating: " << movieArr[i].rating << '\n';
    }
}

void sortMovieArr(Movie* movieArr, const size_t size)
{
    for(int i = 0; i<size; ++i)
    {
        for(int j = i+1; j<size; ++j)
        {
            if(movieArr[i].rating < movieArr[j].rating)
            {
                Movie temp = movieArr[i];
                movieArr[i] = movieArr[j];
                movieArr[j] = temp;
            }
        }
    }
}

void topMovie(Movie* movieArr, const size_t size)
{
    Movie top = movieArr[0];
    for(int i = 1; i<size; ++i)
    {
        if(movieArr[i].rating > top.rating)
        {
            top = movieArr[i];
        }
    }
    cout << "Top movie: \n";
    printName(top);
    cout << "Duration: " << top.time << "; ";
    printGenre(top);
    cout << "Rating: " << top.rating << '\n';
}

int main()
{
    Movie myFirstMovie, mySecondMovie, myThirdMovie;
    const char firstName[] = {'E', 's', 'c', 'a', 'p', 'e', ' ', 'r', 'o', 'o', 'm'};
    const int firstTime = 123;
    const Genre firstGenre = Genre::Horror;
    const double firstRating = 4.8;

    const char secondName[] = {'L', 'o', 's', 't', ' ', 'c', 'i', 't', 'y'};
    const int secondTime = 96;
    const Genre secondGenre = Genre::Comedy;
    const double secondRating = 5.2;

    const char thirdName[] = {'S', 'm', 'i', 'l', 'e'};
    const int thirdTime = 102;
    const Genre thirdGenre = Genre::Thriller;
    const double thirdRating = 5.1;

    createMovie(myFirstMovie, firstName, firstTime, firstGenre, firstRating);
    createMovie(mySecondMovie, secondName, secondTime, secondGenre, secondRating);
    createMovie(myThirdMovie, thirdName, thirdTime, thirdGenre, thirdRating);
    const size_t SIZE = 3;
    Movie movieArr[SIZE] = {myFirstMovie, mySecondMovie, myThirdMovie};
    printMovieArr(movieArr, SIZE);
    topMovie(movieArr, SIZE);
    cout << "Sorted:\n";
    sortMovieArr(movieArr, SIZE);
    printMovieArr(movieArr, SIZE);

}