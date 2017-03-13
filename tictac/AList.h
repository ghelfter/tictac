/*  ============== Galen Helfter ==============  */
/*  ==============    AList.h    ==============  */

#ifndef _ALIST_H__
#define _ALIST_H__

struct alist_node
{
    char *key;
    void *value;

    struct alist_node *next;
};

struct alist
{
    struct alist_node *head;
    struct alist_node *tail;
};

void alist_init(struct alist *list);
void* alist_find(struct alist *list, const char *key);
void alist_insert(struct alist *list, const char *key, void *value);
void* alist_remove(struct alist *list, const char *key);
void alist_clear(struct alist *list);

#endif
