/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:11:21 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 20:07:29 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	forks_are_available(t_fork *f1, t_fork *f2)
{
	return (!(f1->busy || f2->busy));
}

void	pick_up_forks(t_fork *f1, t_fork *f2, t_philo *philo)
{
	pthread_mutex_lock(&f1->mutex);
	f1->busy = TRUE;
	print_log(philo);
	pthread_mutex_lock(&f2->mutex);
	f2->busy = TRUE;
	print_log(philo);
}

void	return_forks(t_fork *f1, t_fork *f2)
{
	f1->busy = FALSE;
	pthread_mutex_unlock(&f1->mutex);
	f2->busy = FALSE;
	pthread_mutex_unlock(&f2->mutex);
}

void	try_to_eat(t_philo *philo)
{
	pick_up_forks(philo->left, philo->right, philo);
	philo->state = EAT;
	print_log(philo);
	usleep(philo->rules->eat_time * 1000);
	return_forks(philo->left, philo->right);
	go_sleep(philo);
}