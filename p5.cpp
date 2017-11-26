#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int max_sum_path(node * root,int &maxed)
{
  if(root==NULL)
    return 0;
  int l  = max_sum_path(root->left,maxed);
  int r =  max_sum_path(root->right,maxed);
  int max_single = max(max(l,r) + root->data,root->data);
  int max_top = max(max_single,l+r+root->data);
  maxed = max(maxed,max_top);
  return max_single;
}

node * newNode(int val)
{
  node * temp = new(node);
  temp->left=NULL;
  temp->right = NULL;
  temp->val = val;
  return temp;
}

int main()
{
    node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    int maxed = INT_MIN;
    max_sum_path(root,maxed);
    cout<<maxed;
  return 0;
}
