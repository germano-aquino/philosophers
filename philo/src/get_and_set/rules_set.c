/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:03:37 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/13 21:45:05 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_rules_must_finish(t_rules *rules, t_bool must_finish)
{
	pthread_mutex_lock(&rules->mutex);
	rules->must_finish = must_finish;
	pthread_mutex_unlock(&rules->mutex);
}

void	set_rules_bool(t_rules *rules, t_bool *has_must_eat, t_bool *must_finish)
{
	pthread_mutex_lock(&rules->mutex);
	if (must_finish != NULL)
		*must_finish = rules->must_finish;
	if (has_must_eat != NULL)
		*has_must_eat = rules->has_must_eat;
	pthread_mutex_unlock(&rules->mutex);
}

unsigned long int	get_must_eat(t_rules *rules)
{
	unsigned long int	must_eat;

	pthread_mutex_lock(&rules->mutex);
	must_eat = rules->must_eat;
	pthread_mutex_unlock(&rules->mutex);
	return (must_eat);
}
