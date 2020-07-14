 // iteration
 class Solution{
 public:
     int maxDepth(TreeNode* root){
         if(root == NULL) return 0;

         int height = 0;
         queue<TreeNode*> q;

         q.push(root);
         while(!q.empty())
         {
             height++;
             int size = q.size();
             for(int i=0;i<size;i++)
             {
                 TreeNode* cur = q.front();
                 q.pop();
                 if(cur->left) q.push(cur->left);
                 if(cur->right) q.push(cur->right);
             }
         }
         return height;
     }
 };