#include QMK_KEYBOARD_H
#include "keymap_us_international.h"
#include "tap_dance.c"
#include "oled.c"
//#include "handlers.c"


enum layer_number {
  _QWERTY = 0,
  _NUMPAD,
  _MOVE,
  _ADJUST,
};

enum custom_keycodes {
    //DBRC,
    DCBR = SAFE_RANGE,
    DPRN,
 };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |  1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAPWRD|  A   |   S  |   D  |   F  |   G  |-------,    ,-------|   H  |   J  |   K  |   L  |   '  |  -   |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |  \   |  Z   |   X  |   C  |   V  |   B  |-------|    |-------|N or Ñ|   M  |   ,  |   .  |   ;  |[ & ] |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| NUM  | /   +   /       \   +  \  | MOVE | OSMod| LGUI |
 *                   |      | LAlt | PAD  |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  QK_GESC, TD(TD_EXC), US_2, US_3, US_4, US_5,                      US_6, US_7, US_8, US_9, US_0, TD(TD_INT),
  KC_TAB,  US_Q, US_W, US_E, US_R, US_T,                            US_Y, US_U, US_I, US_O, US_P, US_EQL,
  CAPSWRD, US_A, US_S, US_D, US_F, US_G,                            US_H, US_J, US_K, US_L, US_ACUT, US_MINS,
  US_BSLS, US_Z, US_X, US_C, US_V, US_B, LCTL_T(KC_DEL), RCTL_T(KC_BSPC), TD(TD_N), US_M, US_COMM, US_DOT, US_SCLN, TD(TD_BRC),
    KC_LGUI, OSM(MOD_LALT), MO(_NUMPAD), LSFT_T(KC_ENT), RSFT_T(KC_SPC), MO(_MOVE), OSM(MOD_RALT), TD(TD_APP)
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   ^  |   7  |   8  |   9  |( & ) |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |                    |      |   4  |   5  |   6  |   *  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |-------,    ,-------|      |   1  |   2  |   3  |   +  |  -   |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   0  |   ,  |   .  |   ;  |Enter |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod|      | /   +   /       \   +  \  | ADJ  | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

[_NUMPAD] = LAYOUT(
  KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                     KC_CIRC, KC_P7, KC_P8, KC_P9, DPRN, KC_PSLS,
  KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                    KC_NO, KC_P4, KC_P5, KC_P6, KC_PAST, US_EQL,
  KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,                     KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PMNS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,         KC_TRNS, KC_NO, KC_P0, US_COMM, US_DOT, KC_TRNS, KC_PENT,
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,  MO(_ADJUST), KC_TRNS, KC_TRNS
),

/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |      |      |Wh_Up |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | Btn1 |Ms_Up | Btn2 |      |                    |      | Home |  Up  | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Wh_L | Ms_L | Ms_D | Ms_R | Wh_R |-------,    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |      |      | Wh_D |      |      |-------|    |-------|      | End  | Ins  | PgDn |      |{ & } |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| ADJ  | /   +   /       \   +  \  |      | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

[_MOVE] = LAYOUT(
  KC_TRNS, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO,KC_NO, KC_NO, KC_NO,
  KC_TRNS, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,               KC_NO, KC_HOME, KC_UP, KC_PGUP, KC_NO, KC_NO,
  KC_NO, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R,  KC_WH_R,            KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_TRNS,       KC_TRNS, KC_NO, KC_END, KC_INS, KC_PGDN, KC_NO, DCBR,
             KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |PrtScr|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Mute | Vol- | Vol+ |      |-------,    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Ctrl |    |  Ctrl |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Shift  /       \Shift \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT(
  QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO,
  KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL,    KC_RCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
               _______, _______, _______, KC_LSFT,        KC_LSFT,  _______, _______, _______
  )
};

// Customizing CAPS WORD behaviour to handle tap dance on TD(TD_N)
// Otherwise, letters N and Ñ will not get capitalized
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case TD(TD_N):  // Tap dance to send N or Ñ
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// Process other special cases
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
 if (record->event.pressed) {
// This code will print any key pressed on OLED
 #ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
*/

  // SEND_STRING Commands for brackets and parenthesis
  switch (keycode) {
        /*case DBRC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_RBRC) SS_TAP(X_LEFT));
                //SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            return false;
        */
      case DCBR:
            if (record->event.pressed) {
                //SEND_STRING(SS_TAP(S(X_LBRC)) SS_TAP(S(X_RBRC)) SS_TAP(X_LEFT));
                SEND_STRING("{}" SS_UP(X_LSFT) SS_UP(X_RSFT) SS_TAP(X_LEFT));
            }
            return false;
        case DPRN:
            if (record->event.pressed) {
                //SEND_STRING(SS_TAP(S(X_9)) SS_TAP(S(X_0)) SS_TAP(X_LEFT));
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            return false;

    // This section is for Luna pet
        case KC_LCTL:
        case KC_RCTL:
        case KC_LGUI:
            if (record->event.pressed)
            { isSneaking = true; } else { isSneaking = false; } break;
        case KC_SPC:
        case US_DOT:
            if (record->event.pressed)
            { isJumping  = true; showedJump = false;} else {isJumping = false;} break;
            return false;

}
        return true;

}
