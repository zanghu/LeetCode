#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void showLink(ListNode* h) {
     while (h != NULL) {
         cout << h->val << " ";
         h = h->next;
     }
     cout << endl;
}

class Solution {
    //假设head不是头结点
    ListNode* reverse(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* p = head;
        ListNode* p_pre = NULL;
        ListNode* p_next = p->next;
        while (p != NULL) {
            p_next = p->next;
            p->next = p_pre;
            p_pre = p;
            p = p_next;
        }
        return p_pre; //返回尾结点
    }
    ListNode* crossInsert(ListNode* h1, ListNode* h2) {
        //cout << "in corssInsert " << endl;
        ListNode* p1 = h1;
        ListNode* p1_next = NULL;
        ListNode* p2 = h2;
        ListNode* p2_next = NULL;
        while (p1 != NULL && p2!=NULL) {
            p1_next = p1->next;
            p2_next = p2->next;
            p1->next = p2;
            p2->next = p1_next;
            p1 = p1_next;
            p2 = p2_next;
        }
        //cout << "after while" << endl;
        return h1;
    }
public:
    void reorderList(ListNode *head) {
        if (head==NULL || head->next==NULL) return;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy;
        ListNode* p2 = dummy;
        while (p2!=NULL && p2->next!=NULL) {
            p1 = p1->next;
            p2=p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL; //将链打开
        //cout << "p1: "; showLink(dummy->next);
        //cout << "p2: "; showLink(p1->next);  
        ListNode* h1 = dummy->next;
        ListNode* h2 = reverse(p2);
        //cout << "h1: "; showLink(h1);
        //cout << "h2: "; showLink(h2);        
        crossInsert(h1, h2);
        delete dummy;
    }
};



int main() {
//    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ListNode* head = new ListNode(1);
    ListNode* ptr = new ListNode(2);
    head->next = ptr;
    ptr = new ListNode(3);
    head->next->next = ptr;
    Solution sol;
    sol.reorderList(head);
    int cnt = 0;
    ListNode* top = head;
    while (top != NULL && cnt < 10) {
        cout << top->val << " ";
        top = top->next;
        cnt ++;
    }
    cout << endl;
    system("pause");
    return 0;
}
        
    
