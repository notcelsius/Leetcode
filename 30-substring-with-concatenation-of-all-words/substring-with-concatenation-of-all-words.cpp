class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        unordered_map<string, int> freq;
        for (string w : words) {
            freq[w]++;
        }

        int wordsCount = words.size();
        int wordLength = words[0].size();
        int totalLength = wordsCount * wordLength;

        if (s.size() < totalLength) return result;

        // try every possible starting offset
        for (int offset = 0; offset < wordLength; offset++) {
            unordered_map<string, int> seen;
            int left = offset;
            int count = 0;

            // move right in steps of wordLength
            for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);

                // word not needed → reset window
                if (freq.find(word) == freq.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLength;
                    continue;
                }

                seen[word]++;
                count++;

                // too many of this word → shrink from left
                while (seen[word] > freq[word]) {
                    string leftWord = s.substr(left, wordLength);
                    seen[leftWord]--;
                    count--;
                    left += wordLength;
                }

                // found all words
                if (count == wordsCount) {
                    result.push_back(left);

                    // move left to look for next match
                    string leftWord = s.substr(left, wordLength);
                    seen[leftWord]--;
                    count--;
                    left += wordLength;
                }
            }
        }

        return result;
    }
};
