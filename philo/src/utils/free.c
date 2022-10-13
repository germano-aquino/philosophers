/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:51:38 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:55:28 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_memfree(void **ptr)
{
	if (*ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	free_philo(void **arg)
{
	t_philo	*philo;

	philo = (t_philo *)*arg;
	pthread_mutex_destroy(&philo->mutex);
	ft_memfree(arg);
}

void	program_free(t_fork **forks, t_clist **philos, t_rules *rules)
{
	int				i;
	pthread_mutex_t	*curr_mutex;

	clst_clear(philos, free_philo);
	i = -1;
	while (++i < (int)rules->philo_amount)
	{
		curr_mutex = &(*forks)[i].mutex;
		pthread_mutex_destroy(curr_mutex);
	}
	ft_memfree((void **)forks);
	pthread_mutex_destroy(&rules->mutex);
}
