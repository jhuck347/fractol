/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhuck <juhuck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:05:28 by jhuck             #+#    #+#             */
/*   Updated: 2025/07/30 17:25:10 by juhuck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	buffer;

	buffer = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1));
	ft_strlcat(res, s2, buffer + 1);
	return (res);
}
