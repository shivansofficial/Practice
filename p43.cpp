#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

int todigit(char s)
{
  return s - '0';
}
string cal_max(string s)
{
    int max_digit = -1;
    int max_digit_index = -1;
    int prim = -1;
    int second = -1;
    for(int i = s.length()-1;i>=0;i--)
    {
      if(todigit(s[i]) > max_digit)
      {
        max_digit = todigit(s[i]);
        max_digit_index = i;
      }
      if(todigit(s[i]) < max_digit)
      {
        prim = max_digit_index;
        second = i;
      }
    }
    char temp = s[prim];
    s[prim] = s[second];
    s[second] = temp;
    return s;
}
int main()
{
  string s;
  cin>>s;
  cout<<cal_max(s);
  return 0;
}
