/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:03:37 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/12 22:42:35 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_rules_must_finish(t_rules *rules, t_bool must_finish)
{
	pthread_mutex_lock(&rules->mutex);
	rules->must_finish = must_finish;
	pthread_mutex_unlock(&rules->mutex);
}
