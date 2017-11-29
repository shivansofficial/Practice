#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int digit(char a)
{
  return a - '0';
}
int main()
{
  string a;
  cin>>a;
  vector<int>tab(a.length());
  tab[0] = digit(a[0]);
  int sum;
  int res = tab[0];
  for(int i=1;i<a.length();i++)
  {
      sum = digit(a[i])*(i+1) + 10*tab[i-1];
      res+=sum;
      tab[i] = sum;
  }
  cout<<res<<endl;
  return 0;
}
