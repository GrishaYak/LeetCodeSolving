#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


typedef long long ll;

int findFittingPower(int x) {
    if (x >= 1e9) {
        return (int) 1e9;
    }
    int res = 1;
    while (res <= x) {
        res *= 10;
    }
    return res / 10;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {return 0;}
        int leftCursor = findFittingPower(x), rightCursor = 1;
        while (leftCursor > rightCursor)
        {
            if (x / leftCursor % 10 != x / rightCursor % 10) {return 0;}
            leftCursor /= 10;
            rightCursor *= 10;
        }
        return 1;
    }
};



int main() {
    int num;
    cin >> num;
    cout << Solution().isPalindrome(num) << endl;
}