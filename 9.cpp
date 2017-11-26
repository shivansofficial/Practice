#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define endl '\n'

void kth_small(vector<int> a , int i,int k,int &j,int &ans )
{
  if(i>a.size()-1)
    return ;
  kth_small(a,2*i+1,k,j,ans);
  if(++j==k)
    ans=a[i];
  kth_small(a,2*i+2,k,j,ans);
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
  int j=0,ans=0;
  kth_small(a,0,k,j,ans);
  cout<<ans<<endl;
  return 0;
}
