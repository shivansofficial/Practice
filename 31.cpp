#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'
#define max_char 256
typedef struct node
{
  char data;
  node * prev,*next;
}node;
void append_node(node ** head,node ** tail,char x)
{
  node * temp=new node;
  temp->data= x;
  temp->prev=temp->next=NULL;
  if(*head==NULL)
    {
      *head=*tail=temp;
      return;
    }
  (*tail)->next=temp;
  temp->prev=(*tail);
  (*tail)=temp;
}
void remove_node(node ** head,node ** tail,node * temp)
{
  if(*head==NULL)
    return;
  if(*head==temp)
    (*head)=(*head)->next;
  if(*tail==temp)
    (*tail)=(*tail)->prev;
  if(temp->next)
    temp->next->prev=temp->prev;
  if(temp->prev)
    temp->prev->next=temp->next;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  vector<node*>inDLL(max_char,NULL);
  vector<bool>repeated(max_char,false);
  node * head=NULL,*tail=NULL;
  for(int i=0;i<s.size();i++)
  {
    char x=s[i];
    if(!repeated[x])
    {
      if(!inDLL[x])
        {
          append_node(&head,&tail,s[i]);
          inDLL[x]=tail;
        }
      else
      {
        remove_node(&head,&tail,inDLL[x]);
        inDLL[x]=NULL;
        repeated[x]=true;
      }
    }
    if(head!=NULL)
      cout<<"First non repeating character : "<<head->data<<endl;
    }
  return 0;
}
