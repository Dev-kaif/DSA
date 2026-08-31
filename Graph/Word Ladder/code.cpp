#include <iostream>

using namespace std;

// https://leetcode.com/problems/word-ladder/description/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {

        // Stores words that are available to be visited.
        unordered_map<string, int> wordSet;

        for (string word : wordList)
        {
            wordSet[word]++;
        }

        // Include beginWord so we can process it normally.
        wordSet[beginWord]++;

        // If endWord does not exist, transformation is impossible.
        if (!wordSet.contains(endWord))
        {
            return 0;
        }

        // {word, sequence length}
        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        // Mark beginWord as visited.
        wordSet.erase(beginWord);

        while (!q.empty())
        {
            pair<string, int> current = q.front();
            q.pop();

            string currentWord = current.first;
            int sequenceLength = current.second;

            // We found the target word.
            if (currentWord == endWord)
            {
                return sequenceLength;
            }

            // Try changing every character.
            for (int i = 0; i < currentWord.size(); i++)
            {

                char originalChar = currentWord[i];

                // Try every lowercase English letter.
                for (char letter = 'a'; letter <= 'z'; letter++)
                {

                    if (letter == originalChar)
                    {
                        continue;
                    }

                    currentWord[i] = letter;

                    // If this transformed word exists and
                    // has not been visited yet, add it to BFS.
                    if (wordSet.find(currentWord) != wordSet.end())
                    {

                        q.push({currentWord, sequenceLength + 1});

                        // Mark as visited immediately to avoid
                        // adding the same word multiple times.
                        wordSet.erase(currentWord);
                    }
                }

                // Restore the original character before
                // moving to the next position.
                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};
