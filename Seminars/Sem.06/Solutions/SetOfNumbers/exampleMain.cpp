#include <iostream>

#include "SetOFNumbers.h"

int main() {
    SetOfNumbers s(10);

    s.AddNumber(4);
    s.AddNumber(8);


    s.print();
    SetOfNumbers s2(10);

    s2.AddNumber(1);
    s2.AddNumber(4);
    s2.AddNumber(9);

    s2.print();

    SetOfNumbers is = UnionOfSets(s, s2);
    SetOfNumbers us = IntersectionOfSets(s, s2);

    is.print();
    us.print();
    return 0;
}
