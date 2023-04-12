#include "lib.h"

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

    usleep(DELAY);
    printf("test1: hexadecimal base (-a1bcfg)\n");
    if (ft_atoi_base("  +--+-a1bcfg", "0123456789abcdef") == -662479)
        printf("OK\n");
    else
        printf("KO\n");
    
    usleep(DELAY);
    printf("\n");
    printf("test2: wrong base (1 number)\n");
    if (ft_atoi_base("2222222", "2") == 0)
        printf("OK\n");
    else
        printf("KO\n");
    
    usleep(DELAY);
    printf("\n");
    printf("test3: base 3 (314)\n");
    if (ft_atoi_base("4433111", "314") == 1957)
        printf("OK\n");
    else
        printf("KO\n");

    usleep(DELAY);
    printf("\n");
	printf("=======================\n");
	printf("TESTING ft_list_push_front\n");
	printf("=======================\n");

    t_list *test = malloc(sizeof(t_list));
    test->data = "test";
    test->next = NULL;
    ft_list_push_front(&test, "test2");
    usleep(DELAY);
    printf("test1: after one push\n");
    print_list(test);

    usleep(DELAY);
    printf("\n");
    printf("test2: push_front before NULL\n");
    t_list *test2 = NULL;
    ft_list_push_front(&test2, "null_test");
    print_list(test2);

    usleep(DELAY);
    printf("\n");
    printf("test3: push a lot more\n");
    ft_list_push_front(&test, "test3");
    ft_list_push_front(&test, "test4");
    ft_list_push_front(&test, "test5");
    ft_list_push_front(&test, "test6");
    ft_list_push_front(&test, "test7");
    print_list(test);


    usleep(DELAY);
    printf("\n");
	printf("=======================\n");
	printf("TESTING ft_list_size\n");
	printf("=======================\n"); 
    
    usleep(DELAY);
    printf("test1: size of test\n");
    printf("%d\n", ft_list_size(test));

    usleep(DELAY);
    printf("test2: size of NULL\n");
    printf("%d\n", ft_list_size(NULL));

    usleep(DELAY);
    printf("\n");
	printf("=======================\n");
	printf("TESTING ft_list_sort\n");
	printf("=======================\n");

    usleep(DELAY);
    printf("test1: sort test\n");
    printf("before: ");
    print_list(test);
    ft_list_sort(&test, strcmp);
    printf("after: ");
    print_list(test);

    usleep(DELAY);
    printf("\n");
    printf("test2: sort after putting more\n");
    ft_list_push_front(&test, "abraham");
    ft_list_push_front(&test, "zibra");
    printf("before: ");
    print_list(test);
    ft_list_sort(&test, strcmp);
    printf("after: ");
    print_list(test);

    usleep(DELAY);
    printf("\n");
	printf("=======================\n");
	printf("TESTING ft_list_remove_if\n");
	printf("=======================\n");

    usleep(DELAY);
    printf("test1: remove the first element\n");
    printf("before: ");
    print_list(test);
    ft_list_remove_if(&test, "abraham", strcmp, free);
    printf("after: ");
    print_list(test);

    usleep(DELAY);
    printf("\n");
    printf("test2: remove an element in the middle\n");
    ft_list_remove_if(&test, "test5", strcmp, free);
    print_list(test);

    usleep(DELAY);
    printf("\n");
    printf("test3: remove the last element\n");
    ft_list_remove_if(&test, "zibra", strcmp, free);
    print_list(test);

    return (0);
}