/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergauth <jergauth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:24:14 by jergauth          #+#    #+#             */
/*   Updated: 2020/07/15 13:12:17 by jergauth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WHITESPACES " \t\n\r\v\f"
# define CMD_DELIMITER ";"

# define PATH			"PATH="
# define PATH_DELIMITER	":"

# define PROMPT_COLOR	"\033[1;32m"

# define ARR_BUFF	128

# define ECHO		"echo"
# define CD			"cd"
# define SETENV		"setenv"
# define UNSETENV	"unsetenv"
# define ENV		"env"
# define EXIT		"exit"

# define ENV_ALLOWED_CHARS	"-_+"

# define EOL_COLOR	"\033[30;47m"

/*
**  SHELL INNER STATUS
*/

# define FAILURE  -1
# define SUCCESS  0
# define MINOR_ERROR 1

/*
**  CMDS EXIT STATUS
*/

# define CMD_ERROR 1
# define CMD_NOT_FOUND  127

#endif
