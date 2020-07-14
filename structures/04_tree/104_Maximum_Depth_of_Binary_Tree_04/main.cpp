// iteration 2 (dfs)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int depth = 0;
        stack<pair<TreeNode*, int>> s;

        pair<TreeNode*, int> tmp(root, 1);
        s.push(tmp);

        while (!s.empty())
        {
            tmp = s.top();
            s.pop();
            root = tmp.first;
            int cur_depth = tmp.second;
            if (root)
            {
                depth = max(depth, cur_depth);
                //tmp = {root->left, cur_depth+1};
                tmp = make_pair(root->left, cur_depth + 1);
                s.push(tmp);
                //tmp = {root->right, cur_depth+1};
                tmp = make_pair(root->right, cur_depth + 1);
                s.push(tmp);
            }
        }
        return depth;
    }
};