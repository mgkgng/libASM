#include "libasm.h"

int main() {
	char *test_str = strdup("Hello world!");

	extern size_t	ft_strlen();
	extern char*	ft_strcpy();
	extern int		ft_strcmp();
	extern size_t	ft_write();
	// extern	ft_read();
	// extern	ft_strdup();

	printf("LIBASM TEST STARTS\n");
	
	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strlen\n");
	printf("=======================\n");

	printf("ft_strlen result: %zu\n", ft_strlen(test_str));
	printf("strlen result: %lu\n", strlen(test_str));

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strcpy\n");
	printf("=======================\n");
	char ft_dest[99];
	char dest[99];

	ft_strcpy(ft_dest, test_str);
	strcpy(dest, test_str);

	printf("ft_strcpy result: %s\n", ft_dest);
	printf("strcpy result: %s\n", dest);

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strcmp\n");
	printf("=======================\n");
	char test1[99] = "ssasdasdsss";
	char test2[1000] = "poadkasda===as=dasd";

	printf("ft_strcmp result: %d\n", ft_strcmp(test1, test2));
	printf("strcmp result: %d\n", strcmp(test1, test2));

	return (0);
}
