#include <iostream>
#include <queue>
#include <string>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode* left, * right;

    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison function for the priority queue
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes
void printCodes(struct MinHeapNode* root, string str) {
    if (!root)
        return;

    if (root->data != '$')
        cout << "Character: " << root->data << " Code: " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to perform Huffman coding
void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* left, * right, * top;

    // Create a priority queue
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    // Build the min heap with given characters and their frequencies
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Construct the Huffman tree
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print the Huffman codes
    printCodes(minHeap.top(), "");
}

