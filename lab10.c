#include <stdio.h>
#include <stdlib.h>

struct llnode {
    int item;
    struct llnode * next;
};

struct llist {
    struct llnode * front;
};

// list_range(n, m) returns a new list containing the integers between
//   n and m (inclusive) in ascending order
// requires: n <= m
// note: caller must free allocated memory
struct llist * list_range(const int n, const int m);

// free_list(lst) frees all memory associated with list lst
void free_list(struct llist * lst);

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    struct llist * range = list_range(n, m);
    struct llnode * rangeNode = range->front;
    while (rangeNode) {
        if(rangeNode->next) {
            printf("%d ", rangeNode->item);
        } else {
            printf("%d", rangeNode->item);
        }
        rangeNode = rangeNode->next;
    }
    free_list(range);
}

struct llist * list_range(const int n, const int m) {
    struct llist * head = malloc(sizeof(struct llist));
    struct llnode * curNode = NULL;
    struct llnode * lastNode = NULL;
    head->front = NULL;
    int i = n;
    while (i <= m) {
        
        curNode = malloc(sizeof(struct llnode));
        curNode->item = i;
        curNode->next = NULL;
        
        if (lastNode) {
            lastNode->next = curNode;
        } else {
            head->front = curNode;
        }
        
        lastNode = curNode;
        i++;
    }
    
    return head;
}

void free_list(struct llist * lst) {
    struct llnode * curNode;
    struct llnode * nextNode;
    if (lst->front) {
        curNode = lst->front;
        while(curNode) {
            nextNode = curNode->next;
            free(curNode);  
            curNode = nextNode;  
        }
    }
    free(lst->front);
}