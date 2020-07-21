class Solution {
public:
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left != NULL) root = root->left;
        return root->val;
    }    
    
    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right != NULL) root = root->right;
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(!root->left && !root->right) root = NULL;
            else if(root->right)
            {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else if(root->left)
            {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            } 
        }
        return root;    
    }
};
