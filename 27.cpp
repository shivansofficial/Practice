#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  int max_s=0;
  sort(a.begin(),a.end());
  for(int i=n-1;i>=0;i--)
  {
    if(a[i]-a[i-1]<k)
    {
      max_s+=a[i]+a[i-1];
      --i;
    }
  }
  cout<<max_s<<endl;
  return 0;
}
