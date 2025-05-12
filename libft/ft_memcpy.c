/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:48:17 by najeuneh          #+#    #+#             */
/*   Updated: 2025/05/12 22:47:17 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*sdest;
	char	*ssrc;
	size_t	i;

	i = 0;
	ssrc = (char *)src;
	sdest = dst;
	if (n > ft_strlen(dst))
		return ("error");
	while (n)
	{
		sdest[i] = ssrc[i];
		i++;
		n--;
	}
	return (sdest);
}
