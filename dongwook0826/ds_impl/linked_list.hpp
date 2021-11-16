template<typename E>
class LinkedList {
private:
    typedef struct Node {
        E value;
        Node *prev = nullptr;
        Node *next = nullptr;
        Node(E value) : value(value) {};
    } Node;
    Node *const HEAD = new Node(NULL);
    Node *const TAIL = new Node(NULL);
    int size = 0;
    void link(Node *n1, Node *n2) {
        n1->next = n2;
        n2->prev = n1;
    }
    Node *getNode(int i);

public:
    LinkedList() { link(HEAD, TAIL); }
    ~LinkedList() { clear(); }
    void append(E val);
    void add(int i, E val);
    E remove(int i);
    bool removeItem(E val);
    E get(int i);
    void set(int i, E val);
    int indexOf(E val);
    int size() { return size };
    bool isEmpty() { return size == 0 };
    void clear();
};
