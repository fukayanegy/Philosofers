/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:37:51 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 20:46:06 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	eating(t_philo *philo);

static void	*monitor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_unlock(&philo->data->write);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_num)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

static void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (ft_get_time() >= philo->dead_line && philo->eating == 0)
			display_status(DIED, philo);
		if (philo->eat_count == philo->data->must_eat_num)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_count++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

static void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->dead_line = philo->data->time_to_die + ft_get_time();
	if (pthread_create(&philo->thread, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		eating(philo);
		display_status(THINKING, philo);
	}
	if (pthread_join(philo->thread, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	start_eating(t_data *data)
{
	int			i;
	pthread_t	thread1;

	data->start_time = ft_get_time();
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
		msleep(10);
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
