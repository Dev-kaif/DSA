#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
        VECTOR

        Dynamic array.
        Can grow/shrink during runtime.

        Array:
            int arr[] = {1,2,3};

        internally becomes:

            int arr[3] = {1,2,3};

        Array size is fixed.
    */

    vector<int> p;

    /*
        push_back()

        Adds an existing object
        into vector.
    */

    int x = 3;

    p.push_back(x);

    /*
        Internally:

            vector inserts x
            into vector memory
    */

    p.push_back(4);

    /*
        Internally similar to:

            int temp = 4;
            p.push_back(temp);

        Temporary object is created first.
    */

    /*
        emplace_back()

        Directly creates object
        inside vector memory.

        No temporary object.
    */

    p.emplace_back(5);

    cout << p[0] << endl;    // 3
    cout << p.at(1) << endl; // 4
    cout << p[2] << endl;    // 5

    //----------- vector of pairs --------

    vector<pair<int, int>> k;

    // needs a full pair object
    k.push_back({2, 3});

    // takes constructor values directly
    k.emplace_back(4, 5);

    cout << k[0].first << " " << k[0].second << endl;
    cout << k[1].first << " " << k[1].second << endl;

    // vector with size (still dynamic, it can increase the size if we do push_back)
    vector<int> v1(5);

    // vector with size and values
    // 100 will be repeated 5 times to fill the size
    vector<int> v2(5, 100);

    // copy of vector
    // v3 will have same size and elements as v2
    vector<int> v3(v2);


}