class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->left == NULL && root->right == NULL) return sum == root->val;

        queue<TreeNode*> q;
        queue<int> num;
        q.push(root);
        num.push(sum - root->val);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto cur = q.front();
                auto sum = num.front();
                q.pop();
                num.pop();
                if (cur->left == NULL && cur->right == NULL && sum == 0) return true;
                if (cur->left != NULL)
                {
                    q.push(cur->left);
                    num.push(sum - cur->left->val);

                }
                if (cur->right != NULL)
                {
                    q.push(cur->right);
                    num.push(sum - cur->right->val);

                }
            }
        }
        return false;
    }
};