/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:47:00 by lupin             #+#    #+#             */
/*   Updated: 2023/05/31 10:57:50 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_list(t_list *list)
{
    while (list) {
        printf("Enemmy: (x = %d, y = %d)\n",
            list->x, list->y);
        list = list->next;
    }
}

int show_helper(void)
{
    printf("\n  ==============================\n");
    printf("  ===      GAME CONTROLS     ===\n");
    printf("  ==============================\n");
    printf("  = Movements                  =\n");
    printf("  =   UP arrow                 =\n");
    printf("  =   DOWN arrow               =\n");
    printf("  =   LEFT arrow               =\n");
    printf("  =   RIGHT arrow              =\n");
    printf("  = EXIT                       =\n");
    printf("  ==============================\n");
    printf("  = Have fun!                  =\n");
    printf("  = For any bug or feedback:   =\n");
    printf("  ===  a.rurangiza@gmail.com ===\n");
    printf("  ==============================\n\n");
    return (0);
}