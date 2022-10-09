/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:02 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/08 14:15:07 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char **argv)
{
    t_rules rules;

    receive_input(argc, argv, &rules);
    run_philo(&rules);
    return (0);
}