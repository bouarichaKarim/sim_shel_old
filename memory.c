#include "shell.h"

/**
 * bfree -this do  frees a pointer and NULLs the address
 * @ptr: the address of the pointer to be free
 *
 * Return: 1 if its freed, if its not 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
