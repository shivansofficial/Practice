#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<deque>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;;
  vector<int>a(n);
  for(int i=0;i<n;i++)
     cin>>a[i];

  deque<int>q(k);
  for(int i=0;i<k;i++)
  {
    while(!q.empty() && a[i]>=a[q.back()])
      q.pop_back();

    q.push_back(i);
  }
  for(int i=k;i<n;i++)
  {
    cout<<a[q.front()]<<" ";
    while(!q.empty() && q.front()<=i-k)
      q.pop_front();

    while(!q.empty() && a[i]>=a[q.back()])
      q.pop_back();

    q.push_back(i);
  }
  cout<<a[q.front()]<<endl;
  return 0;
}
