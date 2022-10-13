/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:29:15 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:41:49 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mutex);
	philo->state = state;
	pthread_mutex_unlock(&philo->mutex);
}

void	set_philo_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal_time = get_timestamp();
	pthread_mutex_unlock(&philo->mutex);
}
