int solve(Node* root, int& target, int& ans) {
    if (root == NULL) {
        return 0;
    }

    int left = solve(root->left, target, ans);
    int right = solve(root->right, target, ans);
    int total = left + right + root->data;

    if (total == target) {
        ans++;
    }

    return total;
}

int countSubtreesWithSumX(Node* root, int X) {
    int ans = 0;
    solve(root, X, ans);
    return ans;
}