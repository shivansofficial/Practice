#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int print(int p[],int n)
{
  int k;
  if(p[n]==1)
    k=1;
  else
    k=print(p,p[n]-1)+1;
  cout<<"Line number : "<<k<<"-->"<<p[n]<<" "<<n<<endl;
    return k;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<int>l(n);
  for(int i=0;i<n;i++)
    cin>>l[i];

  int extras[n+1][n+1],lc[n+1][n+1],c[n+1],p[n+1];

  for(int i=1;i<=n;i++)
  {
    extras[i][i]=m-l[i-1];
    for(int j=i+1;j<=n;j++)
      extras[i][j]=extras[i][j-1]-l[i-1]-1;
  }

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(extras[i][j]<0)
        lc[i][j]=100000000;
      else if(j==n && extras[i][j]>=0)
          lc[i][j]=0;
      else
        lc[i][j]=extras[i][j]*extras[i][j];
    }
  }

  c[0]=0;
  for(int j=1;j<=n;j++)
  {
    c[j]=100000000;
    for(int i=1;i<=j;i++)
    {
      if(c[i-1]!=100000000 && lc[i][j]!=100000000 && (c[i-1]+lc[i][j]<c[j]))
        {
          c[j]=c[i-1]+lc[i][j];
          p[j]=i;
        }
    }
  }
  print(p,n);
  return 0;
}
