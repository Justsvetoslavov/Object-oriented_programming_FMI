#include <iostream>

const int MAX_NAME_SIZE = 30;

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
	char name[MAX_NAME_SIZE + 1];
};

void Swap(Movie& lhs, Movie& rhs)
{
	Movie temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void StrCopy(char* dest, const char* source)
{
	size_t index = 0;
	while (source[index] != '\0') {
		dest[index] = source[index];
		index++;
	}
  
	arr1[index] = '\0';
}

void InitMovie(Movie& movie, const char* name, const double rating, const int duration, const Genre genre)
{
	StrCopy(movie.name, name);
	movie.rating = rating;
	movie.duration = duration;
	movie.genre = genre;
}

void PrintMovies(const Movie* moviesArr, const int count)
{
	for (size_t i = 0; i < count; i++) {
		std::cout << "Movie name: " << moviesArr[i].name << std::endl;
		std::cout << "Duration: " << moviesArr[i].duration << std::endl;
		std::cout << "Rating: " << moviesArr[i].rating << std::endl;
		std::cout << "Genre: ";
		switch (moviesArr[i].genre) {
			case Genre::Comedy: std::cout << "Comedy"; break;
			case Genre::Action: std::cout << "Action"; break;
			case Genre::Horror: std::cout << "Horror"; break;
			case Genre::Romantic: std::cout << "Romantic"; break;
		}
		std::cout << std::endl;
	}
}

void SortMoviesByRating(Movie* movies, const int count)
{
	for (size_t i = 0; i < count - 1; ++i) {
		size_t indexOfMaxElement = i;
		for (size_t j = i + 1; j < count; ++j) {
			if (movies[indexOfMaxElement].rating < movies[j].rating) {
				indexOfMaxElement = j;
			}
		}
		
		if(indexOfMaxElement != i) {
			Swap(movies[i], movies[indexOfMaxElement]);
		}
	}
  
}

void PrintNameOfBestRatedMovie(const Movie* movies, const int count)
{
	int indexOfBest = 0;

	for (size_t i = 1; i < count; i++) {
		if (movies[indexOfBest].rating < movies[i].rating) {
			indexOfBest = i;
		}
	}

	std::cout << movies[indexOfBest].name << std::endl;
}

int main()
{
	int numberOfMovies;
	std::cin >> numberOfMovies;

	Movie* movies = new Movie[numberOfMovies];

	for (size_t i = 0; i < numberOfMovies; i++) {
		char name[MAX_NAME_SIZE + 1];
		std::cin >> name;
		std::cin.ignore();
		double rating;
		int duration, type;
		std::cin >> rating >> duration >> type;
		Genre genre = (Genre)type; // TODO: validation / switch case
		InitMovie(movies[i], name, rating, duration, genre);
	}

	PrintNameOfBestRatedMovie(movies, numberOfMovies);
	SortMoviesByRating(movies, numberOfMovies);
	PrintMovies(movies, numberOfMovies);
  
  	delete[] movies;
}