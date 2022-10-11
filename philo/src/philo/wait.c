/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:55:08 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 16:57:47 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	waiting_to_eat(t_philo *philo)
{
	philo->state = WAITING;
	usleep(1000);
	try_to_eat(philo);
}