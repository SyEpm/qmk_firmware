/*
KEYMAP mzo
Cuenta con las siguentes capas>
0- QWERTY o DVORAK - se seleccionara capa por defecto desde capa FUNCION (aun no implementado DVORAK)
1- NUMERICO - numeros y operadores basicos
2- SIMBOLO - simbolos que facilitan para programacion
3- ADJ/MEDIA - Ajuste de LEDs, teclas multimedia y mouse
4- FUNCION - de F1 a F12
*/

#include QMK_KEYBOARD_H

enum crkbd_layers {
    _QWERTY,
    _DVORAK,
    _NUMER,
    _MOVIM,
    _AJUSTE,
    _MACROS1,
    _MACROS2
};

enum custom_keycodes {
  MCR_MANZ = SAFE_RANGE,
  MCR_SILV, MCR_PINT, MCR_JSIL,
  MCR_ALVE, MCR_MOTT,
  MCR_LUPA, MCR_BONI, MCR_ALVA,
  MCR_CEBE, MCR_FERR,
  MCR_RAVE, MCR_RODR,
  MCR_NOTE
};

enum tapdances{
  TD_ALT_GUI,
  TD_SFT_CAP
};

qk_tap_dance_action_t tap_dance_actions [] = {
    [TD_ALT_GUI] = ACTION_TAP_DANCE_DOUBLE (KC_LALT, KC_LGUI),  // 1 toque- CONTROL, 2 toques- WIN
    [TD_SFT_CAP] = ACTION_TAP_DANCE_DOUBLE (KC_LSFT, KC_CAPS)  // 1 toque- SHIFT, 2 toques- BLOQ MAYUS

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
LT(_MACROS1, KC_TAB), KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(TD_SFT_CAP),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            TD(TD_ALT_GUI), LT(_NUMER, KC_BSPC), KC_SPC, KC_SPC, LT(_MOVIM, KC_ENT),  KC_DEL
                                        //|--------------------------|  |--------------------------|
  ),

  [_DVORAK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
LT(_MACROS1, KC_TAB), KC_DOT, KC_COMM, KC_SCLN, KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_H,    KC_L, KC_LBRC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 TD(TD_SFT_CAP),    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_R,    KC_T,    KC_N,    KC_S, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_SLSH,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  KC_ESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            TD(TD_ALT_GUI), LT(_NUMER, KC_BSPC), KC_SPC, KC_SPC, LT(_MOVIM, KC_ENT),  KC_DEL
                                        //|--------------------------|  |--------------------------|
  ),

  [_NUMER] = LAYOUT_split_3x6_3(
    //el teclado qmk tiene los nombres asignados para teclado en ingles, corresponde a la tecla no al caracter
    //para que las funciones correspondan al teclado español, se llama por el nombre de la tecla que corrsponde, no al simbolo
    //para tener la letra "ñ" es necesario usar teclado español y en esta capa no coincidiran los nombres
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,    KC_0, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,RALT(KC_Q), KC_NO,  KC_EQL, KC_LBRC, KC_RBRC,                      KC_PSLS,    KC_4,    KC_5,    KC_6, KC_PAST, KC_PMNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_NUBS,LSFT(KC_NUBS), KC_NO, KC_QUOT, KC_NUHS,                          KC_0,    KC_1,    KC_2,    KC_3, KC_PDOT, KC_PPLS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT, KC_TRNS,  KC_SPC,    KC_0, LT(_AJUSTE, KC_ENT), KC_RALT
                                        //|--------------------------|  |--------------------------|
  ),

  [_MOVIM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
         KC_TAB, KC_BRIU, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U,                      KC_PSCR, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_VOLU,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                LALT(KC_PSCR), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_VOLD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,   KC_NO, KC_NLCK, KC_CAPS, KC_SLCK,   KC_NO,                       KC_INS, KC_ACL0, KC_ACL1, KC_ACL2, KC_MFFD, KC_MUTE,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_BTN2, LT(_AJUSTE, KC_BSPC), KC_BTN1,  KC_BTN3, KC_TRNS,  KC_DEL
                                        //|--------------------------|  |--------------------------|
  ),

  [_AJUSTE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
         KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,   KC_NO,                        KC_NO,   BL_ON,  BL_INC,   KC_NO,   KC_NO, DF(_QWERTY),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_TOG,                      BL_TOGG,  BL_OFF,  BL_DEC,   KC_NO,   KC_NO, DF(_DVORAK),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT, KC_TRNS,   KC_NO,      KC_NO, KC_TRNS, KC_LCTL
                                        //|--------------------------|  |--------------------------|
  ),

  [_MACROS1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
        KC_TRNS, MO(_MACROS2), KC_NO, KC_NO,  KC_NO,   KC_NO,                     MCR_SILV,MCR_ALVE,MCR_LUPA,MCR_CEBE,MCR_RAVE,   KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MCR_PINT,MCR_MOTT,MCR_BONI,MCR_FERR,MCR_RODR,   KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MCR_JSIL,   KC_NO,MCR_ALVA,   KC_NO,   KC_NO,   KC_NO,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MCR_NOTE,   KC_NO,   KC_NO,   MCR_MANZ,   KC_NO,   KC_NO
                                        //|--------------------------|  |--------------------------|
  ),

  [_MACROS2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------|                    |-----------------------------------------------------|
        KC_TRNS, KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MCR_SILV,MCR_ALVE,MCR_LUPA,MCR_CEBE,MCR_RAVE,   KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MCR_PINT,MCR_MOTT,MCR_BONI,MCR_FERR,MCR_RODR,   KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     MCR_JSIL,   KC_NO,MCR_ALVA,   KC_NO,   KC_NO,   KC_NO,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MCR_NOTE,   KC_NO,   KC_NO,   MCR_MANZ,   KC_NO,   KC_NO
                                        //|--------------------------|  |--------------------------|
  )

};

