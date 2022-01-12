#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include "../ds.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(), *tail = head;

        int t = 0;
        while (l1 || l2) {
            t += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            tail->next = new ListNode(t % 10);
            tail = tail->next;
            l1 = (l1 ? l1->next : nullptr);
            l2 = (l2 ? l2->next : nullptr);
            t /= 10;
        }
        if (t) tail->next = new ListNode(1);

        return head->next;
    }
};