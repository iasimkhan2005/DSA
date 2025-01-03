#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Graph Implementation for Dijkstra's Algorithm
class Graph {
    int vertices;
    vector<pair<int, int>>* adj;

public:
    Graph(int v) {
        vertices = v;
        adj = new vector<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({ v, weight });
    }

    void dijkstra(int start, int end) {
        vector<int> dist(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        if (dist[end] == INT_MAX)
            cout << "No path exists between " << start << " and " << end << "\n";
        else
            cout << "Shortest path cost from " << start << " to " << end << ": " << dist[end] << "\n";
    }
};

// Binary Search Tree Implementation
class BST {
    struct Node {
        int data;
        Node* left, * right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (!node)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (!node)
            return nullptr;
        if (value < node->data)
            node->left = deleteNode(node->left, value);
        else if (value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if (!node->left)
                return node->right;
            if (!node->right)
                return node->left;

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

// Sorting Algorithms
void merge(vector<int>& arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            swaps++;
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

// Main Menu
int main() {
    Graph g(5); // Example graph with 5 vertices
    BST bst;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge to Graph\n";
        cout << "2. Find Shortest Path (Dijkstra)\n";
        cout << "3. Insert Node into BST\n";
        cout << "4. Delete Node from BST\n";
        cout << "5. Display BST Traversals\n";
        cout << "6. Sort Array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v, weight;
            cout << "Enter edge (u v weight): ";
            cout << "Enter Start: ";
            cin >> u;
            cout << "Enter End: ";
            cin >> v;
            cout << "Enter Edge Weight:";
            cin>> weight;
            g.addEdge(u, v, weight);
            break;
        }
        case 2: {
            int start, end;
            cout << "Enter start and end vertices: ";
            cin >> start >> end;
            g.dijkstra(start, end);
            break;
        }
        case 3: {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        }
        case 4: {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            bst.deleteNode(value);
            break;
        }
        case 5: {
            cout << "Inorder Traversal: ";
            bst.inorder();
            cout << "Preorder Traversal: ";
            bst.preorder();
            cout << "Postorder Traversal: ";
            bst.postorder();
            break;
        }
        case 6: {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            vector<int> arr(n);
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            vector<int> arrCopy = arr;
            int mergeComparisons = 0, mergeSwaps = 0;
            mergeSort(arr, 0, n - 1, mergeComparisons, mergeSwaps);

            int quickComparisons = 0, quickSwaps = 0;
            quickSort(arrCopy, 0, n - 1, quickComparisons, quickSwaps);

            cout << "Merge Sort Result: ";
            for (int x : arr)
                cout << x << " ";
            cout << "\nComparisons: " << mergeComparisons << ", Swaps: " << mergeSwaps << endl;

            cout << "Quick Sort Result: ";
            for (int x : arrCopy)
                cout << x << " ";
            cout << "\nComparisons: " << quickComparisons << ", Swaps: " << quickSwaps << endl;
            break;
        }
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}