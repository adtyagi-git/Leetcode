/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* node){
        if(node->next==NULL) return node;
        ListNode* newHead=reverse(node->next);
        ListNode* front=node->next;
        front->next=node;
        node->next=NULL;
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if(head->next==NULL || head==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reversehead=reverse(slow->next);
        slow->next=NULL;
        ListNode* temp=head;
        ListNode* nexttemp=head;
        ListNode* nextreverse=reversehead;
        while(temp!=NULL && reversehead!=NULL){
            nexttemp=temp->next;
            nextreverse=reversehead->next;
            temp->next=reversehead;
            if(nexttemp) reversehead->next=nexttemp;
            temp=nexttemp;
            reversehead=nextreverse;
        }
    }
};