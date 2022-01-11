class Solution {
   public:
    int longestMountain(vector<int>& arr) {
        int res = 0;

        // flag == 0 means decresing element will be part of answer
        int flag = 1;
        int tempAns = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                if (flag == 0) {
                    res = max(res, tempAns);
                }
                tempAns = 1;
                flag = 1;
                continue;
            }

            if (arr[i] > arr[i - 1] and flag == 1) {
                tempAns++;
            } else if (arr[i] > arr[i - 1] and flag == 0) {
                res = max(res, tempAns);
                tempAns = 2;
                flag = 1;
            } else if (arr[i] < arr[i - 1] and tempAns >= 2) {
                flag = 0;
                tempAns++;
            } else if (arr[i] < arr[i - 1] and flag == 0) {
                tempAns++;
            } else {
                tempAns = 1;
            }
        }

        if (flag == 0) {
            res = max(res, tempAns);
        }

        return res;
    }
};