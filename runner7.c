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

void call_clockos2(struct_t *runner)
{
    if (runner->pos_player.x >= runner->pos_bloc1.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc1.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc1.y &&
        runner->pos_player.y >= runner->pos_bloc1.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
}

void call_clock3(struct_t *runner)
{
    call_clockos2(runner);
    if (runner->pos_player.x >= runner->pos_bloc2.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc2.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc2.y &&
        runner->pos_player.y >= runner->pos_bloc2.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
    if (runner->pos_player.x >= runner->pos_bloc3.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc3.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc3.y &&
        runner->pos_player.y >= runner->pos_bloc3.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
}

void call_clockos3(struct_t *runner)
{
    if (runner->pos_player.x >= runner->pos_bloc4.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc4.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc4.y &&
        runner->pos_player.y >= runner->pos_bloc4.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
}

void call_clock4(struct_t *runner)
{
    call_clockos3(runner);
    if (runner->pos_player.x >= runner->pos_bloc5.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc5.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc5.y &&
        runner->pos_player.y >= runner->pos_bloc5.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
    if (runner->pos_player.x >= runner->pos_bloc6.x - 65 &&
    runner->pos_player.x <= runner->pos_bloc6.x + 72) {
        if (runner->pos_player.y <= runner->pos_bloc6.y &&
        runner->pos_player.y >= runner->pos_bloc6.y - 115 &&
        runner->wait_hit == 0)
            runner->vie--;
            sfMusic_play(runner->music_hit);
            runner->wait_hit = 1;
    }
}

void call_clock5(struct_t *runner)
{
    if (runner->wait_hit == 1) {
        runner->cnt = 1;
        runner->wait_hit = 2;
    }
    if (runner->cnt == 1)
        runner->reach += 10;
    if (runner->wait_hit == 2 && runner->reach >= 150) {
        runner->wait_hit = 0;
        runner->cnt = 0;
        sfMusic_stop(runner->music_hit);
        runner->reach = 0;
    }
    if (runner->pos_prlx1.x <= -1920)
        runner->pos_prlx1.x = 0;
    if (runner->pos_prlx2.x <= -1920)
        runner->pos_prlx2.x = 0;
    if (runner->pos_prlx3.x <= -1920)
        runner->pos_prlx3.x = 0;
    if (runner->cnt_jmp == 0)
        runner->player_animation.left += 37;
}