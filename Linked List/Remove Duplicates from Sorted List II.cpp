    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        else
        {
            ListNode *prev=NULL;
            ListNode *curr=head;
            ListNode *p= curr->next;
            while(curr->next != NULL && p!=NULL)
            {
                
                if(curr->val==p->val)
                {
                    if(curr == head && p->next == NULL)
                    {
                        head = NULL;
                        return head;
                    }
                    else if(curr != head && p->next == NULL)
                    {
                        prev->next = NULL;
                        return head;
                    }
                    else
                    p=p->next;
                }
                else
                {
                    if(curr == head && curr->val == curr->next->val)
                    {
                        head = p;
                        curr = p;
                        p=p->next;
                    }
                    else if(curr == head && curr->val != curr->next->val)
                    {
                        prev = curr;
                        curr = p;
                        p=p->next;
                    }
                    else
                    {
                        if(curr!=head && curr->val == curr->next->val)
                        {
                            curr = p;
                            prev->next = p;
                            p = p->next;
                        }
                        else
                        {
                            prev = curr;
                            curr = p;
                            p = p->next;
                        }
                    }
                }
            }
            return head;
        }
    }
