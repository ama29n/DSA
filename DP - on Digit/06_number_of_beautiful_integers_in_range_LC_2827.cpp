#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/

class Solution {
public:
    int k;
    int dp[11][11][2][21][11][2];
    // The find function explores combinations of digits to count beautiful numbers
    // idx: Current index in the digits array
    // tight: Indicates if formed number must match exactly the digits of x
    // sum: The remainder of the number formed so far when divided by k
    // odd: Count of odd digits in the number formed so far
    // isZero: Flag indicating whether a non-zero digit has been encountered
    // actual_length: The length of the number formed so far (ignoring leading zeros)
    // digits: The vector of digits of the number
    int find(int idx, bool tight, int sum, int odd, bool isZero, int actual_length, string &digits) {
        // Base case: If we've formed the entire number, check if it's beautiful
        if(idx == digits.size()) {
            return (((actual_length - odd) == odd) && (sum == 0) && !isZero) ? 1 : 0;
        }

        if(dp[idx][actual_length][tight][sum][odd][isZero] != -1)
            return dp[idx][actual_length][tight][sum][odd][isZero];

        int limit = 9, res = 0;
        if(tight) limit = (digits[idx] - '0'); // Determine the limit for the digit based on tightness

        for(int dig = 0; dig <= limit; dig++) {
            res += find(idx + 1, (tight & (dig == limit)), (10 * sum + dig) % k, odd + (dig % 2),
                        (isZero & (dig == 0)), (isZero & (dig == 0)) ? 0 : actual_length + 1, digits);
            // Recurse to the next digit position with updated states
        }
        return (dp[idx][actual_length][tight][sum][odd][isZero] = res); // Return the sum of all possibilities
    }
    int go(int x) {
        memset(dp, -1, sizeof(dp));
        string digits = to_string(x);
        return find(0, true, 0, 0, true, 0, digits); // Start finding beautiful numbers
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        k = K;
        return go(high) - go(low - 1);
    }
};

// Time complexity: O(N^3*K) where N is the number of digits