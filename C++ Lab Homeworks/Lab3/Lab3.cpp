#include <iostream>
#include <string>
using namespace std;

struct StudentNode
{
    string firstName;
    string lastName;
    int age;
    float gpa;
    char gender;
    StudentNode* next;
};

class StudentLinkedList
{
private:
    StudentNode* head;

    void swapData(StudentNode* a, StudentNode* b) {
        swap(a->firstName, b->firstName);
        swap(a->lastName, b->lastName);
        swap(a->age, b->age);
        swap(a->gpa, b->gpa);
        swap(a->gender, b->gender);
    }
    //QUICK SORT HELPERS
    StudentNode* getTail(StudentNode* cur) {
        while (cur != nullptr && cur->next != nullptr)
            cur = cur->next;
        return cur;
    }

    StudentNode* partition(StudentNode* head, StudentNode* end,
                           StudentNode** newHead, StudentNode** newEnd)
    {
        StudentNode* pivot = end;
        StudentNode* prev = nullptr;
        StudentNode* cur = head;
        StudentNode* tail = pivot;

        while (cur != pivot) {
            if (cur->gpa < pivot->gpa) {
                if (*newHead == nullptr)
                    *newHead = cur;

                prev = cur;
                cur = cur->next;
            } else {
                if (prev)
                    prev->next = cur->next;

                StudentNode* tmp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (*newHead == nullptr)
            *newHead = pivot;

        *newEnd = tail;

        return pivot;
    }

    StudentNode* quickSortRec(StudentNode* head, StudentNode* end) {
        if (!head || head == end)
            return head;

        StudentNode* newHead = nullptr;
        StudentNode* newEnd = nullptr;

        StudentNode* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            StudentNode* temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quickSortRec(newHead, temp);

            temp = getTail(newHead);
            temp->next = pivot;
        }

        pivot->next = quickSortRec(pivot->next, newEnd);
        return newHead;
    }

    //MERGE SORT HELPERS
    StudentNode* mergeLists(StudentNode* a, StudentNode* b)
    {
        if (!a) return b;
        if (!b) return a;

        if (a->gpa <= b->gpa) {
            a->next = mergeLists(a->next, b);
            return a;
        } else {
            b->next = mergeLists(a, b->next);
            return b;
        }
    }

    void splitList(StudentNode* source, StudentNode** front, StudentNode** back)
    {
        if (!source || !source->next) {
            *front = source;
            *back = nullptr;
            return;
        }

        StudentNode* slow = source;
        StudentNode* fast = source->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
    }

    StudentNode* mergeSortRec(StudentNode* head)
    {
        if (!head || !head->next)
            return head;

        StudentNode* first;
        StudentNode* second;

        splitList(head, &first, &second);

        first = mergeSortRec(first);
        second = mergeSortRec(second);

        return mergeLists(first, second);
    }

    //HEAP SORT HELPERS
    void heapify(StudentNode* arr[], int n, int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left]->gpa > arr[largest]->gpa)
            largest = left;

        if (right < n && arr[right]->gpa > arr[largest]->gpa)
            largest = right;

        if (largest != i) {
            swapData(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }


public:
    StudentLinkedList() {
        head = nullptr;
    }

    void addNode(StudentNode value) {
        StudentNode* newNode = new StudentNode;
        *newNode = value;
        newNode->next = head;
        head = newNode;
        cout << value.firstName << " " << value.lastName << " - Student added." << endl;
    }

    void printStudent() {
        if (head == nullptr){
            cout << "List is Empty." << endl;
            return;
        }
        StudentNode* temp = head;
        while (temp != nullptr){
            cout << "--------------------------" << endl;
            cout << "Name: " << temp->firstName << " " << temp->lastName << endl;
            cout << "Age: " << temp->age << endl;
            cout << "GPA: " << temp->gpa << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "--------------------------" << endl;
            temp = temp->next;
        }
    }

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List does not have enough students to sort." << endl;
            return;
        }

