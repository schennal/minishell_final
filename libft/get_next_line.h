/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:25:30 by schennal          #+#    #+#             */
/*   Updated: 2024/03/12 15:25:44 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_str
{
	char			content;
	struct s_str	*next;
}	t_str;
typedef struct s_gnl
{
	int		idx;
	int		read_num;
	int		len;
	char	buffer[BUFFER_SIZE];
}	t_gnl;

char	*get_next_line(int fd);
t_str	*ft_strnew(char content);
void	ft_strclear(t_str **lst);
int		ft_strsize(t_str *lst);
int		copy_buffer(t_str **tail, t_gnl *status);
void	copy_str(char *str, t_str *lst);
#endif
