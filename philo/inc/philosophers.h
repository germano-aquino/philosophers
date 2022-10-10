/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: germano <germano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:09 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/10 16:39:12 by germano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define ERR_MSG_INV_INPUT_AMOUNT "The program requires 4 or 5 parameters.\n"
# define USAGE_MSG "\
You should run the program as follows.\n\
./philo number_of_philos time_to_die time_to_eat time_to_sleep \
[number_of_times_philo_must_eat]\n\
"
# define ERR_MSG_INPUT_NOT_NUMB "This %s parameter has a non digit character.\n"
# define ERR_MSG_ALLOC "Allocation Error!\n"


typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_state
{
	NONE,
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


typedef struct s_fork
{
	int 			id;
	pthread_mutex_t	*mutex;
}	t_fork;


typedef struct s_philo
{
	pthread_t	*th;
	t_state		state;
	t_fork  	*left;
	t_fork  	*right;
}	t_philo;

typedef struct s_rules
{
	unsigned long int	philo_amount;
	unsigned long int	die_time;
	unsigned long int	eat_time;
	unsigned long int	sleep_time;
	unsigned long int	must_eat;
	t_bool				has_must_eat;
}	t_rules;



void    run_philo(t_rules *rules);
void    program_setup(t_fork **forks, t_clist **philos, t_rules *rules);

void    clst_addback(t_clist **head, t_clist *new_elt);
t_clist *create_clist_item(t_clist *next, t_clist *prev, void *content);

void    validate_input(int argc, char *argv[]);
void    receive_input(int argc, char *argv[], t_rules *rule);
void    ft_memfree(void **ptr);
#endif
