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

void klevelDeep(node *&root, int k)
{
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    if (root->left != NULL)
        klevelDeep(root->left, k - 1);
    if (root->right != NULL)
        klevelDeep(root->right, k - 1);

}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();
    int k;
    cin >> k;

    klevelDeep(root, k);
    return 0;
}