#include<bits/stdc++.h>
using namespace std;

bool check(int h, int m, vector<int> &heights){

    int sum = 0;
    for(int i = 0; i < heights.size(); i++){

        if(heights[i] >= h)
        sum += (heights[i] - h);
    }

    if(sum >= m) return true;
    else return false;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> heights(n);
    for(int i = 0; i < n; i++)
    cin >> heights[i];

    sort(heights.begin(), heights.end());

    int beg = heights[0], end = heights[n-1], h;

    while(beg <= end){

        int mid = beg + (end - beg)/2;

        if(check(mid, m, heights)){
            
            h = mid;
            beg = mid + 1;
        }
        else end = mid - 1;
    }
    cout << h;
}