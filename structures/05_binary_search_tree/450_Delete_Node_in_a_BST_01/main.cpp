class Solution{
public:
    int* Delete(TreeNode* root, int target){

        TreeNode* cur = root, *pre=NULL;
        while(cur! = NULL && cur->val != target)
        {
            pre = cur;
            if(cur->val < target)
            {
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        if(cur == NULL) return -1;

        if(cur->left != NULL && cur->right != NULL)
        {
            TreeNode* min = cur->right, *pre_min = cur;
            while(min->left!=NULL)
            {
                pre_min = min;
                min = min->left;
            }
            cur->val = min->val;
            // 接下来删除min节点
            // 由于min节点一定只有一个或没有子节点，因此可以将min作为cur，
            // 直接使用之后的逻辑进行删除操作
            cur = min;
            pre = pre_min;
        }

        TreeNode* single_child = NULL;
        if(cur->left != NULL) single_child = cur->left;
        else if(cur->right != NULL) single_child = cur->right;

        if(pre == NULL) root = single_child;
        else if(pre->left == cur) pre->left = single_child;
        else pre->right = single_child;
        return 0;
    }
};
