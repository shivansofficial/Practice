#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

// int ways(int n,int x,int m)
// {
//     if(n <= 0)
//       return 0;
//     if(n == x)
//       return 1;
//     int sum = 0;
//     for(int i=1;i<=m;i++)
//       sum += ways(n-1,(x-i),m);
//     return sum;
// }

int ways(int m,int n,int x)
{
  vector<vector<int> >tab(n+1,vector<int>(x+1,0));
  for(int i=1;i<=n;i++)
    tab[1][i] = 1;
  for(int i=2;i<=n;i++)
      for(int j=1;j<=x;j++)
        for(int k=1;k<=m && k <j ;k++)
          tab[i][j] += tab[i-1][j] + tab[i-1][j-k];
 return tab[n][x];          
}
int main()
{
  int n,x,m;
  cin>>n>>x>>m;
  cout<<"Answer------------>"<<ways(n,x,m)<<endl;
  return 0;
}
