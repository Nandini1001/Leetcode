class LRUCache {
struct node
{
    int key,value;
    node *prev;
    node *next;

    node(int k,int v): key(k), value(v), prev(nullptr), next(nullptr){}
};
private:
    int cap;
    unordered_map<int,node*> mpp;
    node *head;
    node *tail;
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void dltnode(node *node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        //delete node;
    }

    void insertafterhead(node *node)
    {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }
    
    int get(int key) {
        if(!mpp.count(key)) return -1;
        node *node=mpp[key];
        dltnode(node);
        insertafterhead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.count(key))
        {
            node *node=mpp[key];
            dltnode(node);
            insertafterhead(node);
            node->value=value;
        }
        else
        {
            node *temp=new node(key,value);
            if(mpp.size()==cap)
            {
                mpp.erase(tail->prev->key);
                dltnode(tail->prev);
            }
            insertafterhead(temp);
            mpp[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */