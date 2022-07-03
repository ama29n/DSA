#include<iostream>
using namespace std;

bool isvalid(int a[], int n, int k,int mid)
{
   int count=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]>=mid)
       count++;
   }

   if(count==k)
   return true;
   else return false;
}

int main()
{
    int n;                                              
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int end=a[0],beg=a[0],mid,pos,k;
    cin>>k;
    for(int i=0;i<n;i++)
    {   
        if(a[i]>end)
        end=a[i];
        
        if(a[i]<beg)
        beg=a[i];
    }

    end=end-beg;


    while(beg<=end)
    {
        mid=beg+(end-beg)/2;

        if(isvalid(a,n,k,mid)==1)
        {
            end=mid-1;
            pos=mid;
        }
        else{
            beg=mid+1;
        }
    }

    cout<<pos;

}