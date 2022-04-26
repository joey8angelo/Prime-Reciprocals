#include <iostream>

using namespace std;

int main() { // Inspired by Numberphiles The Reciprocals of Primes, find how many digits in 1/p are unique before repeating
    cout << "Enter a prime number: ";
    int p;
    cin >> p;

    int pp = p; // used to count how many times the prime number goes into div
    int div = 10; // number to divide p by
    int count = 0; // how many times p was divided
    int ppCount = 0; // counts how many times the prime number goes into div
    int multCount = 0; // determines if a zero is added to the string before the other values
    string s = "0."; // stores the final number
    
    while (div != 1) { // if the sequence starts to repeat then 1 will be divided by the prime like the start
        if (div < p) { // simulate long division, add 0s to end until p is smaller
            div *= 10;
            if (multCount > 0 || count == 0) {
                count++;
                s += "0";
            }
            multCount++;
        }
        else { // when p is smaller 
            multCount = 0; // reset multCount for next cycle
            while (pp < div) { // find how many times p goes into div
                pp += p;
                ppCount ++;
            }
            s += to_string(ppCount);
            ppCount = 0;
            pp = p;
            div = (div % p); // next div is div mod p - simulates subtracting in long division
            count++;
        }
    }
    cout << "Number of unique digits before repetition: " << count << endl;
    if (count < 5000) { cout << s << "..." << endl; }
}