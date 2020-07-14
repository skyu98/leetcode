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
        res.push_back(r->val);
        solve(r->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        cout << res.size() << endl;
        return res;
    }
};

