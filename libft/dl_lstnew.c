/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:42 by sadegrae          #+#    #+#             */
/*   Updated: 2025/05/12 22:46:43 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

t_node	*dl_lstnew(char *line, int start, int end)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = ft_strcreate(line, start, end);
	node->flag = 0;
	node->bultin = 0;
	node->cmd = NULL;
	node->in = NULL;
	node->out = NULL;
	node->in_fd = 0;
	node->out_fd = 0;
	node->full_cmd = NULL;
	node->heredoc = 0;
	node->append = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
