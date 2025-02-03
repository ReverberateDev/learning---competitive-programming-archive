#include <iostream>
#include <deque>

using namespace std;

const int MOD = 1e9 + 7;  // Large prime for modular hashing
const int BASE = 2;       // Binary base for rolling hash

struct BinaryMatcher {
    deque<int> A, B;      // Deques to store dynamic binary strings
    long long hashA = 0, hashB = 0; // Rolling hashes
    long long powerA = 1, powerB = 1; // Power factors for hash updates

    // Compute initial hash of a binary string
    long long computeHash(const string &s) {
        long long hashValue = 0;
        for (char c : s) {
            hashValue = (hashValue * BASE + (c - '0')) % MOD;
        }
        return hashValue;
    }

    // Initialize A and B with given binary strings
    void initialize(const string &A_str, const string &B_str) {
        hashA = hashB = 0;
        A.clear();
        B.clear();
        powerA = powerB = 1;

        // Initialize A
        for (char c : A_str) {
            A.push_back(c - '0');
            hashA = (hashA * BASE + (c - '0')) % MOD;
            if (A.size() > 1) powerA = (powerA * BASE) % MOD;
        }

        // Initialize B
        for (char c : B_str) {
            B.push_back(c - '0');
            hashB = (hashB * BASE + (c - '0')) % MOD;
            if (B.size() > 1) powerB = (powerB * BASE) % MOD;
        }
    }

    // Add bit to the LEFT of A
    void addLeftA(int newBit) {
        hashA = (newBit * powerA + hashA) % MOD;
        A.push_front(newBit);
        if (A.size() > 1) powerA = (powerA * BASE) % MOD;
    }

    // Add bit to the RIGHT of A
    void addRightA(int newBit) {
        hashA = (hashA * BASE + newBit) % MOD;
        A.push_back(newBit);
        if (A.size() > 1) powerA = (powerA * BASE) % MOD;
    }

    // Remove bit from the LEFT of A
    void removeLeftA() {
        if (A.empty()) return;
        int leftBit = A.front();
        A.pop_front();
        hashA = (hashA - leftBit * powerA % MOD + MOD) % MOD;
        if (!A.empty()) powerA = (powerA * BASE) % MOD;
    }

    // Remove bit from the RIGHT of A
    void removeRightA() {
        if (A.empty()) return;
        int rightBit = A.back();
        A.pop_back();
        hashA = (hashA - rightBit + MOD) % MOD;
        hashA /= BASE;
        if (!A.empty()) powerA /= BASE;
    }

    // Add bit to the LEFT of B
    void addLeftB(int newBit) {
        hashB = (newBit * powerB + hashB) % MOD;
        B.push_front(newBit);
        if (B.size() > 1) powerB = (powerB * BASE) % MOD;
    }

    // Add bit to the RIGHT of B
    void addRightB(int newBit) {
        hashB = (hashB * BASE + newBit) % MOD;
        B.push_back(newBit);
        if (B.size() > 1) powerB = (powerB * BASE) % MOD;
    }

    // Remove bit from the LEFT of B
    void removeLeftB() {
        if (B.empty()) return;
        int leftBit = B.front();
        B.pop_front();
        hashB = (hashB - leftBit * powerB % MOD + MOD) % MOD;
        if (!B.empty()) powerB = (powerB * BASE) % MOD;
    }

    // Remove bit from the RIGHT of B
    void removeRightB() {
        if (B.empty()) return;
        int rightBit = B.back();
        B.pop_back();
        hashB = (hashB - rightBit + MOD) % MOD;
        hashB /= BASE;
        if (!B.empty()) powerB /= BASE;
    }

    // Query: Check if A == B
    bool query() {
        return hashA == hashB;
    }
};

int main() {
    int Q;
    string A_str, B_str;
    
    // Read initial binary strings
    cin >> A_str >> B_str;

    // Initialize matcher
    BinaryMatcher matcher;
    matcher.initialize(A_str, B_str);

    // Process queries
    cin >> Q;
    while (Q--) {
        string op;
        cin >> op;

        if (op == "addLeftA") {
            int bit;
            cin >> bit;
            matcher.addLeftA(bit);
        } else if (op == "addRightA") {
            int bit;
            cin >> bit;
            matcher.addRightA(bit);
        } else if (op == "removeLeftA") {
            matcher.removeLeftA();
        } else if (op == "removeRightA") {
            matcher.removeRightA();
        } else if (op == "addLeftB") {
            int bit;
            cin >> bit;
            matcher.addLeftB(bit);
        } else if (op == "addRightB") {
            int bit;
            cin >> bit;
            matcher.addRightB(bit);
        } else if (op == "removeLeftB") {
            matcher.removeLeftB();
        } else if (op == "removeRightB") {
            matcher.removeRightB();
        } else if (op == "query") {
            cout << (matcher.query() ? "YES" : "NO") << endl;
        }
    }
}