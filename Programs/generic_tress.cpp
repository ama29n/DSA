#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> child;

    node(int val)
    {
       data = val;     
    }
};

void takeInput(node* &root)
{
    int input[]={10 ,20 ,50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int size=sizeof(input)/sizeof(int);

    root = NULL;

    stack<node *> nodes;

    for (int index = 0; index < size; index++)
    {
        if (input[index] == -1)
        {
            nodes.pop();
        }

        else
        {
            node* newNode = new node(input[index]);

            if (nodes.size() == 0)
            {
                root = newNode;
            }

            else
            {
                nodes.top()->child.push_back(newNode);
            }

            nodes.push(newNode);
        }
    }

}
void print(node*&root)
{
   queue<node*> q;

   
}

void print_linewise( node*& root)
{
    queue<node*> q;
    q.push(root);
    
    queue<node*> cq;
    
    while(q.size()!=0)
    {
        cout<<q.front()->data<<" ";
        node* temp= q.front();
        q.pop();
        
        for(auto ch:temp->child)
        {
            cq.push(ch);
        }
        
        if(q.size()==0)
        {
            cout<<endl;
            while(cq.size()>0)
            {
                q.push(cq.front());
                cq.pop();
            }
        }
    }
}

void mirror(node *&root)
{

    reverse(root->child.begin(),root->child.end());
    for(auto ch:root->child)
    {
        mirror(ch);
    }

    
}


void zigzag(node*&root)
{

}

int size(node* &root)
{
    int s=0;

    for( auto ch: root->child)
    {
        int sum=size(ch);
        s=s+sum;
    }

    s=s+1;
    return s;
}

void remove_leaf(node* &root)
{
    for(int i=0;i<root->child.size();)
    {
        if(root->child[i]->child.size()==0)
        {
            delete root->child[i];
            root->child.erase(root->child.begin()+i);
        }
        else i++;
    }

    for(auto ch:root->child)
    remove_leaf(ch);
}

bool find(node* &root, int target)
{
    if(root->data==target)
    return true;

    for(auto ch:root->child)
    {
        bool res=find(ch,target);
        if(res)
        return true;
    }

    return false;
}



void display2(node* &root)
{
    cout<<root->data<<" -> ";
    for(auto ch:root->child)
    {
        cout<<ch->data<<", ";
    }
    cout<<".";
    cout<<endl;
    for(auto ch:root->child)
    display2(ch);
}

vector<int> findpath(node* &root, int target)
{
    if(root->data==target)
    {
        vector<int> v;
        v.push_back(root->data);
        return v;
    }

    for(auto ch: root->child)
    {
        vector<int> ans=findpath(ch,target);
        if(ans.size()>0)
        {
            ans.push_back(root->data);
            return ans;
        }
    }

    vector<int> x;
    return x;
}

bool check_symmetric(node* &root1, node* &root2)
{
    if(root1->child.size()!=root2->child.size())
    {
        return false;
    }

    for(int i=0; i<root1->child.size();i++)
    {
        node* ch1=root1->child[i];
        node* ch2=root2->child[i];

        bool istrue=check_symmetric(ch1,ch2);
        if(istrue==false)
        {
            return false;
        }
    }

    return true;
}



bool check_mirror(node* &root1, node* &root2)
{
    if(root1->child.size()!=root2->child.size())
    {
        return false;
    }

    for(int i=0 , j=root2->child.size()-1; i<root1->child.size() && j>=0;i++,j--)
    {
        node* ch1=root1->child[i];
        node* ch2=root2->child[j];

        bool istrue=check_mirror(ch1,ch2);
        if(istrue==false)
        {
            return false;
        }
    }

    return true;
}

void self_symmetric(node *&root)
{
    bool check=check_mirror(root,root);
    if(check) cout<<"true";
    else cout<<"false";
}


int pre;
int suc;
int s=0;

void pre_suc(node* &root, int n)
{
    if(root->data==n)
    {
        s++;
    }
    else if(s==0)
    {
        pre=root->data;
    }
    else if(s==1)
    {
        suc=root->data;
        s++;
    }
    else if(s==2) return;
    
    for(auto ch: root->child)
    pre_suc(ch,n);
}


int c;
int f;

void ceilfloor(node* &root, int n)
{
    if(root->data<n)
    {
        f=max(f,root->data);
    }
    else if(root->data>n)
    {
        c=min(c,root->data);
    }
    
    for(auto ch: root->child)
    ceilfloor(ch,n);
}

int depth;

void height(node* &root, int h)
{
    depth=std::max(depth,h);
    for(auto ch: root->child)
    {
        height(ch,h+1);
    }
    return;
}
int main()
{
    node* root;
    takeInput(root);
    depth=0;
    height(root,0);
    cout<<depth;

}


