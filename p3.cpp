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

node * insert(node * root,int val)
{
  if(root==NULL)
    return new_node(val);
  if(root->val < val)
    root->right = insert(root->right,val);
  if(root->val > val)
    root->left = insert(root->left,val);
  return root;
}
void ino(node * root,vector<int> &arr)
{
  if(!root)
    return ;
  ino(root->left,arr);
  cout<<root->val;
  arr.push_back(root->val);
  ino(root->right,arr);
}

int main()
{
  int n;
  cin>>n;
  node * root = NULL;
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    root = insert(root,temp);
  }
  vector<int> arr;
  ino(root,arr);
  int pair_s;
  cin>>pair_s;
  int start = 0,end = arr.size()-1;
  while(start < end)
  {
    if( arr[start]+ arr[end] > pair_s)
      end--;
    else
      if(arr[start] + arr[end] < pair_s)
        start++;
    else
      {
        cout<<"Found the elements with pair sum "<<pair_s<<" Elements are "<<arr[start]<<"\t"<<arr[end]<<endl;
        break;
      }
  }
  return 0;
}
