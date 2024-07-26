#include "../../include/philosopher.h"

int	convert_input(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (1);
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat_num = ft_atoi(av[5]);
	else
		data->must_eat_num = -1;
	data->dead = 0;
	data->finished = 0;
	return (0);
}
