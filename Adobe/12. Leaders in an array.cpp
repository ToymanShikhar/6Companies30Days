class Solution {
    //Function to find the leaders in the array.
   public:
    vector<int> leaders(int a[], int n) {
        vector<int> res;
        res.push_back(a[n - 1]);
        int maxi = res[0];

        for (int i = n - 2; i >= 0; i--) {
            if (a[i] >= maxi) {
                res.push_back(a[i]);
                maxi = max(maxi, a[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};