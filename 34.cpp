#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define endl '\n'
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  priority_queue<int,vector<int>,greater<int> >pq(a.begin(),a.end());
  int res=0;
  while(pq.size()>1)
  {
    int f=pq.top();
    pq.pop();
    int s=pq.top();
    pq.pop();
    res+=f+s;
    pq.push(f+s);
  }
  cout<<res<<endl;
  return 0;
}
