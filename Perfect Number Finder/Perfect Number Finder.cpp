#include <iostream>
#include <cstdint> // Adds ability to use uint64_t

using namespace std;

static bool isPerfect(uint64_t num) {
    // If the number is 1 or smaller it is not a perfect number
    if (num <= 1) {
        return false;
    }

    // Variable to keep track of the sum of all the valid divisors
    uint64_t sumOfDivisors = 1;

    // Loops through each number until the sqrt(num)
    for (uint64_t i = 2; i * i <= num; i++) {
        // Checks if the num devision is a whole num
        if (num % i == 0) {
            // Increases the sum by i
            sumOfDivisors += i;
            if (i != num / i) {
                // Adds num/i if "i" isn't num/i to the sum
                sumOfDivisors += num / i;
            }
        }
    }

    // Returns true if the sum is equal to the num
    return sumOfDivisors == num;
}

int main() {
    // Initializes the search limit variable
    uint64_t searchLimit;

    // Sets the searchlimit to the users input
    cout << "What is the search limit: ";
    cin >> searchLimit;

    // Loops through each number and prints it if it is a perfect number
    cout << "\nAll perfect numbers from 1 to " << searchLimit << ": \n\n";

    for (int i = 1; i <= searchLimit; i++) {
        if (isPerfect(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}
