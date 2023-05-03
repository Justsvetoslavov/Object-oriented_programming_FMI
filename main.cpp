#include "CarPart/Tires/Tires.h"
#include "CarPart/Battery/Battery.h"

int main() {
    Tires tr(1, "rds", "sds", 155, 31, 13);
    std::cout << tr;
}