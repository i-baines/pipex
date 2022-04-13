/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:45:54 by ibaines           #+#    #+#             */
/*   Updated: 2022/04/13 12:30:26 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**ft_splitraro(char const *s, char c);
void	ft_putstr(char *str);
void	ft_free2(char **str);
void	ft_putstr2(char *str);
char	**ft_getpath(char **env);
int		ft_get_size(char **env);
void	ft_secondchild(char **argv, int *fd1, char **env);
void	ft_test2(char **argv, int *fd1, char **env);

#endif
