// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Movies {
	char name[40];
	double time,rating;
	short Genre;
	enum genre { Comedy, Action, Horror, Romantic };
};
void createMovies(Movies*& movies, int numberOfMovies) {
	for (size_t i = 3; i < numberOfMovies+3; i++) {
		cout << "Name: ";
		cin.getline(movies[i].name,20);
		cin.ignore(1, '\n');
		cout << "How long is the movie: ";
		cin >> movies[i].time;
		cout << "Rating of the movie: ";
		cin >> movies[i].rating;
		cout << "Based on the genres enter a number: 0-Comedy , 1-Action , 2-Horror , 3-Romantic";
		cin >> movies[i].Genre;
	 
		while (movies[i].Genre < 0 || movies[i].Genre > 3) {
				cin >> movies[i].Genre;			
		}
	}
}
void sortMovies(Movies*& movies, int numberOfMovies) {
	for (int i = 0; i < numberOfMovies; i++) {
		for (int j = i+1; j < numberOfMovies; j++) {
			if (movies[i].rating > movies[j].rating) {
				Movies temp = movies[i];
				movies[i] = movies[j];
				movies[j] = temp;
				
			}
			
		}
	}
}
void printMovies(Movies* movies, int numberOfMovies) {
	for (int i = 0; i < numberOfMovies+3; i++) {
		cout << "Name:" << movies[i].name<<endl;
		cout << "Runtime:" << movies[i].time << " minutes"<<endl;
        cout << "Rating:" << movies[i].rating<<endl;	
		cout << "Genre:";
		if (movies[i].Genre == 0) {
			cout << "Comedy";
		}
		if (movies[i].Genre == 1) {
			cout << "Action";
		}
		if (movies[i].Genre == 2) {
			cout << "Horror";
		}
		if (movies[i].Genre == 3) {
			cout << "Romantic";
		}
		cout << endl;
	}
}
int main()
{
	int numberOfMovies;
	cout << "Enter the number of movies you want to review: ";
	cin >> numberOfMovies;
	Movies* Movie = new Movies[numberOfMovies + 3];
	Movie[0] = { "The Batman",176,8.7,1 };
	Movie[1] = { "Twilight",122,5.3,3 };
	Movie[2] = { "The thing",109,8.2,2 };
	createMovies(Movie, numberOfMovies);
	sortMovies(Movie, numberOfMovies);
	printMovies(Movie, numberOfMovies);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
