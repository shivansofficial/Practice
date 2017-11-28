#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'
bool is_valid(int i,int j,char a[][3])
{
  return(i>=0 && j>=0 && i<4 && j<3 && a[i][j]!='*' && a[i][j]!='#');
}
int get_count(char a[][3],int n)
{
  if(a==NULL||n<=0)
    return 0;
  if(n==1)
    return 10;
  int row[]={0,1,0,-1,0};
  int col[]={0,0,-1,0,1};

  int count[10][n+1];

  int total=0;

  for(int i=0;i<=9;i++)
  {
    count[i][0]=0;
    count[i][1]=1;
  }
  for(int k=2;k<=n;k++)
  {
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<3;j++)
        {
          if(is_valid(i,j,a))
            {
              int num=a[i][j]-'0';
              count[num][k]=0;

              for(int move=0;move<5;move++)
              {
                int ro=i+row[move];
                int co=j+col[move];

                if(is_valid(ro,co,a))
                {
                  int next_num=a[ro][co]-'0';
                  count[num][k]+=count[next_num][k-1];
                }
              }
            }
          }
      }
  }
  for(int i=0;i<=9;i++)
  {
    total+=count[i][n];
  }
  return total;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  char a[4][3]={{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
  int n;
  cin>>n;
  cout<<get_count(a,n)<<endl;
  return 0;
}
