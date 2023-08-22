 #include <bits/stdc++.h>
using namespace std;

int main () {
    int n = 6;
    // 4 5 5 7 8 25
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    cin >> v[i];

    // Lower bound
    // It will return an interator to the position where it finds the given element 
    // If in case the element is not found the next greater element will be returned 
    // If lower bound is not present we get the it = v.end()
    
    auto it1 = lower_bound(v.begin(), v.end(), 7);
    int ele1 = *lower_bound(v.begin(), v.end(), 7);

    // Both will give that particular element 
    cout << *it1 << " " << ele1 << endl;

    // To get the index of that element 
    cout << it1 - v.begin() << endl;


    // Upper bound 
    // It will return an interator to the next greater element's position
    // If upper bound is not present we get the it = v.end()

    auto it2 = upper_bound(v.begin(), v.end(), 7);
    int ele2 = *upper_bound(v.begin(), v.end(), 7);

    cout << *it2 << " " << ele2 << endl;
    cout << it2 - v.begin() << endl;



    // Stl methods for arrays 
    // Here these methods return the pointer

    // int a[n];
    // sort(a, a + n);
    // int *ptr = lower_bound(a, a + n, 7);
    // int *ptr = upper_bound(a, a + n, 7);
    // if(ptr == a + n)
    //     cout << "No element found";
    // cout << *ptr;



    // Lower bound and upper bound for set and maps 
    // These methods are of log n complexity

    // set<int> s;
    // map<int> m;
    // int ele3, ele4;
    // auto it3 = s.upper_bound(ele3);
    // auto it4 = s.lower_bound(ele4);



    // Vector Methods 

    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());

    // 0 in this is the initial sum
    int sum = accumulate(v.begin(), v.end(), 0);

    // To count the frequency of an element 
    int ct = count(v.begin(), v.end(), 5);

    // To find an element, you will get an iterator 
    auto it5 = find(v.begin(), v.end(), 25);
    if(it5 == v.end())
        cout << "Element not found" << endl;
    else cout << "Element found" << endl;

    cout << min << " " << max << " " << sum << " " << ct;
}