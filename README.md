# Circular Linked List
This code explores how a circular singly linked list works.
* The program provides several operations:
 *
 * 1. **add_beg_end(int data, struct circ **tail):**
 *    - Adds a node with the given `data` at the beginning or end of the list.
 *    - If the list is empty, it initializes the list, setting the `tail` pointer.
 *    - Otherwise, it inserts the node at the end and updates the tail pointer.
 *
 * 2. **add_mid(int data, int order, struct circ **tail):**
 *    - Inserts a node with the given `data` at a specified position (`order`).
 *    - If `order` is 1, it adds the node at the beginning using `add_beg_end`.
 *    - For other positions, it finds the correct place in the list and inserts the node.
 *
 * 3. **delete(int order, struct circ **tail):**
 *    - Deletes the node at the specified position (`order`).
 *    - Special cases like deleting the head (first node) or the tail (last node) are handled.
 *    - If deleting the tail node, the `tail` pointer is updated.
 *
 * 4. **reverse(struct circ **tail):**
 *    - Reverses the entire list by iteratively reversing the pointers of each node.
 *    - After reversal, the head becomes the tail, and the tail becomes the new head.
 *
 * 5. **list_print(struct circ **tail):**
 *    - Prints all nodes in the list, starting from the head (the node after the tail).
 *
 * In the `main` function, the program runs a loop five times, allowing the user to
 * choose and perform any of these operations.
^X
