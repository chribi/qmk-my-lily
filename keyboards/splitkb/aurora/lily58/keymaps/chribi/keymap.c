#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN 1
#define _SYMB 2
#define _MEDIA 3
#define _MOUSE 4

#define M_FN MO(_FN)
#define M_SYMB MO(_SYMB)
#define M_MEDIA MO(_MEDIA)
#define M_MOUSE MO(_MOUSE)
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

// home row mods [base layer]
#define A_WIN MT(MOD_LGUI, KC_A)
#define S_ALT MT(MOD_LALT, KC_S)
#define D_CTRL MT(MOD_LCTL, KC_D)
#define F_SFT MT(MOD_LSFT, KC_F)
#define J_SFT MT(MOD_RSFT, KC_J)
#define K_CTRL MT(MOD_RCTL, KC_K)
#define L_ALT MT(MOD_LALT, KC_L)
#define SCL_WIN MT(MOD_RGUI, KC_SCLN)

// home row mods [symb layer]
#define _1_WIN MT(MOD_LGUI, KC_1)
#define _2_ALT MT(MOD_LALT, KC_2)
#define _3_CTRL MT(MOD_LCTL, KC_3)
#define _4_SFT MT(MOD_LSFT, KC_4)
#define _7_SFT MT(MOD_RSFT, KC_7)
#define _8_CTRL MT(MOD_RCTL, KC_8)
#define _9_ALT MT(MOD_LALT, KC_9)
#define _0_WIN MT(MOD_RGUI, KC_0)

// Space on tap, SYMB layer on hold
#define SYMB_SPC LT(_SYMB, KC_SPC)

// Symbols ( ) { } < > "
#define L_PAREN LSFT(KC_9)
#define R_PAREN LSFT(KC_0)
#define L_BRACE LSFT(KC_LBRC)
#define R_BRACE LSFT(KC_RBRC)
#define L_ANGLE LSFT(KC_COMM)
#define R_ANGLE LSFT(KC_DOT)
#define DQUOT LSFT(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,
    ESC_CTL, A_WIN  , S_ALT  , D_CTRL , F_SFT  , KC_G   ,                   KC_H   , J_SFT  , K_CTRL , L_ALT  , SCL_WIN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC, KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                               KC_LCTL, M_MOUSE, M_FN   , SYMB_SPC, KC_ENT, KC_BSPC, M_MEDIA, M_MEDIA),

[_FN] = LAYOUT(
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
    _______, A_UML  , SZ_LIG , O_UML  , U_UML  , KC_PSCR,                   CW_TOGG, KC_CAPS, _______, _______, KC_INS , TASKMGR,
    _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_DEL , C_A_DEL,
    _______, _______, _______, _______, _______, KC_APP , _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSLS, _______,
                               _______, _______, _______, _______, _______, _______, _______, T_MOUSE),

[_SYMB] = LAYOUT(
    KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
    _______, L_ANGLE, L_BRACE, L_PAREN, KC_LBRC, KC_QUOT,                   DQUOT  , KC_RBRC, R_PAREN, R_BRACE, R_ANGLE, _______,
    KC_GRV , _1_WIN , _2_ALT , _3_CTRL, _4_SFT , KC_5   ,                   KC_6   , _7_SFT , _8_CTRL, _9_ALT , _0_WIN , KC_MINS,
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

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case _BASE:
           rgb_matrix_set_color_all(255, 0, 255);
           break;
        case _FN:
           rgb_matrix_set_color_all(240, 0, 80);
           break;
        case _SYMB:
           rgb_matrix_set_color_all(80, 0, 240);
           break;
        case _MEDIA:
           rgb_matrix_set_color_all(0, 0, 255);
           break;
        case _MOUSE:
           rgb_matrix_set_color_all(0, 255, 0);
           break;
       default:
           break;
    }

    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // left pinky
        case A_WIN:
        case _1_WIN:
            return 230;
        // right pinky
        case SCL_WIN:
        case _0_WIN:
            return 190;

        // ring fingers
        case S_ALT:
        case _2_ALT:
        case L_ALT:
        case _9_ALT:
            return 200;

        // middle fingers
        case D_CTRL:
        case _3_CTRL:
        case K_CTRL:
        case _8_CTRL:
            return 180;

        // index fingers
        case F_SFT:
        case _4_SFT:
        case J_SFT:
        case _7_SFT:
            return 190;

        default:
            return TAPPING_TERM;

    }
}

