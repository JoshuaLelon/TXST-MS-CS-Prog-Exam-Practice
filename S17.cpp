#include <iostream>
#include <string>

using namespace std;

bool hasDups(string strs[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (strs[i].compare(strs[j]) == 0 && i != j) {
                return true;
            }
        }
    }
    return false;
}

int countV(int intArr[], int size, int v) {
    // count number of times v appears in intArr
    if (size > 0) {
        if (intArr[size - 1] == v) {
            return 1 + countV(intArr, size - 1, v);
        }
        else {
            return 0 + countV(intArr, size - 1, v);
        }
    }
    else {
        return 0;
    }
}

class List {
    private:
        struct Node {
            double value
            Node * next;
        };
        Node * head;
    
    public:
        List() {
            head = NULL;
        }
        void lastToFirst() {
            if (head != NULL && head->next != NULL) {
                Node * secToLast = head;
                while (secToLast->next->next != NULL) {
                    secToLast = secToLast->next;
                }
                Node * temp = head;
                head = secToLast->next; // head is now the last one
                head->next = temp->next; // head's (the last one's) next is the previous head's next
                secToLast->next = temp; // second to last node's next now points to the previous head
                temp->next = NULL; // the previous head (now the last node) now point's to nothing next (since it's last)
            }
        }
};

class IntQueue {
    private:
        int arr[100];
        int front;
        int rear;
        int queued;
    
    public:
        IntQueue() {
            queued = 0;
        }
        void enqueue(int x) {
            if (queued == 0) {
                front = 0;
                rear = 0;
                arr[front] = x;
                
            }
            else {
                rear = (rear + 1) % 100;
                arr[rear] = x;
            }
            queued++;
        }
        int dequeue() {
            int returner = arr[front];
            front = (front + 1) % 100;
            queued--;
            return returner;
        }
};