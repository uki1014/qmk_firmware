/*
 * https://syon.github.io/refills/rid/1471100/
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 * */
#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define LAYER1 MO(_LAYER1)
#define LAYER2 MO(_LAYER2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer0 (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | CTRL |LAYER2|                                                         |LAYER1| SHIFT |
     *        '------+------'                                                         '------+------'
     *                      |-----|-------|                             |-------|--------|
     *                      |SHIFT| SPACE |                             | ENTER |   BS   |
     *                      '-----+-------'                             '-------+--------'
     *                                    '------+------' '------+------'
     *                                    |  TAB | CMD  | |LANG1 | CTRL |
     *                                    '------+------' '------+------'
     *                                    |      |      | | CTRL |      |
     *                                    |  ALT |  NO  | |  +   | ALT  |
     *                                    |      |      | | CMD  |      |
     *                                    '------+------' '------+------'
     */
    [_LAYER0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                         	KC_LCTL, LAYER2,                                                               LAYER1,  KC_RSFT,
                                   KC_LSFT, KC_SPC,                                    KC_ENT,  KC_BSPC,
                                                     KC_LGUI,  KC_NO, KC_LNG1, RCTL(KC_RGUI),
                                                     KC_TAB, KC_LALT, KC_RCTL, KC_RALT
    ),

    /* Layer1
     * ,----------------------------------,                             ,----------------------------------,
     * |  1   |  2   |  3   |  *   |  +   |                             |  <   |  @   |  (   |  )   |  \   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  4   |  5   |  6   |  /   |  -   |                             |  >   |  =   |  {   |  }   |  $   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  7   |  8   |  9   |  |   |  _   |                             |  ~   |  `   |  [   |  ]   |  !   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  0   |      |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | | SPACE| TAB  |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LAYER1] = LAYOUT(
        KC_1, KC_2, KC_3, KC_ASTR,  KC_PLUS,                                             KC_LABK, KC_AT,   KC_LPRN, KC_RPRN, KC_BSLS,
        KC_4, KC_5, KC_6, KC_SLSH,  KC_MINS,                                             KC_RABK, KC_PEQL, KC_LCBR, KC_RCBR, KC_DLR,
        KC_7, KC_8, KC_9, KC_PIPE,  KC_UNDS,                                             KC_TILD, KC_GRV,  KC_LBRC, KC_RBRC, KC_EXLM,
              KC_0, _______,                                                                               _______,  _______,
                                   _______, _______,                                     _______, _______,
                                                     _______, _______,  KC_SPACE, _______,
                                                     _______, _______,  KC_TAB,   _______

    ),

    /* Layer2
     * ,----------------------------------,                             ,----------------------------------,
     * | F7   | F12  |  mup |mbtn2 | mbtn |                             |WRight| WUp  |  up  | WDown|WLeft |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * | SHIFT| mleft| mdown|mright| CMD  |                             |  ^   | left | down |right |  $   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * | Alt  | VOL- | VOL+ |Alt+SP| Alt  |                             | MUTE |  %   |  #   |  &   | TAB  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | CTRL |      |                             |      |      |
     *                      |  +   |      |                             |      | ESC  |
     *                      | TAB  |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | | TAB  |SPACE |
     *                                    '------+------' '------+------'
     *                                    |      |      | | RESET|      |
     *                                    '------+------' '------+------'
     */
    [_LAYER2] = LAYOUT(
        KC_F7,   KC_F12,  KC_MU,   KC_MB2,       KC_MB1,                             KC_WH_R, KC_WH_U, KC_UP,   KC_WH_D, KC_WH_L,
        KC_LSFT, KC_ML,   KC_MD,   KC_MR,        KC_LGUI,                            KC_CIRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,
        KC_LALT, KC_VOLD, KC_VOLU, LALT(KC_SPC), KC_LALT,                            KC_MUTE, KC_PERC, KC_HASH, KC_AMPR, KC_TAB,
                 _______, _______,                                                                     _______, _______,
                                   RCTL(KC_TAB), _______,                            _______, KC_ESC,
                                                 _______, _______,  KC_TAB,   RESET,
                                                 _______, _______,  KC_SPACE, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
