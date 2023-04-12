#include "lib.h"

int main() {
	extern size_t	ft_strlen(const char *s);
	extern char*	ft_strcpy(char *dest, const char *src);
	extern int		ft_strcmp(const char *s1, const char *s2);
	extern ssize_t	ft_write(int fd, const void *buf, size_t count);
	extern ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
	extern char*	ft_strdup(const char *s);

	printf("LIBASM TEST STARTS\n");
	
	usleep(DELAY);
	printf("=======================\n");
	printf("ft_strlen\n");
	printf("=======================\n");

	usleep(DELAY);
	printf("test1: Try ft_strlen with an empty string\n");
	if (ft_strlen("") == strlen(""))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test2: Try ft_strlen with a very long string\n");
	char *test_str = "afadsifojadiopjapdiosfjapsjfopisdjfipasdfjpioajfoajfpoijdsiofjijapsdfjaopisdfjiopasdfjpoidsajfpioasdjfopiajsdopifjasdiopfjadsipofjiopasdfjpiaosfjioasdjfioasdjpoifjasiopdfjpoasdfpjasdipofjiaosdjgiafdgiudfhsguidouibnodsfnovndsaifniasdfiuadshfiouaisuvnicnivouhdiuosafhinsidnniovnianrinaiefiuhinidnviasndfiasdifpiasdfhiufnouodsivchaiosudfhciasndufchsdifucadsfhasudfxuaiosfidnfasdhiouvas fahsdim ifhisiufahsoiufhxusfshvuhsuxfhmaiuhb";
	if (ft_strlen(test_str) == strlen(test_str))
		printf("OK\n");
	else
		printf("KO\n");

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
	char *test1 = strdup("zHelloasdasdasdasworld!");
	char *test2 = strdup("poadkasda===as=dasd");

	printf("strcmp result: %d\n", strcmp(test1, test2));
	printf("ft_strcmp result: %d\n", ft_strcmp(test1, test2));

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_write\n");
	printf("=======================\n");

	printf("write result: %zd\n", write(1, "Oui oui\n", 8));
	printf("ft_strcmp result: %zd\n", ft_write(1, "Oui oui\n", 8));

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_read\n");
	printf("=======================\n");

	int fd1 = open("srcs/test1", 0666);
	int fd2 = open("srcs/test2", 0666);
	char buf1[99];
	char buf2[99];

	printf("read result: %zd\n", read(fd1, &buf1, 8));
	printf("ft_read result: %zd\n", ft_read(fd2, &buf2, 8));

	printf("read result: %s\n", buf1);
	printf("ft_read result: %s\n", buf2);

	close(fd1);
	close(fd2);

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strdup\n");
	printf("=======================\n");

	char *ft_str = ft_strdup("boom boom pow");
	char *str = strdup("boom boom pow");
	printf("ft_strdup result: %s\n", ft_str);
	printf("strdup result: %s\n", str);

	return (0);
}
