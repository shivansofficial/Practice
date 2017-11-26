#include<iostream>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

typedef struct node {
  struct node * left;
  struct node * right;
  int val;
}node;

node * new_node(int val)
{
  node * temp = new(node);
  temp->left=NULL;
  temp->right = NULL;
  temp->val = val;
  return temp;
}

int main()
{
  //Visit later
  
  return 0;
}
