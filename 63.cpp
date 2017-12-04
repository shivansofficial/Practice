#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'
int f[31],g[31];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  memset(f,-1,sizeof(f));
  memset(g,-1,sizeof(g));
  f[0]=1;
  f[1]=0;
  g[0]=0;
  g[1]=1;
  for(int i=2;i<=30;i++)
  {
    f[i]=f[i-2]+2*g[i-1];
    g[i]=f[i-1]+g[i-2];
  }
  while(cin>>x && x!=-1)
  {

    cout<<f[x]<<endl;
  }
  return 0;
}
