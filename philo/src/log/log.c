/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:49:21 by germano           #+#    #+#             */
/*   Updated: 2022/10/11 19:44:35 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static char	*ft_strdup(char *str)
{
	char	*word;
	int		i;

	if (str == NULL)
		return (NULL);
	word = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = -1;
	while (str[++i] != '\0')
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

char	*get_suffix_msg(int	state)
{
	char	*messages[NUMBER_OF_STATES] = {
		" has taken a fork\n",
		" has taken a fork\n",
		" is eating\n",
		" is sleeping\n",
		" is thinking\n",
		" died\n"
	};
	return (ft_strdup(messages[state]));
}

static char	*get_timestamp_in_char()
{
	t_timeval		time;
	unsigned long	time_mili;

	gettimeofday(&time, NULL);
	time_mili = time.tv_usec;
	return (unsignedlongint_to_string(time_mili));
}

void	print_log(t_philo *philo)
{
	char		*msg;

	msg = get_timestamp_in_char();
	msg = ft_strjoin_and_free(msg, int_to_string(philo->id));
	msg = ft_strjoin_and_free(msg, get_suffix_msg((int)philo->state));
	write(STDOUT_FILENO, msg, ft_strlen(msg));
}