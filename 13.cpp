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
  node * temp= new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
node * convert_arr_tree(node * root,vector<int> a,int i)
{
  if(i>a.size()-1||a[i]==0)
    return NULL;
  if(!root)
    root=new_node(a[i]);
  root->left=convert_arr_tree(root->left,a,2*i+1);
  root->right=convert_arr_tree(root->right,a,2*i+2);
  return root;
}
node * lca(node * root,int a,int b)
{
  if(!root)
    return NULL;

  if(root->data==a||root->data==b)
    return root;

  node * l_lca=lca(root->left,a,b);
  node * r_lca=lca(root->right,a,b);

  if(l_lca && r_lca)
    return root;

  if(l_lca==NULL)
    return r_lca;
  else
    return l_lca;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  node * root=new_node(arr[0]);
  root=convert_arr_tree(root,arr,0);
  int a,b;
  cin>>a>>b;
  cout<<lca(root,a,b)->data<<endl;
  return 0;
}
