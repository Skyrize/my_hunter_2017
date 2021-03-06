/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_put_ull(unsigned long long);
void my_put_llnbr(long long int);
void my_putnbr_base(unsigned long long, char *);
int my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char const *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_printf(char *, ...);
void my_printunsignedint(va_list);
void my_printchar(va_list);
void my_printint(va_list);
void my_printstr(va_list);
void my_printlowhexa(va_list);
void my_printuphexa(va_list);
void my_printbinary(va_list);
void my_printadress(va_list);
void my_printoctal(va_list);
void my_printpercent(va_list);
void my_printformatedstring(va_list);
void my_amazing_sorter(int *, int);
void	rotate_left(int *, int, int *);
void	rotate_right(int *, int, int *);

typedef struct redcross_t
{
	sfSprite *sprite;
	sfTexture *texture;
	sfColor color;
} redcross_t;

typedef struct seagull_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *shoot;
	sfIntRect rect;
	sfVector2f speed;
	sfVector2f invert;
	sfVector2f position;
	int shots;
	int hits;
	int able;
	redcross_t *death;
} seagull_t;

typedef struct bullet_s
{
	sfSprite *sprite;
	sfTexture *texture;
	sfColor color;
	int number;
} bullet_t;

typedef struct my_window_s
{
	sfRenderWindow *window;
	sfSprite *wall;
	sfTexture *waller;
	sfSprite *lose;
	sfTexture *lose_tx;
	sfMusic *loser;
	sfSprite *win;
	sfTexture *win_tx;
	sfSprite *mouse;
	sfTexture *mouse_tx;
	sfMusic *tada;
	sfEvent event;
} my_w_t;

typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct fnct_s
{
	char balise;
	void (*fptr)(va_list list);
} fnct_t;

typedef struct point_s
{
	float x;
	float y;
} point_t;

typedef struct framebuffer_s
{
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

seagull_t init_seagull(float, float);
ctime_t init_timer(void);
my_w_t init_my_window(void);
redcross_t *init_cross(void);
bullet_t *init_ammos(void);
void analyse_events(my_w_t *, seagull_t *, bullet_t *);
void event_on_click(sfVector2i *, seagull_t *, bullet_t *, my_w_t *);
void move_and_collide(seagull_t *);
void display_seagull_part(seagull_t *, my_w_t *, ctime_t *, bullet_t *);
void replace_cross(redcross_t *, int, sfVector2f);
void displayer(my_w_t *, seagull_t *, ctime_t *, bullet_t *);
void destroy_and_free(my_w_t *, seagull_t *, ctime_t *, bullet_t *);
void get_time(ctime_t *);
void one_ammo_down(bullet_t *, seagull_t *, my_w_t *);
void check_clicked_time1(seagull_t *);
void replace_sprite(float, seagull_t *);
void destroy_and_free_musics(seagull_t *, my_w_t *);

#endif /* MY_H_ */
