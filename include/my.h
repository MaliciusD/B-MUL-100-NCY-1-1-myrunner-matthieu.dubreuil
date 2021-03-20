/*
** EPITECH PROJECT, 2020
** headers
** File description:
** headers
*/

#ifndef my_h
#define my_h
#include <stdarg.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/Window.h>

typedef struct struct_s
{
    sfRenderWindow *window;
    sfEvent event;
    int posx_mouse;
    int posy_mouse;
    sfVector2f pos_prlx1;
    sfFont *font;
    sfVector2f pos_prlx2;
    sfVector2f pos_prlx3;
    sfVector2f pos_player;
    sfVector2f pos_bloc1;
    sfVector2f pos_bloc2;
    sfVector2f pos_bloc3;
    sfVector2f pos_bloc4;
    sfVector2f pos_bloc5;
    sfVector2f pos_vie;
    sfMusic *music_background;
    sfMusic *music_hit;
    sfMusic *music_death;
    sfVector2f pos_bloc6;
    sfVector2f pos_b;
    sfVector2f pos_pause;
    sfText *scoros;
    int play_music;
    sfTime time;
    float seconds;
    sfClock *clock;
    int menu;
    int s;
    int cnt_jmp;
    int nbr_x;
    int stop;
    int count_block;
    int db_jmp;
    int to_end;
    char *score;
    sfSprite *sprite_bgmenu;
    char **stock;
    sfSprite *sprite_end;
    sfSprite *sprite_bg1;
    sfSprite *sprite_pause;
    int reach;
    int cnt;
    int count_reset;
    int wait_hit;
    sfIntRect player_animation;
    int speed;
    int finish;
    int one_time;
    sfSprite *sprite_bg2;
    sfSprite *sprite_bloc1;
    sfSprite *sprite_bloc2;
    sfSprite *sprite_bloc3;
    sfSprite *sprite_bloc4;
    sfSprite *sprite_vie;
    sfSprite *sprite_nul;
    sfSprite *sprite_bloc5;
    sfSprite *sprite_jump;
    sfSprite *sprite_bloc6;
    sfSprite *sprite_player;
    sfSprite *sprite_bg3;
    sfSprite *sprite_b;
    int spd_blc;
    int vie;
    sfTexture *texture_bgmenu;
    sfTexture *texture_player;
    sfTexture *texture_end;
    sfTexture *texture_bg1;
    sfTexture *texture_block1;
    sfTexture *texture_block2;
    sfTexture *texture_block3;
    sfTexture *texture_jump;
    sfTexture *texture_block4;
    sfTexture *texture_block5;
    sfTexture *texture_block6;
    sfTexture *texture_nul;
    sfTexture *texture_vie;
    sfTexture *texture_pause;
    sfTexture *texture_b;
    int size_line;
    sfTexture *texture_bg2;
    sfTexture *texture_bg3;
}struct_t;

void my_put_bin(unsigned int nb);
void my_put_hexa(unsigned int nb);
void my_put_hexauppercase(unsigned int nb);
void my_put_octal(unsigned int nb);
void my_percentS(char *str);
void my_put_pointer(unsigned int nb);
void func_char(va_list ap);
void func_string(va_list ap);
void func_nbr(va_list ap);
void func_percent(va_list ap);
void func_unsignedint(va_list ap);
void func_binary(va_list ap);
void func_hexa(va_list ap);
void func_hexaupper(va_list ap);
void func_octal(va_list ap);
void func_percentS(va_list ap);
void func_pointer(va_list ap);
void func_lsa(va_list ap);
void my_put_unsint(unsigned int nb);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void call_clock6(struct_t *runner);
void call_clock7(struct_t *runner);
void call_clock8(struct_t *runner);
void call_clock(struct_t *runner);
void game_loop(struct_t *runner);
void call_clock5(struct_t *runner);
void call_clock4(struct_t *runner);
void call_clockos3(struct_t *runner);
void call_clock3(struct_t *runner);
void call_clockos2(struct_t *runner);
void display_gm7(struct_t *runner);
void display_gm8(struct_t *runner);
void display_game_and_menu(struct_t *runner);
void call_clockos(struct_t *runner);
void call_clock2(struct_t *runner);
void display_gm2(struct_t *runner);
void display_gm3(struct_t *runner);
void display_gm4(struct_t *runner);
void display_gm5(struct_t *runner);
void display_gm6(struct_t *runner);
void event(struct_t *runner);
void display_game2(struct_t *runner);
void display_game3(struct_t *runner);
void display_game(struct_t *runner);
void display_menu(struct_t *runner);
void create_sprite(struct_t *runner);
void create_fromfile2(struct_t *runner);
void create_fromfile(struct_t *runner);
void set_texture2(struct_t *runner);
void set_texture(struct_t *runner);
char *my_getnbrinverse(int tmp, int k, int trans, int is_neg);
void create_sprite2(struct_t *runner);
void create_sprite3(struct_t *runner);
void create_sprite4(struct_t *runner);
void create_sprite5(struct_t *runner);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif