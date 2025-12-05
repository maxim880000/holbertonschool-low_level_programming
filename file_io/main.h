#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>    /* read, write, close */
#include <fcntl.h>     /* open, O_RDONLY */
#include <sys/types.h> /* ssize_t, size_t */
#include <sys/stat.h>  /* permissions */
#include <stdlib.h>    /* malloc, free, exit */

/* Prototypes des fonctions */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int _putchar(char c);

#endif