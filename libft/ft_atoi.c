/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadegrae <sadegrae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:44:37 by sami              #+#    #+#             */
/*   Updated: 2025/05/12 22:46:48 by sadegrae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/libft.h"

int	check_arg(const char *str, int i)
{
	if ((str[i] == '-' && ft_strncmp(str, "-9223372036854775808", 21) > 0)
		|| ((str[i] == '+' || str[i] == '-')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		|| !(str[i] == '+' || str[i] == '-'
			|| (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((ft_strncmp(str, "9223372036854775807", 20) > 0)
		|| (ft_strlen(str) > 19 && str[i] >= '0' && str[i] <= '9'))
		return (2);
	return (0);
}
/*SEGFAULT if NULL*/

long long	ft_atoi(const char *str1)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str1[i] == 32 || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str1[i++] - 48);
	}
	return (nb * sign);
}

long long	ft_atoi2(const char *str1)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str1[i] == 32 || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+' || str1[i] == '"')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str1[i] >= '0' && str1[i] <= '9') || str1[i] == '"')
	{
		while (str1[i] == '"')
			i++;
		if (str1[i] == '\0')
			break ;
		nb *= 10;
		nb = nb + (str1[i++] - 48);
	}
	return (nb * sign);
}
