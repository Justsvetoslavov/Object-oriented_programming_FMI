#include <iostream>

const unsigned int SIZE_NAME = 30;
enum Genre 
{
    Comedy = 1,
    Action,
    Horror,
    Romantic
};

struct Movie
{
    char name[SIZE_NAME + 1];
    unsigned short duration;
    Genre genre;
    float rating;
};

void createMovie(Movie &m);
void printMovies(const Movie& m);
void swap(Movie& m1, Movie& m2);
void bubbleSort(Movie* movies, const size_t& size);



int main()
{
    Movie* movies = new Movie[3];
    for(int i = 0; i < 3; i++)
    {
        createMovie(movies[i]);
        std::cin.ignore();
    }
    for(int i = 0; i < 3; i++)
    {
        printMovies(movies[i]);
        std::cout << "\n -------------- \n";
    }

    bubbleSort(movies, 3);
    std::cout << "The best movie is " << movies[2].name;
    delete[] movies;

    return 0;
}

void createMovie(Movie &m)
{
    std::cin.getline(m.name, SIZE_NAME + 1);
    std::cin >> m.duration;
    unsigned int helper;
    do
    {
        std::cin >> helper;
        switch (helper)
        {
        case 1:
            m.genre = Comedy;
            break;
        case 2:
            m.genre = Action;
            helper = 1;
            break;
        case 3:
            m.genre = Horror;
            helper = 1;
            break;
        case 4:
            m.genre = Romantic;
            helper = 1;
            break;
        default:
            std::cout << "Invalid genre! \n";
            break;
        }
     
    } while (helper != 1);
    std::cin >> m.rating;
}

void printMovies(const Movie& m)
{
    std::cout << "The title is: " << m.name << '\n'
    << "The duraation is: " << m.duration <<'\n';
    switch (m.genre)
    {
    case 1:
            std::cout << "The genre is: Comedy \n";
            break;
    case 2:
            std::cout << "The genre is: Action \n";
            break;
    case 3:
            std::cout << "The genre is: Horror \n";
            break;
    case 4:
            std::cout << "The genre is: Romantic \n";
            break;
    }
    std::cout << "The rating is: " << m.rating << '\n';
}

void swap(Movie& m1, Movie& m2)
{
    Movie m3 = m1;
    m1 = m2;
    m2 = m3;
}

void bubbleSort(Movie* movies, const size_t& size)
{
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = i; j < size; j++)
        {
            if(movies[i].rating > movies[j].rating)
                swap(movies[i], movies[j]);
        }
    }
}
