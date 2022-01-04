#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int gcd(int a, int b) {
        if(b==0) return a;
        return gcd(b, a%b);
    }
public:
    // TC: O(N)
    // SC: O(1)
    string gcdOfStrings(string str1, string str2) {
        return str1 + str2 == str2 + str1 ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};