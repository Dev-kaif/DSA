#include <iostream>

using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

int findMaxcount(vector<int> &a)
{
    int maxcount = -1;
   
    for (int i = 0; i < 256; i++)
    {
        maxcount = max(maxcount, a[i]);
    }
    return maxcount;
}

int main()
{
    string s = "ABAB";


    // nums of char that we can change
    int k = 2;

     // 256 bcz ascii , vector of 256 and all values 0;
    vector<int> f(256, 0);
    int n = s.size();
    int low = 0, high = 0, res = 0;

    for (high = 0; high < n; high++)
    {
        f[s[high]]++;


        int len = high - low + 1;

        // max count of single digit value , ex: A & B both at end will 2 times reapted so maxcount is 2
        int maxcount = findMaxcount(f);

        // by diff , we check if its lower/greater/equal to K
        // if diff <= k , measn we can just replace the char and make longest substring 
        // if diff > k, means we need to remove one of the char from list 

        // ex: A=2 , B=1,C=1 & k=1
        // maxcount = 2 , len = 4 , diff = 2
        // means there are two char we need to change to get longest sub string 
        // but k is 1 , means we can only chnage 1 of the char
        // hence problamatic
        int diff = len - maxcount;

        // problematic if diff>k;
        while (diff > k)
        {
            f[s[low]]--;
            low++;

            len = high - low + 1;
            maxcount = findMaxcount(f);
            diff = len - maxcount;
        }

        len = high - low + 1;
        res = max(res,len);
    }

    cout << res << endl;

    return res;
}