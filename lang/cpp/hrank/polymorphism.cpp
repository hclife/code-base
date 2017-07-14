//Abstract classes - polymorphism
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};

class LRUCache: public Cache {
protected:
    int count;
public:
    LRUCache(int);
    ~LRUCache();
    Node *mapFind(int);
    void addNew(int,int);
    void add_front(Node*);
    void set_front(Node*);
    void remove_tail(int);
    void clear_list();
    virtual void set(int,int);
    virtual int get(int);
};

LRUCache::LRUCache(int c) {
    head=tail=NULL;
    count=0;
    cp=c;
}

void LRUCache::clear_list() {
    while (head) {
        Node *next=head->next;
        delete head;
        head=next;
    }
}

LRUCache::~LRUCache() {
    mp.clear();
    clear_list();
    head=tail=NULL;
    cp=count=0;
}

Node *LRUCache::mapFind(int k) {
    map<int,Node*>::iterator itor=mp.find(k);
    return itor==mp.end()?NULL:itor->second;
}

void LRUCache::add_front(Node *now) {
    if (head==NULL) {
        head=tail=now;
        return;
    }
    now->prev=NULL;
    now->next=head;
    head->prev=now;
    head=now;
}

void LRUCache::set_front(Node *pos) {
        if (head==tail) return; //There's only one element
        if (pos==head) return; //set the head node
        if (pos==tail) {              //set the tail node
            Node *prev=pos->prev;
            prev->next=NULL;
            tail=prev;
            pos->prev=NULL;
            pos->next=head;
            head->prev=pos;
            head=pos;
            return;
        }
        Node *prev=pos->prev;
        Node *next=pos->next;
        prev->next=pos->next;
        next->prev=pos->prev;
        pos->prev=NULL;
        pos->next=head;
        head->prev=pos;
        head=pos;
}

void LRUCache::remove_tail(int k) {
    mp.erase(k);
    Node *prev=tail->prev;
    prev->next=NULL;
    delete tail;
    tail=prev;
}

void LRUCache::addNew(int k,int v) {
    Node *now=new Node(k,v);
    mp.insert(pair<int,Node*>(k,now));
    add_front(now);
    if (count<cp) ++count;
    else remove_tail(tail->key);
}

void LRUCache::set(int k,int v) {
    Node *pos=mapFind(k);
    if (pos) {
        pos->value=v;
        set_front(pos);
    } else {
        addNew(k,v);
    }
}

int LRUCache::get(int k) {
    Node *pos=mapFind(k);
    if (pos) {
        int v=pos->value;
        set_front(pos);
        return v;
    }
    addNew(k,-1);
    return -1;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
