/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:44:30 by etakaham          #+#    #+#             */
/*   Updated: 2024/07/26 20:45:40 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

unsigned int	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (unsigned int)1000) + (tv.tv_usec / 1000));
}
