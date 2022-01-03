class Solution {
   public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int X = 0;
        for (int i = 1; i <= n; i++) {
            X = X ^ i;
        }
        for (int i = 0; i < n; i++) {
            X = X ^ arr[i];
        }
        // X = A^B;

        int i = 0;
        while (true) {
            int mask = 1 << i;
            int num = X & mask;
            if (num > 0) {
                break;
            }
            i++;
        }

        // i will have set bit position

        int set = 0;
        int nset = 0;

        for (int j = 0; j < n; j++) {
            int mask = 1 << i;
            if ((arr[j] & mask) > 0) {
                set = set ^ arr[j];
            } else {
                nset = nset ^ arr[j];
            }
        }

        for (int j = 1; j <= n; j++) {
            int mask = 1 << i;
            if ((j & mask) > 0) {
                set = set ^ j;
            } else {
                nset = nset ^ j;
            }
        }

        int repeating = -1;

        for (int j = 0; j < n; j++) {
            if (arr[j] == set or arr[j] == nset) {
                repeating = arr[j];
            }
        }

        int missing = X ^ repeating;

        int *res = new int[2];
        res[0] = repeating;
        res[1] = missing;

        return res;
    }
};