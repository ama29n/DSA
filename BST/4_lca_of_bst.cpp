#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

TreeNode *takeInput()
{
    static int index = 0;

    string rootval;

    cin >> rootval;

    if (rootval == "n")
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(stoi(rootval));

    index++;

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

vector<int> path(TreeNode* root, int ele){
    if(root->val == ele){
        vector<int> v;
        v.push_back(root->val);
        return v;
    }
    if(ele < root->val){
        vector<int> v = path(root->left, ele);
            v.push_back(root->val);
            return v;
    }
    if(ele > root->val){
        vector<int> v = path(root->right, ele);
            v.push_back(root->val);
            return v;
    }
    vector<int> empty;
    return empty;
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = takeInput();
    int a, b;
    cin >> a >> b;
    vector<int> v1 = path(root, a);
    vector<int> v2 = path(root, b);

    int i = v1.size()-1;
    int j = v2.size()-1;

    while( i>=0 && j>=0 && v1[i]==v2[j]){
        i--;
        j--;
    }
    for(auto it : v1) cout<<it<<" ";
    cout<<endl;
    for(auto it : v2) cout<<it<<" ";
    cout<<endl;
    cout<<v1[++i];

    return 0;
}

// Input
// 21
// 50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
// 12
// 30

// Output
// 25