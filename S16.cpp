#include <iostream>
#include <string>

// Joshua Lelon Mitchell's attempt at
// TXST CS Dept's Spring 2016 M.S. Programming Exam

bool checkPassword(string str) {
    bool isTrue = false;
    if (str.length() > 7 && containsChars(str)) {
        isTrue = true;
    }
    return isTrue;
}

bool containsChars(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '!' || str[i] == '#' || str[i] == '$') {
            return true;
        }
    }
    return false;
}

double sumOver(int n) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        total += (1.0 / (i + 1));
    }
    return total;
}

class List {
    private:
        struct Node {
            double value;
            Node * next;
        };
        Node * head;
    public:
    List() {
        head = NULL;
    }
    void insertB4Last(double x);
}

void List::insertB4Last(double x) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        return;
    }
    Node * first = head;
    Node * second = head->next;
    while (second->next != NULL) {
        first = first->next;
        second = second->next;
    }
    Node * newNode;
    newNode->value = x;
    newNode->next = second;
    first->next = newNode;
}

class HashTable {
    private:
        int array[10000];
        int size;
        int hash(int key) {
            return key % size;
        }
    public:
        HashTable(int s);
        void insert(int x);
        bool find(int x);
}
HashTable::HashTable(int s) {
    for (int i = 0; i < 10000; i++) {
        array[i] = -1;
    }
    size = s;
}
void HashTable::insert(int x) {
    bool exists = false;
    int index = HashTable::hash(x);
    int attempts = 0;
    while(array[index] != -1) {
        if (array[index] == x) {
            return;
        }
        attempts++;
        if (attempts > 9999) {
            std::cout << "HashTable full" << std::endl;
            return;
        }
        index = (index + 1) % 10000;
    }
    array[index] = x;
}

bool HashTable::find(int x) { 
    bool exists = false;
    int index = HashTable::hash(x);
    int attempts = 0;
    while(array[index] != -1 && attempts < 10000) {
        if(array[index] == x) {
            exists = true;
        }
        index++;
        attempts++;
    }
    return exists;
}