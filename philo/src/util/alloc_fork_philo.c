#include "../../include/philosopher.h"

int	alloc_fork_philo(t_data *data)
{
	data->philos = malloc(data->philo_num * sizeof(t_philo));
	if (!data->philos)
		return (1);
	data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	return (0);
}
