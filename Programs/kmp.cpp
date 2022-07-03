#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    string a="aaaa";
    string b="aaaaabaaaa";

    int lps[a.length()];
    lps[0]=0;
    int i=1,len=0;

    while(i<a.length())
    {
        if(a[i]==a[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    int j=0;
    while(i<b.length())
    {
        if(a[j]==b[i])
        {
            i++;
            j++;
        }
        if(j==a.length())
        {
            cout<<"Pattern is found at "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<b.length() && a[j] != b[i]) {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else 
                i++;
        }
    }
    
}