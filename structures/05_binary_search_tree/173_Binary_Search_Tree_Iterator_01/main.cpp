class BSTIterator {
private:
stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
        s.pop();
        int cur_min = cur->val; 
        cur = cur->right;
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }
        return  cur_min;
            
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() > 0;
    }
};
