/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** my_screensaver
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

void displayer(my_w_t *window, seagull_t *target,
	ctime_t *clocker, bullet_t *ammo)
{
	sfRenderWindow_clear(window->window, sfBlack);
	move_and_collide(target);
	display_seagull_part(target, window, clocker, ammo);
	sfRenderWindow_drawSprite(window->window, window->wall, NULL);
	sfRenderWindow_drawSprite(window->window, window->lose, NULL);
	sfRenderWindow_drawSprite(window->window, window->win, NULL);
	for (int i = 0 ; i < 6 ; i++)
		sfRenderWindow_drawSprite(window->window,
			target->death[i].sprite, NULL);
	for (int i = 0 ; i < 8 ; i++) {
		sfRenderWindow_drawSprite(window->window, ammo[i].sprite, NULL);
	}
	sfRenderWindow_drawSprite(window->window, target->sprite, NULL);
	sfRenderWindow_drawSprite(window->window, window->mouse, NULL);
	sfRenderWindow_display(window->window);
}

sfMusic *init_music(void)
{
	sfMusic *music = sfMusic_createFromFile("sea.ogg");

	if (!music)
		exit (84);
	sfMusic_play(music);
	return (music);
}

void separate_operations(ctime_t *clocker, my_w_t *window,
	seagull_t *target, bullet_t *ammo)
{
	sfVector2i mouse_pos = {0, 0};
	sfVector2f sprite_pos = {0, 0};

	get_time(clocker);
	if (fmodf(clocker->seconds, 1.0/60.0) >= 0 &&
	fmodf(clocker->seconds, 1.0/60.0) < 0.01) {
		displayer(window, target, clocker, ammo);
		mouse_pos = sfMouse_getPositionRenderWindow(window->window);
		sprite_pos.x = (float)mouse_pos.x - 86.4;
		sprite_pos.y = (float)mouse_pos.y - 86.4;
		sfSprite_setPosition(window->mouse, sprite_pos);
	}
	if (target->able == 1 &&
		clocker->seconds >= 1.0 && target->speed.x != 0)
		sfClock_restart(clocker->clock);
	if (target->able == 0 &&
		clocker->seconds >= 2.1 && target->speed.x != 0) {
			sfClock_restart(clocker->clock);
			target->able = 1;
		}
}

void create_Window(float nb)
{
	my_w_t window = init_my_window();
	seagull_t target = init_seagull((nb + 1)/2.0, (nb + 1)/4.0);
	ctime_t clocker = init_timer();
	bullet_t *ammo = init_ammos();
	sfMusic *music = init_music();

	while (sfRenderWindow_isOpen(window.window)) {
		separate_operations(&clocker, &window, &target, ammo);
		if (target.shots == 1000)
			break;
	}
	destroy_and_free(&window, &target, &clocker, ammo);
	destroy_and_free_musics(&target, &window);
	sfMusic_destroy(music);
}

int main(int ac, char **av)
{
	if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h') || ac < 2) {
		my_printf("\nFirstly, enter a difficulty from 0 to 3.\n\n");
		my_printf("To win, shoot the seagull six times,\n");
		my_printf("But be careful to not miss!\n\n");
		return (0);
	}
	if (my_getnbr(av[1]) > 3 && ac < 3) {
		my_printf("\nYou really want to go faster than 3 ? \nAlright ");
		my_printf("so enter your difficulty then I_AM_CRAZY\n\n");
		return (0);
	}
	create_Window((float)my_getnbr(av[1]));
	return (0);
}
