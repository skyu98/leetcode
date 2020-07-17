class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* save = root;
    
        while(root)
        {
            if(root->val < val) 
            {
                if(root->right==NULL)
                {   
                    TreeNode* target = new TreeNode(val);
                    root->right = target;
                    return save;
                }
                else root = root->right;
            }
            else
            {
            if(root->left==NULL)
                {   
                    TreeNode* target = new TreeNode(val);
                    root->left = target;
                    return save;
                }
                else root = root->left;
            }
        }
        return new TreeNode(val);
    }
};
