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

void call_clock6(struct_t *runner)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && runner->cnt_jmp == 0)
        runner->cnt_jmp = 1;
    if (runner->cnt_jmp == 1) {
        runner->pos_player.y -= 15;
        if (runner->pos_player.y <= 675) {
            if (sfMouse_isButtonPressed(sfMouseLeft) && runner->db_jmp == 0)
                runner->db_jmp = 1;
            else
                runner->cnt_jmp = 2;
        }
    }
    if (runner->db_jmp == 1) {
        runner->pos_player.y -= 20;
        runner->pos_player.x += 5;
        if (runner->pos_player.y <= 550)
            runner->db_jmp = 2;
    } if (runner->cnt_jmp == 2) {
        runner->pos_player.x += 1;
        runner->pos_player.y += 15;
    }
}

void call_clock7(struct_t *runner)
{
    if (runner->nbr_x == 1)
        runner->pos_bloc1.x -= 10 + runner->speed;
    if (runner->nbr_x == 2) {
        runner->pos_bloc1.x -= 10 + runner->speed;
        runner->pos_bloc2.x -= 10 + runner->speed;
    }
    if (runner->nbr_x == 3) {
        runner->pos_bloc1.x -= 10 + runner->speed;
        runner->pos_bloc2.x -= 10 + runner->speed;
        runner->pos_bloc3.x -= 10 + runner->speed;
    }
    if (runner->nbr_x == 4) {
        runner->pos_bloc1.x -= 10 + runner->speed;
        runner->pos_bloc2.x -= 10 + runner->speed;
        runner->pos_bloc3.x -= 10 + runner->speed;
        runner->pos_bloc4.x -= 10 + runner->speed;
    }
}

void call_clock8(struct_t *runner)
{
    if (runner->nbr_x == 5) {
        runner->pos_bloc1.x -= 10 + runner->speed;
        runner->pos_bloc2.x -= 10 + runner->speed;
        runner->pos_bloc3.x -= 10 + runner->speed;
        runner->pos_bloc4.x -= 10 + runner->speed;
        runner->pos_bloc5.x -= 10 + runner->speed;
    } if (runner->nbr_x >= 6) {
        runner->pos_bloc1.x -= 10 + runner->speed + runner->spd_blc;
        runner->pos_bloc2.x -= 10 + runner->speed;
        runner->pos_bloc3.x -= 10 + runner->speed;
        runner->pos_bloc4.x -= 10 + runner->speed;
        runner->pos_bloc5.x -= 10 + runner->speed;
        runner->pos_bloc6.x -= 10 + runner->speed;
    } if (runner->pos_player.x == runner->stop)
        runner->menu = 0;
    if (runner->cnt_jmp == 2 && runner->pos_player.y >= 815)
        runner->cnt_jmp = 0;
    if (runner->db_jmp == 2 && runner->pos_player.y >= 815) {
        runner->cnt_jmp = 0;
        runner->db_jmp = 0; }
}

void call_clock(struct_t *runner)
{
    runner->time = sfClock_getElapsedTime(runner->clock);
    runner->seconds = runner->time.microseconds / 800000.0;
    if (runner->menu == 1) {
        runner->s += 1;
        runner->score = my_getnbrinverse(runner->s, 0, 0, 0);
        sfText_setString(runner->scoros, runner->score);
    } if (runner->seconds > 0.05) {
        if (runner->menu == 1) {
            call_clock2(runner);
            call_clock3(runner);
            call_clock4(runner);
            call_clock5(runner);
            call_clock6(runner);
            call_clock7(runner);
            call_clock8(runner);
            if (runner->player_animation.left >= 111)
                runner->player_animation.left = 0;
        } sfSprite_setTextureRect(runner->sprite_player,
        runner->player_animation);
        sfClock_restart(runner->clock); }
}

void game_loop(struct_t *runner)
{
    int zik = 0;
    int hit = 0;
    int change_zik = 0;
    float speed;
    while (sfRenderWindow_isOpen(runner->window)) {
        event(runner);
        call_clock(runner);
        display_game_and_menu(runner);
        if (runner->menu == 1 && runner->play_music == 0) {
            sfMusic_play(runner->music_background);
            runner->play_music = 1;
        }
    }
}