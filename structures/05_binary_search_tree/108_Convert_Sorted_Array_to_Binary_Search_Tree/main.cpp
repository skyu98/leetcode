class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _build(nums, 0, nums.size()-1);
    }

private:
    TreeNode* _build(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int mid = (start+end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _build(nums, start, mid -1);
        root->right = _build(nums, mid+1, end);
        return root;
    }
};