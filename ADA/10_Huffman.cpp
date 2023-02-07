#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    char symbol;
    int fre;
    Node *left;
    Node *right;
    Node() {
        symbol = '$'; fre = 0; right = NULL; left = NULL;
    }
    Node(char s, int f) {
        symbol = s; fre = f; left = NULL; right = NULL;
    }
    Node(int f) {
        symbol = '$'; fre = f; left = NULL; right = NULL;
    }
};

typedef pair<int, Node*> p;

void traverse(Node *root, string str) {
    if(!root) {
        return;
    }
    if(!root->left && !root->right) {
        cout << root->symbol << " " << str << endl;
        return;
    }
    traverse(root->left, str + "0");
    traverse(root->right, str + "1");
}

int main() {
    priority_queue<p, vector<p>, greater<p>> q;
    Node *n1 = new Node('a', 5); q.push({5, n1});
    Node *n2 = new Node('b', 9); q.push({9, n2});
    Node *n3 = new Node('c', 12); q.push({12, n3});
    Node *n4 = new Node('d', 13); q.push({13, n4});
    Node *n5 = new Node('e', 16); q.push({16, n5});
    Node *n6 = new Node('f', 45); q.push({45, n6});
    while(q.size() != 1) {
        Node *x = q.top().second; q.pop();
        Node *y = q.top().second; q.pop();
        int fre = x->fre + y->fre;
        Node *z = new Node(fre);
        z->left = x; z->right = y;
        q.push({fre, z});
    }
    traverse(q.top().second, "");
}