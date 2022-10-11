/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:15:27 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/10 21:48:44 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*life_cicle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->state == NONE)
	// 	initial_state();
	// else if (philo->state == WAITING)
	// 	waiting_to_eat();
	// else if (philo->state == EAT)
	// 	eating();
	// else if (philo->state == SLEEP)
	// 	sleeping();
	// else if (philo->state == THINK)
	// 	thinking();
	// else if (philo->state == DEAD)
	// 	exit_due_death();
	// else if (philo->state == END_OF_PROGRAM)
	// 	exit_due_victory();
	usleep(100 * philo->right->id);
	printf("Hello from %d philosopher.\n", philo->right->id);
	return NULL;
}

void	starting_threads(t_clist *philos, t_rules *rules)
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

void	ending_threads(t_clist *philos, t_rules *rules)
{
	int		i;
	t_clist	*current_philo;
	t_philo	*philo;

	i = -1;
	current_philo = philos;
	while (++i < (int)rules->philo_amount)
	{
		philo = (t_philo *) current_philo->content;
		pthread_join(*(philo->th), NULL);
		current_philo = current_philo->next;
	}
}

void    run_philo(t_rules *rules)
{
	t_fork		*forks;
	t_clist		*philos;

	program_setup(&forks, &philos, rules);
	starting_threads(philos, rules);
	ending_threads(philos, rules);
	program_free(&forks, &philos, rules);
}