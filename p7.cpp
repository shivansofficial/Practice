#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int solve(vector<vector<int> >arr)
{
  int n = arr.size();
  vector<vector<int> >row(n,vector<int>(n,0));
  vector<vector<int> >col(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
    {
      int flip =1;
      for(int j=n-1;j>=0;j--)
      {
        if(arr[i][j]==0)
          flip = 0;
        row[i][j] = flip;
       }
    }

  for(int i=0;i<n;i++)
    {
      int flip = 1;
      for(int j=n-1;j>=0;j--)
      {
          if(arr[j][i] == 0)
            flip =0;
          col[j][i] = flip;
      }
    }
    int count =0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      if(col[i][j]==1 && row[i][j]==1)
        count++;
    }
    return count;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >arr(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  cout<<solve(arr)<<"\na";
  return 0;
}
