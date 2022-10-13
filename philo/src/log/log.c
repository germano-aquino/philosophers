/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:49:21 by germano           #+#    #+#             */
/*   Updated: 2022/10/12 22:49:28 by grenato-         ###   ########.fr       */
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

static char	*get_suffix_msg(int state)
{
	char	*messages[NUMBER_OF_STATES];

	messages[0] = " has taken a fork\n";
	messages[1] = " has taken a fork\n";
	messages[2] = " is eating\n";
	messages[3] = " is sleeping\n";
	messages[4] = " is thinking\n";
	messages[5] = " died\n";
	messages[6] = " ";
	return (ft_strdup(messages[state]));
}

static char	*get_timestamp_in_char(void)
{
	unsigned long	time_mili;

	time_mili = get_timestamp();
	return (unsignedlongint_to_string(time_mili));
}

void	print_log(t_philo *philo)
{
	char	*msg;
	int		id;
	t_state	state;

	id = get_philo_id(philo);
	state = get_philo_state(philo);
	msg = get_timestamp_in_char();
	msg = ft_strjoin_and_free(msg, int_to_string(id));
	msg = ft_strjoin_and_free(msg, get_suffix_msg((int)state));
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	ft_memfree((void **)&msg);
}
