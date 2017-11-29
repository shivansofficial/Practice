#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  priority_queue<int>pq;
  for(int  i=0;i<n;i++)
    {
      cin>>arr[i];
      arr[i]*=-1;
      pq.push(arr[i]);
    }
  int cost = 0;
  int t1,t2;
  while(n!=1)
  {
    t1 = pq.top();
    pq.pop();
    t2 = pq.top();
    pq.pop();
    cost += (t1+t2);    
    pq.push(t1+t2);
    n--;
  }
  cout<<cost<<endl;
  return 0;
}
