class Solution {
private:
    map<TreeNode*, int> map;
    int flag;

    int depth(TreeNode* root){
        if(!root) return 0;
        int res = max(depth(root->left), depth(root->right))+1;
        map[root] = res;
        return res;
    }
    
public:
    void fillMap(TreeNode* root){
        int res = depth(root);
        flag = 1;
        return;
    }
    bool isBalanced(TreeNode* root) {
        if(flag != 1) fillMap(root);
        if(!root) return true;
        if(abs(map[root->left]-map[root->right])<=1) return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
};