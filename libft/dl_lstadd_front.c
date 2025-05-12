/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:44:45 by sami              #+#    #+#             */
/*   Updated: 2025/05/12 22:46:34 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

void	dl_lstadd_front(t_stack *a, char *line, int start, int end)
{
	t_node	*new;

	new = dl_lstnew(line, start, end);
	if (a->up == NULL)
	{
		a->up = new;
		a->low = new;
	}
	else
	{
		new->next = a->up;
		a->up->prev = new;
		a->up = new;
	}
}
