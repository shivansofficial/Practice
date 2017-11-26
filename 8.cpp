#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;
#define endl '\n'
string small_window(string s,string p)
{
  int len1=s.size();
  int len2=p.size();

  if(len2>len1)
    {
      cout<<" No match"<<endl;
      return " ";
    }
  unordered_map<char,int> hash_p;
  unordered_map<char,int> hash_s;

  for(int i=0;i<len2;i++)
    hash_p[p[i]]++;

  int count=0,start=0,start_index=-1,min_len=INT_MAX;
  for(int i=0;i<len1;i++)
  {
    hash_s[s[i]]++;

    if(hash_p[s[i]]!=0 && hash_s[s[i]]<=hash_p[s[i]])
      count++;

    if(count == len2)
    {
      while(hash_p[s[start]]==0||hash_s[s[start]]>hash_p[s[start]])
        {
          if(hash_s[s[start]]>hash_p[s[start]])
            hash_s[s[start]]--;
          start++;
        }

      int len_window=i-start+1;

      if(len_window<min_len)
      {
        min_len=len_window;
        start_index=start;
      }
    }
  }
  if(start_index==-1)
    {
      cout<<" Mo match"<<endl;
      return " ";
    }
  return s.substr(start_index,min_len);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s,p;
  getline(cin,s);
  getline(cin,p);
  cout<<small_window(s,p)<<endl;
  return 0;
}
