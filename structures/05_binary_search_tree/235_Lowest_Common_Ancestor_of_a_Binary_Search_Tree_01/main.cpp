class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int small = min(p->val, q->val), big = max(p->val, q->val);
        if(root->val >= small && root->val <= big) return root;
        if(root->val < small) return lowestCommonAncestor(root->right, p, q);
        else return lowestCommonAncestor(root->left, p, q);
    }
};

