using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        unordered_map<char, int> freq;
        if (k == 0) {
            return 0; 
        }
        int l = 0;
        int r = 0;
        int maxLength = 0;
        for (r = 0; r < s.size(); r++) {
            // if freq has size
            if (freq.size() < k) {
                freq[s[r]]++;
            }
            // freq does not have size
            else {
                // but char already in freq
                if (freq[s[r]] != 0) {
                    freq[s[r]]++;
                }
                else {
                    // char not in freq already
                    freq[s[r]]++;
                    while (freq.size() > k) {
                        char remove = s[l];
                        freq[remove]--;
                        if (freq[remove] == 0) {
                            freq.erase(remove);
                        }
                        l++;
                    }
                }
            }
            maxLength = max(maxLength, r - l + 1);

        }
        return maxLength;
    }
};
