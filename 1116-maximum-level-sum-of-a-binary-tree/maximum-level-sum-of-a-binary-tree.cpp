/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int sum = 0;
        int maxSum = INT_MIN;
        int lvl = 1;
        int maxLvl = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            cout << "lvl: " << lvl << endl;
            int lvlSize = q.size();
            cout << "lvlSize:" << lvlSize << endl;
            for (int i = 0; i < lvlSize; i++) {
                    sum += q.front()->val;
                    cout << sum << endl;
                    if (q.front()->left) {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right) {
                        q.push(q.front()->right);
                    }  
                    q.pop();
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLvl = lvl;
            }
            sum = 0;
            lvl++;
        }
        return maxLvl;
    }
};