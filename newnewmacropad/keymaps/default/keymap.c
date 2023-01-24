#include QMK_KEYBOARD_H

#define XXX _______

//DECLARACION DEL NOMBRE DE LAS 'CAPAS', NUMERADAS DESDE 0
enum layer_names {
    _BASE,      //0
    _FUNC,      //1 ...
    _EXAMPLE    
};

//DECLARACION DEL NOMBRE DE LAS MACROS
enum custom_keycodes {
    EJEMPLO = SAFE_RANGE,
    OPENFOLDER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
        KC_7,               KC_8,       KC_9,       MO(_EXAMPLE),
        KC_4,               KC_5,       KC_6,       KC_PLUS,
        LT(_FUNC, KC_1),    KC_2,       KC_3,       KC_0
    ),

    [_FUNC] = LAYOUT(
        QK_BOOT,    XXX,        XXX,    XXX, 
        KC_VOLU,    KC_VOLD,    XXX,    XXX, 
        XXX,        XXX,        XXX,    KC_MUTE
    ),

    [_EXAMPLE] = LAYOUT(
        XXX,    EJEMPLO,    OPENFOLDER, XXX,
        XXX,    XXX,        XXX,        XXX,
        XXX,    XXX,        XXX,        XXX
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EJEMPLO:
        if (record->event.pressed) {
            SEND_STRING("SMOO FREE");
        }
        break;

    case OPENFOLDER:
            if (record->event.pressed) {        //EVENTO, TECLA SE PRESIONA
                SEND_STRING(SS_LCTL("k"));
            } else {                            //EVENTO, TECLA SE LEVANTA
                SEND_STRING(SS_LCTL("o"));
            }
            break;
    
    default:
        break;
    }

    return true;
}