class Solution {
   public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s) {
        int i = 0;
        int j = 0;
        long long sum = 0;
        vector<int> res;

        while (j < n) {
            sum += arr[j];
            if (sum == s) {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            } else if (sum > s) {
                while (sum > s) {
                    sum -= arr[i];
                    i++;
                }
                if (sum == s) {
                    res.push_back(i + 1);
                    res.push_back(j + 1);
                    break;
                }
            }
            j++;
        }

        if (res.size() == 0) {
            res.push_back(-1);
        }

        return res;
    }
};