#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Function to convert an integer to a string (works for C++98 and C++03)
std::string intToString(int num) {
    std::ostringstream ss;
    ss << num;
    return ss.str();
}

// Function to simulate brute force attack
bool bruteForceCrack(const std::string &targetPin) {
    // Try all combinations from 0000 to 9999
    for (int i = 0; i < 10000; i++) {
        // Generate a 4-digit string from the integer value i
        std::string attempt = intToString(i);
        // If the length is less than 4, pad with leading zeros
        while (attempt.length() < 4) {
            attempt = "0" + attempt;
        }

        // Print current attempt
        std::cout << "Trying: " << attempt << std::endl;

        // If the attempt matches the target pin, return true
        if (attempt == targetPin) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string targetPin;
    std::cout << "Enter the target PIN (4 digits): ";
    std::cin >> targetPin;

    if (targetPin.length() != 4 || !std::isdigit(targetPin[0])) {
        std::cout << "Invalid input. Please enter a 4-digit PIN." << std::endl;
        return 1;
    }

    bool cracked = bruteForceCrack(targetPin);

    if (cracked) {
        std::cout << "PIN cracked successfully!" << std::endl;
    } else {
        std::cout << "Failed to crack the PIN." << std::endl;
    }

    return 0;
}


