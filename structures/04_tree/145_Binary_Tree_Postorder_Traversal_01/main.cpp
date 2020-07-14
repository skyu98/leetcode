// recursion
class Solution {
public:
    vector<int> res;

    void solve(TreeNode* r) {
        if (r == NULL)
        {
            return;
        }
        solve(r->left);
        solve(r->right);
        res.push_back(r->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};