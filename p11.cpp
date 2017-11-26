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

int max_liss(node * root)
{
  if(root==NULL)
    return 0;
  int siz_excl = max_liss(root->left) + max_liss(root->right);
  int siz_incl = 1;
  if(root->left!=NULL)
    siz_incl += max_liss(root->left->left) + max_liss(root->left->right);
  if(root->right !=NULL)
    siz_incl += max_liss(root->right->left) + max_liss(root->right->right);
  return max(siz_excl,siz_incl);
}
int main()
{
    node *root         = new_node(20);
    root->left                = new_node(8);
    root->left->left          = new_node(4);
    root->left->right         = new_node(12);
    root->left->right->left   = new_node(10);
    root->left->right->right  = new_node(14);
    root->right               = new_node(22);
    root->right->right        = new_node(25);
  cout<<max_liss(root)<<endl;
  return 0;
}
