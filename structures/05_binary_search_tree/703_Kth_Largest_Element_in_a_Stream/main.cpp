class KthLargest {
 struct TreeNode{
        int val;
        int count; // 用以记录以包括当前节点，左右子树在内。有多少个节点。
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(NULL), right(NULL), count(1) {}
    };
private:
    int idx;
    TreeNode* root;    

    TreeNode* addNums(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        if(val <= root->val)
        {   
            root->count += 1;
            root->left = addNums(root->left, val);
        }
        else
        {
            root->count += 1;
            root->right = addNums(root->right, val);
        }
        return root;
    }

    int findNums(TreeNode* root, int idx){
        int right_count = 0;
        if(root->right) right_count = root->right->count;
        if(idx == (right_count+1)) return root->val;
        if(idx > (right_count+1)) return findNums(root->left, idx-(right_count+1));
        else return findNums(root->right, idx);
    }

public:

    KthLargest(int k, vector<int>& nums): idx(k), root(NULL) {
        for(auto i : nums)
        {
            root = addNums(root, i);
        }
    }
    
    int add(int val) {
        root = addNums(root, val);
        return findNums(root, idx);
    }
};
