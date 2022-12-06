 ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
		return NULL;
	else
	{
		ListNode *p = head;
		ListNode *q = head->next;
		while (q != NULL)
		{
			if ((p->val == q->val) && p == head)
			{
				p = p->next;
				head = p;
				q = q->next;
			}
			else if (p->val == q->val)
			{
				p->next = q->next;
				q = p->next;
			}
			else if (p->val != q->val)
			{
				p = q;
				q = q->next;
			}
		}
		return head;
	}
    }
