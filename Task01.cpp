#include <iostream>
#include <fstream>

const char PATH[] = "result.txt";

int diff_betw_sum_comp() {
    std::fstream my_file(PATH, std::ios::in);
    if (!my_file.is_open())
        return -1;
    int sum, comp;
    my_file >> sum >> comp;
    my_file.close();
    if (sum < comp)
        return comp - sum;
    return sum - comp;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::fstream res(PATH, std::ios::out);
    res << a + b + c << " " << a * b * c;
    res.close();
    std::cout << diff_betw_sum_comp();
}
