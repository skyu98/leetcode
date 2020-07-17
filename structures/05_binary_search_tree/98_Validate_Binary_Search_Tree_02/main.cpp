class Solution {
public:
    vector<int> res;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        res.push_back(root->val);
        solve(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        solve(root);
        int size = res.size();
        for(int i=0;i<size-1;++i)
        {   
             int last = res[i];
             int cur = res[i+1];
             cout<< last << endl;
             if(last>=cur) return false;
        }
        return true;
    }
};
