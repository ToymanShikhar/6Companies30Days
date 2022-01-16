vector<string> generate(int N) {
    vector<string> res;
    for (int i = 1; i <= N; i++) {
        int num = i;
        string tempAns;

        while (num > 0) {
            int bit = num & 1;
            tempAns = to_string(bit) + tempAns;
            num = num >> 1;
        }

        res.push_back(tempAns);
    }

    return res;
}