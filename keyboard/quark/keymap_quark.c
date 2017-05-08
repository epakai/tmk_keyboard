#include "keymap_common.h"
#include "../../common/action_layer.h"
enum macro_id {
	CUT, 
	COPY, 
	PASTE
};
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	keyevent_t event = record->event;
	switch (id) {
		case CUT:
			if (default_layer_state <= 1) {
				return (event.pressed ?
						MACRO( D(LCTL), T(B), U(LCTL), END ) :
						MACRO( END ) );
			} else {
				return (event.pressed ?
						MACRO( D(LCTL), T(X), U(LCTL), END ) :
						MACRO( END ) );
			}
		case COPY:
			if (default_layer_state <= 1) {
				return (event.pressed ?
						MACRO( D(LCTL), T(I), U(LCTL), END ) :
						MACRO( END ) );
			} else {
				return (event.pressed ?
						MACRO( D(LCTL), T(C), U(LCTL), END ) :
						MACRO( END ) );
			}
		case PASTE:
			if (default_layer_state <= 1) {
				return (event.pressed ?
						MACRO( D(LCTL), T(DOT), U(LCTL), END ) :
						MACRO( END ) );
			} else {
				return (event.pressed ?
						MACRO( D(LCTL), T(V), U(LCTL), END ) :
						MACRO( END ) );
			}
	}
	return MACRO_NONE;
}

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: qwerty (default based on host using software dvorak layout) */
	KEYMAP(
			TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC, \
			LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,     SCLN, \
			FN2, LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, \
			FN3,  FN4,  LALT, FN0,     SPC,        FN1,  NO, RALT, RCTL),
	/* 1: dvorak */
	KEYMAP(
			TAB, QUOT,COMM, DOT,   P,   Y,   F,   G,   C,   R,   L,   SLSH, \
			LCTL,   A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   \
			FN5, LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z, \
			FN3,  FN4,  LALT, FN0,       SPC,     FN1,  NO, RALT, RCTL),
	/* 2: Qwerty on software dvorak. Allows game play on unremappable games without
	   changing any software settings. */
	/* Physical (W): Dvorak (W) maps to (,)*/
	KEYMAP(
			TAB, X,   COMM,D,   O,   K,   T,   F,   G,   S,   R,   MINS, \
			LCTL,A,   SCLN,H,   Y,   U,   J,   C,   V,   P,   Z,         \
			FN6, LSFT, SLSH,B,   I,   DOT, N,   L,   M,   W,   E,  LBRC, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  NO, RALT, RCTL),
	/* 3:  UPPER : upside down heart */
	KEYMAP(
			ESC,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, BSPC, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    ENT, \
			NO,   LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 4: LOWER : upside down spade*/
	KEYMAP(
			GRV,  1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   BSPC, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    ENT, \
			NO,   LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 5: qwerty BLACK MOD */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  MINS,  EQL, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  RBRC, BSLS, \
			FN2,  LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  QUOT,NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 6: DIAMOND */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   BSPC, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    ENT, \
			NO, LSFT, NO, FN10, FN11, FN12,  NO,  NO,  NO,  NO,  NO,  NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 7: CLUB */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   BSPC, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    ENT, \
			NO,   LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 8: dvorak BLACK MOD */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  LBRC, RBRC, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  EQL,  BSLS, \
			FN5,  LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, MINS, NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),
	/* 9: qwerty on soft dvorak BLACK MOD */
	/* not implemented, will do as needed */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO, \
			LCTL,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO, \
			FN6,  LSFT,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			FN3,  FN4,  LALT, FN0,        SPC,      FN1,  FN7, FN8, FN9),

};
const uint16_t PROGMEM fn_actions[] = {
	// black mod is leftmost black key under control, above diamond
	/*  FN KEY                      LAYER */
	[0] = ACTION_LAYER_MOMENTARY(4),  // CLUB: LOWER layer
	[1] = ACTION_LAYER_MOMENTARY(3),  // HEART: UPPER layer
	[2] = ACTION_LAYER_MOMENTARY(5),  // qwerty black mod
	[5] = ACTION_LAYER_MOMENTARY(8),  // dvorak black mod
	[6] = ACTION_LAYER_MOMENTARY(9),  // qwerty on soft dvorak black mod
	[3] = ACTION_LAYER_MOMENTARY(6),  // diamond
	[4] = ACTION_LAYER_MOMENTARY(7),  // club
	[7] = ACTION_DEFAULT_LAYER_SET(0),  // qwerty (FN* KEY + \)
	[8] = ACTION_DEFAULT_LAYER_SET(1),  // (hardware) dvorak (FN* KEY + TAB)
	[9] = ACTION_DEFAULT_LAYER_SET(2),  // Inverted qwerty (FN* KEY + Backspace)
	// cut/copy/paste for software defined dvorak
	[10] = ACTION_MACRO(CUT), 
	[11] = ACTION_MACRO(COPY),
	[12] = ACTION_MACRO(PASTE),
};
