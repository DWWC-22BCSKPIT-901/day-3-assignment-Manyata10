#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);  
    ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummyHead->next; 
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* createNode(int value) {
    return new ListNode(value);
}

int main() {
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result Linked List: ";
    printList(result);  

    ListNode* l3 = createNode(0);
    ListNode* l4 = createNode(0);
    ListNode* result2 = addTwoNumbers(l3, l4);
    cout << "Result Linked List: ";
    printList(result2);  

    ListNode* l5 = createNode(9);
    l5->next = createNode(9);
    l5->next->next = createNode(9);
    l5->next->next->next = createNode(9);
    l5->next->next->next->next = createNode(9);
    l5->next->next->next->next->next = createNode(9);
    l5->next->next->next->next->next->next = createNode(9);

    ListNode* l6 = createNode(9);
    l6->next = createNode(9);
    l6->next->next = createNode(9);
    l6->next->next->next = createNode(9);

    ListNode* result3 = addTwoNumbers(l5, l6);
    cout << "Result Linked List: ";
    printList(result3);  

    return 0;
}
