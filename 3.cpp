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
node * new_node(int d)
{
  node * temp=new node;
  temp->data=d;
  temp->left=temp->right=NULL;
  return temp;
}
node * convert_arr_bst(node * root,vector<int>a,int i)
{
  if(i>a.size()-1||a[i]==0)
    return NULL;
  if(!root)
    root=new_node(a[i]);

    root->left=convert_arr_bst(root->left,a,2*i+1);
    root->right=convert_arr_bst(root->right,a,2*i+2);
  return root;
}
void inorder(node * root,vector<int>&in,int &i)
{
  if(!root)
    return;
  inorder(root->left,in,i);
  in[i++]=root->data;
  inorder(root->right,in,i);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,sum;
  cin>>n;
  vector<int>a(n);

  for(int i=0;i<n;i++)
    cin>>a[i];

  node * root=new_node(a[0]);
  root=convert_arr_bst(root,a,0);
  vector<int>in(n);
  int i=0;
  inorder(root,in,i);
  cin>>sum;
  for(int i=0,j=n-1;i<j;)
  {
    if(in[i]+in[j]==sum)
      {
        cout<<"Pair :"<<in[i]<<" "<<in[j]<<endl;
        break;
      }
    else if(in[i]+in[j]<sum)
      i++;
    else
      j--;
    }
  
  return 0;
}
