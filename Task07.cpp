#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum Genre {
    Comedy,
    Action,
    Horror
};

struct Movie {
    char name[100];
    int time;
    Genre gen;
    double rate;
};

void str_trans(char str1[], const char str2[]) {
    int rotator = -1;
    while (str2[++rotator] != '\0')
        str1[rotator] = str2[rotator];
}

Movie add_movie(const char name[], int time, Genre gen, double rate) {
    Movie res{ "", time, gen, rate};
    str_trans(res.name, name);
    return res;
}

void swap_movies(Movie &mov1, Movie &mov2) {
    Movie agent;
    agent = mov1;
    mov1 = mov2;
    mov2 = agent;
}

void sort_movies(Movie *movies, int num) {
    int max_pos;
    for (int i = 0; i < num - 1; ++i) {
        max_pos = i;
        for (int j = i + 1; j < num; ++j)
            if (movies[j].rate > movies[max_pos].rate)
                max_pos = j;
        if (max_pos != i)
            swap_movies(movies[i], movies[max_pos]);
    }
}

int main() {
    Movie list[3];
    list[0] = add_movie("Film1", 180, Comedy, 9.2);
    list[1] = add_movie("Film2", 150, Action, 5.0);
    list[2] = add_movie("Film3", 110, Horror, 6.7);
    sort_movies(list, 3);
    for (int i = 0; i < 3; ++i) {
        cout << list[i].name << " - " << list[i].rate << endl;
    }
}