// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <utility>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

bool detectLoop(Node *head)
{
    bool hasLoop = false;
    Node *traverse;
    traverse = head;

    map<Node *, int> mapp;

    while (traverse != NULL)
    {
        if (auto it = mapp.find(traverse); it != mapp.end())
        {
            hasLoop = true;
            return hasLoop;
        }
        mapp[traverse] = traverse->data;

        traverse = traverse->next;
    }

    return hasLoop;
}

void printElements(Node *head)
{
    Node *traverse = head;

    while (traverse != NULL)
    {
        cout << traverse->data << endl;
        traverse = traverse->next;
    }
}

void insertElement(int value)
{
    if (head == NULL)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        Node *traverse;
        traverse = head;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        traverse->next = temp;
    }
}

int main()
{

    Node *test_head;

    Node *n1 = new Node;
    Node *n2 = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;

    test_head = n1;
    n1->next = n2;
    n1->data = 10;

    n2->next = n3;
    n2->data = 20;

    n3->next = n4;
    n3->data = 30;

    n4->data = 40;
    n4->next = NULL;

    cout << detectLoop(test_head) << endl;
    // printElements(test_head);

    return 0;
}