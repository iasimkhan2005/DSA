#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

//A Huffman Tree Node.
struct Node {
	char ch;
	int freq;
	Node* left;
	Node* right;

	Node(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
		left = right = nullptr;
	}
};
struct Compare {
	
	bool operator()(Node* a, Node* b) {
		return a->freq > b->freq;
	}
};

int main() {

	//String Input.
	string input;
	cout << "Enter a String: ";
	getline(cin, input);

	//Freq Table
	map<char, int>freqTable;
	for (char ch : input) {
		freqTable[ch]++;
	}

	cout << endl;

	cout << "Frequency Table:" << endl;
	for (auto& pair : freqTable) {
		cout << pair.first << " : " << pair.second << endl;
	}

	priority_queue<Node*,vector<Node*>,Compare>pq;
	for (auto& pair : freqTable) {
		pq.push(new Node(pair.first, pair.second));
	}

	while (pq.size() > 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();

		int sum = left->freq + right->freq;
		Node* newNode = new Node('\0', sum);
		newNode->left = left;
		newNode->right = right;

		pq.push(newNode);
	}

	Node* root = pq.top();



}