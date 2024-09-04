#include <iostream>
#include <string>

using namespace std;

int getLucky(string s, int k) {
    // Step 1: Convert the string to a numerical string based on alphabet positions
    string numStr = "";
    for (char c : s) {
        int value = c - 'a' + 1; // Get the position in the alphabet (1-based)
        numStr += to_string(value); // Append to the result string
    }

    // Step 2: Perform the transformations
    int sum = 0;
    for (char c : numStr) {
        sum += c - '0'; // Convert char digit to integer and sum them up
    }

    while (--k > 0) {
        int newSum = 0;
        while (sum > 0) {
            newSum += sum % 10;
            sum /= 10;
        }
        sum = newSum;
    }

    return sum;
}