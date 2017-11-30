#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<unordered_map>
#include<list>

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
        dq.pop_back();
      }
    }
    else
      dq.erase(dict[x]);// Uses the list iterator thing to delete the element taht already exists
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
  int n;
  cin>>n;
  lru u = lru(n);
    u.refer(1);
    u.refer(2);
    u.refer(3);
    u.refer(1);
    u.refer(4);
    u.refer(5);
    u.display();
  return 0;
}
