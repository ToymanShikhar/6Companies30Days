class Solution {
   public:
    unordered_map<Node*, Node*> m;
    unordered_map<Node*, bool> visited;
    vector<Node*> target;

    void dfs(Node* root, int tar) {
        if (root == NULL) {
            return;
        }

        if (root->data == tar) {
            target.push_back(root);
        }
        visited[root] = false;

        if (root->left) {
            m[root->left] = root;
            dfs(root->left, tar);
        }
        if (root->right) {
            m[root->right] = root;
            dfs(root->right, tar);
        }
    }

    int minTime(Node* root, int t) {
        dfs(root, t);
        queue<Node*> q;
        for (auto x : target) {
            q.push(x);
        }

        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* t = q.front();
                q.pop();
                visited[t] = true;
                if (t->left != NULL and visited[t->left] == false) {
                    q.push(t->left);
                }
                if (t->right != NULL and visited[t->right] == false) {
                    q.push(t->right);
                }
                if (m.count(t) and visited[m[t]] == false) {
                    q.push(m[t]);
                }
            }
            ans++;
        }

        return ans;
    }
};