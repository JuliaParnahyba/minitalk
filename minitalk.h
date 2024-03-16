/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:53:01 by jparnahy          #+#    #+#             */
/*   Updated: 2024/03/16 19:14:26 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*  -*-*-*-*-*-*-* C LIBRARIE USED *-*-*-*-*-*-  */

# include <signal.h>
# include "libft/minilib.h"

/*  -*-*-*-*-*-*-* MANDATORY FUNCTIONS PROTOTYPES  *-*-*-*-*-*-  */

void	back_sig(int type_sig);
void	char_by_char(int c, int id);

/*  -*-*-*-*-*-*-* MANDATORY FUNCTIONS PROTOTYPES  *-*-*-*-*-*-  */

void	back_sig_bonus(int type_sig, siginfo_t *info, void *context);

#endif
