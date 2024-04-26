#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertEnd(ListNode*& head, int value) {
    ListNode* node = new ListNode(value);
    if (head == nullptr)
        head = node;
    else {
        ListNode* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }
}

void printList(ListNode* head) {
    while (head->next != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;
}

ListNode* addTwoNumbers(ListNode* lst1, ListNode* lst2) {
    ListNode* result = new ListNode();
    int carry = 0;
    int sum = 0;
    while (lst1 != nullptr || lst2 != nullptr) {
        sum = lst1->val + lst2->val + carry;
        carry = sum / 10;
        insertEnd(result, sum % 10);
        lst1 = lst1->next;
        lst2 = lst2->next;
        printList(result);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    // Test case 01
    ListNode* lst1 = new ListNode(1);
    lst1->next = new ListNode(2);
    lst1->next->next = new ListNode(3);
    lst1->next->next->next = new ListNode(4);
    lst1->next->next->next->next = new ListNode(5);

    // Test case 02
    ListNode* lst2 = new ListNode(1);
    lst2->next = new ListNode(2);
    lst2->next->next = new ListNode(3);
    lst2->next->next->next = new ListNode(4);
    lst2->next->next->next->next = new ListNode(5);

    ListNode* result = addTwoNumbers(lst1, lst2);

    return 0;
}
