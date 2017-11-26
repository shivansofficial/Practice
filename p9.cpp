#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>

using namespace std;

void kth_smallest(node *root,int ans,int &el,int k)
{
  if(root==NULL)
    return ;
  kth_smallest(root->left,ans,el,k);
  if(++ans == k)
    el = root->val;
  kth_smallest(root->right,ans,el,k);
}
int main()
{
  int ans=0;
  int k_el
  int k;
  cin>>k;
  kth_smallest(root,ans,k_el,k);
  return 0;
}
