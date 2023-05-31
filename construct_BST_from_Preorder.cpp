#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
void construct_BST(vector<int>pre,int &i,node*& root,int maxi)
{
    if(pre[i]>maxi || i == pre.size())return ;
    root = new node(pre[i++]);
    construct_BST(pre,i,root->left,root->data);
    construct_BST(pre,i,root->right,maxi);
}
void LOD(node* root)
{
    if(root == NULL)return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    
    vector<int>preorder(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    int i=0;
    node* root = NULL;
    construct_BST(preorder,i,root,INT_MAX);

    LOD(root);
}
