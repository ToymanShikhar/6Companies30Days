class Solution {
   public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> left(N);
        vector<int> right(N);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            while (!st.empty() and arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        for (int i = N - 1; i >= 0; i--) {
            while (!st.empty() and arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = N;
            } else {
                right[i] = st.top();
            }

            st.push(i);
        }

        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (left[i] != -1 and right[i] != N) {
                res.push_back(arr[left[i]]);
                res.push_back(arr[i]);
                res.push_back(arr[right[i]]);
                break;
            }
        }

        return res;
    }
};