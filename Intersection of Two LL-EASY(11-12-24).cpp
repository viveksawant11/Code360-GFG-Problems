#include<bits/stdc++.h>
using namespace std;

class Node {                                             // Brute force - 'Data replacement' using Stack  
public:                                                  // 
    int data;                                            //    
    Node* next;                                          // 

    Node(int data1) {                                    // T = O(2n)
        data = data1;                                    // S = O(n)
        next = NULL;
    }                                                    // We won't make newNodes,
};                                                       // Optimal approach - 'Change links'

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) 
        temp = temp->next;

    temp->next = newNode;
    return;
}

Node* findIntersection(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    while (t1 != t2) {
        t1 = t1 == NULL ? t1 = head2 : t1->next;
        t2 = t2 == NULL ? t2 = head1 : t2->next;
    }

    return t1;
}

int main() {
    // Creating 1st LL
    Node* head1 = NULL;                                     
    insertNode(head1, 1);
    insertNode(head1, 3);
    insertNode(head1, 1);
    insertNode(head1, 2);
    insertNode(head1, 4);
    Node* intersectionNode = head1->next->next->next;

    // Creating 2nd LL
    Node* head2 = NULL;
    insertNode(head2, 3);
    head2->next = intersectionNode;         // Creating intersection at the 4th node of the 1st LL
    
    //Print both LL
    cout << "First LL - ";
    print(head1);
    cout << "Second LL - ";
    print(head2);

    Node* answerNode = findIntersection(head1, head2);

    if (answerNode == NULL)     
        cout << "No Intersection" << endl;
    else 
        cout << "Intersection point is - " << answerNode->data << endl;

    return 0;
}