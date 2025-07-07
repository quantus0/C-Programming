#include <stdio.h>
#include <stdlib.h>

struct slinklist {
    int data;
    struct slinklist* next;
};

typedef struct slinklist node;

node *start = NULL;

node* getnode() {
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    printf("\n Enter data : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

void traverse() {
    node *temp;
    temp = start;
    printf("\n The contents of List (Left to Right):\n");
    if (start == NULL)
        printf("Empty List");
    else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
    printf("X\n");
}

int countnode(node *st) {
    if (st == NULL)
        return 0;
    else
        return (1 + countnode(st->next));
}

void createlist(int n) {
    node* newnode;
    node* temp;
    for (int i = 0; i < n; i++) {
        newnode = getnode();
        if (start == NULL) {
            start = newnode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void insert_at_beg() {
    node* newnode = getnode();
    newnode->next = start;
    start = newnode;
}

void insert_at_end() {
    node *newnode = getnode();
    node *temp;
    if (start == NULL) {
        start = newnode;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_at_mid() {
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    printf("\n Enter the Position : ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if (pos > 1 && pos < nodectr) {
        temp = prev = start;
        while (ctr < pos) {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    } else {
        printf("%d is not a middle position\n", pos);
    }
}

void delete_at_beg() {
    node* temp;
    if (start == NULL) {
        printf("\n No nodes exist");
        return;
    } else {
        temp = start;
        start = start->next;
        free(temp);
        printf("\n Node deleted");
    }
}

void delete_at_end() {
    node *temp, *prev;
    if (start == NULL) {
        printf("\n No nodes exist");
        return;
    } else if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        temp = start;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("\n Node deleted");
}

void delete_at_mid() {
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    if (start == NULL) {
        printf("\n No nodes exist");
        return;
    } else {
        printf("\n Enter position of node to delete: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if (pos > nodectr) {
            printf("\n This node does not exist");
        } else if (pos > 1 && pos < nodectr) {
            temp = prev = start;
            while (ctr < pos) {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
            printf("\n Node deleted");
        } else {
            printf("\n Position is not in the middle");
        }
    }
}

