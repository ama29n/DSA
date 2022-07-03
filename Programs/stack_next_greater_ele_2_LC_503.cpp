#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{

    stack<int> s;
    int idx = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
            idx = i;
        }
    }

    vector<int> greater(nums.size());
    greater[idx] = -1;
    s.push(nums[idx]);

    for (int i = idx - 1; i >= 0; i--)
    {
        while (s.size() > 0 && nums[i] >= s.top())
            s.pop();

        greater[i] = s.size() == 0 ? -1 : s.top();

        s.push(nums[i]);
    }

    for (int i = nums.size() - 1; i > idx; i--)
    {
        while (s.size() > 0 && nums[i] >= s.top())
            s.pop();

        greater[i] = s.size() == 0 ? -1 : s.top();

        s.push(nums[i]);
    }

    return greater;
}

// We want to find the next greater element in the circular array

int main()
{
    vector<int> nums{1, 2, 4, 3, 1, 3};

    vector<int> ans = nextGreaterElements(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << ans[i] << " ";
    return 0;
}