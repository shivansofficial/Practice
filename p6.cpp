#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

typedef struct node {
  struct node * left;
  struct node * right;
  int val;
}node;

int max_sum_path_leaves(node * root,int &maxed)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->val;
  int left  = max_sum_path_leaves(root->left,maxed);
  int right = max_sum_path_leaves(root->right,maxed);
  if(root->left && root->right)
  {
    maxed = max(maxed,left+right+root->val);
    return max(left,right) + root->val;
  }
  if(root->left==NULL)
    return right+root->val;
  else
    return left+root->val;
}

int main()
{

  return 0;
}
