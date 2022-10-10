/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:15:27 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/10 16:40:24 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*life_cicle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->state == NONE)
		initial_state();
	else if (philo->state == WAITING)
		waiting_to_eat();
	else if (philo->state == EAT)
		eating();
	else if (philo->state == SLEEP)
		sleeping();
	else if (philo->state == THINK)
		thinking();
	else if (philo->state == DEAD)
		exit_due_death();
	else if (philo->state == END_OF_PROGRAM)
		exit_due_victory();
}

void	starting_threads(t_fork *forks, t_clist *philos, t_rules *rules)
{
	int		i;
	t_clist	*current_philo;
	t_philo	*philo;

	i = -1;
	current_philo = philos;
	while(++i < (int)rules->philo_amount)
	{
		philo = (t_philo *)current_philo->content;
		pthread_create(philo->th, NULL, life_cicle, current_philo->content);
		current_philo = current_philo->next;
	}
}

void    run_philo(t_rules *rules)
{
	t_fork		*forks;
	t_clist		*philos;

	program_setup(&forks, &philos, rules);
	starting_threads(forks, philos, rules);
	ending_threads(forks, philos, rules);
}