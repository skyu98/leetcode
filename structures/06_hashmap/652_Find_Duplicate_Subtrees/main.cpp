/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> res;
    unordered_map<string, int> map;

    string _getkey(TreeNode* root){
        if(!root) return "#";

        string key = to_string(root->val) + ',' + _getkey(root->left) + ',' + _getkey(root->right);

        if(map[key] == 1)
        {
            res.push_back(root);
            
        }
        ++map[key];
        return key;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return res;
        _getkey(root);
        return res;
    }
};