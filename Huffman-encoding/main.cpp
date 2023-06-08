#include <iostream>
#include <string>
#include "algo.hpp"

using namespace std;


int main(){
    char data[] = { 'A', 'B', 'C', 'D', 'E' };
    int freq[] = { 5, 1, 6, 3, 2 };
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq, size);

    return 0;
}