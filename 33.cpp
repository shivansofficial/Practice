#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
#define endl '\n'
int select_random(int x)
{
  static int res;
  static int count =0;
  count++;
  if(count==1)
    res=x;
  else
  {
    int i=rand()%count;
    if(i==count-1)
      res=x;
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    cout<<select_random(a[i])<<endl;
  return 0;
}
