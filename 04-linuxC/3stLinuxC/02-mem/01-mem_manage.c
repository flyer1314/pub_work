#include <stdio.h>
#include <stdlib.h>

#if (0)
#include <stdlib.h>
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

#include <unistd.h>
int getpagesize(void);

#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags,
int fd, off_t offset);
int munmap(void *addr, size_t length);
#endif

#define DEBUG_TEST
#define MAX_NAME_TYPE 6
#define NAME_MAX_SIZE 16

void printf_arr_str(int )

#ifdef DEBUG_TEST
int main(int argc,char **argv)
{
	char func[MAX_NAME_TYPE][NAME_MAX_SIZE] = {
		"calloc",
		"free",
		"getpagesize",
		"malloc",
		"mmap",
		"munmap"
	};

	enum FUNC{
		CALLOC,
		FREE,
		GETPAGESIZE,
		MALLOC,
		MMAP,
		MUNMAP
	}func_name;

	if(argc < 2)
	{
		printf("Usage : %s funcname\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
#endif
