#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int ranks[100000];

void makeSet(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findParent(int node) {
    if(parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent[node]);
}

void makeUnion(int u, int v) {
    int uPar = findParent(u);
    int vPar = findParent(v);

    if(ranks[uPar] < ranks[vPar]) {
        parent[uPar] = vPar;
    } 
    else if(ranks[vPar] < ranks[uPar]) {
        parent[vPar] = uPar;
    } 
    else {
        parent[vPar] = uPar;
        ranks[uPar]++;
    }
}

int main() {
    int n;
    cin >> n;
    makeSet(n);
    while(n--) {
        int u, v;
        cin >> u >> v;
        makeUnion(u, v);
    }

    if(findParent(2) != findParent(3)) 
    cout << "Parents are not same";
    else 
    cout << "Parents are same";

    return 0;
}
