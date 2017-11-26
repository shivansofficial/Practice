#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;
int solve(vector<vector<int> >,int k)
{
  int source,dest;
  cin>>source>>dest;

}
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >matrix(n,vector<int>(n,0));
  int e;
  cin>>e;
  int x,y;
  for(int i=0;i<e;i++)
  {
    cin>>x>>y;
    matrix[x][y] = 1;
    matrix[y][x] = 1;
  }
  int k;
  cin>>k;
  cout<<solve(matrix,k);
  return 0;
}
