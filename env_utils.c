/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:52:28 by schennal          #+#    #+#             */
/*   Updated: 2024/03/11 16:03:26 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_env(t_minishell *m)
{
	int		i;
	int		j;
	char	**env_tmp;
	int		env_size;

	i = 0;
	while (envp[i])
		i++;
	env_tmp = ft_malloc(sizeof(char *) * ++i, m->env_list);
	if (!env_tmp)
		return (1);
	m->env_size = i;
	j = 0;
	while (j < i - 1)
	{
		env_size = ft_strlen(envp[j]) + 1;
		env_tmp[j] = ft_malloc(env_size, m->env_list);
		if (!env_tmp[j])
			return (1);
		ft_strlcpy(env_tmp[j], envp[j], env_size);
		j++;
	}
	env_tmp[j] = NULL;
	envp = env_tmp;
	return (0);
}
