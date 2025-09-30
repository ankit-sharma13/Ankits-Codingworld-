
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // malloc in C++ (C-style)
    if (newNode == NULL) {
        cout << "Memory allocation failed\n";
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;
    if (n <= 0) {
        cout << "Invalid size of list.\n";
        return NULL;
    }
    cout << "Enter elements of linked list:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> value;
        newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void displayLinkedList(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void searchLinkedList(Node* head, int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << key << " not found in the list.\n";
}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Insert at end
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at beginning
void insertAtBeginning(Node* &head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = NULL;
    int n, key;
    cout << "Enter number of nodes: ";
    cin >> n;
    head = createLinkedList(n);
    displayLinkedList(head);
    cout << "Enter element to search: ";
    cin >> key;
    searchLinkedList(head, key);

    // Single choice for insertion
    int choice, value;
    bool mind;
    cout<<"Do you want to insert the element ?\nEnter 1 for Yes:";
    cin>>mind;
    if(mind==true)
    {
    cout << "Where do you want to insert the element?\n(1 = Beginning, 2 = End, 0 = No insertion): ";
    cin>>choice;
    if (choice == 1) {
        cout << "Enter the  element to be inserted at the beginning: ";
        cin >> value;
        insertAtBeginning(head, value);
        displayLinkedList(head);
    } 
    else if (choice == 2) {
        cout << "Enter element to insert at the end: ";
        cin >> value;
        insertAtEnd(head, value);
        displayLinkedList(head);
    }}

    freeLinkedList(head);
    return 0;
}