class Solution {
public:
    //brute force - store all numbers of linked list in a vector and then check if vector is palindrome - TC=O(n),SC=O(n)
    bool checkpalindrome(vector<int>&v)
    {
        int n=v.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(v[i]!=v[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) 
    {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        if(checkpalindrome(v)==true)
        {
            return true;
        }
        return false;
    }
    
    //optimal - Fast & Slow Pointers - take slow to middle of linked list then reverse right half of middle and traverse both left & right halves simultaneously - TC=O(n), SC=O(1)
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        //fast pointer moves to end & slow pointer moves to middle 
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the part after slow pointer of linked list i.e reverse the part after middle of linked list
        ListNode*prev=NULL,*curr=slow->next,*temp;
        while(curr!=NULL)
        {                                 
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;
        //traverse slow pointer to right half of middle
        slow=slow->next;
        //now check left and right halves of middle node
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
