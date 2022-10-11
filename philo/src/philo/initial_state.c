/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inital_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:26 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 15:25:38 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long int	get_timestamp(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((long int)(time.tv_usec / 1000));
}

void	initial_state(t_philo *philo)
{
	philo->last_meal_time = get_timestamp();
	if (philo->id % 2 && (unsigned int long)philo->id != philo->rules->philo_amount)
		try_to_eat(philo);
	else
		waiting_to_eat(philo);
}