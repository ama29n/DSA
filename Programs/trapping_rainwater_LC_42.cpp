 #include<bits/stdc++.h>
 using namespace std;
 
 int trap(vector<int>& height) {
      
      int n=height.size();
      vector<int> l(n),r(n);
      int max;
      
      max=height[0];
      l[0]=height[0];
      for(int i=1;i<n;i++)
      {
        if(height[i]>max)
        {
          max=height[i];
          l[i]=height[i];
        }
        else l[i]=max;
      }
      
      max=height[n-1];
      r[n-1]=height[n-1];
      for(int i=n-2;i>=0;i--)
      {
        if(height[i]>max)
        {
          max=height[i];
          r[i]=height[i];
        }
        else r[i]=max;
      }
      int water=0;
      for(int i=0;i<n;i++)
      {
        int low=min(l[i],r[i]);
        water+=(low-height[i]);
      }
      return water;
    }


int main()
{
    vector<int> height;
    height={0,1,0,2,1,0,1,3,2,1,2,1};
    // height={4,2,0,3,2,5};
    int water=trap(height);
    cout<<water;
}

