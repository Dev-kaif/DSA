#include <iostream>

using namespace std;

/*
    PAIRS IN C++

    A pair is a container provided by STL that stores
    TWO values together as a single unit.

    Syntax:
        pair<dataType1, dataType2>

    Why are pairs used?
    -------------------
    - To store two related values together
    - Useful in DSA and competitive programming
    - Saves time from creating custom classes/structures

    Real life example:
        (rollNo, marks)
        (x, y)
        (name, age)

    Access values using:
        .first
        .second
*/

int main()
{
    // Simple pair
    pair<int, int> p = {1, 3};

    // first = 1
    // second = 3
    cout << p.first << "\t" << p.second << endl;

    // Nested Pair
    pair<int, pair<int, int>> s = {1, {2, 3}};

    cout << s.first << "\t"
         << s.second.first << "\t"
         << s.second.second << endl;

    //  Array of pairs
    //  Each element stores TWO values together
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};

    /*
        arr[0] = {1, 2}
        arr[0].first  = 1
        arr[0].second = 2
    */

    cout << arr[0].first << "\t" << arr[0].second << endl;
}