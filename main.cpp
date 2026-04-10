#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


typedef long long ll;
class Solution {
public:
    int myAtoi(string s) {
        ll res = 0, min = (1<<31), max = 2'147'483'647;
        ll abs_min = -min;
        int i, n = s.size();
        bool sign;
        for (i = 0; i < n; ++i) {
            if (s[i] != ' ') {break;}
        }
        if (s[i] == '-') {sign = 1; ++i;}
        else if (s[i] == '+') {sign = 0; ++i;}
        else {sign = 0;} 
        
        for (; i<n; ++i) {
            if (s[i] != '0') {break;}
        }
        for (; i < n; ++i) {
            int digit = s[i] - '0';
            if (digit > 9 || digit < 0) {break;}
            res = res * 10 + digit;
            if (!sign && res > max) {return max;}
            if (sign && res > abs_min) {return min;}
        }
        return res * (1 - (sign << 1));
    }
};

int main() {
    Solution().myAtoi("");
}