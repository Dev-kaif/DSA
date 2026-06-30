#include <iostream>
#include <numeric>

using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/

/*
Intuition:
let say CurrentSum is 3 at index2 , now you need to check how much I remove from 3 so that I get k=2
        You need 1 number so that you get  3-1(need)=2(k)
        Now you don't know what is need here programmatically? so you do 3-k=need
        and ask hashmap that do you have my need in your prefix sum list?
       If yes then count = count+freq
*/

int main()
{

    vector<int> nums = {1, 1, 1};
    int k = 2;

    unordered_map<int, int> f;
    int sum = 0;
    int res = 0;

    // prefix of index 0 in array
    f[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        // running sum
        sum += nums[i];

        // Look at images for explanation
        int ques = sum - k;

        // we check if we have "red part" in the hashmap
        int freq = f[ques];

        // If yes, then the "green part" satifies the condition of sum = k
        res += freq;

        // prefix of next element
        f[sum]++;
    }

    cout << res << endl;

    return res;
}
