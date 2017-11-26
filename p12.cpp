#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  vector<int>inc(n,1);
  vector<int>dec(n,1);
  for(int i=1;i<n;i++)
    for(int j=0;j<i;j++)
      if(arr[i] > arr[j])
      {
          if(dec[j] + 1 > inc[i])
            inc[i] = dec[j] + 1;
      }
      else
      {
          if(inc[j] + 1 > dec[i])
            dec[i] = inc[j] + 1;
      }
    int maxed = INT_MIN;
    for(int i=0;i<n;i++)
      maxed = max(maxed,max(inc[i],dec[i]));
    cout<<maxed<<endl;  
  return 0;
}
