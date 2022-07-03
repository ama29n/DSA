#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string a="geeks for geeks";
    string b="geek";
    int n=a.length();
    int m=b.length();
    int q=101;

    int h=1,d=123,p=0,t=0;

    for(int i=0;i<m-1;i++)
    h=(h*d)%q;

    for(int i=0;i<m;i++)
    {
        p=(p*d + b[i])%q;
        t=(t*d + a[i])%q;
    }

    int i=0,j;
    while(i<=n-m)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(a[i+j]!=b[j])
                break;
            }

            if(j==m)
            cout<<"Pattern is found at "<<i<<endl;
        }
        if(i<=n-m)
        {
            t=(d*(t-a[i]*h) + a[i+m])%q;
            i++;

            if(t<q)
            t=t+q;
        }
    }
    

}