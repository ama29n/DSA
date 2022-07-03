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

class diapair
{
public:
    int dia;
    int height;
};

diapair diameter(node *&root)
{
    if (root == NULL)
    {
        diapair d;
        d.height = -1;
        d.dia = 0;
        return d;
    }

    diapair lp = diameter(root->left);
    diapair rp = diameter(root->right);

    diapair mp;

    mp.height = max(lp.height, rp.height) + 1;

    int f = lp.height + rp.height + 2;

    mp.dia = max(f, max(lp.height, rp.height));

    return mp;
}

int main()
{
    int size;
    cin >> size;

    node *root = takeInput();
    diapair dm = diameter(root);
    cout << dm.dia;

    return 0;
}
