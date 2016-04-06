#include "yanghui_triangle.h"

int getlines(void)
{
	int n;

	printf("Enter the line(s) of Yang Hui's Triangle(Pascal's Triangle): ");
	scanf("%d", &n);

	return n;
}

void print_angle(int num_lines)
{
	linked_queue triangle;
	triangle = LinkedQueueInit();
	LinkedQueueEnter(triangle, 0);

	if (num_lines <= 0) {
		printf("line is too small.\n");
		exit(0);
	}
	while (num_lines > 0) {
		linked_queue_elemtype num1 = LinkedQueueExit(triangle);
		LinkedQueueEnter(triangle, 1);

		while (num1 != 0) {
			printf("%-4d", num1);
			linked_queue_elemtype num2 = LinkedQueueExit(triangle);
			LinkedQueueEnter(triangle, num1 + num2);
			num1 = num2;
		}
		printf("\n");
		LinkedQueueEnter(triangle, 0);

		num_lines--;
	}
	linked_queue_elemtype num = LinkedQueueExit(triangle);
	while (num != 0) {
		printf("%-4d", num);
		num = LinkedQueueExit(triangle);
	}
	printf("\n");
}

//print Yang Hui's Triangle(Pascal's Triangle) which has n line(s).
void yanghui_triangle()
{
	int n;

	n = getlines();
	print_angle(n);
}