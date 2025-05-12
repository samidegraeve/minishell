/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:33:23 by najeuneh          #+#    #+#             */
/*   Updated: 2025/05/12 22:47:27 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char		*str;
// 	//char		str2[] = "bonjour";

// 	if (!(str = ft_strchr("teste", '\0')))
// 		printf("NULL");
// }