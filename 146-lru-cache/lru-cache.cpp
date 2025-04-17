class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val, Node* prev, Node* next){
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};
class LRUCache {
public:
     int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1, NULL, NULL);
        tail = new Node(-1, -1, NULL, NULL);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int value = -1;
        if(m.find(key) != m.end()){
            Node *nodeToBeUpdated = m[key];
            value = nodeToBeUpdated->val;
            deleteNode(nodeToBeUpdated);
            insertNode(nodeToBeUpdated);
        }
        return value;
    }
    
    void put(int key, int value) {
         if(m.find(key) == m.end()){
            Node *newNode = new Node(key, value, NULL, NULL);
            if(m.size() == size){
                int key = deleteLRU();
                m.erase(key);
            }
            insertNode(newNode);
            m[key] = newNode;
        }
        else{
            Node *nodeToBeUpdated = m[key];
            nodeToBeUpdated->val = value;
            deleteNode(nodeToBeUpdated);
            insertNode(nodeToBeUpdated);
        }
    }

    int deleteLRU(){
        Node *nodeToBeDeleted = head->next;

        int key = head->next->key;
        head->next = nodeToBeDeleted->next;
        head->next->prev = head;
        delete(nodeToBeDeleted);
        return key;
    }

    void insertNode(Node* newNode){
        
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;

    }

    void deleteNode(Node* node){

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */