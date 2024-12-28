#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

// Node structure for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return  b->freq < a->freq;
    }
};

// Generate Huffman codes recursively
void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}


void freeTree(Node* root) {//for memory effivencyy
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}


void compressFile(const string& inputFileName, const string& outputFileName, const string& codebookFileName) {
    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    unordered_map<char, int> freq;
    char ch;

    
    while (inputFile.get(ch)) {
        freq[ch]++;
    }

   
    priority_queue<Node*, vector<Node*>, Compare> pq;//min heap based

    for (const auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    Node* root = pq.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

   //writing code to file
    ofstream codebookFile(codebookFileName);
    for (const auto& pair : huffmanCode) {
        codebookFile << pair.first << ":" << pair.second << "\n";
    }
    codebookFile.close();

    // Reset input file pointer
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Write compressed file
    ofstream outputFile(outputFileName, ios::binary);
    string encodedString = "";

    while (inputFile.get(ch)) {
        encodedString += huffmanCode[ch];
    }

    // Pad encodedString to make its length a multiple of 8
    int extraBits = 8 - (encodedString.size() % 8);
    if (extraBits != 8) {
        encodedString.append(extraBits, '0');
    }

    outputFile.put(extraBits); // Store extra bits at the beginning

    for (size_t i = 0; i < encodedString.size(); i += 8) {
        bitset<8> bits(encodedString.substr(i, 8));
        outputFile.put(static_cast<char>(bits.to_ulong()));
    }

    inputFile.close();
    outputFile.close();
    freeTree(root);

    cout << "File compressed successfully!" << endl;
    
}


void decompressFile(const string& compressedFileName, const string& codebookFileName, const string& outputFileName) {
    ifstream compressedFile(compressedFileName, ios::binary);
    if (!compressedFile) {
        cerr << "Error opening compressed file!" << endl;
        return;
    }

    ifstream codebookFile(codebookFileName);
    if (!codebookFile) {
        cerr << "Error opening codebook file!" << endl;
        return;
    }

    unordered_map<string, char> reverseHuffmanCode;
    string line;
    while (getline(codebookFile, line)) {
        char ch = line[0];
        string code = line.substr(2);
        reverseHuffmanCode[code] = ch;
    }

    codebookFile.close();

    // Read the extra bits from the compressed file
    char extraBitsChar;
    compressedFile.get(extraBitsChar);
    int extraBits = static_cast<int>(extraBitsChar);

    // Read the compressed binary data
    string encodedString = "";
    char byte;
    while (compressedFile.get(byte)) {
        bitset<8> bits(static_cast<unsigned char>(byte));
        encodedString += bits.to_string();
    }

    compressedFile.close();

    // Remove the padding
    encodedString = encodedString.substr(0, encodedString.size() - extraBits);

    // Decode the binary string
    ofstream outputFile(outputFileName, ios::binary);
    string currentCode = "";
    for (char bit : encodedString) {
        currentCode += bit;
        if (reverseHuffmanCode.find(currentCode) != reverseHuffmanCode.end()) {
            outputFile.put(reverseHuffmanCode[currentCode]);
            currentCode = "";
        }
    }

    outputFile.close();
    cout << "File decompressed successfully!" << endl;
}

// Main function
int main() {
    int choice;
    cout << "Huffman Coding\n";
    cout << "1. Compress (Encode)\n";
    cout << "2. Decompress (Decode)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    string inputFileName, outputFileName, codebookFileName;
    if (choice == 1) {
        cout << "Enter input file name: ";
        cin >> inputFileName;
        cout << "Enter compressed file name: ";
        cin >> outputFileName;
        cout << "Enter codebook file name: ";
        cin >> codebookFileName;

        compressFile(inputFileName, outputFileName, codebookFileName);
    } else if (choice == 2) {
        cout << "Enter compressed file name: ";
        cin >> inputFileName;
        cout << "Enter codebook file name: ";
        cin >> codebookFileName;
        cout << "Enter output file name: ";
        cin >> outputFileName;

        decompressFile(inputFileName, codebookFileName, outputFileName);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
