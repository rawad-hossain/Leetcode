int findLength(Node *slow, Node *fast)
{
    int count = 1;
    while (slow != fast) //keep slow static and traverse fast until it reaches its original position to find length
    {
        count++;
        fast = fast->next;
    }
    return count;
}

Node *LengthofLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next;
        if (slow == fast)
            return findLength(slow, fast);
    }
    return 0;
}
