/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:38:05 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/10 22:17:07 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    display_rules(t_rules *rules)
{
    printf("Philo Amount:%ld\n", rules->philo_amount);
    printf("Time to Die:%ld\n", rules->die_time);
    printf("Time to Eat:%ld\n", rules->eat_time);
    printf("Time to Sleep:%ld\n", rules->sleep_time);
    printf("Philo have to eat at least %ld times.\n", rules->must_eat);
}