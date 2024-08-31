/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:01:26 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 20:11:23 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

int	display_status(enum e_status status, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(&philo->data->write);
	time = ft_get_time() - philo->data->start_time;
	if (status == DIED && philo->data->dead == 0)
	{
		printf("%u %d died\n", time, philo->id);
		philo->data->dead = 1;
	}
	else if (!philo->data->dead && status == TAKE_FORKS)
		printf("%u %d has taken a fork\n", time, philo->id);
	else if (!philo->data->dead && status == THINKING)
		printf("%u %d is thinking\n", time, philo->id);
	else if (!philo->data->dead && status == EATING)
		printf("%u %d is eating\n", time, philo->id);
	else if (!philo->data->dead && status == SLEEPING)
		printf("%u %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->write);
	return (0);
}
