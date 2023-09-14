#include <bits/stdc++.h>
using namespace std;

// define node
class Node
{
public:
    int value;
    Node *next;
};

class Solution
{
public:
    Node *head = new Node;
    Node *tail = new Node;
    Solution()
    {
        head = NULL;
        tail = NULL;
    }

public:
    void insertIntoNode(int data)
    {
        // initialize node
        Node *temp = new Node;

        // insert into temp node
        temp->value = data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            // linkup with previous node
            tail->next = temp;
            // update with current node
            tail = temp;
        }
    }

    // Method to insert into last of current list
    void insertIntoEnd(int data)
    {
        // initialize node
        Node *temp = new Node;

        // insert into temp node
        temp->value = data;
        temp->next = NULL;

        tail->next = temp;
        tail = temp;
    }

    // insert into first

    void insertIntoFirst(int data)
    {
        // initialize node
        Node *temp = new Node;

        // insert into temp node
        temp->value = data;

        // update text->next address with head node address
        temp->next = head;

        // now update head with temp node references
        head = temp;
    }

    // Insert item into specific position
    void insertDataInGivenPosition(int pos, int data)
    {
        // initialize node
        Node *temp = new Node;

        temp->value = data;
        temp->next = NULL;

        if (head == NULL)
        {
            temp->next = head;
            head = temp;
        }

        // make copy of head
        Node *copyTemp = head;
        int count = 0;

        while (pos > 1) // or pos != 1
        {
            // cout << copyTemp->value << " " << endl;
            copyTemp = copyTemp->next;
            pos--;
        }

        // cout << copyTemp->value << " " << copyTemp->next << endl;
        temp->next = copyTemp->next; // this is the references of number -> 60
        copyTemp->next = temp;       // or temp->next;
    };

    // DELETE FROM BEGINNING
    void deleteFromBeginning()
    {
        Node *temp = new Node;
        if (head == NULL)
        {
            cout << "Ther is no item to delete. insert item first" << endl;
            return;
        }

        temp = head;
        head = head->next;

        // free memory
        free(temp);
    };

    // REMOVE ITEM FROM LAST OR END
    void removeItemFromEnd()
    {
        Node *temp = new Node;
        temp = head;

        if (head == NULL)
        {
            cout << "Ther is no item to delete. insert item first" << endl;
            return;
        }

        Node *prv = new Node;
        prv = NULL;

        while (temp->next)
        {
            // hold previous item
            prv = temp;
            temp = temp->next;
        }

        prv->next = NULL;

        // free memory
        free(temp);
    }

    // DELETE NODE AT ANY POSITION
    void deleteNodeAtAnyPosition(int pos)
    {

        if (head == NULL)
        {
            cout << "Ther is no item to delete. insert item first" << endl;
            return;
        }

        // for 0 base indexing

        Node *temp = new Node;
        temp = head;

        Node *prv = new Node;
        prv = NULL;

        for (int i = 0; i < pos; i++)
        {
            // if we want to removed first node or head node
            if (i == pos - 1 && pos == 1 && temp)
            {
                head = head->next;
                free(temp);
                return;
            }
            else if (i == pos - 1)
            {
                // cout << "PRV ->" << prv->value << " " << prv->next << endl;
                // cout << "TEMP ->" << temp->value << " " << temp->next << endl;
                prv->next = temp->next;

                free(temp);

                return;
            }
            else
            {
                prv = temp;

                if (prv == NULL)
                {
                    cout << "Your given node is not found at position -> " << pos << endl;
                    free(temp);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void printNode()
    {
        Node *root = new Node;
        root = head;

        while (root != NULL)
        {
            cout << root->value << " ";
            root = root->next;
        }
    };
};

int main(void)
{
    Solution obj;

    obj.insertIntoNode(30);
    obj.insertIntoNode(40);
    obj.insertIntoNode(60);
    obj.insertIntoNode(70);

    // insert at end
    obj.insertIntoEnd(80);

    // insert into first
    obj.insertIntoFirst(20);
    obj.insertIntoFirst(10);

    cout << "After insert some node => ";

    // print list of node
    obj.printNode();
    cout << endl;

    // insert into given position
    obj.insertDataInGivenPosition(3, 50);

    cout << "After insert into certain position node => ";

    // print list of node
    obj.printNode();
    cout << endl;

    // Delete from beginning
    obj.deleteFromBeginning();

    cout << "After delete node from beginning => ";

    // print list after deleting from beginning
    obj.printNode();
    cout << endl;

    // Removed from end
    obj.removeItemFromEnd();
    obj.removeItemFromEnd();

    cout << "After delete node from end => ";

    // print list after deleting from beginning
    obj.printNode();
    cout << endl;

    // remove node dynamically
    obj.deleteNodeAtAnyPosition(7);

    cout << "After delete node by providing dynamic position => ";

    // print list after deleting from beginning
    obj.printNode();
    cout << endl;

    return 0;
}