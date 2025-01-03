#include<iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class Sorting {
public:
    vector<int> arr;

    Sorting(int size) {
        arr.resize(size);
    }

    void getnumber() {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rand() % 1000000;
        }
    }

    void selectionsort() {
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

    void bubblesort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Simple implementation of Binary Search Tree sort
    struct Node {
        int info;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int value) : info(value) {}
    };

    Node* insert(Node* root, int value) {
        if (!root) 
            return new Node(value);
        if (value < root->info)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
        return root;
    }

    void inorder_traversal(Node* root, vector<int>& sortedArr) {
        if (!root) return;
        inorder_traversal(root->left, sortedArr);
        sortedArr.push_back(root->info);
        inorder_traversal(root->right, sortedArr);
    }

    void bstsort() {
        Node* root = nullptr;
        for (int value : arr) {
            root = insert(root, value);
        }
        vector<int> sortedArr;
        inorder_traversal(root, sortedArr);
        arr = sortedArr; // Storing the sorted result back in arr
    }
};

int main() {
    int sizes[] = { 10, 1000, 10000, 100000 };
    
    cout << "Size\tSelection Sort \t\tBubble Sort \t\tBST Sort" << endl;

    for (int size : sizes) {
        Sorting sort(size);

        // Selection Sort
        sort.getnumber();
        auto start = high_resolution_clock::now();
        sort.selectionsort();
        auto stop = high_resolution_clock::now();
        auto selectionduration = duration_cast<milliseconds>(stop - start);
        cout << size << "\t" << selectionduration.count() << "\t\t\t";

        // Bubble Sort
        sort.getnumber();
        auto startbubble = high_resolution_clock::now();
        sort.bubblesort();
        auto stopbubble = high_resolution_clock::now();
        auto bubbleduration = duration_cast<milliseconds>(stopbubble - startbubble);
        cout << bubbleduration.count() << "\t\t\t";

        // BST Sort
        sort.getnumber();
        auto startbst = high_resolution_clock::now();
        sort.bstsort();
        auto stopbst = high_resolution_clock::now();
        auto bstduration = duration_cast<milliseconds>(stopbst - startbst);
        cout << bstduration.count() << endl;
    }

    return 0;
}
