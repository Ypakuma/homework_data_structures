#include "KMP.h"

int KMP(char * string_aimed, char * string_matched)
{
	int * next = KMP_create_next_array(string_matched);
	int ans = KMP_match(string_aimed, string_matched, next);

	free(next);

	return ans;
}

int * KMP_create_next_array(char * string_matched)
{
	int len = strlen(string_matched);
	int * next = (int *) malloc(sizeof(int) * len);
	if (!next) {
		printf("Fail to allocate memory.\n");
		exit(0);
	}

	next[0] = -1;
	next[1] = 0;

	for (int i = 2; i < len; i++) {
		next[i] = KMP_get_next_value(string_matched, next, i - 1, next[i - 1]);
	}
	for (int i = 1; i < len; i++) {
		if (string_matched[i] == string_matched[next[i]])
			next[i] = next[next[i]];
	}
	return next;
}

int KMP_get_next_value(char * string_matched, int * next_array, int num1, int num2)
{
	if (string_matched[num1] == string_matched[num2])
		return num2 + 1;
	else if (next_array[num2] == -1)
		return 0;
	else
		return KMP_get_next_value(string_matched, next_array, num1, next_array[num2]);
}

int KMP_match(char * string_aimed, char * string_matched, int * next)
{
	int i = 0;
	int j = 0;
	int len_match = strlen(string_matched);
	int len_aim = strlen(string_aimed);

	while (j != len_aim && i != len_match) {
		if (string_matched[i] == string_aimed[j]) {
			i++;
			j++;
		}
		else if (next[i] == -1) {
			j++;
			i = 0;
		}
		else {
			i = next[i];
		}
	}
	if (i != len_match)
		return -1;
	else
		return j - len_match;
}
