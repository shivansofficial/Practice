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
node * insert(node * root,int tim,int k)
{
  if(root==NULL)
    return new_node(tim);
  if( (tim-k) < root->val && (tim+k) > root->val )
    return root;
  if(tim<root->val)
    root->left = insert(root->left,tim,k);
  if(tim > root->val)
    root->right = insert(root->right,tim,k);
  return root;
}
void ino(node * root)
{
  if(!root)
    return ;
  ino(root->left);
  cout<<root->val;
  ino(root->right);
}
int main()
{
  int n;
  cin>>n;
  node * root = NULL;
  int  tim;
  int k;
  cin>>k;
  for(int i=0;i<n;i++)
    {
      cin>>tim;
      root = insert(root,tim,k);
    }
  ino(root) ;
  return 0;
}
