//class Solution {
//public:
//    Node* connect(Node* root) {
//        if(!root || !root->left) return root;
//        root->left->next = root->right;
//        if(root->next) {
//            root->right->next = root->next->left;
//        }
//        connect(root->left);
//        connect(root->right);
//        return root;
//    }
//
//};
class Solution {
public:
    void solve(Node* root) {
        if (root->left == NULL) return;
        root->left->next = root->right;
        if (root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        solve(root->left);
        solve(root->right);
    }

    Node* connect(Node* root) {
        if (root == NULL) return root;
        solve(root);
        return root;
    }
};