/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:36:33 by qmoreau           #+#    #+#             */
/*   Updated: 2021/11/27 15:11:13 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (str)
		ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
