#include <iostream>
#include <stack>
using namespace std;

string processString(const string& input) {
    stack<char> s;
    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) {
                s.pop(); 
            }
        } else {
            s.push(ch);
        }
    }
    
    // Construct the resulting string
    string result;
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string with '+': ";
    cin >> input;
    
    string processed = processString(input);
    cout << "Processed string: " << processed << endl;
    
    return 0;
}
