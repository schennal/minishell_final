/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:25:06 by schennal          #+#    #+#             */
/*   Updated: 2024/03/11 15:56:24 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
    t_minishell minishell;
    
    init_signal();
    set_terminal(&minishell);
    minishell.end_status = 0;
    minishell.env_list = ft_lstnew(NULL);
	if (!minishell.env_list)
	{
		perror("minishell");
		exit(1);
	}
	init_shell(&minishell);
	if (init_env(&minishell))
	{
		perror("minishell");
		exit(1);
	}
	start_env(&minishell);
	main_loop(&minishell);
	ft_free_all(minishell.env_list);
    exit (0);
}