#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>

using namespace std;

string process(string text, string pat)
{
    map<char,int>hash_text;
    map<char,int>hash_pat;
    for(int i=0;i<pat.length();i++)
      hash_pat[pat[i]]++;
    int count = 0;
    int start=0;
    int min_l = INT_MAX;
    int start_i;
    for(int i=0;i<text.length();i++)
    {
      hash_text[text[i]]++;
      if(hash_pat[text[i]] && hash_pat[text[i]] >= hash_text[text[i]])
        count++;
      if(count == pat.length())
      {
        while(hash_pat[text[start]]==0 || hash_text[text[start]] > hash_pat[text[start]])
          {
            if(hash_text[text[start]] > hash_pat[text[start]])
              hash_text[text[start]]--;
            start++;
          }
        int len = i - start + 1;
        if(len < min_l)
        {
          min_l = len;
          start_i = start;
        }
      }
    }
    cout<<start<<"\t\t"<<start_i<<endl;
    return text.substr(start_i,min_l);
}

int main()
{
  string a;
  string b;
  getline(cin,a);
  getline(cin,b);
  cout<<process(a,b)<<endl;
  return 0;
}
