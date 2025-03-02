class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1; // If both are equal, result is 1

        bool sign = (dividend < 0) ^ (divisor < 0); // Determine sign using XOR

        // Use long long to avoid overflow when taking abs(INT_MIN)
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1) && (temp << 1) > 0) { // Prevent left shift overflow
                temp <<= 1;
                multiple <<= 1;
            }
            quotient += multiple;
            n -= temp;
        }

        if (sign) quotient = -quotient;

        // Handle overflow cases
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return quotient;
    }
};
