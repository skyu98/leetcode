class Solution {
private:
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(depth(root->left) - depth(root->right))<=1) return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
};