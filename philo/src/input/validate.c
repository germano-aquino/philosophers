/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:00:30 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/08 11:20:05 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int  is_number(char *str)
{
    unsigned char    *ch;

    ch = (unsigned char *)str;
    while (ch != NULL && *ch != '\0')
    {
        if (*ch < '0' || *ch > '9')
            return (0);
        ch++;
    }
    return (1);
}

void    validate_input(int argc, char *argv[])
{
    int i;

    if (argc != 5 && argc != 6)
    {
        printf(ERR_MSG_INV_INPUT_AMOUNT);
        printf(USAGE_MSG);
        exit(1);
    }
    i = 0;
    while (++i < argc)
    {
        if (!is_number(argv[i]))
            {
                printf(ERR_MSG_INPUT_NOT_NUMB, argv[i]);
                exit(1);
            }
    }
}