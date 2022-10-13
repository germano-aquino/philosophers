/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_to_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:41:41 by germano           #+#    #+#             */
/*   Updated: 2022/10/12 22:50:21 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*strjoin;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	i = -1;
	while (++i < len1 + len2)
	{
		if (i < len1)
			strjoin[i] = s1[i];
		else
			strjoin[i] = s2[i - len1];
	}
	strjoin[i] = '\0';
	ft_memfree((void **)&s1);
	ft_memfree((void **)&s2);
	return (strjoin);
}

static int	get_digits_amount(unsigned long int number)
{
	int	amount;

	if (number == 0)
		return (1);
	amount = 0;
	while (number != 0)
	{
		amount++;
		number /= 10;
	}
	return (amount);
}

char	*unsignedlongint_to_string(unsigned long int number)
{
	char	*str;
	int		digits_amount;

	digits_amount = get_digits_amount(number);
	str = malloc(sizeof(char) * (digits_amount + 2));
	str[digits_amount + 1] = '\0';
	str[digits_amount] = ' ';
	while (digits_amount--)
	{
		str[digits_amount] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

char	*int_to_string(int id)
{
	char	*str;
	int		digits_amount;

	digits_amount = get_digits_amount((unsigned long int)id);
	str = malloc(sizeof(char) * (digits_amount + 1));
	str[digits_amount] = '\0';
	while (digits_amount--)
	{
		str[digits_amount] = (id % 10) + '0';
		id /= 10;
	}
	return (str);
}
