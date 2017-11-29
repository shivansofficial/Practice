#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int r=0;
  while(1)
  {
    int bit;
    cin>>bit;
    if(bit==0)
      r=(r*2)%n;
    else if(bit==1)
      r=(r*2+1)%n;
    else
      break;

    if(r%n==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
