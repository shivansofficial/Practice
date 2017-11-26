#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>
using namespace std;
#define endl '\n'
typedef struct node
{
  int data;
  int liss;
  node * left,*right;
}node;
node * new_node(int d)
{
  node * temp = new node;
  temp->data=d;
  temp->liss=-1;
  temp->left=temp->right=NULL;
  return temp;
}
node * convert_arr_tree(node * root,vector<int> a,int i)
{
  if(i>a.size()-1 || a[i]==0)
    return NULL;
  if(!root)
    root=new_node(a[i]);
  root->left=convert_arr_tree(root->left,a,2*i+1);
  root->right=convert_arr_tree(root->right,a,2*i+2);
  return root;
}
int liss(node * root)
{
  if(!root)
    return 0;
  if(root->liss!=-1)
    return root->liss;
  if(root->left==NULL && root->right==NULL)
    return root->liss=1;

  int liss_excl=liss(root->left)+liss(root->right);

  int liss_incl=1;
  if(root->left)
        liss_incl+=liss(root->left->left)+liss(root->left->right);
  if(root->right)
        liss_incl+=liss(root->right->left)+liss(root->right->right);

  root->liss=max(liss_incl,liss_excl);
  return root->liss;
}
void pre(node * root)
{
  if(!root)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  node * root=new_node(a[0]);
  root=convert_arr_tree(root,a,0);
  pre(root);
  cout<<endl;
  cout<<liss(root)<<endl;
  return 0;
}
