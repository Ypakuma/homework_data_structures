#include "KMP.h"

int main(void)
{
	char * string_aimed = "ababcdabbabababad";
	char * string_matched = "abababa";

	int ans = KMP(string_aimed, string_matched);

	return 0;
}