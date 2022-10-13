/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:30:33 by germano           #+#    #+#             */
/*   Updated: 2022/10/12 21:18:59 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	sleeping(t_philo *philo, t_rules *rules)
{
	static unsigned long int	sleep_time;

	if (!sleep_time)
		sleep_time = get_sleep_time(rules);
	print_log(philo);
	usleep(sleep_time * 1000);
	set_philo_state(philo, THINK);
	life_cicle((void *)philo);
}

void	thinking(t_philo *philo)
{
	print_log(philo);
	set_philo_state(philo, EAT);
	life_cicle((void *)philo);
}

void	waiting(t_philo *philo)
{
	usleep(1000);
	set_philo_state(philo, EAT);
	life_cicle((void *)philo);
}
