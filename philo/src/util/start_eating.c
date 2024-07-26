#include "../../include/philosopher.h"

void	*monitor(void *data_pointer)
{
	printf("start_monitor\n");
	return (data_pointer);
}

void	*supervisor(void *philo_pointer)
{
	return (philo_pointer);
}

void	*routine(void *philo_pointer)
{
	printf("routine\n");
	return (philo_pointer);
}


int	start_eating(t_data *data)
{
	int			i;
	pthread_t	thread1;

	(void)data;
	(void)monitor;
	(void)supervisor;
	(void)routine;
	// data->start_time = ft_get_time();
	if (data->must_eat_num > 0)
	{
		if (pthread_create(&thread1, NULL, &monitor, &data->philos[0]))
			return (1);
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]))
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
