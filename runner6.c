/*
** EPITECH PROJECT, 2020
** runner
** File description:
** runner
*/

#include "include/my.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void display_gm7(struct_t *runner)
{
    if (runner->nbr_x == 4) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
    }
    if (runner->nbr_x == 5) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc5, NULL);
    } if (runner->nbr_x >= 6) {
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc1, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc2, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc3, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc4, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc5, NULL);
        sfRenderWindow_drawSprite(runner->window, runner->sprite_bloc6, NULL);
    }
}

void display_gm8(struct_t *runner)
{
    if (runner->db_jmp == 0)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_player, NULL);
    if (runner->db_jmp > 0)
        sfRenderWindow_drawSprite(runner->window, runner->sprite_jump, NULL);
    sfSprite_setPosition(runner->sprite_bg1, runner->pos_prlx1);
    sfSprite_setPosition(runner->sprite_bg3, runner->pos_prlx3);
    sfSprite_setPosition(runner->sprite_bg2, runner->pos_prlx2);
    sfSprite_setPosition(runner->sprite_player, runner->pos_player);
    sfSprite_setPosition(runner->sprite_bloc1, runner->pos_bloc1);
    sfSprite_setPosition(runner->sprite_bloc2, runner->pos_bloc2);
    sfSprite_setPosition(runner->sprite_bloc3, runner->pos_bloc3);
    sfSprite_setPosition(runner->sprite_bloc4, runner->pos_bloc4);
    sfSprite_setPosition(runner->sprite_bloc5, runner->pos_bloc5);
    sfSprite_setPosition(runner->sprite_bloc6, runner->pos_bloc6);
    sfSprite_setPosition(runner->sprite_jump, runner->pos_player);
    sfSprite_setPosition(runner->sprite_vie, runner->pos_vie);
    sfSprite_setPosition(runner->sprite_b, runner->pos_b);
    sfRenderWindow_drawSprite(runner->window, runner->sprite_pause, NULL);
}

void display_game_and_menu(struct_t *runner)
{
    display_gm2(runner);
    display_gm5(runner);
    if (runner->menu == 4) {
        display_gm6(runner);
        display_gm7(runner);
        display_gm8(runner);
    }
}

void call_clockos(struct_t *runner)
{
    runner->to_end += 10;
    if (runner->to_end >= runner->stop && runner->count_block >= runner->nbr_x)
        runner->finish = 1;
    if (runner->finish == 1 && runner->pos_player.x !=
    runner->pos_player.x + 1920)
        runner->pos_player.x += 40;
    if (runner->pos_player.x >= 1935)
        runner->menu = 2;
}

void call_clock2(struct_t *runner)
{
    call_clockos(runner);
    runner->pos_prlx1.x -= 10 + runner->speed;
    runner->pos_prlx2.x -= 7;
    runner->pos_prlx3.x -= 25;
    if (runner->pos_bloc1.x <= 0 || runner->pos_bloc2.x == 0 ||
    runner->pos_bloc3.x == 0 ||
    runner->pos_bloc4.x == 0 || runner->pos_bloc5.x == 0
    || runner->pos_bloc6.x == 0) {
        runner->count_block += 1;
        if (runner->nbr_x > 6 && runner->count_block <
        runner->nbr_x && runner->pos_bloc1.x <= 0) {
            runner->pos_bloc1.x = 1900;
            runner->speed += 5;
            runner->spd_blc += 2;
        }
    }
}