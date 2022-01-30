class Solution {
   public:
    int solve(Node* root) {
        if (root == NULL) {
            return 0;
        }

        int curr = root->data;
        int left = solve(root->left);
        int right = solve(root->right);

        root->data = left + right;

        return left + right + curr;
    }
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node* node) {
        solve(node);
    }
};