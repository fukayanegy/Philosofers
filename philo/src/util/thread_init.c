/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:37:20 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 18:46:32 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

int	thread_init(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
	return (0);
}
