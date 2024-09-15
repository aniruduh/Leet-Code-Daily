class Solution {

public:

    int findTheLongestSubstring(string s) {

        vector<int> firstOccurrence(32, INT_MAX);

        firstOccurrence[0] = -1;

        string vowels = "aeiou";

        int currentState = 0;

        int longestSubstringLength = 0;

        for (int i = 0; i < s.size(); ++i) {


            for (int j = 0; j < 5; ++j) { 

                if (s[i] == vowels[j]) {

                    currentState ^= (1 << j);

                }

            }

            longestSubstringLength = max(longestSubstringLength, i - firstOccurrence[currentState]);

            firstOccurrence[currentState] = min(firstOccurrence[currentState], i);

        }

        return longestSubstringLength;

    }

};