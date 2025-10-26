#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
};

void addNode(Node **head, string name, int score)
{
    Node *newNode = new Node();
    newNode->name = name;
    newNode->score = score;
    newNode->next = *head;
    *head = newNode;
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *getNodeAt(Node *head, int index)
{
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

Node *binarySearch(Node *head, string name, int score, int len)
{
    int low = 0;
    int high = len - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        Node *midNode = getNodeAt(head, mid);
        if (midNode->score == score)
        {
            if (midNode->name == name)
            {
                return midNode;
            }
            else
            {
                return NULL;
            }
        }
        else if (midNode->score < score)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return NULL;
}

void deleteNode(Node **head, Node *del)
{
    if (*head == del)
    {
        *head = del->next;
        delete del;
        return;
    }
    Node *temp = *head;
    while (temp->next != del)
    {
        temp = temp->next;
    }
    temp->next = del->next;
    delete del;
}

void radixSort(Node **head)
{
    int max = 0;
    Node *temp = *head;
    while (temp)
    {
        if (temp->score > max)
            max = temp->score;
        temp = temp->next;
    }
    int exp = 1;
    while (max / exp > 0)
    {
        Node *buckets[10] = {NULL};
        Node *tails[10] = {NULL};
        temp = *head;
        while (temp)
        {
            Node *next = temp->next;
            int digit = (temp->score / exp) % 10;
            if (buckets[digit] == NULL)
            {
                buckets[digit] = temp;
                tails[digit] = temp;
            }
            else
            {
                tails[digit]->next = temp;
                tails[digit] = temp;
            }
            temp->next = NULL;
            temp = next;
        }
        *head = NULL;
        Node *currentTail = NULL;
        for (int i = 0; i < 10; i++)
        {
            if (buckets[i])
            {
                if (*head == NULL)
                {
                    *head = buckets[i];
                    currentTail = tails[i];
                }
                else
                {
                    currentTail->next = buckets[i];
                    currentTail = tails[i];
                }
            }
        }
        if (currentTail)
            currentTail->next = NULL;
        exp *= 10;
    }
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->name << " " << temp->score << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);
    radixSort(&head);
    display(head);
    string name;
    int score;
    cout << "Enter name and score: ";
    cin >> name >> score;
    int len = getLength(head);
    Node *found = binarySearch(head, name, score, len);
    if (found)
    {
        deleteNode(&head, found);
        display(head);
    }
    return 0;
}
