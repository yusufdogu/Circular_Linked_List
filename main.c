#include <stdio.h>
#include <stdlib.h>
typedef struct circ {
    int data;
    struct circ *next;
}circ_list;
void add_beg_end(int ,struct circ **);
void add_mid(int ,int ,struct circ **);
void delete(int,struct circ **);
void reverse(struct circ **);
void list_print(struct circ **);
int main(void) {
    int x=5;
    while (x>0) {
        circ_list *tail=NULL;
        int a,num,order;
        scanf("%d",&a);
        switch (a) {
            case 1:
                scanf("%d",&num);
                add_beg_end(num,&tail);
                break;
            case 2:
                scanf("%d",&num);
                scanf("%d",&order);
                add_mid(num,order,&tail);
                break;
            case 3:
                scanf("%d",&order);
                delete(order,&tail);
                break;
            case 4:
                reverse(&tail);
                break;
            case 5:
                list_print(&tail);
                break;
        }
        x--;
    }
}
void add_beg_end(int data ,struct circ **tail) {
    circ_list *new=malloc(sizeof(circ_list));
    new->data=data;
    if(*tail==NULL) {
        (*tail)=new;
        new->next=(*tail);
    }
    else {
        new->next=(*tail)->next;
        (*tail)->next=new;
        (*tail)=new;
    }
}
void add_mid(int data,int order,struct circ **tail) {
    if (order == 1) {
        add_beg_end(data, tail);  // Call the function to add at the beginning
        return;
    }
    circ_list *new=malloc(sizeof(circ_list));
    new->data=data;
    circ_list *temp = (*tail)->next; // Start from the head (tail->next)
    while (order>2) {
        temp=temp->next;
        order--;
    }
    if (temp->next == *tail) {
        add_beg_end(data, tail);  // Call the function to add at the end
    } else {
        // Insert in the middle
        new->next = temp->next;
        temp->next = new;
    }
}
void delete(int order,struct circ **tail){
    if (*tail == NULL) {
        return; // Empty list, nothing to delete
    }
    struct circ *temp = (*tail)->next;
    struct circ *prev = *tail;
    // If the first node (head) is to be deleted
    if (order == 1) {
        if (temp == *tail) {
            // Only one node in the list
            free(*tail);
            *tail = NULL;
        } else {
            prev->next = temp->next; // Skip over the head node
            free(temp); // Free the old head}
        return;}
    // Traverse to find the node to delete
    while (order > 1 && temp != *tail) {
        prev = temp;
        temp = temp->next;
        order--;}
    prev->next = temp->next; // Bypass the node to delete
    // If we're deleting the tail node, update the tail pointer
    if (temp == *tail) {
        *tail = prev;}
    free(temp);
}}
void reverse(struct circ **tail) {
    circ_list *prev=(*tail);
    circ_list *current=(*tail)->next ;
    circ_list *next=NULL;
    do {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move prev to this node
        current = next;         // Move to the next node
    } while (current != (*tail)->next);
    *tail=current;
}

void list_print(struct circ **tail) {
    circ_list *temp=(*tail)->next;
    while(temp!=(*tail)) {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

