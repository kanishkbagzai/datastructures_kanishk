#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    int getLength() {
        return length;
    }

    void addAtBeg(char x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
        length++;
    }

    void append(char x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
    }

    void addAtPOS(char x, int pos) {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            addAtBeg(x);
            return;
        }

        Node* newNode = new Node();
        newNode->data = x;

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Node Address: " << temp << ", Value: " << temp->data << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        length--;
    }

    void removePOS(int pos) {
        if (pos < 1 || pos > length) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            removeFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        length--;
    }

    ~LinkedList() {
        while (head != nullptr) {
            removeFirst();
        }
    }
};

int main() {
    LinkedList list;

    list.addAtBeg('c');
    list.addAtBeg('b');
    list.addAtBeg('a');

    list.append('d');
    list.append('e');

    cout << "Initial List: ";
    list.display();

    list.addAtPOS('x', 3);
    cout << "After adding 'x' at position 3: ";
    list.display();

    cout << "List length: " << list.getLength() << endl;

    cout << "Detailed display of the list:" << endl;
    list.displayMORE();

    list.removeFirst();
    cout << "After removing the first element: ";
    list.display();

    list.removeLast();
    cout << "After removing the last element: ";
    list.display();

    list.removePOS(3);
    cout << "After removing element at position 3: ";
    list.display();

    return 0;
}