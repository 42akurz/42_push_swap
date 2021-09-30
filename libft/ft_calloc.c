/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:20:57 by akurz             #+#    #+#             */
/*   Updated: 2021/07/28 09:12:47 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*b;
	size_t	i;

	i = 0;
	b = (char *)(malloc(size * count));
	if (b == NULL)
		return (NULL);
	while (i < size * count)
	{
		b[i] = 0;
		i++;
	}
	return ((void *) b);
}
//size_t: size_t selbe wie unsigned int (ist meint counter fuer while loop)
//b =: malloc type casting weil man mit char und void nicht rechnen kann
//erstes if: wichtig muss bei malloc immer mit rein
//erster while: speicher mit nullen vollmachen
//return: void pointer muss returned werden deshalb wieder type casten
