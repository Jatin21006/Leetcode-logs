class LRUCache {
public:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };


    int cap;
    unordered_map<int, Node*> mp;
    Node* head;  // dummy head
    Node* tail;  // dummy tail

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Remove node from DLL
    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    // Insert node right after head (MRU position)
    void insert(Node* node) {
        Node* n = head->next;
        head->next = node;
        node->prev = head;
        node->next = n;
        n->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);   // move to MRU
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
        }
        else {
            if (mp.size() == cap) {
                // remove LRU (node before tail)
                Node* lru = tail->prev;
                mp.erase(lru->key);
                remove(lru);
                delete lru;
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insert(node);
        }
    }
};
