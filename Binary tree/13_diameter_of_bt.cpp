#include<bits/stdc++.h>
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

void display(node* &root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}


/* how this algorithm is working is that for each node we calculate the left deepest and right deepest distance 
   and then we calculate the diameter which is the sum of the received maximum heights of left and right side and then return 
   the greatest of the 3 values, the right deepest the left deepest or the diamater at the current node.
*/

/* and in speacial case what will happen is that if we get the subnode having the greatest diamaeter, that diameter will 
   keep get returned until other greater diamater is found.
*/   

/* time complexity is O(n^2) */   

int height(node* &root)
{
    if(root==NULL) return 0;
    int h;
    int l = height(root->left);
    int r = height(root->right);
    h = max(l, r);
    h += 1;
    return h;
}

int diameter(node* &root)
{
    if(root==NULL) return 0;
    int l=diameter(root->left);
    int r=diameter(root->right);
    int dia = height(root->left) + height(root->right);
    return max(dia, max(l, r));
}

int main()
{
    int size;
    cin >> size;
    node *root = takeInput();
    int diaa=diameter(root);
    cout<<diaa;
    return 0;
}

