#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct double_node
{
    int val;
    struct double_node *prev;
    struct double_node *next;
}doubleNode;

