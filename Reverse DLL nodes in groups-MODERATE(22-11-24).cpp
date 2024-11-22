#include <bits/stdc++.h>
using namespace std;

/*********************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
    };

************************************************************/

// Function to reverse k nodes in a doubly linked list
Node* reverseDLLInGroups(Node* head, int k)
{
    Node* current = head;
    Node* newHead = NULL;
    int cnt = 0;

    // Reverse the first k nodes
    while (current != NULL && cnt < k) {
        Node* nextNode = current->next;
        current->next = newHead;

        if (newHead != NULL)
            newHead->prev = current;

        newHead = current;
        current = nextNode;
        cnt++;
    }

    // If there are nodes left in the list, recursively reverse the next part
    if (head) {
        head->next = reverseDLLInGroups(current, k);

        if (head->next) {
            head->next->prev = head;
        }
    }

    return newHead;
}

// Function to print the doubly linked list
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "-1" << endl;
}

// Function to append a new node at the end
void appendNode(Node*& head, int data)
{
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    int T;  
    cin >> T;

    while (T--) {
        int data;
        Node* head = NULL;
        while (cin >> data && data != -1) {
            appendNode(head, data);
        }

        int k;
        cin >> k;

        head = reverseDLLInGroups(head, k);

        printList(head);
    }

    return 0;
}
