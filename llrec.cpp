#include <iostream>
#include <fstream>
#include "llrec.h"
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

//may have issue is smaller and larger are not null
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  //cout << "i exit" << endl;

  if(head == NULL)
  {
    //cout << "world!" << endl;
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  else if(head->val <= pivot)
  {
    //cout << "hello! " << head->val << endl;
    Node* temp = head->next;
    head->next = smaller;
    smaller = head;
    head = temp;
    return llpivot(head, smaller->next, larger, pivot);
  }
  else if(head->val > pivot)
  {
    //cout << "hi! " << head->val << endl;
    Node* temp = head->next;
    head->next = larger;
    larger = head;
    head = temp;
    return llpivot(head, smaller, larger->next, pivot);
  }

}
