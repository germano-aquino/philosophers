/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:42:09 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/13 23:03:23 by grenato-         ###   ########.fr       */
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
	WAIT,
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
}	t_clist;

typedef struct s_record
{
	int				*rec;
	long int 		accumulator;
	pthread_mutex_t	mutex;
}	t_record;


typedef struct s_rules
{
	unsigned long int	philo_amount;
	unsigned long int	die_time;
	unsigned long int	eat_time;
	unsigned long int	sleep_time;
	unsigned long int	must_eat;
	t_record			meals;
	t_bool				has_must_eat;
	t_bool				must_finish;
	pthread_mutex_t		mutex;
}	t_rules;

typedef struct s_fork
{
	int 			id;
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct s_philo
{
	int				id;
	long int		last_meal_time;
	pthread_mutex_t	mutex;
	pthread_t		th;
	t_state			state;
	t_fork  		*left;
	t_fork  		*right;
	t_rules			*rules;
}	t_philo;



void				run_philo(t_rules *rules);
void				program_setup(t_fork **forks, t_clist **philos, t_rules *rules);

void				clst_clear(t_clist **head, void (*f)(void **));
void				clst_addback(t_clist **head, t_clist *new_elt);
t_clist 			*create_clist_item(t_clist *next, t_clist *prev, void *content);

void				validate_input(int argc, char *argv[]);
void				receive_input(int argc, char *argv[], t_rules *rule);

void				*life_cicle(void *arg);

void				waiting(t_philo *philo);
void				sleeping(t_philo *philo, t_rules *rules);
void				thinking(t_philo *philos);
void				eating(t_philo *philo, t_rules *rules);
void				initial_state(t_philo *philo, t_rules *rules);

void				display_rules(t_rules *rules);

void				print_log(t_philo *philo);

int 				ft_strlen(char *str);
char				*ft_strjoin_and_free(char *s1, char *s2);
char				*unsignedlongint_to_string(unsigned long int number);
char				*int_to_string(int id);

long int			get_timestamp(void);

void				ft_memfree(void **ptr);
void				program_free(t_fork **forks, t_clist **philos, t_rules *rules);
void				program_should_finish(t_philo *philo);
void				*verify_philo_is_alive(void *args);

int 				get_philo_id(t_philo *philo);
t_state 			get_philo_state(t_philo *philo);
long int			get_philo_last_meal(t_philo *philo);
t_rules 			*get_philo_rules(t_philo *philo);
void				set_philo_state(t_philo *philo, t_state state);
void				set_philo_last_meal(t_philo *philo);

unsigned long int	get_philo_amount(t_rules *rules);
unsigned long int	get_die_time(t_rules *rules);
unsigned long int	get_sleep_time(t_rules *rules);
unsigned long int	get_eat_time(t_rules *rules);
unsigned long int	get_must_eat(t_rules *rules);
t_bool				get_must_finish(t_rules *rules);
void				set_rules_bool(t_rules *rules, t_bool *has_must_eat, t_bool *must_finish);
void				set_rules_must_finish(t_rules *rules, t_bool must_finish);

void				init_meals_record(t_rules *rules, t_record *meals);
t_record			*get_meals_reference(t_rules *rules);
long int			get_accumulator(t_record *meals);
int					get_meals_min(t_record *meals, int philo_amount);
void				inc_meals_rec(t_record *meals, int index);

#endif
