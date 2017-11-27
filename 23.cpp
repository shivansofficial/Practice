#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  int res=0;
  int x,sum;
  for(int i=0;i<32;i++)
  {
    sum=0;
    x=(1<<i);
    for(int j=0;j<n;j++)
      {
        if(a[j] & x)
          sum++;
      }
      if(sum%3)
        res|=x;
  }
  cout<<res<<endl;
  return 0;
}
