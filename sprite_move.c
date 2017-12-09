/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (sprite_move part)
*/
#include "include/my.h"

void move_rect(sfIntRect *rect, int max_value)
{
	if (rect->left < max_value)
		rect->left += 133;
	if (rect->left == max_value)
		rect->left = 133;
}

void wall_hit(seagull_t *target)
{
	sfColor color = sfColor_fromRGBA(0, 0, 0, 0);

	if (target->position.x >= 1640 || target->position.x <= 100) {
		if (target->position.x >= 1640)
			target->position.x -= 130;
		if (target->position.x <= 100)
			target->position.x = 200;
		target->speed.x *= -1;
		sfSprite_setPosition(target->sprite,
		target->position);
		sfSprite_scale(target->sprite, target->invert);
	}
	if (target->position.y >= 750 || target->position.y <= 40) {
		target->speed.y *= -1;
		if (target->position.y <= 40 && target->hits == 6) {
			sfSprite_setColor(target->sprite, color);
		}
	}
}

void move_and_collide(seagull_t *target)
{
	sfSprite_move(target->sprite, target->speed);
	target->position = sfSprite_getPosition(target->sprite);
	wall_hit(target);
}

void display_seagull_part(seagull_t *target, my_w_t *window,
	ctime_t *clocker, bullet_t *ammo)
{
	if (target->speed.x != 0 && fmod(clocker->seconds, 0.05) >= 0
	&& fmod(clocker->seconds, 0.05) < 0.00001) {
		move_rect(&target->rect, 1064);
		sfSprite_setTextureRect(target->sprite, target->rect);
	}
	analyse_events(window, target, ammo);
}
