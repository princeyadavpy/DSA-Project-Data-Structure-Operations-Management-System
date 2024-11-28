#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int element, int position) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    displayArray(arr, size);
}

void deleteElement(int arr[], int& size, int position) {
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    displayArray(arr, size);
}

void copyArray(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
    displayArray(arr2, size);
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    displayArray(arr, size);
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[], int& resultSize) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }
    resultSize = k;
    displayArray(result, resultSize);
}

void allarray() {
    int size1, size2, resultSize;
    cout << "Enter the size of array 1: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter elements of array 1: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    displayArray(arr1, size1);

    cout << "Enter the size of array 2: ";
    cin >> size2;
    int arr2[size2];
    cout << "Enter elements of array 2: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    displayArray(arr2, size2);

    int choice, element, position;
    int result[size1 + size2];
    do {
        cout << "\nMenu:\n1. Insert element\n2. Delete element\n3. Copy array elements\n4. Reverse array\n5. Merge two arrays\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert: ";
                cin >> position;
                insertElement(arr1, size1, element, position);
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteElement(arr1, size1, position);
                break;
            case 3:
                copyArray(arr1, arr2, size1);
                break;
            case 4:
                reverseArray(arr1, size1);
                break;
            case 5:
                mergeArrays(arr1, size1, arr2, size2, result, resultSize);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

}



struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode(int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for(int i=1; i<position-1; i++) {
            if(temp != NULL) {
                temp = temp->next;
            }
        }
        if(temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode(int position) {
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* temp = head;
        for(int i=1; i<position-1; i++) {
            if(temp != NULL) {
                temp = temp->next;
            }
        }
        if(temp != NULL && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
}

int countNodes() {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList() {
    Node* temp = head;
    while(temp != NULL) {
        cout<<endl <<"\nLinked list -> " << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void alllinkedlist() {
    int choice, data, position;
    while(true) {
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Count Nodes" << endl;
        cout << "4. Print List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> position;
                insertNode(data, position);
                printList();
                break;
            case 2:
                cout << "Enter position: ";
                cin >> position;
                deleteNode(position);
                printList();
                break;
            case 3:
                cout << "Number of nodes: " << countNodes() << endl;
                break;
            case 4:
                printList();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

}

struct Node2 {
    int data;
    Node2* next;
};

struct StackLinkedList {
    Node2* top;
};

StackLinkedList* createStackLinkedList() {
    StackLinkedList* stack = new StackLinkedList();
    stack->top = NULL;
    return stack;
}

void pushLinkedList(StackLinkedList* stack, int value) {
    Node2* newNode2 = new Node2();
    newNode2->data = value;
    newNode2->next = stack->top;
    stack->top = newNode2;
}

int popLinkedList(StackLinkedList* stack) {
    if (stack->top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    Node2* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    delete temp;
    return poppedValue;
}

bool isEmptyLinkedList(StackLinkedList* stack) {
    return stack->top == NULL;
}

int peekLinkedList(StackLinkedList* stack) {
    if (stack->top == NULL) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return stack->top->data;
}

void displayLinkedList(StackLinkedList* stack) {
    Node2* temp = stack->top;
    cout << "Stack (linked list): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Stack functions using array
struct StackArray {
    int* arr;
    int top;
    int capacity;
};

StackArray* createStackArray(int size) {
    StackArray* stack = new StackArray();
    stack->capacity = size;
    stack->arr = new int[stack->capacity];
    stack->top = -1;
    return stack;
}

void pushArray(StackArray* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        cout << "Stack is full." << endl;
        return;
    }
    stack->arr[++stack->top] = value;
}

int popArray(StackArray* stack) {
    if (stack->top == -1) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return stack->arr[stack->top--];
}

bool isEmptyArray(StackArray* stack) {
    return stack->top == -1;
}

int peekArray(StackArray* stack) {
    if (stack->top == -1) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return stack->arr[stack->top];
}

void displayArray(StackArray* stack) {
    if (stack->top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (array): ";
    for (int i = 0; i <= stack->top; i++) {
        cout << stack->arr[i] << " ";
    }
    cout << endl;
}

void allstack() {
    int size, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> size;

    StackArray* stackArray = createStackArray(size);
    StackLinkedList* stackLinkedList = createStackLinkedList();

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Empty\n5. Display Stack\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                pushArray(stackArray, value);
                pushLinkedList(stackLinkedList, value);
                cout << "Stack after push:\n";
                displayArray(stackArray);
                displayLinkedList(stackLinkedList);
                break;
            case 2:
                cout << "Popped value (array): " << popArray(stackArray) << endl;
                cout << "Popped value (linked list): " << popLinkedList(stackLinkedList) << endl;
                cout << "Stack after pop:\n";
                displayArray(stackArray);
                displayLinkedList(stackLinkedList);
                break;
            case 3:
                cout << "Top value (array): " << peekArray(stackArray) << endl;
                cout << "Top value (linked list): " << peekLinkedList(stackLinkedList) << endl;
                break;
            case 4:
                cout << "Array stack is " << (isEmptyArray(stackArray) ? "empty" : "not empty") << endl;
                cout << "Linked list stack is " << (isEmptyLinkedList(stackLinkedList) ? "empty" : "not empty") << endl;
                break;
            case 5:
                cout << "Stack contents:\n";
                displayArray(stackArray);
                displayLinkedList(stackLinkedList);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

}

struct Node1 {
    int data;
    Node1* next;
};

struct QueueLinkedList {
    Node1* front;
    Node1* rear;
};

QueueLinkedList* createQueueLinkedList() {
    QueueLinkedList* q = new QueueLinkedList();
    q->front = q->rear = NULL;
    return q;
}

void enqueueLinkedList(QueueLinkedList* q, int value) {
    Node1* newNode1 = new Node1();
    newNode1->data = value;
    newNode1->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode1;
    } else {
        q->rear->next = newNode1;
        q->rear = newNode1;
    }
}

int dequeueLinkedList(QueueLinkedList* q) {
    if (q->front == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    Node1* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    delete temp;
    return dequeuedValue;
}

bool isEmptyLinkedList(QueueLinkedList* q) {
    return q->front == NULL;
}

int peekLinkedList(QueueLinkedList* q) {
    if (q->front == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return q->front->data;
}

int rearLinkedList(QueueLinkedList* q) {
    if (q->rear == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return q->rear->data;
}

void displayLinkedList(QueueLinkedList* q) {
    if (q->front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node1* temp = q->front;
    cout << "Queue (linked list): ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void allqueue() {
    int choice, value;
    QueueLinkedList* queueLinkedList = createQueueLinkedList();

    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Rear\n5. Is Empty\n6. Display Queue\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueueLinkedList(queueLinkedList, value);
                displayLinkedList(queueLinkedList);
                break;
            case 2:
                cout << "Dequeued value: " << dequeueLinkedList(queueLinkedList) << endl;
                displayLinkedList(queueLinkedList);
                break;
            case 3:
                cout << "Front value: " << peekLinkedList(queueLinkedList) << endl;
                displayLinkedList(queueLinkedList);
                break;
            case 4:
                cout << "Rear value: " << rearLinkedList(queueLinkedList) << endl;
                displayLinkedList(queueLinkedList);
                break;
            case 5:
                cout << "Queue is " << (isEmptyLinkedList(queueLinkedList) ? "empty" : "not empty") << endl;
                displayLinkedList(queueLinkedList);
                break;
            case 6:
                displayLinkedList(queueLinkedList);
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

struct Node4 {
    int data;
    Node4* left;
    Node4* right;
    Node4(int value) : data(value), left(NULL), right(NULL) {}
};

// In-order traversal: left -> root -> right
void inOrderTraversal(Node4* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-order traversal: root -> left -> right
void preOrderTraversal(Node4* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal: left -> right -> root
void postOrderTraversal(Node4* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void treeall() {
    // Example tree
    Node4* root = new Node4(1);
    root->left = new Node4(2);
    root->right = new Node4(3);
    root->left->left = new Node4(4);
    root->left->right = new Node4(5);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    // Deallocate memory
    delete root;
}
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if key is found
        }
    }
    return -1;  // Return -1 if key is not found
}

void linearall() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "List of numbers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the number to search for: ";
    cin >> key;

    int position = linearSearch(arr, n, key);

    if (position != -1) {
        cout << "Number found at position: " << position + 1 << endl;
    } else {
        cout << "Number not found in the list." << endl;
    }

    
}

  int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;  // Return the index if key is found
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Return -1 if key is not found
}

void binaryall() {
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " numbers in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "List of numbers: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cout << "Enter the number to search for: ";
    cin >> key;

    int position = binarySearch(arr, 0, n - 1, key);

    if (position != -1) {
        cout << "Number found at position: " << position + 1 << endl;
    } else {
        cout << "Number not found in the list." << endl;
    }

    
}

// Function prototypes
void selectionSort(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int low, int high);
void merge(vector<int>& arr, int low, int mid, int high);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void radixSort(vector<int>& arr);

// Utility function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}



void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}
void sortingall() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Select a sorting algorithm:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Radix Sort" << endl;
    cout<<"enter your choice";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(arr);
            break;
        case 2:
            bubbleSort(arr);
            break;
        case 3:
            insertionSort(arr);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        case 5:
            quickSort(arr, 0, n - 1);
            break;
        case 6:
            radixSort(arr);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    cout << "Sorted array: ";
    printArray(arr);


}

int main() {
    int choice;
    do {
        cout << "Choose a data category:" << endl;
        cout << "1. Linear" << endl;
        cout << "2. Non-Linear" << endl;
        cout << "3. Searching" <<endl;
        cout << "4. Sorting "<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Linear Data Structures:" << endl;
                cout << "1. Array" << endl;
                cout << "2. Linked List" << endl;
                cout << "3. Stack" << endl;
                cout << "4. Queue" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        allarray();
                        break;
                    case 2:
                        alllinkedlist();
                        break;
                    case 3:
                        allstack();
                        break;
                    case 4:
                        allqueue();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 2:
                cout << "Non-Linear Data Structures:" << endl;
                cout << "1. Tree" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        treeall();
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            case 3:
            	cout << "1. Linear Search Tree" << endl;
                cout << "2. Binary Search Tree" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        linearall();
                        break;
                    case 2:
                        binaryall();
                        break;
                        default:
                        cout << "Invalid choice. Please try again." << endl;}
                        break ;
            case 4:
            	sortingall();
            	break;
            	
			case 5 :
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 3);

    return 0;
}

