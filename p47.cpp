#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

int main()
{
  string s;
  cin>>s;
  vector<int>tab(s.length()+1);
  tab[0] = 1;
  tab[1] = 1;
  for(int i=2;i<=s.length();i++)
  {
    tab[i] = 0;
    if(s[i-1] > '0')
      tab[i] = tab[i-1];
    if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
      tab[i] += tab[i-2];
  }
  cout<<tab[s.length()];
  return 0;
}
