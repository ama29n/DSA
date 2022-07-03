#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int mid,beg=0,end=n-1;
    int pos;

    while(beg<=end)
    {
        mid=beg+(end-beg)/2;

        if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        {
            pos=a[mid];
            break;
        }

        else if(a[beg]<a[mid])
        beg=mid+1;

        else if(a[beg]>a[mid])
        end=mid-1;

        else if(a[mid]>a[end])
        end=mid-1;
    }

    cout<<pos;
}