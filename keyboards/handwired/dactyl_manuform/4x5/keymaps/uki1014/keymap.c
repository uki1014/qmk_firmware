/*
 * https://syon.github.io/refills/rid/1471100
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 * */
#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define LAYER1 MO(_LAYER1)
#define LAYER2 MO(_LAYER2)
#define LAYER3 MO(_LAYER3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer0 (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | CTRL |LAYER2|                                                         |   /  | SHIFT|
     *        '------+------'                                                         '------+------'
     *                      |-----|-------|                             |-------|--------|
     *                      | CMD | SPACE |                             | ENTER | LAYER1 |
     *                      '-----+-------'                             '-------+--------'
     *                                    '------+------' '------+------'
     *                                    |LAYER3|SHIFT | |  BS  | TAB  |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    |  ALT |      | |      | CTRL |
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LAYER0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                         	KC_LCTL, LAYER2,                                                               KC_SLSH, KC_RSFT,
                                   KC_LGUI, KC_SPC,                                    KC_ENT,  LAYER1,
                                                   KC_LSFT, _______, KC_BSPC, _______, // cmd ctrlは+ QしてPC閉じるやつ
                                                   LAYER3,  KC_LALT, _______, KC_RCTL
    ),

    /* Layer1
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |  \   |  *   |  +   |                             |  <   |  @   |  (   |  )   |  &   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * | TAB  |  ^   |  #   |  /   |  -   |                             |  >   |  =   |  {   |  }   |  $   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |  _   |  |   |  %   |                             |  ~   |  `   |  [   |  ]   |  !   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | CMD+CTRL+Q  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LAYER1] = LAYOUT(
        _______, _______, KC_BSLS, KC_ASTR,  KC_PLUS,                                     KC_LABK, KC_AT,   KC_LPRN, KC_RPRN, KC_AMPR,
        KC_TAB,  KC_CIRC, KC_HASH, KC_SLSH,  KC_MINS,                                     KC_RABK, KC_PEQL, KC_LCBR, KC_RCBR, KC_DLR,
        _______, _______, KC_PERC, KC_PIPE,  KC_UNDS,                                     KC_TILD, KC_GRV,  KC_LBRC, KC_RBRC, KC_EXLM,
                 _______, _______,                                                                          RCTL(KC_RGUI), KC_Q,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______

    ),

    /* Layer2
     * ,----------------------------------,                             ,----------------------------------,
     * | PgDwn| PgUp |  mup | Home | End  |                             |WRight| WUp  |  up  | WDown|WLeft |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * | SHIFT| mleft| mdown|mright| CMD  |                             |  ^   | left | down |right |  $   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |Ctr+Al| F7   | F12  |Alt+SP| Alt  |                             |LANG2 | TAB  | mbtn2| mbtn |CTR+TB|
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |LANG1 | ESC  |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |DELETE|      |
     *                                    '------+------' '------+------'
     *                                    |      |      | | RESET|      |
     *                                    '------+------' '------+------'
     */
    [_LAYER2] = LAYOUT(
        KC_PGDN, KC_PGUP,KC_MU,  KC_HOME,      KC_END,                                    KC_WH_R, KC_WH_U, KC_UP,   KC_WH_D, KC_WH_L,
        KC_LSFT, KC_ML,  KC_MD,  KC_MR,        KC_LGUI,                                   KC_CIRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,
        LALT(KC_LCTL), KC_F7,  KC_F12, LALT(KC_SPC), KC_LALT,                                   KC_LNG2, KC_TAB,  KC_MB2,  KC_MB1,  RCTL(KC_TAB),
                 _______, _______,                                                                          _______, _______,
                                 _______, _______,                                   KC_LNG1, KC_ESC,
                                                         _______, _______,  KC_DEL,  RESET,
                                                         _______, _______,  _______, _______
    ),

    /* Layer3
     * ,----------------------------------,                             ,----------------------------------,
     * |      |      |      |      |      |                             |  1   |  2   |  3   |  4   |  5   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |CMDSHI| Prev | Pause| Next | CMD  |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      | VOL- | MUTE | VOL+ | Alt  |                             |Ctr+4 |      |      |      |      |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |             |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LAYER3] = LAYOUT(
        _______, _______, _______, _______,  _______,                                    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        LGUI(KC_LSFT), KC_MPRV, KC_MPLY, KC_MNXT,  KC_LGUI,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        _______, KC_VOLD, KC_MUTE, KC_VOLU,  KC_LALT,                                    RCTL(KC_4), _______, _______, _______, _______,
                 _______, _______,                                                                         _______, _______,
                                   _______, _______,                                     _______, _______,
                                                     _______, _______,  _______,  _______,
                                                     _______, _______,  _______, _______

    ),

};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
