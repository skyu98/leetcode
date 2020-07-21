// down to up
class Solution {
private: 
    int res = 0;

public:
    void solve(TreeNode* root, int depth) {
        if (root == NULL) return;
        if (!root->left && !root->right)
        {
            res = max(res, depth);
        }
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root, 1);
        return res;
    }
};