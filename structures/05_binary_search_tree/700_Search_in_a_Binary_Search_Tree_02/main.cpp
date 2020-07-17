class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->val == val) return cur;
            if(cur->val < val) cur = cur->right;
            else cur = cur->left;
        }
        return nullptr;
    }
};
