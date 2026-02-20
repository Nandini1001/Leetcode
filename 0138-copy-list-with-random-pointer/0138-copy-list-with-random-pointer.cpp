/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
        temp=head;
        while(temp){
            if(temp->random==NULL)
                temp->next->random=NULL;
            else{
                temp->next->random=temp->random->next; 
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* newhead=NULL;
        while(temp){
            Node* copy=temp->next;
            if(!newhead) newhead=copy;
            temp->next=copy->next;
            if(copy->next) copy->next=copy->next->next;
            temp=temp->next;
        }
        return newhead;
    }
};