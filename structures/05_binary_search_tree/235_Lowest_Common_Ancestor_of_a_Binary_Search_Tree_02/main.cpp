class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int small = min(p->val, q->val), big = max(p->val, q->val);
        while(root)
        {
            if(root->val >= small && root->val <= big) return root;
            if(root->val < small) 
            {
                root = root->right;
            }
            else 
            {
                root= root->left;
            }
        }
        return NULL;
    }
};
