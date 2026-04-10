#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        bool transfer = false;
        ListNode* cur = res;
        while (true) {
            int val1 = 0, val2= 0;
            if (l1 != nullptr) {
                val1 = l1->val;
            }
            if (l2 != nullptr) {
                val2 = l2->val;
            }
            int summ = val1 + val2 + transfer;
            transfer = false;
            if (summ > 9) {
                transfer = true;
                summ -= 10;
            }
            cur->val = summ;
            if ((l1 == nullptr || l1->next == nullptr) && (l2 == nullptr || l2->next == nullptr)) {
                break;
            }
            cur->next = new ListNode();
            cur = cur->next;
            if (l1 != nullptr)
            l1 = l1->next;
            if (l2 != nullptr)
            l2 = l2->next;
        }
        if (transfer) {
            cur->next = new ListNode(1);
        }
        return res;
    }
};

ListNode* from_vector(vector<int>& input, int index) {
    if (index >= input.size() - 1) {
        return new ListNode(input[index]);
    }
    ListNode* res = new ListNode(input[index], from_vector(input, index + 1));
    return res;
}

ListNode* from_vector(vector<int> input) {
    return from_vector(input, 0);
}

vector<int> to_vector(ListNode* l1) {
    auto my_copy = l1;
    vector<int> res;
    while(my_copy != nullptr) {
        res.push_back(my_copy->val);
        my_copy = my_copy->next;
    }
    return res;
}

void print_vector(vector<int>& arr) {
    for (int el : arr) {
        cout << el << ' ';
    }
    cout << '\n';
}

void print_list(ListNode* l) {
    while (l != nullptr)
    {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << '\n';
    
}

int main() {
    ListNode* l1 = from_vector({2, 4, 3});
    ListNode* l2 = from_vector({5, 6, 4});
    ListNode* summ = Solution().addTwoNumbers(l1, l2);
    print_list(summ);
}