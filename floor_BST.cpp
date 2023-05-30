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
        this->right = NULL;
        this->left = NULL;
    }
};
void insert2bst(node* &root,int val)
{
    if(root == NULL)
    {
        root = new node(val);
        return ;
    }
    if(root->data>val)
    {
        insert2bst(root->left,val);
    }
    else insert2bst(root->right,val);
}

void takeinput(node*& root)
{
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
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            node* temp = q.front();q.pop();
            cout<<temp->data <<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cout<<endl;
    }
}
int floor(node* root,int val)
{int ans = -1;
    while(root)
    {
        if(root->data == val)return val;
        else if(root->data<val)
        {
            ans = root->data;
            root=root->right;
        }
        else root = root->left;
    }
return ans;
}
int main()
{
    node* root = NULL;
    takeinput(root);

    LOD(root);

    cout<<"Enter val "<<endl;
    int val;
    cin>>val;
    cout<<floor(root,val);
}







