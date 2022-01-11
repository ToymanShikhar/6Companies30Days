class Solution {
   public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> q;
        vector<int> res;

        int i = 0;
        int j = 0;

        while (j < n) {
            while (!q.empty() and arr[q.back()] < arr[j]) {
                q.pop_back();
            }
            q.push_back(j);

            if (j - i + 1 < k) {
                j++;
            } else {
                int top = q.front();
                res.push_back(arr[top]);
                if (i == top) {
                    q.pop_front();
                }
                i++;
                j++;
            }
        }

        return res;
    }
};