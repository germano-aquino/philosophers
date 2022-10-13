/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:26:47 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:42:19 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

unsigned long int	get_philo_amount(t_rules *rules)
{
	unsigned long int	philo_amount;

	pthread_mutex_lock(&rules->mutex);
	philo_amount = rules->philo_amount;
	pthread_mutex_unlock(&rules->mutex);
	return (philo_amount);
}

unsigned long int	get_die_time(t_rules *rules)
{
	unsigned long int	die_time;

	pthread_mutex_lock(&rules->mutex);
	die_time = rules->die_time;
	pthread_mutex_unlock(&rules->mutex);
	return (die_time);
}

unsigned long int	get_sleep_time(t_rules *rules)
{
	unsigned long int	sleep_time;

	pthread_mutex_lock(&rules->mutex);
	sleep_time = rules->sleep_time;
	pthread_mutex_unlock(&rules->mutex);
	return (sleep_time);
}

unsigned long int	get_eat_time(t_rules *rules)
{
	unsigned long int	eat_time;

	pthread_mutex_lock(&rules->mutex);
	eat_time = rules->eat_time;
	pthread_mutex_unlock(&rules->mutex);
	return (eat_time);
}

t_bool	get_must_finish(t_rules *rules)
{
	t_bool	must_finish;

	pthread_mutex_lock(&rules->mutex);
	must_finish = rules->must_finish;
	pthread_mutex_unlock(&rules->mutex);
	return (must_finish);
}
