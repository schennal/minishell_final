/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:07:17 by schennal          #+#    #+#             */
/*   Updated: 2024/03/11 15:44:51 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_shell_mem(t_minishell *m)
{
	m->mem_alloc = ft_lstnew(NULL);
	if (!m->mem_alloc)
		return (1);
	m->t_head = ft_malloc(sizeof(t_token), m->mem_alloc);
	if (!m->t_head)
		return (1);
	m->path = ft_malloc(PATH_MAX, m->mem_alloc);
	if (!m->path)
		return (1);
	return (0);
}

bool	init_shell(t_minishell *m)
{
	m->a_size = 0;
	m->b_size = 0;
	m->input = NULL;
	if (init_shell_mem(m))
		return (1);
	m->t_head->next = NULL;
	m->t_head->cont = NULL;
	m->t_head->end_pos = -100;
	m->t_tail = m->t_head;
	m->exe_idx = 0;
	m->exe_size = 0;
	m->is_print_sig = 1;
	return (0);
}