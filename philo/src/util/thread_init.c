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
