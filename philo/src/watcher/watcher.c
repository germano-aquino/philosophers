/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:39:13 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:55:59 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	is_philo_alive(t_philo *philo, t_rules *rules)
{
	long int					now;
	long int					last_meal_time;
	static unsigned long int	die_time;

	now = get_timestamp();
	last_meal_time = get_philo_last_meal(philo);
	if (!die_time)
		die_time = get_die_time(rules);
	if (last_meal_time + (long int)die_time < now)
	{
		set_philo_state(philo, DEAD);
		print_log(philo);
		set_rules_must_finish(rules, TRUE);
	}
}

void	*verify_philo_is_alive(void *args)
{
	t_rules	*rules;
	t_philo	*philo;
	t_clist	*clist_philo;
	t_bool	must_finish;

	clist_philo = (t_clist *)args;
	philo = (t_philo *)clist_philo->content;
	rules = get_philo_rules(philo);
	must_finish = get_must_finish(rules);
	while (must_finish == FALSE)
	{
		is_philo_alive(philo, rules);
		clist_philo = clist_philo->next;
		philo = (t_philo *)clist_philo->content;
		must_finish = get_must_finish(rules);
	}
	return (NULL);
}
