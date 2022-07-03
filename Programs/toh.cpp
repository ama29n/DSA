#include<bits/stdc++.h>
using namespace std;

void toh( int n , char source, char destination , char helper)
{
    if(n==0)
    return;

    toh(n-1,source,helper,destination);
    cout<<"Move from "<<source<<" to "<<destination<<"\n";
    toh(n-1,helper,destination,source);

}

int main()
{
    toh(3,'a','b','c');
}