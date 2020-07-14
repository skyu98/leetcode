class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        int inorderIndex = 0;
        for(int i = 1; i < preorder.size(); i++){
            int preVal = preorder[i];
            TreeNode* node = st.top();
            // 一直找到最左节点，循环入栈
            if(node->val != inorder[inorderIndex]) {
                TreeNode* newNode = new TreeNode(preVal);
                node->left = newNode;
                st.push(newNode);
            }else { // 当找到最左节点后，在中序中找到根节点，下一节点为其右节点
                while(!st.empty() && st.top()->val == inorder[inorderIndex]) {
                    node = st.top();
                    st.pop();
                    inorderIndex++;
                }
                TreeNode* newNode = new TreeNode(preVal);
                node->right = newNode;
                st.push(newNode);
            }
        }
        return root;
    }
};