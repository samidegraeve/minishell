/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:54:38 by najeuneh          #+#    #+#             */
/*   Updated: 2025/05/12 22:47:30 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strcreate(char *line, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (line == NULL)
		return (NULL);
	str = malloc((end - start) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = line[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
