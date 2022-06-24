class Solution {
public:
    //brute - traverse and find size and then again traverse to middle and return - TC is O(n)
    ListNode* middleNode(ListNode* head) 
    {
        int sz=0;
        ListNode* temp=head;
        //calculate the size of linked list
        while(temp!=NULL)
        {
            sz++;
            temp=temp->next;
        }
        //if size is 0 then we can't find middle element
        if(sz==0)
        {
            return NULL;
        }
        //size is odd or even in both cases - middle=(sz/2)+1
        int i=(sz/2)+1;
        temp=head;
        while(i>1)
        {
            //reach to middle of linked list
            temp=temp->next;
            i--;
        }
        //in end return the portion after middle of linked list
        return temp;
    }
    //optimal - using Fast & Slow Pointers - TC is O(n)
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast=head;
        ListNode* slow=head;
        //fast moves 2 places and slow moves 1 place
        //this way as fast reaches to end of list slow reaches to middle of list
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
