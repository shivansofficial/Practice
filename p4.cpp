#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

bool bounded(int i,int j,int n)
{
  if(i<0 || j<0 || i>=n || j>=n)
    return false;
  return true;
}
int paths_util(vector<vector<char> > mat,vector<vector<bool> >&vis,int i,int j,int &count)
{
    cout<<"Visiting "<<i<<"\t"<<j<<endl;
    count ++;
    vis[i][j]=1;
    int xs[] = {-1,-1,-1,0,0,1,1,1};
    int ys[] = {-1,0,1,-1,1,-1,0,1};
    int siz = 8;
    for(int k=0;k<siz;k++)
    {
      int x_c = i + xs[k];
      int y_c = j + ys[k];
      if(bounded(x_c,y_c,vis.size()) && mat[x_c][y_c] == (1 + mat[i][j]) && vis[x_c][y_c] ==0)
        paths_util(mat,vis,x_c,y_c,count);
    }
    return count;
}
int paths(vector<vector<char> >mat,char start)
{
  int n = mat.size();
  vector<vector<bool> >vis(n,vector<bool>(n,0));
  int count;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      count=0;
      if(vis[i][j]==0 && mat[i][j] == start)
        {
          paths_util(mat,vis,i,j,count);
          cout<<count<<endl;
        }  
    }
  return count;
}
int main()
{
  int n;
  cin>>n;
  vector<vector<char> >_arr(n,vector<char>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>_arr[i][j];
  char start_char;
  cin>>start_char;
  cout<<paths(_arr,start_char);
  return 0;
}
