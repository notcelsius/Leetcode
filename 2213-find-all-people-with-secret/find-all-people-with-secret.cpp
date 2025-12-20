#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // Person 0 and firstPerson know the secret at time 0.
        unify(parent, 0, firstPerson);

        int m = (int)meetings.size();
        int i = 0;

        while (i < m) {
            int t = meetings[i][2];

            // Collect everyone involved at this time t
            vector<int> participants;
            int j = i;
            while (j < m && meetings[j][2] == t) {
                int a = meetings[j][0];
                int b = meetings[j][1];
                participants.push_back(a);
                participants.push_back(b);
                j++;
            }

            // Union all meetings at time t
            for (int k = i; k < j; k++) {
                unify(parent, meetings[k][0], meetings[k][1]);
            }

            // After unions, reset components not connected to 0 (only for participants)
            int root0 = find(parent, 0);
            sort(participants.begin(), participants.end());
            participants.erase(unique(participants.begin(), participants.end()), participants.end());

            for (int p : participants) {
                if (find(parent, p) != root0) {
                    parent[p] = p; // disconnect after this time
                }
            }

            i = j;
        }

        // Everyone connected to 0 knows the secret
        vector<int> res;
        int root0 = find(parent, 0);
        for (int p = 0; p < n; p++) {
            if (find(parent, p) == root0) res.push_back(p);
        }
        return res;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void unify(vector<int>& parent, int a, int b) {
        int ra = find(parent, a);
        int rb = find(parent, b);
        if (ra != rb) parent[rb] = ra;
    }
};
