class Solution {
private:
    unordered_map<int, int> map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = inorder.size();
        if (len == 0) return nullptr;
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return _build(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* _build(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);
        if (pre_start == pre_end) return root;

        int idx_of_root_inorder = map[root_val];
        int left_len = idx_of_root_inorder - in_start;

        if (left_len > 0)
        {
            root->left = _build(preorder, inorder, pre_start + 1, pre_start + left_len, in_start, in_start + left_len);
        }
        if (left_len < pre_end - pre_start)
        {
            root->right = _build(preorder, inorder, pre_start + left_len + 1, pre_end, idx_of_root_inorder + 1, in_end);
        }
        return root;
    }
};


