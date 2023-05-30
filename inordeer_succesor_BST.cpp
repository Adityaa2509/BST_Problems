#include<iostream>
#include<queue>
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
        this->left = NULL;
        this->right = NULL;
    }

};
void insert2bst(node*& root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return ;
    }
if(root->data<data)insert2bst(root->right,data);
else insert2bst(root->left,data);
}

void takeInput(node*& root)
{
    cout<<"Enter data for BST"<<endl;
    int data;
    cin>>data;
    while(data!=-1)
    {
        insert2bst(root,data);
        cin>>data;
    }
}
void LOD(node* root)
{
    if(root == NULL)return ;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
    cout<<endl;
}

node* succesor(node* root,int tar)
{
    node* ans = NULL;
    while(root)
    {
        if(root->data>tar)
        {
            ans = root;
            root=root->left;
        }
        else root=root->right;
    }
    return ans;
}

int main()
{
    node* root = NULL;
    takeInput(root);
    LOD(root);

    cout<<"Enter tar";
    int tar;
    cin>>tar;
    node* ans = succesor(root,tar);
    if(ans)cout<<ans->data<<endl;else cout<<"Hai hi nahi"<<endl;
}

















