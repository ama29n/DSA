#include<bits/stdc++.h>
using namespace std;

// Generate All subsets and then find maximum product
// Exponential

class Solution {
public:
    vector<vector<int>> ans;

    void fn(int idx, vector<int> &nums, vector<int> &helper) {
        if(idx == nums.size()) {
            ans.push_back(helper);
            return;
        } else {
            helper.push_back(nums[idx]);
            fn(idx + 1, nums, helper);
            helper.pop_back();
            fn(idx + 1, nums, helper);
        }
    }

    void subsets(vector<int>& nums) {
        vector<int> helper;
        fn(0, nums, helper);
    }
    
    int maxProduct(vector<int>& nums) {
        subsets(nums);
        int maxProduct = INT_MIN;
        for(auto v : ans) {
            int p = 1;
            for(auto it : v)
                p *= it;
            maxProduct = max(maxProduct, p);
        }
        return maxProduct;
    }
};



// Greedy Solution 

// We can come up with a better solution if we pay attention to the following:

// If there are an odd number of negative numbers, the result is the product of all non-zero numbers except 
// the largest valued negative number.
// If there are an even number of negative numbers, the result is the product of all non-zero numbers.
// If there are zeros and no positive numbers, the result is zero.
// If all numbers are negative, the result is the largest valued number.

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    //Setting variable negative to store maximum valued negative number
    int negative = INT_MIN;
    //Counter variables to store number of zeros and negative numbers
    int countzero = 0, countneg = 0;
    //Initializing product to 1
    int product = 1;

    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i] == 0) {
            //Incrementing zero counter if input is 0
            countzero++;
        } else if(a[i] < 0) {
            //Incrementing negative counter if input is < 0
            countneg++;
            //Updating negative to maximum valued negative number
            negative = max(negative, a[i]);
        }
        //Updating product
        product *= a[i];
    }

    if(countzero == n) {
        // If there are all zeros
        cout << 0;
    } else if(countneg % 2) {
        // If there are odd number of negative numbers
        if(countneg == 1 && countzero > 0 && countzero + countneg == n) {
            //If there is only one negative number and all others are zeros
            cout << 0;
        } else {
            //Result is product of all non-zeros divided by maximum valued negative.
            cout << product / negative;
        }
    } else { 
        cout << product;
    }

    return 0;
}

