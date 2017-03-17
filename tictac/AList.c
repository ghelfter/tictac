/*  ============== Galen Helfter ==============  */
/*  ==============    AList.c    ==============  */

#include <stdlib.h>
#include <string.h>

#include "AList.h"

/*  Internal function  */
struct alist_node* alist_node_create(const char *key, void *value);

void alist_init(struct alist *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void* alist_find(struct alist *list, const char *key)
{
    void *result = NULL;

    struct alist_node *iter = list->head;

    while(iter != NULL)
    {
        if(!strcmp(key, iter->key))
        {
            result = iter->value;
            break;
        }

        iter = iter->next;
    }

    return result;
}

void alist_insert(struct alist *list, const char *key, void *value)
{
    struct alist_node *node = NULL;

    if(key == NULL)
    {
        return;
    }

    node = alist_node_create(key, value);

    if(list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

void* alist_remove(struct alist *list, const char *key)
{
    void *result = NULL;

    struct alist_node *iter = list->head;
    struct alist_node *prev = NULL;

    while(iter != NULL)
    {
        if(!strcmp(key, iter->key))
        {
            result = iter->value;
            if(iter == list->head)
            {
                list->head = iter->next;
            }
            if(iter == list->tail)
            {
                list->tail = prev;
            }
            if(prev != NULL)
            {
                prev->next = iter->next;
            }

            free(iter->key);
            free(iter);
            break;
        }

        iter = iter->next;
        prev = iter;
    }

    return result;
}

void alist_clear(struct alist *list)
{
    struct alist_node *iter = list->head;
    struct alist_node *next = NULL;

    while(iter != NULL)
    {
        next = iter->next;
        if(iter->value != NULL)
            free(iter->value);
        free(iter->key);
        free(iter);
        iter = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

struct alist_node* alist_node_create(const char *key, void *value)
{
    struct alist_node *node = malloc(sizeof(struct alist_node));
    node->key = malloc(strlen(key) + 1);

    strcpy(node->key, key);
    node->value = value;
    node->next = NULL;

    return node;
}
