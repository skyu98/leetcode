class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() || !q2.empty())
        {
            TreeNode* left = q1.front();
            TreeNode* right = q2.front();

            if (left != NULL && right == NULL)
            {
                return false;
            }
            if (right != NULL && left == NULL)
            {
                return false;
            }
            if (left != NULL && right != NULL && (left->val != right->val))
            {
                return false;
            }

            q1.pop();
            q2.pop();

            if (left != NULL)
            {
                q1.push(left->left);
                q1.push(left->right);
            }
            if (right != NULL)
            {
                q2.push(right->right);
                q2.push(right->left);
            }
        }
        return true;
    }
};