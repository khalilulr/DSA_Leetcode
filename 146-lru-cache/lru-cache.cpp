class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int capacity;

    // Remove a node from wherever it currently is
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Add node immediately after head
    void addNodeFront(Node* node) {
        Node* headNextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = headNextNode;
        headNextNode->prev = node;
    }

    // Remove least recently used node
    void removeEndNode() {
        Node* toDel = tail->prev;

        // Cache is empty
        if (toDel == head)
            return;

        // Remove from linked list
        removeNode(toDel);

        // Remove from hashmap
        mp.erase(toDel->key);

        // Delete node
        delete toDel;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move to front because it was recently used
        removeNode(node);
        addNodeFront(node);

        return node->value;
    }

    void put(int key, int value) {
        // Case 1: Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            // Update value
            node->value = value;

            // Move to front
            removeNode(node);
            addNodeFront(node);

            return;
        }

        // Case 2: Cache is full
        if (mp.size() == capacity) {
            removeEndNode();
        }

        // Case 3: Insert new node
        Node* node = new Node(key, value);

        mp[key] = node;
        addNodeFront(node);
    }
};