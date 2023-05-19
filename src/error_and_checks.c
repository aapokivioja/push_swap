/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 14:48:06 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/19 15:31:08 by akivioja      ########   odam.nl         */
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

int	large_int_check(int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		value = 0;
		while (*argv[i] >= '0' && *argv[i] <= '9')
		{
			value = value * 10 + (*argv[i] - '0');
			argv[i]++;
		}
		if (value > 2147483647)
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
	if (large_int_check(argc, argv) == -1)
		return (-1);
	return (0);
}
