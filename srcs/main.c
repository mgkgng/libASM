#include "lib.h"
#include <errno.h>

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
	char ft_dest[99999];
	char dest[99999];

	usleep(DELAY);
	printf("test1: Try ft_strcpy with an empty string\n");
	ft_strcpy(ft_dest, "");
	strcpy(dest, "");
	if (!strcmp(ft_dest, dest))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test2: Try ft_strcpy with a very long string\n");
	ft_strcpy(ft_dest, test_str);
	strcpy(dest, test_str);
	if (!strcmp(ft_dest, dest))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strcmp\n");
	printf("=======================\n");

	usleep(DELAY);
	printf("test1: Try ft_strcmp with 2 empty strings\n");
	if (ft_strcmp("", "") == strcmp("", ""))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test2: Try ft_strcmp with 1 empty string as first argument\n");
	if (ft_strcmp("", test_str) == strcmp("", test_str))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test3: Try ft_strcmp with 1 empty string as second argument\n");
	if (ft_strcmp(test_str, "") == strcmp(test_str, ""))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test4: Try ft_strcmp with multiple strings, equal or not\n");
	char *test_str2 = "lol";
	char *test_str3 = "lal";
	char *test_str4 = "lal";
	if (ft_strcmp(test_str, test_str2) == strcmp(test_str, test_str2)
		&& ft_strcmp(test_str, test_str3) == strcmp(test_str, test_str3)
		&& ft_strcmp(test_str2, test_str3) == strcmp(test_str2, test_str3)
		&& ft_strcmp(test_str3, test_str4) == strcmp(test_str3, test_str4))
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_write\n");
	printf("=======================\n");

	usleep(DELAY);
	printf("test1: Try ft_write with the stdout\n");
	char *test_5 = "I'm trying ft_write with the stdout\n";
	ft_write(1, test_5, strlen(test_5));
	
	usleep(DELAY);
	printf("test2: Try ft_write with an open file descriptor\n");
	char *test_6 = "I'm trying ft_write with an open file descriptor\n";
	int fd = open("srcs/test_write", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	ft_write(fd, test_6, strlen(test_6));
	close(fd);

	usleep(DELAY);
	printf("test3: Try ft_write with a wrong file descriptor\n");
	char *test_7 = "I'm trying ft_write with a wrong file descriptor\n";
	int res_write = ft_write(999, test_7, strlen(test_7));
	int err = errno;
	int res_write2 = write(999, test_7, strlen(test_7));
	int err2 = errno;
	if (err == err2)
		printf("OK\n");
	else
		printf("KO\n");
	
	usleep(DELAY);
	printf("test4: Check the return value\n");
	if (res_write == res_write2)
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_read\n");
	printf("=======================\n");

	usleep(DELAY);
	printf("test1: Try ft_read with the stdin\n");
	char buf[99999];
	ft_read(0, buf, 99999);
	printf("ft_read result: %s\n", buf);

	usleep(DELAY);
	printf("test2: Try ft_read with an open file descriptor\n");
	int fd2 = open("srcs/lorem_ipsum", O_RDONLY);
	int fd3 = open("srcs/lorem_ipsum2", O_RDONLY);
	char buf2[99999];
	int res = ft_read(fd2, buf, 99999);
	int res2 = read(fd3, buf2, 99999);

	buf[res] = '\0';
	buf2[res2] = '\0';
	if (!strcmp(buf, buf2))
		printf("OK\n");
	else
		printf("KO\n");
	close(fd2);
	close(fd3);

	usleep(DELAY);
	printf("test3: Try ft_read with a wrong file descriptor\n");
	int res3 = ft_read(999, buf, 1);
	int err3 = errno;
	int res4 = read(999, buf, 1);
	int err4 = errno;
	if (err3 == err4)
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("test4: Check the return value\n");
	if (res3 == res4)
		printf("OK\n");
	else
		printf("KO\n");

	usleep(DELAY);
	printf("=======================\n");
	printf("TESTING ft_strdup\n");
	printf("=======================\n");

	usleep(DELAY);
	printf("test1: Try ft_strdup with an empty string\n");
	char *test_8 = "";
	char *ft_test_8 = ft_strdup(test_8);
	if (!strcmp(ft_test_8, test_8))
		printf("OK\n");
	else
		printf("KO\n");
	
	usleep(DELAY);
	printf("test2: Try ft_strdup with a very long string\n");
	if (!strcmp(ft_strdup(test_str), test_str))
		printf("OK\n");
	else
		printf("KO\n");

	return (0);
}
