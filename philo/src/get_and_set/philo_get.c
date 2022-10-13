/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:26:27 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:41:16 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	get_philo_id(t_philo *philo)
{
	int	id;

	pthread_mutex_lock(&philo->mutex);
	id = philo->id;
	pthread_mutex_unlock(&philo->mutex);
	return (id);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mutex);
	state = philo->state;
	pthread_mutex_unlock(&philo->mutex);
	return (state);
}

long int	get_philo_last_meal(t_philo *philo)
{
	long int	last_meal;

	pthread_mutex_lock(&philo->mutex);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->mutex);
	return (last_meal);
}

t_rules	*get_philo_rules(t_philo *philo)
{
	t_rules	*rules;

	pthread_mutex_lock(&philo->mutex);
	rules = philo->rules;
	pthread_mutex_unlock(&philo->mutex);
	return (rules);
}
