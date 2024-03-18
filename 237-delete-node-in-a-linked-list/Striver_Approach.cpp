//Striver Way
Node* removeNode(Node* node) {
  if (node == NULL || node->next == NULL) {
    return NULL; // List is empty or only has one node, can't remove anything
  }

//e.g      4 5 1 9     node = 5, which we want to remove
    
  // Copy 1 to 5's position
  node->val = node->next->val;        // 4 1 1 9

  // will skip the immediate next postion of required node, skip the 3rd position
  node->next = node->next->next;     // 4 1 9
    
  delete node->next;
  return head; 
}
