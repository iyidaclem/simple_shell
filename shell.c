#include "simple_shell.c"

int main(void)
{
	char *lineptr;
	size_t n;

	while (1)
	{
		show_prompt(&lineptr, &n);
	}
}

