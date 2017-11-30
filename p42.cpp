#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

bool isvalid(int i,int j,int n)
{
  return (i>=0 && j>=0 && i<n && j<n);
}
int bfs(vector<vector<int> >arr,queue<pair<int,int> >q)
{
  int xs[] = {-1,-1,-1,0,0,1,1,1};
  int ys[] = {-1,0,1,-1,1,-1,0,1};
  q.push(make_pair(-1,-1));
  int ctr=0;
  int days = 0;
  int r,s;
  pair<int,int>temp;
  while(!q.empty())
  {
    temp = q.front();
    q.pop();
    r = temp.first;
    s = temp.second;
    cout<<"--------------> Releasing "<<r<<"  "<<s<<endl;
    if( r== -1 && s== -1)
      {
        ctr++;
        cout<<"-------------->Crusing at level"<<ctr<<endl;
        q.push(make_pair(-1,-1));
        days++;
        if(ctr==arr.size()-2)
          break;
      }

    for(int i=0;i<8;i++)
      {
        int temp_x = r + xs[i];
        int temp_y = s + ys[i];
        if(isvalid(temp_x,temp_y,arr.size()) && arr[temp_x][temp_y] == 0 )
          {
            cout<<"Pushing this "<<temp_x<<" "<<temp_y<<endl;
            q.push(make_pair(temp_x,temp_y));
            arr[temp_x][temp_y] = 1;
          }
      }
  }
  return days;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >arr(n,vector<int>(n));
  int t;
  queue<pair<int,int> >q;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      {
        cin>>t;
        arr[i][j] = t;
        if(arr[i][j] == 1)//1 is unhealthy
          q.push(make_pair(i,j));
      }
  cout<<bfs(arr,q)<<endl;
  return 0;
}
