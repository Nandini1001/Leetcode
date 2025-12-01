class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long left = 0, right = total / n; // max possible time

        while (left < right) {
            long long mid = (left + right + 1) / 2;

            long long sum = 0;
            for (long long b : batteries)
                sum += min(b, mid);

            if (sum >= mid * n)
                left = mid;       // feasible
            else
                right = mid - 1;  // too large
        }
        return left;
    }
};
