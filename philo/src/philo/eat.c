/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:11:21 by germano           #+#    #+#             */
/*   Updated: 2022/10/12 22:52:20 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	pick_up_forks(t_philo *philo, t_rules *rules)
{
	t_fork	*f1;
	t_fork	*f2;

	pthread_mutex_lock(&philo->mutex);
	philo->state = WAIT;
	f1 = philo->left;
	f2 = philo->right;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&f1->mutex);
	if (get_must_finish(rules))
	{
		pthread_mutex_unlock(&f1->mutex);
		return (FALSE);
	}
	print_log(philo);
	pthread_mutex_lock(&f2->mutex);
	if (get_must_finish(rules))
	{
		pthread_mutex_unlock(&f1->mutex);
		pthread_mutex_unlock(&f2->mutex);
		return (FALSE);
	}
	print_log(philo);
	set_philo_last_meal(philo);
	return (TRUE);
}

void	return_forks(t_philo *philo)
{
	t_fork	*f1;
	t_fork	*f2;

	pthread_mutex_lock(&philo->mutex);
	f1 = philo->left;
	f2 = philo->right;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&f1->mutex);
	pthread_mutex_unlock(&f2->mutex);
}

void	eating(t_philo *philo, t_rules *rules)
{
	static unsigned long int	eat_time;

	if (!eat_time)
		eat_time = get_eat_time(rules);
	if (!pick_up_forks(philo, rules))
		return ;
	set_philo_state(philo, EAT);
	print_log(philo);
	usleep(eat_time * 1000);
	return_forks(philo);
	set_philo_state(philo, SLEEP);
	life_cicle((void *)philo);
}
