/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:30:33 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 19:35:53 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	go_sleep(t_philo *philo)
{
	philo->state = SLEEP;
	print_log(philo);
	usleep(philo->rules->sleep_time * 1000);
	go_think(philo);
}