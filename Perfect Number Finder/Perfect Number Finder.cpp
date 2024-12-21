#include <iostream>
#include <cstdint>

using namespace std;

static bool isPerfect(uint64_t num) {
    if (num <= 1) {
        return false;
    }

    uint64_t sumOfDivisors = 1;

    for (uint64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sumOfDivisors += i;
            if (i != num / i) {
                sumOfDivisors += num / i;
            }
        }
    }

    return sumOfDivisors == num;
}

int main() {
    uint64_t searchLimit;

    cout << "What is the search limit: ";
    cin >> searchLimit;

    cout << "\nAll perfect numbers from 1 to " << searchLimit << ": \n\n";

    for (int i = 1; i <= searchLimit; i++) {
        if (isPerfect(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}
