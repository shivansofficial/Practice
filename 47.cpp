#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  int n=s.size();
  int count[n+1];
  memset(count,0,sizeof(count));
  if(s[0]==0)
    count[0]=0;
  else
    count[0]=1;
  count[1]=count[0];
  for(int i=2;i<=n;i++)
  {
    if(s[i-1]>'0')
      count[i]=count[i-1];
    if(s[i-2]=='1'||(s[i-2]=='2' && s[i-1]<'7'))
      count[i]+=count[i-2];
  }
  cout<<count[n]<<endl;
  return 0;
}
