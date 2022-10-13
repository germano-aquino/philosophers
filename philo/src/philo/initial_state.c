/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:46:26 by germano           #+#    #+#             */
/*   Updated: 2022/10/12 22:50:42 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	program_should_finish(t_philo *philo)
{
	long int	now;

	if (philo->state == DEAD || philo->state == END_OF_PROGRAM)
	{
		philo->rules->must_finish = TRUE;
		return ;
	}
	if (philo->rules->must_finish)
	{
		philo->state = DEAD;
		return ;
	}
	now = get_timestamp();
	if (philo->last_meal_time + (long int)philo->rules->die_time < now)
	{
		philo->state = DEAD;
		philo->rules->must_finish = TRUE;
	}
}

long int	get_timestamp(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((long int)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	initial_state(t_philo *philo, t_rules *rules)
{
	int							id;
	static unsigned long int	philo_amount;

	id = get_philo_id(philo);
	if (!philo_amount)
		philo_amount = get_philo_amount(rules);
	set_philo_last_meal(philo);
	if (id % 2 && (unsigned long int)id != philo_amount)
		set_philo_state(philo, EAT);
	else
		set_philo_state(philo, WAIT);
	life_cicle((void *)philo);
}