/*
//CONFIGURACION LEDs DE CAPAS
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {21, 21, HSV_RED}     // Light 21 LEDs, starting with LED 22
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 0, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 0, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {42, 0, HSV_GREEN}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

//ENCENDER LAS CAPAS

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUMER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MOVIM));
    return state;
}

*/

#ifdef OLED_DRIVER_ENABLE
  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_270;
    }

    //dejar capa por defecto en macro
    //set_single_persistent_defalt_layer(layer)

  void oled_render_layer_state(void) {

        switch (get_highest_layer(layer_state)) {
            case 0:
                switch (get_highest_layer(default_layer_state)) {
                  case _QWERTY:
                    oled_write_ln_P(PSTR("QWRTY"), false);
                    break;
                  case _DVORAK:
                    oled_write_ln_P(PSTR("DVORK"), false);
                    break;
                }
                break;
            case _NUMER:
                oled_write_ln_P(PSTR("-NRO-"), false);
                break;
            case _MOVIM:
                oled_write_ln_P(PSTR("-MOV-"), false);
                break;
            case _AJUSTE:
                oled_write_ln_P(PSTR("-AJT-"), false);
                break;
            default:
                oled_write_ln_P(PSTR("-err-"), false);
                break;
        }
    }


  char keylog_str[24] = {};

  const char code_to_name[60] = {
      ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
      'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
      '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
      'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
      '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

  void set_keylog(uint16_t keycode, keyrecord_t *record) {
        char name = ' ';
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
        if (keycode < 60) {
        name = code_to_name[keycode];
        }

        // update keylog
        snprintf(keylog_str, sizeof(keylog_str), "[ %c ]\n",name);
    }

  void oled_render_keylog(void) {
      oled_write(keylog_str, false);
    }

  void oled_task_user(void) {
      if (is_keyboard_master())
          oled_write_ln_P(PSTR("      USB      \n"), true);
      else
          oled_write_ln_P(PSTR("     TRRS      \n"), true);

      oled_render_layer_state();
      oled_render_keylog();
    }

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        if (record->event.pressed) {
            set_keylog(keycode, record);

            //rgblight_enable_noeeprom();

            switch (keycode) {
                case MCR_MANZ:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Pablo Manzinalli CI ");
                    SEND_STRING("47667029");
                    return false;
                case MCR_SILV:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Gustavo Silveira CI ");
                    SEND_STRING("37114773");
                    return false;
                case MCR_PINT:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Juan Pablo Pintos CI ");
                    SEND_STRING("46359328");
                    return false;
                case MCR_JSIL:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING(" ");
                    SEND_STRING(" ");
                    return false;
                case MCR_ALVE:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Victor Alves CI ");
                    SEND_STRING("41805372");
                    return false;
                case MCR_MOTT:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Mauricio Motta CI ");
                    SEND_STRING("46397758");
                    return false;
                case MCR_LUPA:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Juan Gaspar Lupano CI ");
                    SEND_STRING("46333516");
                    return false;
                case MCR_BONI:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Bruno Bonilla CI ");
                    SEND_STRING("36230865");
                    return false;
                case MCR_ALVA:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING(" ");
                    SEND_STRING(" ");
                    return false;
                case MCR_CEBE:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Alvaro Cebey CI ");
                    SEND_STRING("40551471");
                    return false;
                case MCR_FERR:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Mario Ferreira CI ");
                    SEND_STRING("32338520");
                    return false;
                case MCR_RAVE:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Robert Ravelli CI ");
                    SEND_STRING("47645417");
                    return false;
                case MCR_RODR:
                    if (get_highest_layer(layer_state) == _MACROS2)
                        SEND_STRING("Ricardo Rodriguez CI ");
                    SEND_STRING("36449987");
                    return false;
                case MCR_NOTE:
                    tap_code(KC_LGUI);
                    SEND_STRING("notepad");
                    tap_code(KC_ENT);
                    return false;
                default:
                    return true; // Process all other keycodes normally
            }
        }
        //else
        //    rgblight_disable_noeeprom();

        return true;
    }

  /*
  void oled_render_logo(void) {
      static const char PROGMEM crkbd_logo[] = {
          0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
          0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
          0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
          0};
      oled_write_P(crkbd_logo, false);
    }

   void render_bootmagic_status(bool status) {
      // Show Ctrl-Gui Swap options
      static const char PROGMEM logo[][2][3] = {
          {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
          {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
      };
      if (status) {
          oled_write_ln_P(logo[0][0], false);
          oled_write_ln_P(logo[0][1], false);
      } else {
          oled_write_ln_P(logo[1][0], false);
          oled_write_ln_P(logo[1][1], false);
      }
    }
    */
#endif // OLED_DRIVER_ENABLE
