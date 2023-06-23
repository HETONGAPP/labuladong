// 反转列表
ListNode* reverse(ListNode* head) {
    if(!head || !head->next)
        return head;
    
    ListNode* last = reverse(head->next);
    std::cout<<last->val<<std::endl;
    head->next->next = head;
    head->next = nullptr;
    return last;
}

// 反打印
void traverse(ListNode* root) {
    if(root == nullptr)
        return;
    
    traverse(root->next);
    cout<< head->val;
}




//反转前n个列表
ListNode* successor = nullptr;

ListNode* reverseN(ListNode* head, int n) {
    if(n==1)
    {
        successor = head->next;
        return head;

        ListNode* last = reverseN(head->next, n-1);

        head->next->next = head;
        head->next = successor;
        return last;
    }
}


//反转m-n个列表
ListNode* successor = nullptr;
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(m==1)
    {
        return reverseN(head, n);
    }

    head->next = reverseBetween(head->next, m-1, n-1);
    return head;
}


//合并链表并排序
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1) *p = dummy;
    ListNode* p1 = l1, *p2 = l2;
    while(!p1 && !p2)
    {
        if(p1->val > p2->val)
        {
            p->next = p2;
            p2 = p2->next;
        }
        else
        {
            p->next = p1;
            p1 = p1->next;
        }
        p = p->next;
    }
    if(!p1) p->next = p1;
    if(!p2) p->next = p2;
    return dummy->next;
}


//链表的分解

ListNode* partition(ListNode* head, int x) {
    ListNode* dummy1 = new ListNode(-1), *p1 = dummy1;
    ListNode* dummy2 = new ListNode(-1), *p2 = dummy2;
    ListNode* p = head;
    while(!p)
    {
        if(p->val > x)
        {
            p1->next = p;
            p1 = p1->next;
        }
        else
        {
            p2->next = p;
            p2 = p2->next;
        }
        ListNode* tmp = p->next;
        p->next = nullptr;
        p = tmp;
    }
    p1->next = dummy2->next;
    return dummy1->next;
}


//合并K个升序链表
class compare
{
    public:
        bool operator()(ListNode*a, ListNode*b)
        {
            return a->val > b->val;
        }
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(-1), *p = dummy;
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto ls : lists)
    {
        if(ls!=nullptr) pq.push(ls);
    }
    while(!pq.empty())
    {
        ListNode* tmp = pq.top();
        if(tmp!=nullptr) break;
        pq.pop();
        p->next = tmp;
        if(p->next!=nullptr)
            pq.push(tmp->next);
        p->next;
    }
    return dummy->next;
}


//单链表的倒数第 k 个节点
ListNode* findFromEnd(ListNode* head, int k) {
    ListNode* fast = head;

    for(int i=0; i<k; ++k) fast = fast->next;

    ListNode* slow = head;
    
    while(fast!=nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

//删除链表的倒数第 N 个结点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode x = findFromEnd(dummy, n+1);
    x->next = x->next->next;
    return dummy->next;
}

//单链表的中点
ListNode middleNode(ListNode head) {
    ListNode* slow = head,  *fast = head;
    while(fast!= nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//判断链表是否包含环
bool hasCycle(ListNode* head) {
    ListNode* slow = head,  *fast = head;
    while(fast!= nullptr && fast->next!= nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return false;
    }
    return false;
}

//判断链表是否包含环 起点
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head,  *fast = head;
    while(fast!= nullptr && fast->next!= nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }
    slow = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//两个链表是否相交
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* p1 = headA, *p2 = headB;
    while(p1!=p2)
    {
        if(p1==nullptr) p1 = headB;
        else p1 = p1->nextl;
        if(p2==nullptr) p2 = headA;
        else p2 = p2->nextl;
    }
    return p1;
}