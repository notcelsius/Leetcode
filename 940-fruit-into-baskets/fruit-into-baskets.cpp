using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int l = 0;
        int maxLength = 0;

        for (int r = 0; r < (int)fruits.size(); ++r) {
            // take the fruit at position r
            freq[fruits[r]]++;

            // shrink window until we have at most 2 types
            while (freq.size() > 2) {
                int leftFruit = fruits[l];
                freq[leftFruit]--;
                if (freq[leftFruit] == 0) {
                    freq.erase(leftFruit);
                }
                l++;
            }

            // update maximum window size
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
