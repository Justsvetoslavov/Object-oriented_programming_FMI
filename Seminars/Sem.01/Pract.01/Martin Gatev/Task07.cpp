#include <iostream>

using std::cin;
using std::cout;

const int MAX_SIZE_MOVIE_NAME = 31;
const int MAX_AMOUNT_MOVIES_ARR = 3;

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
	int duration;
	char name[MAX_SIZE_MOVIE_NAME];
	Genre genre;
};

void initMovie(Movie& movie)
{
	cin >> movie.name;

	int movieGenre{};
	cin >> movieGenre;
	movie.genre = (Genre)movieGenre;

	cin >> movie.duration >> movie.rating;
}

void printMovie(const Movie& movie)
{
	cout << movie.name << ", ";

	switch (movie.genre)
	{
	case Genre::Comedy:
		cout << "Comedy";
		break;
	case Genre::Horror:
		cout << "Horror";
		break;
	case Genre::Action:
		cout << "Action";
		break;
	case Genre::Romantic:
		cout << "Romantic";
		break;
	default:
		break;
	}

	cout << ", " << movie.rating << ", " << movie.duration << std::endl;
}

void printMovieWithHighestRating(const Movie* movies, const int size)
{
	unsigned int maxRating = movies[0].rating;
	unsigned int moviePos{};

	for (int i = 0; i < MAX_AMOUNT_MOVIES_ARR; i++)
	{
		if (movies[i].rating >= maxRating)
		{
			maxRating = movies[i].rating;
			moviePos = i;
		}
	}

	printMovie(movies[moviePos]);
}

void mySwap(Movie& a, Movie& b)
{
	Movie temp = a;
	a = b;
	b = temp;
}

void sortMoviesByRating(Movie* movies, const int size)
{
	int min_idx{};

	for (int i = 0; i < size - 1; i++)
	{
		
		min_idx = i;

		for (int j = i + 1; j < size; j++)
		{
			if (movies[j].rating < movies[min_idx].rating)
			{
				min_idx = j;
			}	
		}

		if (min_idx != i)
		{
			mySwap(movies[min_idx], movies[i]);
		}	
	}
}

int main()
{
	int amountOfMovies{};

	cin >> amountOfMovies;

	Movie* mArr = new Movie[amountOfMovies];

	for (int i = 0; i < MAX_AMOUNT_MOVIES_ARR; i++)
	{
		initMovie(mArr[i]);
	}

	for (int i = 0; i < MAX_AMOUNT_MOVIES_ARR; i++)
	{
		printMovie(mArr[i]);
	}

	cout << std::endl;

	printMovieWithHighestRating(mArr, MAX_AMOUNT_MOVIES_ARR);

	cout << std::endl;

	sortMoviesByRating(mArr, MAX_AMOUNT_MOVIES_ARR);

	for (int i = 0; i < MAX_AMOUNT_MOVIES_ARR; i++)
	{
		printMovie(mArr[i]);
	}


	return 0;
}