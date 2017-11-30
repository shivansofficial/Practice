#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define endl '\n'
bool is_valid(int x,int y,vector<vector<char> > a)
{
  return(x>=0 && y>=0 && x<a.size() && y<a.size() && a[x][y]=='H');
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<vector<char> > a(n,vector<char>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];

  queue<pair<int,int> >q;
  int num_days=0;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(a[i][j]=='U')
        q.push(make_pair(i,j));

  q.push(make_pair(-1,-1));
  int flag=0;
  pair<int,int>temp;
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    int x=temp.first;
    int y=temp.second;
    if(x==-1 && y==-1)
    {
      flag++;
      q.push(make_pair(-1,-1));
      if(flag==2)
        break;
      num_days++;
    }
    else
    {
      flag=0;
      for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
          {
            if(i==0 && j==0)
              continue;

            if(is_valid(x+i,y+j,a))
              {
                q.push(make_pair(x+i,y+j));
                a[x+i][y+j]='U';
              }
          }
     }
  }
  cout<<num_days-1<<endl;
  return 0;
}
