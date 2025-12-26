class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // penalty if we close at 0: we're closed all day, so every 'Y' is a penalty
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int bestTime = 0;
        int bestPenalty = penalty;

        // try closing at times 1..n by sweeping
        for (int j = 0; j < n; j++) {
            if (customers[j] == 'Y') penalty -= 1; // now we are open for this 'Y'
            else penalty += 1;                     // now we are open for this 'N'

            // closing time is j+1 after processing hour j
            if (penalty < bestPenalty) {
                bestPenalty = penalty;
                bestTime = j + 1;
            }
        }

        return bestTime;
    }
};
