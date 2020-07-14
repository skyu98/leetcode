// iteration
class Solution {
public:
    vector<int> res;

    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return res;
        }
        stack<TreeNode*> s;

        while (root != NULL || !s.empty())
        {
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }

            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);

            root = cur->right;
        }
        return res;
    }
};