/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:09 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/11 19:38:29 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_MSG_INV_INPUT_AMOUNT "The program requires 4 or 5 parameters.\n"
# define USAGE_MSG "\
You should run the program as follows.\n\
./philo number_of_philos time_to_die time_to_eat time_to_sleep \
[number_of_times_philo_must_eat]\n\
"
# define ERR_MSG_INPUT_NOT_NUMB "This %s parameter has a non digit character.\n"
# define ERR_MSG_ALLOC "Allocation Error!\n"
# define NUMBER_OF_STATES 7


typedef struct timeval t_timeval;


typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_state
{
	INIT,
	WAITING,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	END_OF_PROGRAM
}	t_state;

typedef struct s_clist
{
	void    *content;
	struct s_clist *next;
	struct s_clist *prev;
}   t_clist;

typedef struct s_rules
{
	unsigned long int	philo_amount;
	unsigned long int	die_time;
	unsigned long int	eat_time;
	unsigned long int	sleep_time;
	unsigned long int	must_eat;
	t_bool				has_must_eat;
}	t_rules;

typedef struct s_fork
{
	int 			id;
	t_bool			busy;
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct s_philo
{
	int			id;
	long int	last_meal_time;
	pthread_t	th;
	t_state		state;
	t_fork  	*left;
	t_fork  	*right;
	t_rules		*rules;
}	t_philo;



void    run_philo(t_rules *rules);
void    program_setup(t_fork **forks, t_clist **philos, t_rules *rules);

void    clst_clear(t_clist **head, void (*f)(void **));
void    clst_addback(t_clist **head, t_clist *new_elt);
t_clist *create_clist_item(t_clist *next, t_clist *prev, void *content);

void    validate_input(int argc, char *argv[]);
void    receive_input(int argc, char *argv[], t_rules *rule);

void	waiting_to_eat(t_philo *philo);
void	go_sleep(t_philo *philo);
void	go_think(t_philo *philo);
void	try_to_eat(t_philo *philo);

void	initial_state(t_philo *philo);

void    display_rules(t_rules *rules);

void	print_log(t_philo *philo);

int 	ft_strlen(char *str);
char    *ft_strjoin_and_free(char *s1, char *s2);
char	*unsignedlongint_to_string(unsigned long int number);
char	*int_to_string(int id);

void    ft_memfree(void **ptr);
void    program_free(t_fork **forks, t_clist **philos, t_rules *rules);
#endif
