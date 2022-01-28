class Solution {
   public:
    int convertInt(string s) {
        stringstream ss(s);
        int a;
        ss >> a;
        return a;
    }

    int compareVersion(string version1, string version2) {
        replace(version1.begin(), version1.end(), '.', ' ');
        replace(version2.begin(), version2.end(), '.', ' ');
        stringstream ss1(version1);
        stringstream ss2(version2);
        vector<int> v1;
        vector<int> v2;
        string temp;
        while (ss1 >> temp) {
            int x = convertInt(temp);
            v1.push_back(x);
        }
        while (ss2 >> temp) {
            int x = convertInt(temp);
            v2.push_back(x);
        }

        int i = 0;
        while (i < v1.size() or i < v2.size()) {
            int first, second;
            if (i < v1.size()) {
                first = v1[i];
            } else {
                first = 0;
            }

            if (i < v2.size()) {
                second = v2[i];
            } else {
                second = 0;
            }

            if (first < second) {
                return -1;
            } else if (first > second) {
                return 1;
            }

            i++;
        }

        return 0;
    }
};