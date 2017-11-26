#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
typedef struct node
{
  int data;
  node * left,*right;
}node;
node * new_node (int d)
{
  node * temp = new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
node * convert_arr_tree(node * root,vector<int> a,int i)
{
  if(i>a.size()-1)
    return NULL;
  if(!root)
      root= new_node(a[i]);
  root->left=convert_arr_tree(root->left,a,2*i+1);
  root->right=convert_arr_tree(root->right,a,2*i+2);
  return root;
}
void pre(node * root)
{
  if(!root)
    return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);
}
int max_sum_path(node * root,int & res)
{
  if(!root)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->data;
  int l=max_sum_path(root->left,res);
  int r=max_sum_path(root->right,res);

  int max_single=max(max(l,r)+root->data,root->data);
  int max_top=max(max_single,l+r+root->data);
  if(res<max_top)
    res=max_top;
  return max_single;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  node* root= new_node(a[0]);
  root=convert_arr_tree(root,a,0);
  pre(root);
  cout<<endl;
  int res=INT_MIN;
  max_sum_path(root,res);
  cout<<res<<endl;
  return 0;
}
