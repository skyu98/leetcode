class Solution {
public: 
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        long long last_val = (long long)INT_MIN -1;
        stack<TreeNode*> s;
        while(!s.empty()|| root)
        {   
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(last_val >= root->val) return false;
            last_val = root->val;
            root= root->right;
        }
        return true;
    }
};
