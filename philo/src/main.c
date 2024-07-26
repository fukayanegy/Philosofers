/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:37:37 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 18:37:37 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	data.m_node = malloc(sizeof(t_node));
	if (!data.m_node)
		return (1);
	malloc_startup(data.m_node);
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
	malloc_end(data.m_node);
	return (0);
}

__attribute__((destructor))
static void    destructor(void)
{
	system("leaks -q philo");
}
