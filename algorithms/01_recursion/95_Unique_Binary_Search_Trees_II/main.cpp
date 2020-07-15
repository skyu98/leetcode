class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        {
            vector<TreeNode*> all_trees;
            return all_trees;
        }
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> all_trees;
        if(start>end) {
            all_trees.push_back(nullptr);
            return all_trees;
        }

        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = generate(start, i-1);
            vector<TreeNode*> right = generate(i+1, end);
            for(auto left_tree: left)
            {
                for(auto right_tree : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
};
