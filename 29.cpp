#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
#define endl '\n'
int string_reduction(string s)
{
  int n=s.size();
  int count[3]={0};
  for(int i=0;i<n;i++)
    count[s[i]-'a']++;

  if(count[0]==n||count[1]==n||count[2]==n)
    return n;

  if((count[0]%2==count[1]%2) && (count[1]%2==count[2]%2))
    return 2;
  return 1;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  cout<<string_reduction(s)<<endl;
  return 0;
}
