/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (analise_events.c)
*/
#include "include/my.h"

void one_ammo_down(bullet_t *ammo, seagull_t *target, my_w_t *window)
{
	if (target->shots == 7 && target->hits < 6) {
		sfSprite_setColor(window->lose, (sfColor){255, 255, 255, 255});
		sfMusic_play(window->loser);
	} else if (target->hits == 6) {
		sfSprite_setColor(window->win, (sfColor){255, 255, 255, 255});
		sfMusic_play(window->tada);
	}
	sfSprite_setColor(ammo[target->shots].sprite,
		ammo[target->shots].color);
}

void replace_cross(redcross_t *death, int i, sfVector2f pos)
{
	sfSprite_setColor(death[i].sprite, death[i].color);
	sfSprite_setPosition(death[i].sprite, pos);
}

void event_on_click(sfVector2i *m_pos, seagull_t *target,
	bullet_t *ammo, my_w_t *window)
{
	float px = target->position.x;
	float py = target->position.y;

	if (((m_pos->x <= px && m_pos->x >= px - 115 && target->speed.x > 0)
	|| (m_pos->x <= px + 115 && m_pos->x >= px && target->speed.x < 0))
	&& (m_pos->y >= py && m_pos->y <= py + 115)) {
		replace_sprite(target->speed.x, target);
		check_clicked_time1(target);
		target->hits += 1;
	}
	one_ammo_down(ammo, target, window);
	target->shots += 1;
	sfMusic_play(target->shoot);
}

void analyse_events(my_w_t *window, seagull_t *target, bullet_t *ammo)
{
	sfVector2i m_pos = {0, 0};

	while (sfRenderWindow_pollEvent(window->window,
	&window->event)) {
		if (window->event.type == sfEvtMouseButtonPressed
			&& target->speed.x != 0 && target->shots < 8
			&& target->able == 1) {
			m_pos = sfMouse_getPosition(
				(const sfWindow *)window->window);
			event_on_click(&m_pos, target, ammo, window);
			target->able = 0;
		} else if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (window->event.type == sfEvtKeyPressed
			&& (target->shots == 8 || target->hits == 6))
			target->shots = 1000;
	}
}
