// iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty())
        {
            auto cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right != NULL)
            {
                s.push(cur->right);
            }
            if (cur->left != NULL)
            {
                s.push(cur->left);
            }
        }
        return res;
    }
};