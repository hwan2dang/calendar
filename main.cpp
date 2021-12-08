#include <iostream>
#include "calendar.hpp"

using namespace std;
// https://www.youtube.com/watch?v=loHb2JZdMjs&ab_channel=KyoHeo
// https://en.wikipedia.org/wiki/Zeller%27s_congruence
// https://www.cuemath.com/calculators/leap-year-calculator/

int main() {
    int year = 0;
    cout << "Type year: ";
    cin >> year;
    Calendar calendar(year);

    return 0;
}