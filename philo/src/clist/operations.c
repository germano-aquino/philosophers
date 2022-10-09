/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:32:26 by grenato-          #+#    #+#             */
/*   Updated: 2022/10/08 15:21:05 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_clist *create_clist_item(t_clist *next, t_clist *prev, void *content)
{
    t_clist *new_item;

    new_item = (t_clist *)malloc(sizeof(t_clist));
    new_item->content = content;
    new_item->next = next;
    new_item->prev = prev;
    return (new_item);
}

void    clst_addback(t_clist **head, t_clist *new_elt)
{
    t_clist *last;

    if (*head == NULL)
    {
        *head = new_elt;
        (*head)->next = new_elt;
        (*head)->prev = new_elt;
    }
    else 
    {
        last = (*head)->prev;
        last->next = new_elt;;
        (*head)->prev = new_elt;
        new_elt->next = *head;
        new_elt->prev = last;
    }
}