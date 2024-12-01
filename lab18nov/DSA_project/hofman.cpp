#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip> 
using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


class Compare {        
    public:                                                // function object
    bool operator()(Node* a, Node* b) {
       return b->freq < a->freq; // Min-heap based on frequency
    }
};


void generateCodes(Node* root, string code, vector<char>& characters, vector<string>& codes) {
    if (!root)
        return;

   
    if (!root->left && !root->right) {
        characters.push_back(root->ch);
        codes.push_back(code);
    }

    //recursion
    generateCodes(root->left, code + "0", characters, codes);
    generateCodes(root->right, code + "1", characters, codes);
}


string encode(const string& text, const vector<char>& characters, const vector<string>& codes) {
    string encodedText = "";
    for (char ch : text) {
        for (int i = 0; i < characters.size(); i++) {
            if (ch == characters[i]) {
                encodedText += codes[i];
                break;
            }
        }
    }
    return encodedText;
}


string decode(const string& encodedText, Node* root) {
    string decodedText = "";
    Node* current = root;

    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

       
        if (!current->left && !current->right) {
            decodedText += current->ch;
            current = root; 
        }
    }
    return decodedText;
}

int main() {
    Node* root = nullptr; 

    while (true) {
        cout << "\n*************************************\n";
        cout << "          Huffman Coding Tool       \n";
        cout << "*************************************\n";
        cout << "1. Encrypt Text\n";
        cout << "2. Decrypt Text\n";
        cout << "3. Exit\n";  
        cout << "Enter your choice (1, 2, or 3): ";
        
        int choice;
        cin >> choice;
        cin.ignore(); 

        
        if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }

        string text;

        if (choice == 1) {
            cout << "\nEnter the text to compress: ";
            getline(cin, text);
            
          
            vector<char> uniqueChars;
            vector<int> frequencies;
            for (char ch : text) {
                vector<char>::iterator it = find(uniqueChars.begin(), uniqueChars.end(), ch);
                if (it != uniqueChars.end()) {
                    frequencies[it - uniqueChars.begin()]++;
                } else {
                    uniqueChars.push_back(ch);
                    frequencies.push_back(1);
                }
            }

            
            priority_queue<Node*, vector<Node*>, Compare> pq;
            for (size_t i = 0; i < uniqueChars.size(); i++) {
                pq.push(new Node(uniqueChars[i], frequencies[i]));
            }

          
            while (pq.size() > 1) {
                Node* left = pq.top(); pq.pop();
                Node* right = pq.top(); pq.pop();

                Node* combined = new Node('\0', left->freq + right->freq);
                combined->left = left;
                combined->right = right;

                pq.push(combined);
            }

            
            root = pq.top();
            pq.pop();

            
            vector<char> characters;
            vector<string> codes;
            generateCodes(root, "", characters, codes);

            
            cout << "\nHuffman Codes:\n";
            for (size_t i = 0; i < characters.size(); i++) {
                cout << setw(4) << characters[i] << ": " << codes[i] << endl;
            }

           
            string encodedText = encode(text, characters, codes);
            cout << "\nEncoded Text: " << encodedText << endl;
            
            cout << "\nOriginal Size (in bits): " << text.length() * 8 << " bits\n";
            cout << "Compressed Size (in bits): " << encodedText.length() << " bits\n";

        } else if (choice == 2) {
            cout << "\nEnter the encoded text to decompress: ";
            getline(cin, text);
            cout << "\nDecoded Text: " << decode(text, root) << endl;

        } else {
            cout << "Invalid choice. Please choose again.\n";
        }
    }

    return 0;
}
