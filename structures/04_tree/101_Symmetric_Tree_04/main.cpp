 // recursion
 class Solution {
 public:
     bool solve(TreeNode*l, TreeNode* r){
         if(l == NULL)
         {
             return r == NULL;
         }
         if(r == NULL)
         {
             return false;
         }
         if(l->val != r->val)
         {
             return false;
         }
         return solve(l->left, r->right) && solve(l->right, r->left);
     }

     bool isSymmetric(TreeNode* root) {
         if(root ==NULL) return true; 
         return solve(root->left, root->right);
     }

 };
