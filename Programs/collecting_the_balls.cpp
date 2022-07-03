// Collecting the balls

// There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the container. At each step, 
// Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the remaining balls. Suppose there are 29 balls at the moment 
// and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls 
// remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will last until the 
// container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from 
// the container.

// Input Format:
// The first line of input will contain T (number of test cases).
// The next n lines of input contain a single integer ‘n’.
// Output Format:
// For every test case print a single integer denoting the minimal value of ‘k’ in a newline.

// Constraints:
// 1 <= T <= 10^4
// 1 <= n <= 10^18
// Time Limit: 1 second

// Sample Input:
// 1
// 68

// Sample Output:
// 3

// Explanation:
// 68-3 = 65; 65/10 = 6; 65-6 = 59
// 59-3 = 56; 56/10 = 5; 56-5 = 51
// 51-3 = 48; 48/10 = 4; 48-4 = 44
// 44-3 = 41; 41/10 = 4; 41-4 = 37
// …..
// …..
// …..
// 6-3 = 3; 3/10 = 0; 3-0 = 3
// 3-3 = 0; 0/10 = 0; 0-0 = 0


#include<bits/stdc++.h>
using namespace std;

bool check(int k, int balls){

    int singh = 0, sharma = 0, n = balls;
    
    while(n > k){

        sharma += k;
        n -= k;
        int h = n/10;
        singh += h;
        n -= h;
    }
    sharma += n;
    
    if(sharma >= balls/2) return true;
    else return false;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int beg = 0, end = n, ans = 0;

        while(beg <= end){

            int mid = beg + (end - beg)/2;

            if(check(mid,n)){
                ans = mid;
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        cout << ans;
    }
}

