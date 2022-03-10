 ListNode* reverseList(ListNode* head)
{
	if(head == NULL || head->next == NULL)
        return head;
        else
        {
            ListNode *ans = reverseList(head->next);
            ListNode* tail = head->next;
            tail->next = head;
            head->next = NULL;
            return ans;
        }
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL)
            return head;
        else if(left == right)
        {
            return head;
        }
         else
         {
             ListNode *fhead = NULL;
             ListNode *ftail = NULL;
             int count=1;
             ListNode *temp = head;
             ListNode* p = NULL;
             // ListNode *prev= NULL;
             while(temp != NULL)
             {
                 if(left>1)
                 {
                      if(count == (left-1))
                 {
                     p = temp;
                 }
                 // count++;
                 if(count == left)
                 {
                     // prev = temp;
                     // p = temp;
                     fhead = temp;
                 }
                 }
                 else if(left == 1 && count == 1)
                 {
                     // p = head;
                     fhead = head;
                 }
                 if(count == right)
                 {
                     ftail = temp->next;
                     temp->next = NULL;
                 }
                 temp = temp->next;
                 count++;
             }
             ListNode *smallAns = reverseList(fhead);
                 fhead->next = ftail;
             if(left> 1)
             {
                 p->next = smallAns;
             }
             else if(left == 1)
                 return smallAns;
             return head;
         }
    }
