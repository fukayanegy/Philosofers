#include "../../include/philosopher.h"

void	messages(char *str, t_philo *philo)
{
	// size_t	time;
	//
	// pthread_mutex_lock(&philo->data->write);
	// time = get_time() - philo->data->start_time;
	// if (ft_strcmp(DIED, str) == 0 && philo->data->dead == 0)
	// {
	// 	printf("%llu %d %s\n", time, philo->id, str);
	// 	philo->data->dead = 1;
	// }
	// if (!philo->data->dead)
	// 	printf("%llu %d %s\n", time, philo->id, str);
	// pthread_mutex_unlock(&philo->data->write);
	(void)str;
	((void)philo);
	return ;
}

void	take_fork(t_philo *philo)
{
	printf("take_fork\n");
	// pthread_mutex_lock(philo->r_fork);
	// messages(TAKE_FORKS, philo);
	// pthread_mutex_lock(philo->l_fork);
	// messages(TAKE_FORKS, philo);
	(void)philo;
	return ;
}

void	drop_fork(t_philo *philo)
{
	printf("drop_fork\n");
	// pthread_mutex_unlock(philo->l_fork);
	// pthread_mutex_unlock(philo->r_fork);
	// messages(SLEEPING, philo);
	// ft_usleep(philo->data->sleep_time);
	(void)philo;
	return ;
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	messages(EATING, philo);
	philo->eat_cont++;
	ft_usleep(philo->data->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
	(void)philo;
	return ;
}
