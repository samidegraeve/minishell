/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh < najeuneh@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:11:32 by najeuneh          #+#    #+#             */
/*   Updated: 2024/09/16 16:29:19 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_countcmd(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->up;
	while (node != NULL)
	{
		if (node->flag == 8)
			i++;
		node = node->next;
	}
	return (i);
}

void	ft_use_bultin(t_node *node, t_env *env)
{
	if (ft_strcmp(node->content, "echo") == 0)
	{
		if (node->full_cmd[1] == NULL)
			printf("\n");
		else
			ft_echo(node);
	}
	else if (ft_strcmp(node->content, "cd") == 0)
		ft_cd(env, node);
	else if (ft_strcmp(node->content, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(node->content, "export") == 0)
	{
		ft_export(env, node, 1);
	}
	else if (ft_strcmp(node->content, "unset") == 0)
		ft_unset(env, node);
	else if (ft_strcmp(node->content, "env") == 0)
		printf_env(env);
	else if (ft_strcmp(node->content, "exit") == 0)
		ft_exit(node->full_cmd, 0);
}

void	ft_perror(void)
{
	exit(1);
}

void	ft_wait(int pid, int status, int count)
{
	while (count != 0)
	{
		if (wait(&status) == pid)
		{
			if (WIFEXITED(status))
				g_exit_code = WEXITSTATUS(status);
		}
		count--;
	}
}

void	ft_check_out(t_node *node)
{
	if (node->out != NULL)
	{
		if (node->append == 1)
		{
			node->out_fd = open(node->out, O_RDWR | O_CREAT | O_APPEND, 0644);
		}
		else
			node->out_fd = open(node->out, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (node->out_fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(node->out, 2);
			ft_putstr_fd(" no such file or directory", 2);
			ft_putstr_fd("\n", 2);
			g_exit_code = 1;
			exit(g_exit_code);
		}
	}
	else
		node->out_fd = -1;
}
