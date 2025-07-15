int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int s = 0, e = x/2;
    int ans = 0;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        long long sq = 1LL * mid * mid;

        if (sq == x) return mid;
        else if (sq < x) {
            ans = mid;      // potential answer
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}