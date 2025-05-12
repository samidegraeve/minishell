/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:44:42 by sami              #+#    #+#             */
/*   Updated: 2025/05/12 22:46:30 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

void	dl_lstadd_back(t_stack *a, char *line, int start, int end)
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
		new->prev = a->low;
		a->low->next = new;
		a->low = new;
	}
}
