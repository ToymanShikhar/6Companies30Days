class compare {
   public:
    bool operator()(string& a, string& b) {
        int lena = a.length();
        int lenb = b.length();

        if (lena != lenb)
            return lena > lenb;
        return a > b;
    }
};

class Solution {
   public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, compare> pq;

        for (auto s : nums) {
            pq.push(s);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};