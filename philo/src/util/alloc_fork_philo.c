/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fork_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:46:52 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 18:46:53 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

int	alloc_fork_philo(t_data *data)
{
	data->philos = ft_calloc(data->philo_num, sizeof(t_philo), data->m_node);
	if (!data->philos)
		return (1);
	data->forks = ft_calloc(data->philo_num, sizeof(pthread_mutex_t),
			data->m_node);
	if (!data->forks)
		return (1);
	return (0);
}
