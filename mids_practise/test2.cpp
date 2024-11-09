#include <iostream>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

// Class representing a single state of the code
class CodeState {
public:
    string code;           
    time_t timestamp;      // When the state was saved
    string description; 
    CodeState(const string& code, const string& description) {
        this->code = code;
        this->timestamp = time(0); // Save current time
        this->description = description;
    }

    void print() const {
        cout << "CodeState:\n";
        cout << "Code: " << code << "\n";
        cout << "Timestamp: " << ctime(&timestamp); // Print formatted time
        cout << "Description: " << description << "\n";
    }
};

// Class representing the code editor with undo functionality
class CodeEditor {
private:
    string current;                     // Current code in the editor
    stack<CodeState> undoStack;        // Stack to hold previous CodeState instances

public:
    CodeEditor() {
        current = "";                   // Initialize current code
    }

    // Method to edit code and save the current state to the stack
    void edit_code(const string& newCode, const string& description) {
        // Save the current state before editing
        undoStack.push(CodeState(current, description));
        current = newCode; // Update the current code
        cout << "Code edited. Description: " << description << "\n";
    }

    // Method to undo the last edit
    void undo() {
        if (undoStack.empty()) {
            cout << "No actions can be undone.\n";
            return;
        }

        CodeState lastState = undoStack.top(); // Get the last state
        undoStack.pop();                       // Remove it from the stack
        current = lastState.code;              // Restore the code to the last state
        cout << "Undid: " << lastState.description << "\n";
    }

    // Method to peek at the last state without modifying the current code
    CodeState peek() {
        if (undoStack.empty()) {
            cout << "No previous states to peek.\n";
            return CodeState("", ""); // Return an empty state if no history
        }
        return undoStack.top(); // Return the last state
    }

    // Method to display the current state of the code in the editor
    void display_code() {
        cout << "Current Code:\n" << current << "\n";
    }
};

// Example usage
int main() {
    CodeEditor editor;

    editor.edit_code("print('Hello, World!')", "Added a print statement");
    editor.display_code();

    editor.edit_code("print('Hello, Universe!')", "Changed greeting");
    editor.display_code();

    editor.undo(); // Undo last change
    editor.display_code();

    CodeState lastState = editor.peek(); // Peek at the last change
    lastState.print();

    return 0;
}
