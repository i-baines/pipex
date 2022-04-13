/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:35:12 by ibaines           #+#    #+#             */
/*   Updated: 2022/04/13 12:29:36 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "pipex.h"
#include <stdio.h> // librearia de test
#include <string.h> // libreria de tt

int	ft_get_command(char **argcc, char **env)
{
	int		x;
	int		i;
	char	*ptr;

	i = 0;
	while (env[i])
	{
		ptr = ft_strjoin(env[i], argcc[0]);
		x = access(ptr, X_OK);
		if (x == 0)
			execve(ptr, &argcc[0], env);
		else
		{
			if (i == (ft_get_size(env) - 1))
				ft_putstr2(argcc[0]);
		}
		free(ptr);
		i++;
	}
	return (0);
}

int	ft_open(void)
{
	int	fd;

	fd = open("mifd", O_CREAT, 0644);
	return (fd);
}

void	ft_test(int file1, char *str, int *fd1, char **env)
{
	char	**command;	

	close(fd1[0]);
	dup2(file1, STDIN_FILENO);
	dup2(fd1[1], STDOUT_FILENO);
	close(fd1[1]);
	command = ft_split(str, ' ');
	ft_get_command(command, env);
	ft_free2(command);
	close(file1);
}

void	ft_test2(char **argv, int *fd1, char **env)
{
	int		pid;
	char	**ptr;
	int		file2;

	close(fd1[1]);
	pid = fork();
	if (pid == 0)
	{
		file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file2 == -1)
			return ;
		dup2(fd1[0], STDIN_FILENO);
		close(fd1[0]);
		dup2(file2, STDOUT_FILENO);
		close(file2);
		ptr = ft_split(argv[3], ' ');
		ft_get_command(ptr, env);
		ft_free2(ptr);
	}
	else
	{
		close(fd1[0]);
		waitpid(pid, NULL, 0);
		close(fd1[1]);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd1[2];
	int		file1;
	int		pid;
	char	**path;

	path = ft_getpath(env);
	if (argc != 5)
		return (0);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		perror("zsh");
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		if (file1 == -1)
			exit(0);
		ft_test(file1, argv[2], fd1, path);
	}
	else
	{
		waitpid(pid, NULL, 0);
		ft_secondchild(argv, fd1, path);
	}
	return (0);
}
