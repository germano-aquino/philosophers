/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:34:13 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 19:58:25 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	go_think(t_philo *philo)
{
	philo->state = THINK;
	print_log(philo);
	return ;
}