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
  getline(cin,s);
  map<char,int>dict;
  for(int i=0;i<s.length();i++)
    dict[s[i]]++;
  priority_queue<int >pq;
  for(auto it = dict.begin();it!=dict.end();++it)
    pq.push(it->second);
  int k;
  cin>>k;
  long int cost = 0;
  while(k--)
      {
        int t = pq.top();
        pq.pop();
        t--;
        pq.push(t);
      }
  while(!pq.empty())
  {
    cout<<pq.top()<<endl;
    cost+= (pq.top()*pq.top());
    pq.pop();
  }
  cout<<cost<<endl;
  return 0;
}
