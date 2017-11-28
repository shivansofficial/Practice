#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int nCr=1,res=1;
  for(int r=1;r<=n;r++)
  {
    nCr=nCr*(n-r+1)/r;
    res+=nCr*nCr;
  }
  cout<<res<<endl;
  return 0;
}
