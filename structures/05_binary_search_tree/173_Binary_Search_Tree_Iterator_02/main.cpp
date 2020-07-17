class BSTIterator {
private:
vector<int> res;
int count = 0;
public:
    BSTIterator(TreeNode* root) {
        _inorder(root);
    }

    void _inorder(TreeNode* root)
    {
        if(!root) return;
        _inorder(root->left);
        res.push_back(root->val);
        _inorder(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        int cur_min = res[count++];
        return  cur_min;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return count < res.size();
    }
};

