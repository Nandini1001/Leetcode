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
        unordered_map<Node*, Node*> mpp;
        mpp[NULL]=NULL;
        Node* temp=head;
        Node* prev=NULL;
        while(temp){
            Node* copy=new Node(temp->val);
            mpp[temp]=copy;
            if(prev){
                prev->next=copy;
            }
            prev=copy;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            mpp[temp]->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};