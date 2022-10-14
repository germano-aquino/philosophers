/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:39:13 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/13 23:05:25 by grenato-         ###   ########.fr       */
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

void	count_meal_amount(t_rules *rules)
{
	int				acc;
	static int		min;
	static int		philo_amount;
	static int		must_eat;
	static t_record	*meals;

	if (philo_amount == 0)
		philo_amount = (int)get_philo_amount(rules);
	if (must_eat == 0)
		must_eat = (int)get_must_eat(rules);
	if (meals == NULL)
		meals = get_meals_reference(rules);
	acc = get_accumulator(meals);
	if (acc >= (min + 1) * philo_amount)
	{
		min = get_meals_min(meals, philo_amount);
		if (min >= must_eat)
			set_rules_must_finish(rules, TRUE);
	}
}

void	*verify_philo_is_alive(void *args)
{
	t_rules	*rules;
	t_philo	*philo;
	t_clist	*clist_philo;
	t_bool	must_finish;
	t_bool	has_must_eat;

	clist_philo = (t_clist *)args;
	philo = (t_philo *)clist_philo->content;
	rules = get_philo_rules(philo);
	set_rules_bool(rules, &has_must_eat, &must_finish);
	while (must_finish == FALSE)
	{
		is_philo_alive(philo, rules);
		if (has_must_eat)
			count_meal_amount(rules);
		clist_philo = clist_philo->next;
		philo = (t_philo *)clist_philo->content;
		must_finish = get_must_finish(rules);
	}
	return (NULL);
}
