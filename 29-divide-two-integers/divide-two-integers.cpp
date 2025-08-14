class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // that was a edge case why?

        // Handle the case where dividend is equal to divisor
        if (dividend == divisor) return 1;

        long long ans = 0;
        long long sign = 1;

        // Determine the sign of the result
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            sign = -1;
        }
        // Convert both dividend and divisor to positive integers
        unsigned long long n = llabs((long long)dividend); long long d = llabs((long long)divisor);
        // Perform the division
        int a = n;cout<<a;
        while (n >= d) {
            long long count = 0;
            while (n > (d << (count + 1)))
                count++;
            n -= d << count;
            ans += 1 << count;
        }

        return sign*ans;
    }
};