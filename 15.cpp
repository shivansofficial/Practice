#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  long long total=k;
  int same=0,diff=k;
  for(int i=2;i<=n;i++)
  {
    same=diff;
    diff=total*(k-1);
    total=same+diff;
  }
  cout<<total<<endl;
  return 0;
}
