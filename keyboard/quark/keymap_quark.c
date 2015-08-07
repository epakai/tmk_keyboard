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
			NO,  LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, \
			NO,  NO,  LALT, FN0,        SPC,      FN1,  NO,  NO,   NO),
	/* 1: dvorak */
	KEYMAP(
			TAB, QUOT,COMM, DOT,   P,   Y,   F,   G,   C,   R,   L,   SLSH, \
			LCTL,   A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   \
			NO,  LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z, \
			NO,  NO,  LALT, FN0,        SPC,      FN1,  NO,  NO,   NO),
	/* 2: Qwerty on software dvorak. Allows game play on unremappable games without
	   changing any software settings. */
	/* Physical (W): Dvorak (W) maps to (,)*/
	KEYMAP(
			TAB, X,   COMM,D,   O,   K,   T,   F,   G,   S,   R,   MINS, \
			LCTL,A,   SCLN,H,   Y,   U,   J,   C,   V,   P,   Z,         \
			NO, LSFT, SLSH,B,   I,   DOT, N,   L,   M,   W,   E,   LBRC, \
			NO,  NO,  LALT, FN0,        SPC,      FN1,  NO,  NO,   NO),
	/* 3:  */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			NO,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO, \
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			NO,  NO,  LALT, FN0,        SPC,      FN1,  NO,  NO,   NO),
	/* 4: Function keys + mouse keys */
	/* http://www.keyboard-layout-editor.com/#/layouts/f5299cb5d5b4b07b124400796e8c9272 */
	KEYMAP(
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			NO,     NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO, \
			NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
			NO,  NO,  LALT, FN0,        SPC,      FN1,  NO,  NO,   NO),
};
const uint16_t PROGMEM fn_actions[] = {
	/* Poker Layout */
	/*  FN KEY                      LAYER */
	[0] = ACTION_LAYER_MOMENTARY(3),  // 
	[1] = ACTION_LAYER_MOMENTARY(4),  // 
	[3] = ACTION_DEFAULT_LAYER_SET(0),  // qwerty (FN* KEY + \)
	[2] = ACTION_DEFAULT_LAYER_SET(1),  // (hardware) dvorak (FN* KEY + TAB)
	[4] = ACTION_DEFAULT_LAYER_SET(2),  // Inverted qwerty (FN* KEY + Backspace)
	// cut/copy/paste for software defined dvorak
	[5] = ACTION_MACRO(CUT), 
	[6] = ACTION_MACRO(COPY),
	[7] = ACTION_MACRO(PASTE),
};
