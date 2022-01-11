class Solution {
   public:
    void matchPairs(char nuts[], char bolts[], int n) {
        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};