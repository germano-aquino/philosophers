/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:03:51 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/13 22:14:49 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_meals_record(t_rules *rules, t_record *meals)
{
	int	i;
	int	philo_amount;

	philo_amount = (int) rules->philo_amount;
	meals->rec = (int *)malloc(sizeof(int) * philo_amount);
	i = -1;
	while (++i < philo_amount)
		meals->rec[i] = 0;
	meals->accumulator = 0;
	pthread_mutex_init(&meals->mutex, NULL);
}