/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:23:03 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/08 12:24:36 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>


unsigned long int char_to_ulongint(char *str)
{
    unsigned long int number;
    unsigned char   *tmp;

    tmp = (unsigned char *)str;
    number = 0;
    while (tmp && *tmp != '\0')
    {
        number *= 10;
        number += (unsigned long int)(*tmp - '0');
    }
    return (number);
}

static unsigned long int    *alloc_numbers(int numb_amount)
{
    unsigned long int   *numbers;
    int                 i;

    numbers = malloc(sizeof(unsigned long int) * (numb_amount));
    if (numbers == NULL)
    {
        printf(ERR_MSG_ALLOC);
        exit(1);
    }
    i = -1;
    while (++i< numb_amount)
        numbers[i] = 0;
    return (numbers);
}

static void populate_numbers(unsigned long int *numb, int numbers_amount, char *argv[])
{
    int i;

    i = 0;
    while (++i < numbers_amount)
        numb[i - 1] = char_to_ulongint(argv[i]);
}

static void populate_rules(t_rules *rules, unsigned long int *numb, int numbers_amount)
{
    rules->philo_amount = numb[0];
    rules->die_time = numb[1];
    rules->eat_time = numb[2];
    rules->sleep_time = numb[3];
    if (numbers_amount == 5)
    {
        rules->has_must_eat = TRUE;
        rules->must_eat = numb[4];
    }
}

void    receive_input(int argc, char *argv[], t_rules *rules)
{
    unsigned long int   *numb;
    int                 numb_amount;

    numb_amount = argc - 1;
    validate_input(argc, argv);
    numb = alloc_numbers(numb_amount);
    populate_numbers(numb, numb_amount, argv);
    populate_rules(rules, numb, numb_amount);
    ft_memfree((void **)&numb);
}