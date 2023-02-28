#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
//Natalia Nakollofski   1MI8000034    GR.1

//Реализирайте структура, описваща филм(Movie) със следните характеристики :
//
//Име на филм
//Продължителност в минути
//Жанр
//Възможните стойности са описани с множеството{ Comedy, Action, Horror, Romantic }
//Рейтинг
//Създайте масив от филми и имплементирайте следната функционалност :
//
//Функция, която създава филм по подадени параметри.
//Spoiler : По принцип тази задача се делегира на конструкторите, които ще изучаваме скоро.
//
//Направете масив от филми и добавете 3 филма по ваш избор.
//Изведете всички филми в масива.
//Изведете топ филма в масива - този с най - много рейтинг.
//Бонус :
//
//	Сортиране на филмите по рейтинг.

enum Genre {
	Comedy, Action, Horror, Romantic
};

struct Movie {
	std::string name;
	int duration;
	Genre genre;
	double rating;
};

void createmovies(Movie& movies, std::string name, int duration, Genre genre, double rating) {
	movies.name = name;
	movies.duration = duration;
	movies.genre = genre;
	movies.rating = rating;
}

void displaymovies(const Movie mymovie[], const int numMovies) {
	for (int i = 0; i < numMovies; i++) {
		cout << "Name:" << mymovie[i].name << endl;
		cout << "Duration:" << mymovie[i].duration << endl;
		cout << "Rating:" << mymovie[i].rating << endl;
		cout << "Genre:";
		switch (mymovie[i].genre) {
		case Comedy:
			cout << "Comedy";
			break;
		case Action:
			cout << "Action";
			break;
		case Horror:
			cout << "Horror";
			break;
		case Romantic:
			cout << "Romantic";
			break;
		default:
			cout << "Unknown";
		}
		cout << endl;
	}
}

void displayTopMovie(const Movie mymovie[], const int numMovies) {
	double MaxRating = 0.0;
	int topMovieINDX = -1;
	for (int i = 0; i < numMovies; i++) {
		if (mymovie[i].rating > MaxRating) {
			MaxRating = mymovie[i].rating;
			topMovieINDX = i;
		}
	}
	if (topMovieINDX >= 0) {
		cout << "The top movie is:" << mymovie[topMovieINDX].name << endl;
		cout << "Rating:" << mymovie[topMovieINDX].rating << endl;
	}
	else {
		cout << "No movie found" << endl;
	}
}
void sortMoviesByrating(Movie movie[], const int numMovies) {
	for (int i = 0; i < numMovies; i++) {
		for (int j = i + 1; j < numMovies; j++) {
			Movie temp = movie[i];
			movie[i] = movie[j];
			movie[j] = temp;
		}

	}
}
int main() {

	const int NUMBER_OF_MOVIES = 3;
	Movie movies[NUMBER_OF_MOVIES];
	createmovies(movies[0], "The Shawshank Redemption", 142, Action, 9.3);
	createmovies(movies[1], "The Godfather", 175, Action, 9.2);
	createmovies(movies[2], "The Dark Knight", 152, Action, 9.0);

	displaymovies(movies, NUMBER_OF_MOVIES);
	cout << "endl";
	displayTopMovie(movies, NUMBER_OF_MOVIES);
	cout << endl;
	sortMoviesByrating(movies, NUMBER_OF_MOVIES);
	cout << "Movies sorted by rating:" << endl;
	displaymovies(movies, NUMBER_OF_MOVIES);
	return 0;

}
