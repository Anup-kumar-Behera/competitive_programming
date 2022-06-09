#include <bits/stdc++.h>
using namespace std;



struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

Node* deleteK(Node *head,int k)
{
  //Your code here
  if(!head) return NULL;
  if(k == 0)    return head;
  vector<Node *> v;
  Node *p = head;
  
  while(p){
      v.push_back(p);
      p = p->next;
  }
  
  for(int i = 0; i < v.size(); i++){
      int it = i+1;
      
      if(it % k == 0){
          if(i-1 >= 0 && v[i-1] && i+1 < v.size())
            v[i-1]->next = v[i+1];
            else if(i-1 >= 0 && v[i-1] && i+1 >= v.size())
                v[i-1]->next = NULL;
          free(v[i]);
          v[i] = NULL;
      }
  }
  for(auto i:v)
    if(i)   return i;
return NULL;
}
int main(){
    int k;
    cin>>k;

    Node *head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(67);
    head->next->next->next = new Node(4);

    head = deleteK(head, k);
}