class Pair {
   public:
    int val;
    int row;
    int idx;

    Pair() {
        val = 0;
        row = 0;
        idx = 0;
    }
};

class compare {
   public:
    bool operator()(Pair& a, Pair& b) {
        return a.val > b.val;
    }
};

class Solution {
   public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k) {
        priority_queue<Pair, vector<Pair>, compare> pq;
        int low, high;
        int mx = INT_MIN;
        int range = INT_MAX;

        for (int i = 0; i < k; i++) {
            Pair p;
            p.val = arr[i][0];
            p.row = i;
            p.idx = 0;
            mx = max(mx, p.val);
            pq.push(p);
        }

        while (true) {
            Pair t = pq.top();
            pq.pop();

            int mn = t.val;
            int r = mx - mn;
            if (r < range) {
                low = mn;
                high = mx;
                range = r;
            }

            if (t.idx + 1 >= n) {
                break;
            }

            Pair p;
            p.val = arr[t.row][t.idx + 1];
            p.row = t.row;
            p.idx = t.idx + 1;

            mx = max(mx, p.val);
            pq.push(p);
        }

        return {low, high};
    }
};