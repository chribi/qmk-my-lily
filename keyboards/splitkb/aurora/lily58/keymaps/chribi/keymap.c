#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN 1
#define _SYMB 2
#define _MEDIA 3
#define _MOUSE 4

#define M_FN MO(_FN)
#define M_SYMB MO(_SYMB)
#define M_MEDIA MO(_MEDIA)
#define T_MOUSE TG(_MOUSE)

#define ESC_CTL MT(MOD_LCTL, KC_ESC)

#define A_UML  ALGR(KC_Q) // ä on us_intl
#define O_UML  ALGR(KC_P) // ö on us_intl
#define U_UML  ALGR(KC_Y) // ü on us_intl
#define SZ_LIG ALGR(KC_S) // ß on us_intl

#define COPY  C(KC_C)
#define CUT   C(KC_X)
#define PASTE C(KC_V)

#define SNIP  LSG(KC_S)

#define TASKMGR RCS(KC_ESC)
#define C_A_DEL LCA(KC_DEL)

// home row mods
#define A_WIN MT(MOD_LGUI, KC_A)
#define S_ALT MT(MOD_LALT, KC_S)
#define D_CTRL MT(MOD_LCTL, KC_D)
#define F_SFT MT(MOD_LSFT, KC_F)
#define J_SFT MT(MOD_RSFT, KC_J)
#define K_CTRL MT(MOD_RCTL, KC_K)
#define L_ALT MT(MOD_LALT, KC_L)
#define SCL_WIN MT(MOD_RGUI, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,
    ESC_CTL, A_WIN  , S_ALT  , D_CTRL , F_SFT  , KC_G   ,                   KC_H   , J_SFT  , K_CTRL , L_ALT  , SCL_WIN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC, KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                               KC_LCTL, M_SYMB , M_FN   , KC_SPC , KC_ENT , KC_BSPC, M_SYMB , M_MEDIA),

[_FN] = LAYOUT(
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
    _______, A_UML  , SZ_LIG , O_UML  , U_UML  , KC_PSCR,                   CW_TOGG, KC_CAPS, _______, _______, KC_INS , TASKMGR,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_DEL , C_A_DEL,
    _______, _______, _______, _______, _______, KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSLS, _______,
                               _______, _______, _______, _______, _______, _______, _______, T_MOUSE),

[_SYMB] = LAYOUT(
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______),

[_MEDIA] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______,                   KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSEL, _______,
    _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_TOG, _______,                   KC_BRID, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, T_MOUSE, _______, _______, _______, _______, _______),
[_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, _______,
    _______, _______, SNIP   , _______, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, CUT    , COPY   , PASTE  , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, T_MOUSE, _______, KC_BTN1, KC_BTN2, _______, T_MOUSE),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




