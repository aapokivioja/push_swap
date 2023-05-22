/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 14:48:06 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/22 13:06:03 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	has_duplicates(char **argv, int argc)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			k = 0;
			while (argv[i][k] != '\0' && argv[j][k] != '\0')
			{
				if (argv[i][k] != argv[j][k])
					break ;
				k++;
			}
			if (argv[i][k] == '\0' && argv[j][k] == '\0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	non_numeric(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **argv, int argc)
{
	argc--;
	while (argc > 1)
	{
		if (ft_atoi(argv[argc - 1]) > ft_atoi(argv[argc]))
			return (0);
		argc--;
	}
	return (-1);
}

int	min_max_check(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;
	int		sign;

	i = 1;
	while (i < argc)
	{
		j = 0;
		num = 0;
		sign = 1;
		if (argv[i][j] == '-')
		{
			sign = -1;
			j++;
		}
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
			num = num * 10 + argv[i][j++] - '0';
		num *= sign;
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int	error_check(char **argv, int argc)
{
	int	count;

	count = 1;
	if (has_duplicates(argv, argc) == -1)
		return (-1);
	if (non_numeric(argv, argc) == -1)
		return (-1);
	if (min_max_check(argc, argv) == -1)
		return (-1);
	return (0);
}
