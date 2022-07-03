#include<bits/stdc++.h>
using namespace std;

string nextPermutation(string str) // Function to calculate the next permutation of the number
{
    int n = str.length();
    int idx1 = -1;

    for (int i = n - 2; i >= 0; i--)
        if (str[i + 1] > str[i])
        {
            idx1 = i;
            break;
        }
    if (idx1 == -1)  return str; // If there is no permutation possible which is greater than the current one, return same string
	
    int pos = idx1, idx2 = 0;

    for (int i = n - 1; i > idx1; i--)
        if (str[i] > str[idx1])
        {
            idx2 = i;
            break;
        }

    swap(str[idx1], str[idx2]);
    int i = idx1 + 1, j = n - 1;

    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

int nextGreaterElement(int num)
{
    string str = to_string(num);
    str = nextPermutation(str);
    auto ans = stol(str);
    return (ans > INT_MAX || ans <= num) ? -1 : (int)ans;
}