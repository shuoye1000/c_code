#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct Stu
{
    int no;
    int age;
    struct list_node list;
};

int main()
{
    struct list_node* iter;
    struct Stu head;
    struct Stu* p;

    list_init_head(&head.list);

    int i = 5;
    while (i--)
    {
        struct Stu* stu = (struct Stu*)malloc(sizeof(struct Stu));
        if(stu != NULL)
        {
            stu->no = i;
            stu->age = i+3;
            list_push_back(&head.list, &stu->list);
        }
    }

    list_for_each(iter, &head.list)
    {
        p = list_entry(iter, struct Stu, list);
        printf("%d, %d\n", p->no, p->age);
    }

    printf("\nReversed list:\n");
    list_for_each_reverse(iter, &head.list)
    {
        p = list_entry(iter, struct Stu, list);
        printf("%d, %d\n", p->no, p->age);
    }

    struct list_node* iter_backup;
    list_for_each_remove(iter, iter_backup, &head.list)
    {
        p = list_entry(iter, struct Stu, list);
        list_remove(iter);
        free(p);
    }

    return 0;
}
