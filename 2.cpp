#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define endl '\n'
typedef struct node
{
  int data;
  node * left,*right;
}node;
node * new_node(int d)
{
  node * temp=new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
void pre(node * root)
{
  if(!root)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}
node * insert(node * root,int t,int k)
{
  if(!root)
    return new_node(t);

  if(t-k<root->data && t +k>root->data)
    return root;

  if(t <root->data)
    root->left=insert(root->left,t,k);
  else
    root->right=insert(root->right,t,k);

  return root;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  node * root;
  for(int i=0;i<n;i++)
  {
    int t;
    cin>>t;
    root=insert(root,t,k);
  }
  pre(root);
  cout<<endl;
  return 0;
}
