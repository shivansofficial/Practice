#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
typedef struct node
{
  int data;
  node * left , * right;
}node;
node * new_node(int d)
{
  node * temp=new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
node * convert(node * root,vector<int> a,int i)
{
  if(i>a.size()-1||a[i]==0)
    return NULL;
  if(!root)
    root=new_node(a[i]);
  root->left=convert(root->left,a,2*i+1);
  root->right=convert(root->right,a,2*i+2);
  return root;
}
void print_k_dist_leaf(node * root,int path[],bool visited[] , int i , int k)
{
  if(!root)
    return;
  path[i]=root->data;
  visited[i]=false;
  i++;
  if(root->left==NULL && root->right==NULL && i-k-1>=0 && visited[i-k-1]==false)
  {
    // cout<<"RUNS---:>";
    cout<<path[i-k-1]<<" ";
    visited[i-k-1]=true;
    return;
  }
  print_k_dist_leaf(root->left,path,visited,i,k);
  print_k_dist_leaf(root->right,path,visited,i,k);
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
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  node * root=new_node(a[0]);
  root=convert(root,a,0);
  pre(root);
  cout<<endl;
  int path[1000]={0};
  bool visited[1000]={false};
  print_k_dist_leaf(root,path,visited,0,k);
  cout<<endl;
  return 0;
}
