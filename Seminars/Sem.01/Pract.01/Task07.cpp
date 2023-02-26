#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

const int MAX_NAME_SIZE = 31;
const double EPSYLON = 0.0000001;

enum class Genre
{
	Comedy,
	Action,
	Horror,
	Romantic
};

struct Movie
{
	double rating;
	Genre genre;
	int duration;
	char name[MAX_NAME_SIZE];
};

void initMovie(Movie& movie)
{
	cin >> movie.rating >> movie.duration;
	cin.ignore();
	cin >> movie.name;
	int genre = 0;
	cin >> genre;
	movie.genre = (Genre)genre;
}

void printMovies(const Movie* moviesArr, const int& count)
{
	for (size_t i = 0; i < count; i++)
	{
		Movie movie = moviesArr[i];
		cout << i + 1 << "." << endl;
		cout << "Movie name: ";
		cout << movie.name;
		cout << endl;
		cout << "Duration: " << movie.duration << endl;
		cout << "Rating: " << movie.rating << endl;
		cout << "Genre: ";
		switch (movie.genre)
		{
		case Genre::Comedy:cout << "Comedy"; break;
		case Genre::Action:cout << "Action"; break;
		case Genre::Horror:cout << "Horror"; break;
		case Genre::Romantic:cout << "Romantic"; break;
		}
		cout << endl;
	}
}

// return true if second is bigger, else false
bool compareDoubles(const double& firstNum, const double& secondNum)
{
	return (secondNum - firstNum) > EPSYLON;
}

void sortMoviesByRating(Movie* movies, const int& count)
{
	for (size_t i = 0; i < count - 1; ++i)
	{
		for (size_t j = 0; j < count - i - 1; ++j)
		{
			if (compareDoubles(movies[j].rating, movies[j + 1].rating))
			{
				swap(movies[j], movies[j + 1]);
			}
		}
	}
}

void PrintNameOfBestRatedMovie(const Movie* movies, const int& count)
{
	int indexOfBest = 0;

	for (size_t i = 1; i < count; i++)
	{
		if (compareDoubles(movies[indexOfBest].rating, movies[i].rating))
		{
			indexOfBest = i;
		}
	}

	cout << movies[indexOfBest].name << endl;
}

int main()
{
	Movie firstMovie;
	Movie secondMovie;
	Movie thirdMovie;
	initMovie(firstMovie);
	initMovie(secondMovie);
	initMovie(thirdMovie);

	Movie movies[3] = { firstMovie, secondMovie, thirdMovie };

	printMovies(movies, 3);

	PrintNameOfBestRatedMovie(movies, 3);

	sortMoviesByRating(movies, 3);

	printMovies(movies, 3);
}