/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:14:22 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/11 11:58:29 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*create_philo(t_fork *left, t_fork *right, t_state state, int id)
{
	t_philo	*new_philo;

	new_philo = (t_philo *)malloc(sizeof(t_philo));
	new_philo->id = id;
	new_philo->left = left;
	new_philo->right = right;
	new_philo->state = state;
    return (new_philo);
}

t_clist	*create_philo_clist(unsigned long int philo_amount, t_fork *forks)
{
	t_clist				*philo_clist;
	t_philo				*new_philo;
	unsigned long int	i;

	i = 0;
	new_philo = create_philo(&forks[philo_amount - 1], &forks[0], NONE, i + 1);
	philo_clist = create_clist_item(NULL, NULL, (void *)new_philo);
	while (++i < philo_amount)
	{
		new_philo = create_philo(&forks[i - 1], &forks[i], NONE, i + 1);
		clst_addback(&philo_clist, create_clist_item(NULL, NULL, (void *)new_philo));
	}
	return (philo_clist);
}

t_fork  *create_forks(unsigned long int forks_amount)
{
	t_fork				*forks;
	unsigned long int	i;

	forks = (t_fork *)malloc(sizeof(t_fork) * forks_amount);
	if (forks == NULL)
	{
		printf(ERR_MSG_ALLOC);
		exit(1);
	}
	i = -1;
	while (++i < forks_amount)
	{
		forks[i].id = 1 + i;
		pthread_mutex_init(&forks[i].mutex, NULL);
		printf("Mutex %d init.\n", forks[i].id);
	}
	return (forks);
}

void    program_setup(t_fork **forks, t_clist **philos, t_rules *rules)
{
    *forks = create_forks(rules->philo_amount);
	*philos = create_philo_clist(rules->philo_amount, *forks);
}