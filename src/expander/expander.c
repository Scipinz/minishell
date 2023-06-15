/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 17:00:13 by kblok         #+#    #+#                 */
/*   Updated: 2023/06/15 15:28:44 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*expanded_exit(char *input)
{

}

static char	*get_dollar_val(char *input)
{

}

static char	*get_env_val(char *input)
{
	bool	exit_code;
	int		i;

	i = 0;

}

static char	*set_res(char *input)
{
	int		i;
	char	*dollar_val;
	char	*env_val;
	bool	expand;

	i = 0;
	expand = true;
	while (input[i] && expand)
	{
		expand = check_expand(&input[i]);
		g_shell.expanded_exit = false;
		if (input[i] == '$')
		{
			dollar_val = get_dollar_val(&input[i]);
			env_val = get_env_val(&input[i]);
			input = replace(input, dollar_val, env_val);
			if (!input)
				return (NULL);
			if (g_shell.expanded_exit)
				free(env_val);
			free(dollar_val);
		}
		i++;
	}
	return (input);
}

char	*expand(char *input)
{
	char	*temp;

	temp = set_res(input);
	if (!temp)
		return (NULL);
	return (temp);
}