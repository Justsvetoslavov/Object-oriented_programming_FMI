#include <iostream>

const char genreComedy[] = "Comedy";
const char genreAction[] = "Action";
const char genreHorror[] = "Horror";
const char genreRomantic[] = "Romantic";

struct Movie
{
    char name[31];
    unsigned short duration;
    const char* genre;
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
    std::cin.getline(m.name, 31);
    std::cin >> m.duration;
    char helper;
    do
    {
     std::cin >> helper;
     switch (helper)
     {
     case 'C':
         m.genre = new char[sizeof(genreComedy)];
         m.genre = genreComedy;
         helper = '0';
         break;
     case 'A':
         m.genre = new char[sizeof(genreAction)];
         m.genre = genreAction;
         helper = '0';
         break;
     case 'H':
         m.genre = new char[sizeof(genreHorror)];
         m.genre = genreHorror;
         helper = '0';
         break;
     case 'R':
         m.genre = new char[sizeof(genreRomantic)];
         m.genre = genreRomantic;
         helper = '0';
         break;            
     default:
         std::cout << "There is not such genre \n";
         break;
    }
    } while (helper != '0');
    std::cin >> m.rating;
}

void printMovies(const Movie& m)
{
    std::cout << "The title is: " << m.name << '\n'
         << "Its duration is " << m.duration << " minutes" << '\n'
         << "The genre is " << m.genre << '\n'
         << "And its rating is " << m.rating << '\n';
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
