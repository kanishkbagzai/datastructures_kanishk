//A10
#include <iostream>
#include <string>
using namespace std;

// Structure to define a Contact
struct Contact {
    string name;
    string mobileNumber;
};

// Node class for the linked list
class Node {
public:
    Contact contact;
    Node* next;

    Node(const string& name, const string& mobileNumber) {
        contact.name = name;
        contact.mobileNumber = mobileNumber;
        next = nullptr;
    }
};

// LinkedList class for managing the contact list
class ContactList {
private:
    Node* head;

public:
    ContactList() : head(nullptr) {}

    // Add a contact at the beginning
    void addAtBeg(const string& name, const string& mobileNumber) {
        Node* newNode = new Node(name, mobileNumber);
        newNode->next = head;
        head = newNode;
    }

    // Append a contact at the end
    void append(const string& name, const string& mobileNumber) {
        Node* newNode = new Node(name, mobileNumber);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Add a contact at a specific position
    void addAtPos(const string& name, const string& mobileNumber, int pos) {
        if (pos < 0 || pos > getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            addAtBeg(name, mobileNumber);
            return;
        }
        Node* newNode = new Node(name, mobileNumber);
        Node* temp = head;
        int currPos = 0;
        while (currPos != pos - 1) {
            temp = temp->next;
            currPos++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display all contacts
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->contact.name << ", Mobile Number: " << temp->contact.mobileNumber << endl;
            temp = temp->next;
        }
    }

    // Display more detailed information
    void displayMore() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Name: " << temp->contact.name;
            cout << ", Mobile Number: " << temp->contact.mobileNumber;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Remove the first contact
    void deleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove the last contact
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        delete temp;
    }

    // Remove a contact at a specific position
    void deleteAtPos(int pos) {
        if (pos < 0 || pos >= getLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            deleteAtStart();
            return;
        }
        Node* prev = head;
        int currPos = 0;
        while (currPos != pos - 1) {
            prev = prev->next;
            currPos++;
        }
        Node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }

    // Get the length of the linked list
    int getLength() {
        Node* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }


};

// Main function to test the contact list
int main() {
    ContactList contactList;

    // Add contacts to the list
    contactList.addAtBeg("Kanishk", "8839673561");
    contactList.append("Ashsish", "9754186097");
    contactList.addAtPos("Tanisha", "9827008550", 1);
    
    cout << "Contact list:" << endl;
    contactList.display();

    cout << "Detailed contact info:" << endl;
    contactList.displayMore();

    // Remove contacts from the list
    contactList.deleteAtStart();
    contactList.deleteAtEnd();
    contactList.deleteAtPos(0);

    cout << "Contact list after removals:" << endl;
    contactList.display();



    return 0;
}
