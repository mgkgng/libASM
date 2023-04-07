#include "libasm.h"

int main() {
    extern int  ft_atoi_base(char *str, char *base);
    extern int  check_base(char *base);
    extern void ft_list_push_front(t_list **begin_list, void *data);
    extern int  ft_list_size(t_list *begin_list);
    extern void ft_list_sort(t_list **begin_list, int (*cmp)());
    extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

    char *base = "0128";

    printf("test %d\n", check_base(base));
}