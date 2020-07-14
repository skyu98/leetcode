class Solution {
private:
    unordered_map<int, int> map;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if (len == 0) return nullptr;
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return _build(postorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* _build(vector<int>& postorder, vector<int>& inorder, int post_start, int post_end, int in_start, int in_end) {
        int root_val = postorder[post_end];
        cout << post_end << " " << root_val << endl;
        TreeNode* root = new TreeNode(root_val);
        if (post_start == post_end) return root;

        int idx_of_root_inorder = map[root_val];
        int left_len = idx_of_root_inorder - in_start;

        if (left_len > 0)
        {
            root->left = _build(postorder, inorder, post_start, post_start + left_len - 1, in_start, in_start + left_len);
        }
        if (left_len < post_end - post_start)
        {
            root->right = _build(postorder, inorder, post_start + left_len, post_end - 1, idx_of_root_inorder + 1, in_end);
        }
        return root;
    }
};
