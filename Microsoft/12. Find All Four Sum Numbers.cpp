class Solution {
   public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i != 0 and arr[i] == arr[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j != i + 1 and arr[j] == arr[j - 1]) {
                    continue;
                }
                int sum = k - arr[i] - arr[j];
                int start = j + 1;
                int end = n - 1;

                while (start < end) {
                    int currSum = arr[start] + arr[end];
                    if (currSum == sum) {
                        res.push_back({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        while (arr[start] == arr[start - 1]) {
                            start++;
                        }
                        end--;
                        while (arr[end] == arr[end + 1]) {
                            end--;
                        }
                    } else if (currSum < sum) {
                        start++;
                        while (arr[start] == arr[start - 1]) {
                            start++;
                        }
                    } else {
                        end--;
                        while (arr[end] == arr[end + 1]) {
                            end--;
                        }
                    }
                }
            }
        }

        return res;
    }
};