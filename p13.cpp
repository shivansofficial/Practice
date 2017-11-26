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

node * new_node(int val)
{
  node * temp = new(node);
  temp->left=NULL;
  temp->right = NULL;
  temp->val = val;
  return temp;
}
node * lca(node*root,int r,int s)
{
  if(root==NULL)
    return NULL;
  if(root->val == r || root->val == s)
    return root;
  node * left  = lca(root->left,r,s);
  node * right = lca(root->right,r,s);
  if(left && right)
    return root;
  if(left == NULL)
    return right;
  if(right == NULL)
    return left;
}
int main()
{
    node * root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);
    root->right->left = new_node(6);
    root->right->right = new_node(7);
    cout<< lca(root, 4, 5)->val<<endl;
    cout<< lca(root, 4, 6)->val<<endl;
    cout<< lca(root, 3, 4)->val<<endl;
    cout<< lca(root, 2, 4)->val<<endl;
    return 0;
}
