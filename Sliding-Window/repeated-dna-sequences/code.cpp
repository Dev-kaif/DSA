#include <iostream>

using namespace std;

// https://leetcode.com/problems/repeated-dna-sequences/description/

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    int k = 10;
    int low = 0;
    int high = k - 1;
    vector<string> result;
    int n = s.size();

    unordered_map<string, int> freq;

    string window;

    // creating strating string
    for (int i = low; i <= high; i++)
    {
        window += s[i];
    }

    // putting string in map
    freq[window]++;

    while (high < n - 1)
    {
        high++;

        // remove first element of string
        string newWindow = window.substr(1);

        // new element added
        newWindow += s[high];

        freq[newWindow]++;

        // if string appreared twice we push it in result
        if (freq[newWindow] == 2)
        {
            result.push_back({newWindow});
        }

        window = newWindow;
    }

    for (const string &str : result)
    {
        cout << str << endl;
    }

    // return result;
}