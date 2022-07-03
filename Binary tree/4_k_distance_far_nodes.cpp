#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~node()
    {
        delete left;
        delete right;
    }
};

node *takeInput()
{
    static int index = 0;

    string rootData;

    cin >> rootData;

    if (rootData == "n")
    {
        return NULL;
    }

    node *root = new node(stoi(rootData));

    index++;

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

void display(node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

vector<node*> find_rootpath(node *&root, int t)
{

    if (root->data == t)
    {
        vector<node*> answer;
        answer.push_back(root);
        return answer;
    }

    if (root->left != NULL)
    {
        vector<node*> check = find_rootpath(root->left, t);
        if (check.size() > 0)
        {
            check.push_back(root);
            return check;
        }
    }

    if (root->right != NULL)
    {
        vector<node*> check2 = find_rootpath(root->right, t);
        if (check2.size() > 0)
        {
            check2.push_back(root);
            return check2;
        }
    }

    vector<node*> empty;
    return empty;
}

void klevelDeep(node *&root, int k, int block)
{
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    if (root->left != NULL && root->left->data != block)
        klevelDeep(root->left, k - 1, block);
    if (root->right != NULL && root->right->data != block)
        klevelDeep(root->right, k - 1, block);

    return;
}

void kdistanceNodes(node *&root, int val, int k)
{
    vector<node*> path = find_rootpath(root, val);

    klevelDeep(path[0], k, 0);

    for (int i = 1; i < path.size() && i <= k; i++)
    {
        klevelDeep(path[i], k - i, path[i - 1]->data);
    } 
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();

    int val, key;
    cin >> val >> key;

    kdistanceNodes(root, val, key);

    return 0;
}