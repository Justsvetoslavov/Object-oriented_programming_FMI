#include <iostream>

const int COUNT_OF_MOVIES = 3;

enum class Genre {
	Comedy,
	Action,
	Horror,
	Romantic
};

struct Movie {
	const char* name;
	double duration;
	Genre genre;
	double rating;
};

Movie MakeMovie(const char* name, double duration, Genre genre, double rating) {
	Movie movie;
	movie.name = name;
	movie.duration = duration;
	movie.genre = genre;
	movie.rating = rating;

	return movie;
}

void PrintMovie(const Movie& movie) {
	std::cout << "Name: " << movie.name << "\nDuration: " << movie.duration << std::endl;
	std::cout << "Genre: ";
	switch (movie.genre) {
	case Genre::Comedy: std::cout << "Comedy" << std::endl;
		break;
	case Genre::Action: std::cout << "Action" << std::endl;
		break;
	case Genre::Horror: std::cout << "Horror" << std::endl;
		break;
	case Genre::Romantic: std::cout << "Romantic" << std::endl;
		break;
	}
	std::cout << "Rating: " << movie.rating << std::endl;
}

Movie FindTopMovie(const Movie* movies, size_t N) {
	int maxRating = -10000;
	int topMovieId = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (movies[i].rating > maxRating) {
			topMovieId = i;
			maxRating = movies[i].rating;
		}
	}

	return movies[topMovieId];
}

void SortMoviesByRating(Movie* movies, size_t N) {
	for (size_t i = 0; i < N; i++)
	{
		int maxRatingId = i;

		for (size_t j = i + 1; j < N; j++)
		{
			if (movies[j].rating > movies[maxRatingId].rating) {
				maxRatingId = j;
			}
		}

		if (maxRatingId != i) {
			std::swap(movies[i], movies[maxRatingId]);
		}
	}
}

int main()
{
	Movie movies[COUNT_OF_MOVIES];

	Movie m1 = MakeMovie("Harry Potter", 2.03, Genre::Action, 5);
	Movie m2 = MakeMovie("IT", 1.09, Genre::Horror, 3);
	Movie m3 = MakeMovie("Friends", 3.21, Genre::Comedy, 4.5);

	movies[0] = m1;
	movies[1] = m2;
	movies[2] = m3;

	std::cout << "List of movies: " << std::endl;
	for (size_t i = 1; i <= COUNT_OF_MOVIES; i++)
	{
		std::cout << "Movie " << i << ":" << std::endl;
		PrintMovie(movies[i - 1]);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	Movie topRatingMovie = FindTopMovie(movies, COUNT_OF_MOVIES);
	std::cout << "Top rated movie: " << std::endl;
	PrintMovie(topRatingMovie);
	std::cout << std::endl;

	SortMoviesByRating(movies, COUNT_OF_MOVIES);

	std::cout << "Movies sorted by rating: " << std::endl;
	for (size_t i = 0; i < COUNT_OF_MOVIES; i++)
	{
		PrintMovie(movies[i]);
		std::cout << std::endl;
	}
}
