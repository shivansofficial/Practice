#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
#define endl '\n'
#define mod 1000000007
int dp[1025][101];
vector<int>c[101];
int all_mask;
long long int count(int mask,int i)
{
  if(all_mask==mask)
    return 1;
  if(i>100)
    return 0;
  if(dp[mask][i]!=-1)
    return dp[mask][i];
  long long int ways=count(mask,i+1);
  for(int j=0;j<c[i].size();j++)
  {
    if(mask & (1<<c[i][j]))
      continue;
    else
      ways+=count((mask|1<<c[i][j]),i+1);
      ways%=mod;
  }
  return dp[mask][i]=ways;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  string s;
  getline(cin,s);

  for(int i=0;i<n;i++)
  {
    getline(cin,s);
    stringstream ss;
    ss<<s;
    int x;
    while(!ss.eof())
    {
      string temp;
      ss>>temp;
      x=stoi(temp);
      c[x].push_back(i);
    }
  }
  memset(dp,-1,sizeof(dp));
  all_mask=(1<<n)-1;
  cout<<count(0,1)<<endl;
  return 0;
}
