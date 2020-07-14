// O(n) space cost 
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        queue<Node*> q;
        q.push(root);
        auto res = root;

        while (!q.empty())
        {
            int size = q.size();
            Node* tmp = NULL;
            for (int i = 0; i < size; i++)
            {
                root = q.front();
                q.pop();
                root->next = tmp;
                tmp = root;
                if (root->right) q.push(root->right);
                if (root->left)  q.push(root->left);
            }
        }
        return res;
    }
};
