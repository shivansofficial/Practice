#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>

using namespace std;

class lru{
  list<int>dq;
  unordered_map<int,list<int>::iterator>dict;
  int cap;
public:
  lru(int r)
  {
    cap = r;
  }
  void refer(int x)
  {
    if(dict.find(x) == dict.end())
    {
      if(dq.size()==cap)
      {
        dict.erase(dq.back());
        dict.pop_back();
      }
    }
    else
      dict.erase(dict[x]);
      dq.push_front(x);
      dict[x] = dq.begin();

  }
  void display()
  {
    for (auto it = dq.begin(); it != dq.end();it++)
        cout << (*it) << " ";
    cout << endl;
  }
};
int main()
{
  return 0;
}
