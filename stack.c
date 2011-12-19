#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

stack *stack_alloc() {
    stack *list = malloc(sizeof(stack));
    memset(list, 0, sizeof(stack));
    return list;
}

void stack_push(stack *list, char *val) {
    list->current = malloc(sizeof(stack_item));
    list->current->val = val;
    list->current->next = (struct stack_item *)list->top;
    list->top = list->current;
}

char stack_pop(stack *list) {
    char *val = list->top->val;
    stack_item *p = list->top;

    list->top = (stack_item *)list->top->next;
    free(p);

    return *val;
}

void stack_display(stack *list) {
    stack_item *p = list->top;
    while (p != NULL) {
        printf("%s ", p->val);
        p = (stack_item *)p->next;
    }

    printf("\n");
}

void stack_free(stack *list) {
    stack_item *p = list->top;
    while (p != NULL) {
        p = (stack_item *)p->next;
        stack_pop(list);
    }

    free(list);
}
