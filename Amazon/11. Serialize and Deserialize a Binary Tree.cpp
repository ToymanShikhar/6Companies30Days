class Solution {
   public:
    void helper(Node* root, vector<int>& res) {
        if (root == NULL) {
            res.push_back(-1);
            return;
        }

        res.push_back(root->data);
        helper(root->left, res);
        helper(root->right, res);
        return;
    }

    Node* helper2(vector<int>& v, int& idx) {
        if (v[idx] == -1) {
            idx++;
            return NULL;
        }

        Node* res = new Node(v[idx]);
        idx++;
        res->left = helper2(v, idx);
        res->right = helper2(v, idx);
        return res;
    }

    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int>& A) {
        int idx = 0;
        return helper2(A, idx);
    }
};