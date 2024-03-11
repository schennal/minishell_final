/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:25:27 by schennal          #+#    #+#             */
/*   Updated: 2024/03/11 15:54:56 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

extern int					g_sig;
extern char					**envp;

typedef enum e_type
{
	TYPE_PIPE,
	TYPE_REDIR_IN,
	TYPE_REDIR_OUT,
	TYPE_REDIR_AP,
	TYPE_HEREDOC,
	TYPE_COMMAND,
	TYPE_ARG,
	TYPE_FD,
	TYPE_DELIMETER,
	TYPE_FILENAME
}	t_type;

typedef struct s_token
{
	char	*cont;
	t_token	*next;
	int		pos;
	int		end_pos;
	t_type	type;
	bool	is_div;
}           t_token;

typedef struct s_token
{
	char	*cont;
	t_token	*next;
	int		pos;
	int		end_pos;
	t_type	type;
	bool	is_div;
};

typedef struct s_rdr
{
	int		fd;
	int		o_fd;
	char	*fn;
	t_type	type;
	bool	if_rdr;
}           t_rdr;

typedef struct s_hdc
{
	int		fd;
	char	*eof;
	int		pipe[2];
}           t_hdc;

struct s_exe
{
	char	**args;
	t_rdr	*rdr;
	t_hdc	*hdc;
	int		rdr_size;
	int		hdc_size;
	pid_t	pid;
	int		pipe[2];
	bool	if_exe;
};

typedef struct s_minishell
{
    bool        is_print_sig;
    int         a_size;
    int         b_size;
    int         exe_idx;
    int         exe_size;
    int         env_size;
    long long	end_status;
    char        *input;
    char        *path;
    t_list		*env_list;
    t_list      *mem_alloc;
    t_token     *t_head;
    t_token     *t_tail;
}             t_minishell ;


#endif