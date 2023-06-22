/*
 * prototypes for functions in string_funcs.c
 */


/* Copies String t to s using array indexing */
void array_strcpy(char *s, char *t);

/* Copies String t to s using pointers */
void ptr_strcpy(char *s, char *t);

/* Copies the first n characters of t to s */
void my_strncpy(char *s, char *t, int n);

/* Concatenates t to s */
void my_strcat(char *s, char *t);
