#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void addNode(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void swapNodes(Node **head, Node *a, Node *b)
{
    if (a == b)
        return;
    Node *prevA = NULL;
    Node *currA = *head;
    while (currA && currA != a)
    {
        prevA = currA;
        currA = currA->next;
    }
    Node *prevB = NULL;
    Node *currB = *head;
    while (currB && currB != b)
    {
        prevB = currB;
        currB = currB->next;
    }
    if (!currA || !currB)
        return;
    if (prevA)
        prevA->next = currB;
    else
        *head = currB;
    if (prevB)
        prevB->next = currA;
    else
        *head = currA;
    Node *temp = currA->next;
    currA->next = currB->next;
    currB->next = temp;
}

Node *getTail(Node *head)
{
    while (head && head->next)
        head = head->next;
    return head;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL;
    Node *cur = head;
    Node *tail = pivot;
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (*newHead == NULL)
        *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node *quickSortRec(Node *head, Node *end)
{
    if (!head || head == end)
        return head;
    Node *newHead = NULL;
    Node *newEnd = NULL;
    Node *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        newHead = quickSortRec(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node **head)
{
    *head = quickSortRec(*head, getTail(*head));
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    addNode(&head, 3);
    addNode(&head, 5);
    addNode(&head, 1);
    addNode(&head, 9);
    addNode(&head, 8);
    addNode(&head, 7);
    addNode(&head, 10);
    quickSort(&head);
    printList(head);
    return 0;
}