#pragma once

// Keyboard layout MUST BE in US_INTERNATIONAL !!!

enum {
    TD_CAPS,
    TD_APP,
    TD_N,
    TD_EXC,
    TD_INT,
    TD_BRC,
    /*TD_Z,
    TD_X,
    TD_C,
    TD_V,
    TD_P,
    TD_A,
    TD_Q,
    TD_W,
    */
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    MORE_TAPS,
};

static tap dance_state[12];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        //if (state->interrupted) return DOUBLE_SINGLE_TAP;
        //else if (state->pressed) return DOUBLE_HOLD;
        //else
        return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


// TO-DO  THIS ONE IS NOT WORKING AS EXPECTED
// Combined Caps Lock and Caps Word actions
void on_dance_caps(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSFT);
    }
}

void dance_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(CAPSWRD); break;
        case SINGLE_HOLD: register_code16(KC_CAPS); break;
        //case DOUBLE_TAP: register_code16(KC_CAPS); break;
    }
}

void dance_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(CAPSWRD); break;
        case SINGLE_HOLD: unregister_code16(KC_CAPS); break;
        //case DOUBLE_TAP: unregister_code16(KC_CAPS); break;
    }
    dance_state[1].step = 0;
}

// LGUI on single tap and single hold ;  KC_APP on double tap
void on_dance_app(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LGUI);
    }
}

void dance_app_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_APP); break;
    }
}

void dance_app_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_APP); break;
    }
    dance_state[3].step = 0;
}

// Writes Spanish Ñ when N is held down
// Keyboard layout MUST BE in US_INTERNATIONAL !!!
void on_dance_n(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_N);
        tap_code16(US_N);
        tap_code16(US_N);
    }
    if(state->count > 3) {
        tap_code16(US_N);
    }
}

void dance_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(US_N); break;
        case SINGLE_HOLD: register_code16(ALGR(US_N)); break;
        case DOUBLE_TAP: register_code16(US_N); register_code16(US_N); break;
    }
}

void dance_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(US_N); break;
        case SINGLE_HOLD: unregister_code16(ALGR(US_N)); break;
        case DOUBLE_TAP: unregister_code16(US_N); unregister_code16(US_N); break;
    }
    dance_state[0].step = 0;
}


// Writes inverted exclamation '¡' when 1 is held down
// Keyboard layout MUST BE in US_INTERNATIONAL !!!
void on_dance_exc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_1);
        tap_code16(US_1);
        tap_code16(US_1);
    }
    if(state->count > 3) {
        tap_code16(US_1);
    }
}

void dance_exc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(US_1); break;
        case SINGLE_HOLD: register_code16(ALGR(US_1)); break;
        case DOUBLE_TAP: register_code16(US_1); register_code16(US_1); break;
    }
}

void dance_exc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(US_1); break;
        case SINGLE_HOLD: unregister_code16(ALGR(US_1)); break;
        case DOUBLE_TAP: unregister_code16(US_1); unregister_code16(US_1); break;
    }
    dance_state[0].step = 0;
}


// Writes inverted interrogation '¿' when '/' is held down
// Keyboard layout MUST BE in US_INTERNATIONAL !!!
void on_dance_int(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_SLSH);
        tap_code16(US_SLSH);
        tap_code16(US_SLSH);
    }
    if(state->count > 3) {
        tap_code16(US_SLSH);
    }
}

void dance_int_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(US_SLSH); break;
        case SINGLE_HOLD: register_code16(ALGR(US_SLSH)); break;
        case DOUBLE_TAP: register_code16(US_SLSH); register_code16(US_SLSH); break;
    }
}

void dance_int_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(US_SLSH); break;
        case SINGLE_HOLD: unregister_code16(ALGR(US_SLSH)); break;
        case DOUBLE_TAP: unregister_code16(US_SLSH); unregister_code16(US_SLSH); break;
    }
    dance_state[0].step = 0;
}


// Enter [ on SINGLE_TAP, []+left on DOUBLE_TAP, ] on SINGLE_HOLD
void on_dance_brc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count >2) {
        tap_code16(US_LBRC);
    }
}

void dance_brc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_LBRC); break;
        case SINGLE_HOLD: register_code16(US_RBRC); break;
        case DOUBLE_TAP: register_code16(US_LBRC); register_code16(US_RBRC); break;
    }
}

void dance_brc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_LBRC); break;
        case SINGLE_HOLD: unregister_code16(US_RBRC); break;
        case DOUBLE_TAP: unregister_code16(US_LBRC); unregister_code16(US_RBRC); register_code16(KC_LEFT); unregister_code16(KC_LEFT); break;
    }
    dance_state[3].step = 0;
}


