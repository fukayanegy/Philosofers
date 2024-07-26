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
