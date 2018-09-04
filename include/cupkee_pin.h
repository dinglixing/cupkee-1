/* GPLv2 License
 *
 * Copyright (C) 2016-2018 Lixing Ding <ding.lixing@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 **/

#ifndef __CUPKEE_PIN_INC__
#define __CUPKEE_PIN_INC__

typedef struct cupkee_pinmap_t {
    uint8_t bank;
    uint8_t port;
} cupkee_pinmap_t;

typedef uint32_t (*cupkee_wave_engine_t)(uint32_t edge_cnt, uint32_t next_half, void *data);

int  cupkee_pin_setup(void);
void cupkee_pin_schedule(uint32_t ticks);
void cupkee_pin_event_dispatch(uint16_t id, uint8_t code);

int cupkee_pin_map(uint8_t pin_num, const cupkee_pinmap_t *pin_map);

int cupkee_pin_mode_set(int pin, int mode);
int cupkee_pin_mode_get(int pin);
int cupkee_pin_listen(int pin, int events, cupkee_callback_t handler, void *entry);
int cupkee_pin_ignore(int pin);

int cupkee_pin_set(int pin, int v);
int cupkee_pin_get(int pin);
int cupkee_pin_toggle(int pin);
int cupkee_pin_wave_gen(int pin, uint32_t first, uint32_t second,
                        cupkee_wave_engine_t engine, void *data);
int cupkee_pin_wave_set(int pin, int start, uint32_t first, uint32_t second);
int cupkee_pin_wave_update(int pin, uint32_t first);
int cupkee_pin_wave_stop(int pin, int v);
int cupkee_pin_wave_get(int pin, int i);
uint32_t cupkee_pin_duration(int pin);

int cupkee_pin_set_analog(int pin, float v);
int cupkee_pin_get_analog(int pin, float *v);

#endif /* __CUPKEE_PIN_INC__ */

