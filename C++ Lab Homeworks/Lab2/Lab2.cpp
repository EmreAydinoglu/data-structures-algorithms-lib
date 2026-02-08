#include<iostream>
using namespace std;

template<typename N>
struct Node
{
    N data;
    Node<N>* next;
};

template<typename N>
class LinkedList
{
private:
    Node<N>* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void addNode(N value) {
        Node<N>* newNode = new Node<N>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " added." << endl;
    }

    void deleteNode(N value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == value) {
            Node<N>* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list." << endl;
            return;
        }

        Node<N>* current = head->next;
        Node<N>* previous = head;

        while (current != nullptr) {
            if (current->data == value) {
                previous->next = current->next;
                delete current;
                cout << value << " deleted from the list." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << value << " not found in the list." << endl;

    }

    bool searchNode(N value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return false;
        }
        Node<N>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found in the list." << endl;
                return true;
            }
            temp = temp->next;
        }

        cout << value << " not found in the list." << endl;
        return false;
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node<N>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {

    int choice;
    int value;
    LinkedList<int> list;
    do
    {
        cout << "===============By Emre Aydinoglu================" << endl;
        cout << "      ~~ WELCOME to Linked List program ~~" << endl;
        cout << "=============================================" << endl;
        cout << "   Select and Enter Your Choice from the Menu __" << endl;
        cout << "=============================================" << endl;
        cout << "    1. Add   2. Delete  3. Search  4. Print  5. Exit" << endl;
        cout << "=============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter a value to add: ";
            cin >> value;
            list.addNode(value);
            break;
        case 2:
            cout << "Enter a value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 3:
            cout << "Enter a value to search: ";
            cin >> value;
            list.searchNode(value);
            break;
        case 4:
            cout << "Printing values:" << endl;
            list.printList();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try Again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
