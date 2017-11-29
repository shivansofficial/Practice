#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define endl '\n'
int min_val(string s,int k)
{
  int n=s.size();
  if(k>=n)
    return 0;
  map<char,int> m;
  int res=0;
  for(int i=0;i<n;i++)
    m[s[i]]++;
  priority_queue<int>pq;
  map<char,int>::iterator it;
  for(it=m.begin();it!=m.end();it++)
    pq.push(it->second);

  while(k--)
  {
    int temp=pq.top();
    pq.pop();
    pq.push(temp-1);
  }
  while(!pq.empty())
  {
    int temp=pq.top();
    pq.pop();
    res+=temp*temp;
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  int k;
  cin>>s>>k;
  cout<<min_val(s,k)<<endl;
  return 0;
}
