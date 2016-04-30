#include "homework_string.h"

char* getstr(void)
{
	char* str;
	char* _str;
	int i = 1;
	str = (char*) malloc(sizeof(char) * (i + 1));
	while ('\n' != (str[i - 1] = getchar())) {
		i++;
		_str = (char*) malloc(strlen(str) + 1);
		str[i - 1] = '\0';
		strcpy(_str, str);
		free(str);
		str = (char*) malloc(sizeof(char) * (i + 1));
		if (NULL == str) {
			free(_str);
			printf("No enough memory!");
			return NULL;
		}
		strcpy(str, _str);
		free(_str);
	}
	str[i - 1] = '\0';
	return str;
}