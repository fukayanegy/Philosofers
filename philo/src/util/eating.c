#include "../../include/philosopher.h"

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	display_status(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->l_fork);
	display_status(TAKE_FORKS, philo);
}

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	display_status(SLEEPING, philo);
	usleep(philo->data->time_to_sleep);
}

void	eating(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->dead_line = ft_get_time() + philo->data->time_to_die;
	display_status(EATING, philo);
	philo->eat_count++;
	usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}
