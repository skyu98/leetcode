class Solution {
public:
    bool solve(TreeNode* root, long long min_val, long long max_val){
        if(!root) return true;
        if(root->val <= min_val ||root->val >= max_val) return false;
        return solve(root->left, min_val, root->val) && solve(root->right, root->val, max_val);
    }
    
    bool isValidBST(TreeNode* root) {
        long long max = LONG_MAX;
        long long min = LONG_MIN;
        return solve(root, min, max);
    }
};
