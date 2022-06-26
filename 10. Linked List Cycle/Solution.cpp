class Solution {
public:
    //better - store all nodes in hashset and keep checking simultaneously if any node was previously present - Tc=O(n), SC=O(n)
    bool hasCycle(ListNode *head) 
    {
        unordered_set<ListNode*>st;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
            {
                return true;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return false;
    }
  
    //optimal - Fast & Slow Pointers - if both of them meet at any point then there is a cycle in linked list - Tc=O(n), SC=O(1)
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL)
        {
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
    }
};
