#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int k;
  cin>>k;
  vector<int>tab(n+1);
  tab[0]=0;
  tab[1]=k;
  // same[i] = diff[i-1];
  // diff[i] = total[i]*(k-1);
  int same = 0;
  int diff = k;
  for(int i=2;i<=n;i++)
  {
    same   =    diff;
    diff   =    tab[i-1]*(k-1);
    tab[i] =    (diff + same);
  }
  cout<<tab[n];
  return 0;
}
