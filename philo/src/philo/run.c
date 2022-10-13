/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:15:27 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 23:54:02 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	change_philo_state(t_philo *philo, t_rules *rules)
{
	t_state	state;

	state = get_philo_state(philo);
	if (state == INIT)
		initial_state(philo, rules);
	else if (state == WAIT)
		waiting(philo);
	else if (state == EAT)
		eating(philo, rules);
	else if (state == SLEEP)
		sleeping(philo, rules);
	else if (state == THINK)
		thinking(philo);
	return ;
}

void	*life_cicle(void *arg)
{
	t_rules	*rules;
	t_philo	*philo;
	t_bool	must_finish;

	philo = (t_philo *)arg;
	rules = get_philo_rules(philo);
	must_finish = get_must_finish(rules);
	if (!must_finish)
		change_philo_state(philo, rules);
	return (NULL);
}

void	starting_threads(t_clist *philos, pthread_t *watcher, t_rules *rules)
{
	int		i;
	t_clist	*current_philo;
	t_philo	*philo;

	i = -1;
	current_philo = philos;
	while (++i < (int)rules->philo_amount)
	{
		philo = (t_philo *)current_philo->content;
		pthread_create(&philo->th, NULL, life_cicle, current_philo->content);
		current_philo = current_philo->next;
	}
	pthread_create(watcher, NULL, verify_philo_is_alive, (void *)philos);
}

void	ending_threads(t_clist *philos, pthread_t *watcher, t_rules *rules)
{
	int		i;
	t_clist	*current_philo;
	t_philo	*philo;

	i = -1;
	current_philo = philos;
	while (++i < (int)rules->philo_amount)
	{
		philo = (t_philo *) current_philo->content;
		pthread_join(philo->th, NULL);
		current_philo = current_philo->next;
	}
	pthread_join(*watcher, NULL);
}

void	run_philo(t_rules *rules)
{
	t_fork		*forks;
	t_clist		*philos;
	pthread_t	watcher;

	program_setup(&forks, &philos, rules);
	starting_threads(philos, &watcher, rules);
	ending_threads(philos, &watcher, rules);
	program_free(&forks, &philos, rules);
}
