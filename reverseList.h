typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
   if(head == NULL)
       return NULL;
    ListNode* PreNode = NULL;
    ListNode* CurNode = head;
    ListNode* NexNode = CurNode->next;
    while(1)
    {
        CurNode->next = PreNode;
        PreNode = CurNode;
        CurNode = NexNode;
        if(CurNode == NULL)
            break;
        NexNode = NexNode->next;
    }
    return PreNode;

}