/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    vector<vector<int>> ans; 
    public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }

    private:

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return -1;
        }

        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        int curDepth = max(leftDepth, rightDepth) + 1;

        if (curDepth >= ans.size()) {
            ans.push_back({});
        }

        ans[curDepth].push_back(node->val);
        return curDepth;

    }
};