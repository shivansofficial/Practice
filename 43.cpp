#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int max_d=-1;
  int max_i=-1;
  int li=-1,ri=-1;
  string s=to_string(n);
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]>max_d)
      {
        max_d=s[i];
        max_i=i;
        continue;
      }
    if(s[i]<max_d)
    {
      li=i;
      ri=max_i;
    }
  }
  if(li==-1)
    cout<<n<<endl;
  else
  {
    swap(s[li],s[ri]);
    cout<<stoi(s)<<endl;
  }
  return 0;
}
