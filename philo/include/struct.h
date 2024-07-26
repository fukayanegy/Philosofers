/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:47:03 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 18:47:04 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../lib/malloc_lib/malloc_lib.h"

enum e_status {
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
};

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		thread;
	int				id;
	int				eat_count;
	enum e_status	status;
	int				eating;
	unsigned int	dead_line;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_data
{
	pthread_t		thread;
	int				philo_num;
	int				dead;
	int				finished;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				must_eat_num;
	unsigned int	start_time;
	unsigned int	eating_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	t_node			*m_node;
}					t_data;

#endif
