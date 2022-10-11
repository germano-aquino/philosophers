/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:51:38 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/10 21:49:36 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    ft_memfree(void **ptr)
{
    if (*ptr == NULL)
        return ;
    free(*ptr);
    *ptr = NULL;
}

void    free_philo(void *content)
{
    t_philo *philo;

    philo = (t_philo *) content;
    ft_memfree((void **)&philo->th);
}

void    program_free(t_fork **forks, t_clist **philos, t_rules *rules)
{
    int i;

    clst_clear(philos, free_philo);
    i = -1;
    while (++i < (int)rules->philo_amount)
        pthread_mutex_destroy(forks[i]->mutex);
    ft_memfree((void **)forks);
}