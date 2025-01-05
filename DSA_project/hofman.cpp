#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
class Compare {           
    public:                 
    bool operator()(Node* a, Node* b) {     //function object
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
    ifstream inputFiletmp(inputFileName);

    string orignal_text="";
    getline(inputFiletmp,orignal_text);
    inputFiletmp.close();

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
    inputFile.clear();//clear flags
    inputFile.seekg(0, ios::beg);//bring pointe rto begining

    // Write compressed file
    ofstream outputFile(outputFileName, ios::binary);
    string encodedString = "";

    while (inputFile.get(ch)) {
        encodedString += huffmanCode[ch];
    }
    string es=encodedString;
    

    
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

    cout << "\nFile compressed successfully!" << endl;
    cout << "\nOriginal Size (in bits): " << orignal_text.length() * 8 << " bits\n";
    cout << "Compressed Size (in bits): " << es.length() << " bits\n";
    
}


void decompressFile(const string& compressedFileName, const string& codebookFileName,string outputFileName="") {
    ifstream compressedFile(compressedFileName, ios::binary);//opening requird files
    ifstream codebookFile(codebookFileName);
   

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
    // cout<<encodedString<<endl;

    // Decode the binary string
    
    string currentCode = "";
    string output_text="";
    for (char bit : encodedString) {
        currentCode += bit;
        if (reverseHuffmanCode.find(currentCode) != reverseHuffmanCode.end()) {
            output_text+=reverseHuffmanCode[currentCode];
            currentCode = "";
            
        }
    }

    
    cout << "File decompressed successfully!" << endl;


    cout<<"\nThe Extracted Text is: "<<output_text<<endl;
    cout<<"\nWould you like to save this to a file? y/n\n";
    char opt;
    cin>>opt;

    if(opt=='y' || opt=='Y'){
        cout << "Enter output file name: ";
        cin>>outputFileName;
        ofstream outputFile(outputFileName+".txt");
        outputFile<<output_text<<endl;
        outputFile.close();
    }
    else{
        cout<<"\nok byeee....\n";
    }
}



int main() {
    while (true) {
        char choice;
        cout << "\n*************************************\n";
        cout << "          Huffman Coding Tool       \n";
        cout << "*************************************\n";
        cout << "1. Compress (Encode)\n";
        cout << "2. Decompress (Decode)\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        // Validate choice as a digit
        if (!isdigit(choice)) {
            cout << "Please enter a valid digit (1, 2, or 3)!\n";
            continue;
        }

        // Convert char to integer
        int option = choice - '0';

        // Variables for filenames
        string inputFileName, outputFileName, codebookFileName;

        switch (option) {
            case 1: // 
            {
                cout << "Enter input file name (without extension): ";
                cin >> inputFileName;

                // Open and check input file
                ifstream inputFile(inputFileName + ".txt");
                if (!inputFile) {
                    cerr << "\nError opening input file!\n";
                    continue;
                }

                cout << "Enter compressed file name (without extension): ";
                cin >> outputFileName;

                cout << "Enter codebook file name (without extension): ";
                cin >> codebookFileName;

                compressFile(inputFileName + ".txt", outputFileName + ".txt", codebookFileName + ".txt");
                break;

            }
                

            case 2: 

            {
                cout << "Enter compressed file name (without extension): ";
                cin >> inputFileName;

                // Open and check compressed file
                ifstream compressedFile(inputFileName + ".txt");
                if (!compressedFile) {
                    cerr << "\nError opening compressed file!\n";
                    continue;
                }

                cout << "Enter codebook file name (without extension): ";
                cin >> codebookFileName;

                // Open and check codebook file
                ifstream codeFile(codebookFileName + ".txt");
                if (!codeFile) {
                    cerr << "\nError opening codebook file!\n";
                    continue;
                }

                decompressFile(inputFileName + ".txt", codebookFileName + ".txt");
                break;
            }
                

            case 3: // Exit
                cout << "\nExiting...\n";
                exit(0);

            default:
                cout << "Invalid choice! Please select 1, 2, or 3.\n";
                break;
        }
    }
    return 0;
}

