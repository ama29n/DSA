#include <bits/stdc++.h>
using namespace std;

class Manacher {
public:
    vector<int> p;
    void run_manacher(string s) {
        int n = s.size();
        p.assign(n, 1);
        int l = 1, r = 1;
        for(int i = 1; i < n; i++) {
            p[i] = max(0, min(r - i, p[l + r - i]));
            while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    void build(string s) {
        string t = "";
        for(auto it : s) {
            t += string("#") + it;
        }
        t += string("#");
        run_manacher(t);
    }
    // Function to get longest palindrome at each center
    // odd = 0 -> even length string
    // odd = 1 -> cen element will be at the center of odd length string
    int getLongest(int cen, bool odd) {
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }
    // Function to check if a string is palindrome
    bool checkPalindrome(int l, int r) {
        if((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "babbabbabc";
    Manacher m;
    m.build(s);
    cout << m.getLongest(4, 1) << endl;
    cout << m.getLongest(2, 0) << endl;
    cout << (m.checkPalindrome(0, 8) == true ? "True" : "False");
}