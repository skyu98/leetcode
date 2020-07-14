// recursion
class Solution {
public:
     vector<int> res;

     void solve(TreeNode* root){
         if(root == NULL) return;

         res.push_back(root->val);
         preorderTraversal(root->left);
         preorderTraversal(root->right);
     }

     vector<int> preorderTraversal(TreeNode* root) {
         solve(root);
         return res;
     }
};