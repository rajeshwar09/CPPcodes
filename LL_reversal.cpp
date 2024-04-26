#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int x) : value(x), next(NULL){}
};

Node* reverseLL(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void printLL(Node* head) {
    
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->value << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original linked list: ";
    printLL(head);
    
    // Reverse the linked list in place
    head = reverseLL(head);
    
    cout << "Reversed linked list: ";
    printLL(head);
    
    // Freeing memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
