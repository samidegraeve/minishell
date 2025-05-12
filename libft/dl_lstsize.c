/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:44 by sadegrae          #+#    #+#             */
/*   Updated: 2025/05/12 22:46:45 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

int	dl_lstsize(t_stack *stack)
{
	int		i;
	t_node	*node;

	node = stack->up;
	i = 0;
	if (!stack)
		return (0);
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

	// ft_printf("-----------a-----------\n");
	// while (stack->up != NULL)
	// {
	// 	printf("%lld\n", stack->up->nbr);
	// 	stack->up = stack->up->next;
	// }