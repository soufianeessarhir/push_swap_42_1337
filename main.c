
#include "push_swap.h"

int main(int ac, char  **av)
{
	t_list *stack_a;
	 stack_a = NULL;
	if (parcing(ac, av, stack_a) == 0)
	{
		write(1, "Error\n",6);
		return (0);
	}
	return 0;
}

