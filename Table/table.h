#pragma once
#include <iostream>

using namespace std;

template<typename Key, typename Value>
class Table {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(Key key, Value value) : key(key), value(value), next(nullptr) {}
    };
    Node* head;

public:
    Table() : head(nullptr) {}

    ~Table() {
        clear();
    }

    void add(Key key, Value value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    void remove(Key key) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }


    bool find(Key key, Value& value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->key == key) {
                value = temp->value;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->key << ": " << temp->value << endl;
            temp = temp->next;
        }
    }
};