        bool swapped;
        do {
            swapped = false;
            StudentNode* current = head;
            StudentNode* prev = nullptr;

            while (current->next != nullptr) {
                if (current->gpa > current->next->gpa) {
                    StudentNode* tmp = current->next;
                    current->next = tmp->next;
                    tmp->next = current;

                    if (prev == nullptr) {
                        head = tmp;
                    } else {
                        prev->next = tmp;
                    }
                    prev = tmp;
                    swapped = true;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
        
        cout << "List sorted by GPA (Bubble Sort)." << endl;
    }

    void insertionSort() {
        if (head == nullptr || head->next == nullptr) {
            cout << "List does not have enough students to sort." << endl;
            return;
        }

        StudentNode* sorted = nullptr;
        StudentNode* current = head;

        while (current != nullptr) {
            StudentNode* nextNode = current->next;

            if (sorted == nullptr || current->gpa < sorted->gpa) {
                current->next = sorted;
                sorted = current;
            } else {
                StudentNode* temp = sorted;
                while (temp->next != nullptr && temp->next->gpa <= current->gpa) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = nextNode;
        }

        head = sorted;

        cout << "List sorted by GPA (Insertion Sort)." << endl;
    }

    void selectionSort() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Not enough students to sort." << endl;
            return;
        }

        StudentNode* current = head;

        while (current != nullptr) {
            StudentNode* minNode = current;
            StudentNode* nextNode = current->next;

            while (nextNode != nullptr) {
                if (nextNode->gpa < minNode->gpa) {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }

            if (minNode != current) {
                swapData(current, minNode);
            }

            current = current->next;
        }

        cout << "List sorted by GPA (Selection Sort)." << endl;
    }

    void quickSort() {
        if (!head || !head->next) {
            cout << "Not enough students to sort." << endl;
            return;
        }

        StudentNode* tail = getTail(head);
        head = quickSortRec(head, tail);

        cout << "List sorted by GPA (Quick Sort)." << endl;
    }

    void heapSort() {
        if (!head || !head->next) {
            cout << "Not enough students to sort." << endl;
            return;
        }

        int n = 0;
        StudentNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        StudentNode** arr = new StudentNode*[n];

        temp = head;
        for (int i = 0; i < n; i++) {
            arr[i] = temp;
            temp = temp->next;
        }

        for (int i = n/2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swapData(arr[0], arr[i]);
            heapify(arr, i, 0);
        }

        delete[] arr;

        cout << "List sorted by GPA (Heap Sort)." << endl;
    }

    void mergeSort() {
        if (!head || !head->next) {
            cout << "Not enough students to sort." << endl;
            return;
        }

        head = mergeSortRec(head);
        cout << "List sorted by GPA (Merge Sort)." << endl;
    }
};

int main() {
    StudentLinkedList list;
    int choice;

    do {
        cout << "\n===== STUDENT SORTING PROGRAM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Print Students\n";
        cout << "O (n * n) Sorting Algorithms:\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Selection Sort\n";
        cout << "O (n * Log n) Sorting Algorithms:\n";
        cout << "6. Quick Sort\n";
        cout << "7. Heap Sort\n";
        cout << "8. Merge Sort\n";
        cout << "9. Cancel\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        } else {
            cin.ignore();
        }

        switch (choice) {

        case 1: {
            StudentNode s;
            cout << "Enter first name: ";
            getline(cin, s.firstName);
            cout << "Enter last name: ";
            getline(cin, s.lastName);
            cout << "Enter age: ";
            cin >> s.age;
            cout << "Enter GPA: ";
            cin >> s.gpa;
            cout << "Enter gender (M/F): ";
            cin >> s.gender;
            cin.ignore();
            s.next = nullptr;

            list.addNode(s);
            break;
        }

        case 2:
            list.printStudent();
            break;

        case 3:
            list.bubbleSort();
            break;

        case 4:
            list.insertionSort();
            break;

        case 5:
            list.selectionSort();
            break;

        case 6:
            list.quickSort();
            break;

        case 7:
            list.heapSort();
            break;

        case 8:
            list.mergeSort();
            break;

        case 9:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
