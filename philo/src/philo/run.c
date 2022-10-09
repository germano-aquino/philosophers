/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:15:27 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/08 15:24:42 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    run_philo(t_rules *rules)
{
	t_fork		*forks;
	t_clist		*philos;
	pthread_t	*th;

	program_setup(&forks, &philos, rules);
}