/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:37:51 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 18:46:34 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	*monitor(void *data_pointer)
{
	printf("start_monitor\n");
	return (data_pointer);
}

void	*supervisor(void *philo_pointer)
{
	printf("supervisor\n");
	return (philo_pointer);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->dead_line = philo->data->time_to_die + ft_get_time();
	if (pthread_create(&philo->thread, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		eating(philo);
		output(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	start_eating(t_data *data)
{
	int			i;
	pthread_t	thread1;

	(void)supervisor;
	data->start_time = (unsigned int)ft_get_time();
	if (data->must_eat_num > 0)
	{
		if (pthread_create(&thread1, NULL, &monitor, &data->philos[0]))
			return (1);
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
					&routine, &data->philos[i]))
			return (1);
		i++;
		usleep(10);
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
