class Node {
   public:
    bool end;
    Node** arr;

    Node() {
        end = false;
        arr = new Node*[26];
        for (int i = 0; i < 26; i++) {
            arr[i] = NULL;
        }
    }
};

class Solution {
   public:
    void solve(Node* curr, string pre, vector<string>& ans) {
        if (curr->end == true) {
            ans.push_back(pre);
        }

        for (int i = 0; i < 26; i++) {
            if (curr->arr[i] != NULL) {
                char ch = i + 'a';
                solve(curr->arr[i], pre + ch, ans);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Node* root = new Node;
        for (int i = 0; i < n; i++) {
            string sp = contact[i];
            Node* curr = root;
            for (int j = 0; j < sp.length(); j++) {
                int idx = sp[j] - 'a';
                if (curr->arr[idx] == NULL) {
                    curr->arr[idx] = new Node;
                }
                curr = curr->arr[idx];
            }
            curr->end = true;
        }

        vector<vector<string>> res;
        Node* curr = root;
        string pre;
        int flag = 0;
        for (int i = 0; i < s.length(); i++) {
            pre += s[i];
            int idx = s[i] - 'a';
            vector<string> ans;
            if (curr->arr[idx] != NULL and flag == 0) {
                curr = curr->arr[idx];
                solve(curr, pre, ans);
            }
            if (ans.size() == 0) {
                ans.push_back("0");
                flag = 1;
            }
            res.push_back(ans);
        }

        return res;
    }
};