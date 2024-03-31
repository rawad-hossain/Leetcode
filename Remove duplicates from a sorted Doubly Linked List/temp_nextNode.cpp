Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode; // additional node used to delete duplicate elements
            nextNode = nextNode->next;
            delete duplicate;
        }

        temp = temp->next;
        if (nextNode)
            nextNode->back = temp; // Connect the last node

        temp = temp->next;
    }
    return head;
}
