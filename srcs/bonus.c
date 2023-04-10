#include "libasm.h"

void print_list(t_list *list) {
    while (list) {
        printf("%s--", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    extern int  ft_atoi_base(char *str, char *base);
    extern void ft_list_push_front(t_list **begin_list, void *data);
    extern int  ft_list_size(t_list *begin_list);
    extern void ft_list_sort(t_list **begin_list, int (*cmp)());
    extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

	printf("LIBASM BONUS TEST STARTS\n");
	
	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_atoi_base\n");
	printf("=======================\n");

    char *base = "0123456789abcdef";
    printf("test %i\n", ft_atoi_base("  +--+-a", base));

    usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_list_push_front\n");
	printf("=======================\n");

    t_list *test = malloc(sizeof(t_list));
    test->data = "test";
    test->next = NULL;
    ft_list_push_front(&test, "test2");
    print_list(test);

    t_list *test2 = NULL;
    ft_list_push_front(&test2, "null_test");
    print_list(test2);

    usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_list_size\n");
	printf("=======================\n"); 
    
    ft_list_push_front(&test, "test3");
    ft_list_push_front(&test, "test4");
    ft_list_push_front(&test, "test5");
    ft_list_push_front(&test, "test6");
    ft_list_push_front(&test, "test7");
    printf("list size: %i\n", ft_list_size(test));
    print_list(test);

    usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_list_sort\n");
	printf("=======================\n");

    ft_list_sort(&test, strcmp);
    print_list(test);
    ft_list_push_front(&test, "abraham");
    ft_list_push_front(&test, "zibra");
    print_list(test);
    ft_list_sort(&test, strcmp);
    print_list(test);

    usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_list_remove_if\n");
	printf("=======================\n");

    ft_list_remove_if(&test, "abraham", strcmp, free);
    print_list(test);
    ft_list_remove_if(&test, "test5", strcmp, free);
    print_list(test);
    ft_list_remove_if(&test, "zibra", strcmp, free);
    print_list(test);
}