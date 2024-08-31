/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:47:06 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 20:54:09 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include "struct.h"
# include "../lib/malloc_lib/malloc_lib.h"

int				ft_atoi(const char *nptr);
unsigned int	ft_get_time(void);
int				display_status(enum e_status status, t_philo *philo);
int				msleep(unsigned int mmseconds);

#endif
