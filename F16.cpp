#include <iostream>
#include <string>

// Joshua Lelon Mitchell's attempt at
// TXST CS Dept's Fall 2016 M.S. Programming Exam

int sumDigits(int num) {
    // 7823 --> 20
    int value, sum;
    while (num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

bool isMember(std::string strArr[], int size, std::string tarStr) {
    if (size < 1) {
        return false;
    }
    else if (size == 1) {
        return strArr[0].compare(tarStr) == 0;
    }
    else if (size % 2 == 0) {
        return isMember(strArr, size/2, tarStr) || isMember(strArr + size/2, size/2, tarStr);
    }
    else if (size % 2 == 1) {
        return isMember(strArr, 1, tarStr) || isMember(strArr + 1, size - 1, tarStr);
    }
}

int indexOfMax(int array[], int size) {
    int maxIndex = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void swap(int arr[], int indexOne, int indexTwo) {
    int temp = arr[indexOne];
    arr[indexOne] = arr[indexTwo];
    arr[indexTwo] = temp;
}

void selectionSort(int array[], int size) {
    int maxIndex = 0;
    for (int i = 0; i < size; i++) {
        maxIndex = indexOfMax(array, size - i);
        swap(array, maxIndex, size - (i + 1));
    }
}

class IntStack {
    private:
        struct Node {
            int value;
            Node * next;
        };
        Node * head;
        int size;
    
    public:
        IntStack() {
            head = NULL;
            size = 0;
        }
        void push(int x) {
            Node * iter = head;
            Node * xNode;
            xNode->value = x;
            xNode->next = NULL;
            if (head == NULL) { 
                head = xNode;
            }
            else {
                while (iter->next != NULL) {
                    iter = iter->next;
                }
                iter->next = xNode;
            }
            size++;
        }
        int pop() {
            if (size == 0) {
                return -1;
            }
            size--;
            Node * iterBefore = head;
            Node * iterCurrent = head->next;
            while (iterCurrent->next != NULL) {
                iterBefore = iterCurrent;
                iterCurrent = iterCurrent->next;
            }
            iterBefore->next = NULL;
            return iterCurrent->value;
        }
        bool isempty() {
            return size == 0;
        }
};

int main() {
    std::cout << sumDigits(7823) << std::endl;

    std::string strArr[5] = {"hi", "hello", "ha", "are", "josh"};
    std::string tarStr = "hey";
    std::string tarStr2 = "hi";
    std::cout << isMember(strArr, 5, tarStr) << std::endl;
    std::cout << isMember(strArr, 5, tarStr2) << std::endl;

    int intArr[10] = {1, 3, 5, 2, 4, 9, 6, 8, 7, 10};
    selectionSort(intArr, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << intArr[i];
    }
    std::cout << std::endl;
    
    // std::cout << isMember
    return EXIT_SUCCESS;
}