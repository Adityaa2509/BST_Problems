//Approach - 1 ==> Using the propertry of inorder

/*
Approach - 2 ==> cheching whether each node lies into its range or not
                   root starting from range (INT_MIN,INT_MAX)
                   for left range will be (INT_MIN,curr_root->data)
                   for right range will be (curr_root->data ,INT-MAX)
                   as well as each subtree needs to be bst
*/
/*
To submmit on Leetcode use LONG_MAX and LONG_MIN as value of nodes can be upto long long 
*/

//Solution for Approach -1 Begins

class Solution {
public:
    void in(TreeNode* root,vector<int> & ino)
    {
        if(root == NULL)
            return ;
        in(root->left,ino);
        ino.push_back(root->val);
        in(root->right,ino);
    }
    bool isSorted(vector<int> v)
    {
        int size= v.size();
        for(int i=0;i<size-1;i++)
        {
            if(v[i]>=v[i+1])
                return false;
            }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        //return solve(root,INT_MIN,INT_MAX);
        vector<int> v;
        in(root,v);
        if(isSorted(v))
            return true;
        return false;
    }
};



//Solution for approach-2 Begins
class Solution {
public:
bool solve(TreeNode* root,long long mini,long long maxi)
{
    if(root == NULL)return true;
   
    if(root->val>mini && root->val<maxi)
    {
        bool lefti = solve(root->left,mini,root->val);
        bool righti = solve(root->right,root->val,maxi);
        return (lefti && righti);
    }
    return false;
}
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};

