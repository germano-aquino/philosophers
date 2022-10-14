/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:37:08 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/13 22:59:28 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_record	*get_meals_reference(t_rules *rules)
{
	t_record	*meals;

	pthread_mutex_lock(&rules->mutex);
	meals = &rules->meals;
	pthread_mutex_unlock(&rules->mutex);
	return (meals);
}

long int	get_accumulator(t_record *meals)
{
	long int	acc;

	pthread_mutex_lock(&meals->mutex);
	acc = meals->accumulator;
	pthread_mutex_unlock(&meals->mutex);
	return (acc);
}

int	get_meals_min(t_record *meals, int philo_amount)
{
	int	i;
	int	min;

	i = -1;
	pthread_mutex_lock(&meals->mutex);
	min = meals->rec[0];
	while (++i < philo_amount)
	{
		if (min > meals->rec[i])
			min = meals->rec[i];
	}
	pthread_mutex_unlock(&meals->mutex);
	return (min);
}

void	inc_meals_rec(t_record *meals, int index)
{
	pthread_mutex_lock(&meals->mutex);
	meals->accumulator += 1;
	meals->rec[index] += 1;
	pthread_mutex_unlock(&meals->mutex);
}
