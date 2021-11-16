#include "linked_list.hpp"

template<typename E>
LinkedList<E>::Node *LinkedList<E>::getNode(int i) {
    if (i < 0 || i >= size)
        return NULL;
    Node *itrPos = HEAD;
    while (i) {
        itrPos = itrPos->next;
        i--;
    }
    return itrPos;
}

template<typename E>
void LinkedList<E>::append(E val) {
    Node *newNode = new Node(val);
    link(TAIL->prev, newNode);
    link(newNode, TAIL);
    size++;
}

template<typename E>
void LinkedList<E>::add(int i, E val) {
    Node *addPos = getNode(i);
    Node *newNode = new Node(val);
    link(addPos, newNode);
    link(newNode, addPos->next);
    size++;
}

template<typename E>
E LinkedList<E>::remove(int i) {
    Node *delPos = getNode(i);
    link(delPos->prev, delPos->next);
    E delVal = delPos->value;
    delete[] delPos;
    size--;
    return delVal;
}

template<typename E>
bool LinkedList<E>::removeItem(E val) {
    Node *delPos = HEAD;
    while (delPos != TAIL) {
        delPos = delPos->next;
        if (delPos->value == val) {
            link(delPos->prev, delPos->next);
            delete[] delPos;
            size--;
            return true;
        }
    }
    return false;
}

template<typename E>
E LinkedList<E>::get(int i) {
    return getNode(i)->value;
}

template<typename E>
void LinkedList<E>::set(int i, E val) {
    Node *setPos = getNode(i);
    setPos->value = val;
}

template<typename E>
int LinkedList<E>::indexOf(E val) {
    Node *itrPos = HEAD;
    int i = -1;
    while (itrPos != TAIL) {
        itrPos = itrPos->next;
        i++;
        if (itrPos->value == val)
            return i;
    }
    return -1;
}

template<typename E>
void LinkedList<E>::clear() {
    Node *itrPos = HEAD->next;
    HEAD->next = TAIL;
    while (itrPos != TAIL) {
        itrPos = itrPos->next;
        delete[] itrPos->prev;
    }
    TAIL->prev = HEAD;
    size = 0;
}

