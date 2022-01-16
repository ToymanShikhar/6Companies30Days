void rotate(int n, int a[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = 0, k = n - 1;
        while (j < k) {
            int temp = a[j][i];
            a[j][i] = a[k][i];
            a[k][i] = temp;
            j++;
            k--;
        }
    }
}