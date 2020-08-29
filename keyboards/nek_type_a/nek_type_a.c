/* Copyright 2018 Mike Roberts
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "nek_type_a.h"

static uint32_t oled_timer = 0;

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware
	oled_timer = timer_read32();
	return process_record_user(keycode, record);
}

uint32_t layer_state_set_kb(uint32_t state) {
	return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_90;
}

int display_state = 0;
void oled_task_user(void) {
  if (timer_elapsed32(oled_timer) > 60000) {
  	if (display_state == 1) {
		  oled_clear();
		  display_state = 0;
	  }
	  return;
  } else {
	  display_state = 1;
  }

  uint8_t mods = get_mods();
  
  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_ln_P(PSTR("FUNCT"), false);
      break;
    case 1:
      oled_write_ln_P(PSTR("FUNCT"), true);
      break;
    default:
      break;
  }

  oled_write_P(PSTR("SHIFT"), mods & MOD_MASK_SHIFT);

  oled_write_ln_P(PSTR(""), true);
  oled_write_P(PSTR("CTROL"), mods & MOD_MASK_CTRL);

  oled_write_ln_P(PSTR(""), true);
  oled_write_P(PSTR("OPTON"), mods & MOD_MASK_ALT);

  oled_write_ln_P(PSTR(""), true);
  oled_write_P(PSTR("COMMD"), mods & MOD_MASK_GUI);

  oled_write_ln_P(PSTR(""), true);
  oled_write_ln_P(PSTR(""), true);

  oled_write_P(PSTR("ENCR:"), false);

  oled_write_P(PSTR("VL"), false);
  oled_advance_char();
  oled_write_P(PSTR("LR"), false);

  oled_write_P(PSTR("PG"), false);
  oled_advance_char();
  oled_write_P(PSTR("UD"), false);
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
//     switch(get_highest_layer(layer_state)) {
//         case _BASE:
//             clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
//             break;
//         case _UPPER:
          
//             break;
//         case _LOWER:
//             clockwise ? tap_code(KC_MEDIA_NEXT_TRACK) : tap_code(KC_MEDIA_PREV_TRACK);
//             break;
//         }
}