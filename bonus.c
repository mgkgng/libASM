#include "libasm.h"

void print_list(t_list *list) {
    while (list) {
        printf("loop...!\n");
        printf("%s\n", list->data);
        list = list->next;
    }
}

int main() {
    extern int  ft_atoi_base(char *str, char *base);
    extern void ft_list_push_front(t_list **begin_list, void *data);
    extern int  ft_list_size(t_list *begin_list);
    extern void ft_list_sort(t_list **begin_list, int (*cmp)());
    extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

    //char *base = "0123456789abcdef";
    //printf("test %i\n", ft_atoi_base("  +--+-a", base));

    t_list *test = malloc(sizeof(t_list));
    test->data = "test";
    test->next = NULL;
    ft_list_push_front(&test, "test2");
    print_list(test);

    t_list *test2 = NULL;
    ft_list_push_front(&test2, "test3");
    print_list(test2);

}