#include <iostream>
#include <string>
#include <stack>
using namespace std;

void swapChars(string &s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void getPermutations(string input_str) {
    stack<pair<string, int>> st;
    st.push(make_pair(input_str, 0));

    while (!st.empty()) {
        string current_str = st.top().first;
        int index = st.top().second;
        st.pop();

        if (index == current_str.length() - 1) {
            // We have a complete permutation, print it
            cout << current_str << endl;
        }

        // Move to the next character in the string
        index++;

        for (int i = index; i < current_str.length(); i++) {
            // Generate permutations by swapping characters
            string new_str = current_str;
            swapChars(new_str, index, i);
            st.push(make_pair(new_str, index + 1));
        }
    }
}

int main() {
    string input_string = "programming";
    cout << "Permutations of '" << input_string << "' are:" << endl;
    getPermutations(input_string);
    return 0;
}
