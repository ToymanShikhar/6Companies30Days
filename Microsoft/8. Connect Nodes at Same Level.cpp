class Solution {
   public:
    //Function to connect nodes at same level.
    void connect(Node* root) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            Node* last = NULL;
            while (sz--) {
                Node* currNode = q.front();
                q.pop();
                currNode->nextRight = last;
                last = currNode;
                if (currNode->right) {
                    q.push(currNode->right);
                }
                if (currNode->left) {
                    q.push(currNode->left);
                }
            }
        }

        return;
    }
};