// Simulate Ctrl+Z when Z is held down
/*
void on_dance_z(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_Z);
        tap_code16(US_Z);
        tap_code16(US_Z);
    }
    if(state->count > 3) {
        tap_code16(US_Z);
    }
}

void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_Z); break;
        case SINGLE_HOLD: register_code16(C(US_Z)); break;
        case DOUBLE_TAP: register_code16(US_Z); register_code16(US_Z); break;
    }
}

void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_Z); break;
        case SINGLE_HOLD: unregister_code16(C(US_Z)); break;
        case DOUBLE_TAP: unregister_code16(US_Z); break;
    }
    dance_state[3].step = 0;
}

// Simulate Ctrl+X when X is held down
void on_dance_x(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_X);
        tap_code16(US_X);
        tap_code16(US_X);
    }
    if(state->count > 3) {
        tap_code16(US_X);
    }
}

void dance_x_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_X); break;
        case SINGLE_HOLD: register_code16(C(US_X)); break;
        case DOUBLE_TAP: register_code16(US_X); register_code16(US_X); break;
    }
}

void dance_x_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_X); break;
        case SINGLE_HOLD: unregister_code16(C(US_X)); break;
        case DOUBLE_TAP: unregister_code16(US_X); break;
    }
    dance_state[3].step = 0;
}

// Simulate Ctrl+C when C is held down
void on_dance_c(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_C);
        tap_code16(US_C);
        tap_code16(US_C);
    }
    if(state->count > 3) {
        tap_code16(US_C);
    }
}

void dance_c_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_C); break;
        case SINGLE_HOLD: register_code16(C(US_C)); break;
        case DOUBLE_TAP: register_code16(US_C); register_code16(US_C); break;
    }
}

void dance_c_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_C); break;
        case SINGLE_HOLD: unregister_code16(C(US_C)); break;
        case DOUBLE_TAP: unregister_code16(US_C); break;
    }
    dance_state[3].step = 0;
}


// Simulate Ctrl+V when V is held down
void on_dance_v(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_V);
        tap_code16(US_V);
        tap_code16(US_V);
    }
    if(state->count > 3) {
        tap_code16(US_V);
    }
}

void dance_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_V); break;
        case SINGLE_HOLD: register_code16(C(US_V)); break;
        case DOUBLE_TAP: register_code16(US_V); register_code16(US_V); break;
    }
}

void dance_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_V); break;
        case SINGLE_HOLD: unregister_code16(C(US_V)); break;
        case DOUBLE_TAP: unregister_code16(US_V); break;
    }
    dance_state[3].step = 0;
}


// Simulate Ctrl+P when P is held down
void on_dance_p(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_P);
        tap_code16(US_P);
        tap_code16(US_P);
    }
    if(state->count > 3) {
        tap_code16(US_P);
    }
}

void dance_p_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_P); break;
        case SINGLE_HOLD: register_code16(C(US_P)); break;
        case DOUBLE_TAP: register_code16(US_P); register_code16(US_P); break;
    }
}

void dance_p_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_P); break;
        case SINGLE_HOLD: unregister_code16(C(US_P)); break;
        case DOUBLE_TAP: unregister_code16(US_P); break;
    }
    dance_state[3].step = 0;
}


// Simulate Ctrl+A when A is held down
void on_dance_a(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_A);
        tap_code16(US_A);
        tap_code16(US_A);
    }
    if(state->count > 3) {
        tap_code16(US_A);
    }
}

void dance_a_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_A); break;
        case SINGLE_HOLD: register_code16(C(US_A)); break;
        case DOUBLE_TAP: register_code16(US_A); register_code16(US_A); break;
    }
}

void dance_a_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_A); break;
        case SINGLE_HOLD: unregister_code16(C(US_A)); break;
        case DOUBLE_TAP: unregister_code16(US_A); break;
    }
    dance_state[3].step = 0;
}

// Simulate Ctrl+Q when Q is held down
void on_dance_q(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_Q);
        tap_code16(US_Q);
        tap_code16(US_Q);
    }
    if(state->count > 3) {
        tap_code16(US_Q);
    }
}

void dance_q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_Q); break;
        case SINGLE_HOLD: register_code16(C(US_Q)); break;
        case DOUBLE_TAP: register_code16(US_Q); register_code16(US_Q); break;
    }
}

void dance_q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_Q); break;
        case SINGLE_HOLD: unregister_code16(C(US_Q)); break;
        case DOUBLE_TAP: unregister_code16(US_Q); break;
    }
    dance_state[3].step = 0;
}

// Simulate Ctrl+W when W is held down
void on_dance_w(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(US_W);
        tap_code16(US_W);
        tap_code16(US_W);
    }
    if(state->count > 3) {
        tap_code16(US_W);
    }
}

void dance_w_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(US_W); break;
        case SINGLE_HOLD: register_code16(C(US_W)); break;
        case DOUBLE_TAP: register_code16(US_W); register_code16(US_W); break;
    }
}

void dance_w_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(US_W); break;
        case SINGLE_HOLD: unregister_code16(C(US_W)); break;
        case DOUBLE_TAP: unregister_code16(US_W); break;
    }
    dance_state[3].step = 0;
}
*/

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_caps, dance_caps_finished, dance_caps_reset),
    [TD_APP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_app, dance_app_finished, dance_app_reset),
    [TD_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_n, dance_n_finished, dance_n_reset),
    [TD_EXC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_exc, dance_exc_finished, dance_exc_reset),
    [TD_INT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_int, dance_int_finished, dance_int_reset),
    [TD_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_brc, dance_brc_finished, dance_brc_reset),
    /*[TD_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
    [TD_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_x, dance_x_finished, dance_x_reset),
    [TD_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_c, dance_c_finished, dance_c_reset),
    [TD_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_v, dance_v_finished, dance_v_reset),
    [TD_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_p, dance_p_finished, dance_p_reset),
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_a, dance_a_finished, dance_a_reset),
    [TD_Q] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_q, dance_q_finished, dance_q_reset),
    [TD_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_w, dance_w_finished, dance_w_reset),
    */
};
