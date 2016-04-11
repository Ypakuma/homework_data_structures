#include "string\application\KMP.h"
#include "string\homework_string.h"

int main(void)
{
	char * s1;
	char * s2;

	printf("Enter the aimed string(long): ");
	s1 = getstr();
	printf("Enter the matched string(short): ");
	s2 = getstr();

	int ans = KMP_main(s1, s2);

	return 0;
}
