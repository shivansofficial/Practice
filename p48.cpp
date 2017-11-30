#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<deque>

using namespace std;

void arrs(int n,int k,vector<int>arr)
{
  deque<int>q;
  for(int i=0;i<k;i++)
  {
    while( (!q.empty()) && arr[i]>=arr[q.back()] )
      q.pop_back();
    q.push_back(i);
  }
  for(int i=k;i<n;i++)
  {
    cout<<arr[q.front()]<<"\t";
    while( (!q.empty()) && q.front()< i - k)
      q.pop_front();
    while( (!q.empty()) && arr[i] >= arr[q.back()])
      q.pop_back();
    q.push_back(i);
  }
  cout<<arr[q.front()]<<endl;
}
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int k;
  cin>>k;
  arrs(n,k,arr);
}
