#include "../include/philosopher.h"

int	convert_input(int ac, char **av, t_data *data);
int	alloc_fork_philo(t_data *data);
int	link_fork_philo(t_data *data);
int	philo_init(t_data *data);
int	thread_init(t_data *data);
int	start_eating(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;

	if (convert_input(ac, av, &data))
		return (1);
	if (alloc_fork_philo(&data))
		return (1);
	if (link_fork_philo(&data))
		return (1);
	if (philo_init(&data))
		return (1);
	if (thread_init(&data))
		return (1);
	if (start_eating(&data))
		return (1);
	return (0);
}
