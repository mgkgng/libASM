#include "libasm.h"

int main() {
	char *test_str = strdup("Hello world!");

	extern size_t ft_strlen();
	extern char *ft_strcpy();
	// extern	ft_strcmp();
	// extern	ft_write();
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

	printf("ft_strlen result: %s\n", ft_dest);
	printf("strlen result: %s\n", dest);

	return (0);
}
