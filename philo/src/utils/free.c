/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:51:38 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/11 14:54:37 by germano          ###   ########.fr       */
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

void    program_free(t_fork **forks, t_clist **philos, t_rules *rules)
{
    int             i;
    pthread_mutex_t *curr_mutex;

    clst_clear(philos, ft_memfree);
    i = -1;
    while (++i < (int)rules->philo_amount)
    {
        curr_mutex = &(*forks)[i].mutex;
        pthread_mutex_destroy(curr_mutex);
    }
    ft_memfree((void **)forks);
}
