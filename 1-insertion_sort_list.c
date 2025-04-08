#include "sort.h"

/**
 * swap_next - entry point
 *
 * Description: swaps node with next node
 * @curr_node: current node
 * @next_node: next node
 * Return: curr_node after swap
 */

listint_t *swap_next(listint_t *curr_node, listint_t *next_node)
{

	if (next_node->next)
		next_node->next->prev = curr_node;
	if (curr_node->prev)
		curr_node->prev->next = next_node;
	curr_node->next = next_node->next;
	next_node->prev = curr_node->prev;
	next_node->next = curr_node;
	curr_node->prev = next_node;

	return (next_node);
}

/**
 * swap_prev - entry point
 *
 * Description: swaps node with previous node
 * @curr_node: current node
 * @prev_node: previous node
 * Return: curr_node after swap
 */

listint_t *swap_prev(listint_t *curr_node, listint_t *prev_node)
{
	if (prev_node->prev)
		prev_node->prev->next = curr_node;
	if (curr_node->next)
		curr_node->next->prev = prev_node;
	prev_node->next = curr_node->next;
	curr_node->next = prev_node;
	curr_node->prev = prev_node->prev;
	prev_node->prev = curr_node;

	return (curr_node);
}


/**
 * insertion_sort_list - entry point
 *
 * Description: sorts doubly linked lists using insertion
 * @list: list to sort
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *next_node, *prev_node;

	curr_node = *list;
	next_node = curr_node->next;

	while (next_node)
	{
		if (curr_node->n > next_node->n)
		{
			prev_node = swap_next(curr_node, next_node);
			if (prev_node->next == *list)
				*list = prev_node;
			print_list(*list);

			while (prev_node->prev && prev_node->n < prev_node->prev->n)
			{
				prev_node = swap_prev(prev_node, prev_node->prev);
				if (prev_node->next == *list)
					*list = prev_node;
				print_list(*list);
			}
		}
		curr_node = next_node;
		next_node = curr_node->next;
	}
}
