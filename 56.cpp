#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define endl '\n'
struct temple
{
  int l,r;
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  temple c_s[n];
  for(int i=0;i<n;i++)
    {
      c_s[i].l=-1;
      c_s[i].r=-1;
    }
  c_s[0].l=1;
  c_s[n-1].r=1;
  for(int i=1;i<n;i++)
  {
    if(a[i]>a[i-1])
      c_s[i].l=c_s[i-1].l + 1;
    else
      c_s[i].l=1;
  }
  for(int i=n-2;i>=0;i--)
  {
    if(a[i]>a[i+1])
      c_s[i].r=c_s[i+1].r+1;
    else
    c_s[i].r=1;
  }
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=max(c_s[i].l,c_s[i].r);
  cout<<sum<<endl;
  return 0;
}
