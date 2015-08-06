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
	/* http://www.keyboard-layout-editor.com/#/layouts/68fc065cd4cab657b2dff0ea6517d06e */
	KEYMAP(
			GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
			TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
			LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
			LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
			FN0, LALT,          SPC,                     RALT, FN1),
	/* 1: dvorak */
	/* http://www.keyboard-layout-editor.com/#/layouts/a642d243b8e4688be99fd2468f9ca212 */
	KEYMAP(
			GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC, \
			TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS, \
			LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,     ENT,  \
			LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,             RSFT, \
			FN0, LALT,          SPC,                     RALT, FN1),
	/* 2: Qwerty on software dvorak. Allows game play on unremappable games without
	   changing any software settings. */
	/* Physical (W): Dvorak (W) maps to (,)*/
	/* http://www.keyboard-layout-editor.com/#/layouts/db2981d07af3389e82d8002822612f6c */	
	KEYMAP(
			GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   QUOT,RBRC,BSPC, \
			TAB, X,   COMM,D,   O,   K,   T,   F,   G,   S,   R,   MINS,EQL, BSLS, \
			LCTL,A,   SCLN,H,   Y,   U,   J,   C,   V,   P,   Z,   Q,         ENT,  \
			LSFT,SLSH,B,   I,   DOT, N,   L,   M,   W,   E,   LBRC,           RSFT, \
			FN0, LALT,          SPC,                     RALT, FN1),
	/* 3: Function keys + ins-pgdn cluster + cut/copy/paste */
	/* http://www.keyboard-layout-editor.com/#/layouts/88abbdcaa101e3d7a45dd56ef3296110 */
	KEYMAP(
			ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,    F8,  F9,  F10, F11, F12, FN4, \
			FN2, NO,  PSCR,SLCK,PAUS,NO,  NO,  INS,   HOME,PGUP,NO,  NO,  NO,  FN3, \
			TRNS,NO,  MPRV,MPLY,MNXT,NO,  NO,  DELETE,END,PGDN,NO,  NO,        NO,   \
			TRNS,NO,  FN5 ,FN6 ,FN7 ,NO,  NO,  NO,  NO,  NO,  NO,            TRNS, \
			TRNS,TRNS,          NO,                      TRNS,TRNS),
	/* 4: Function keys + mouse keys */
	/* http://www.keyboard-layout-editor.com/#/layouts/f5299cb5d5b4b07b124400796e8c9272 */
	KEYMAP(
			ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, FN4, \
			FN2 ,NO,  NO,  MS_U,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN3,  \
			TRNS,NO,  MS_L,MS_D,MS_R,NO,  NO,  BTN1,BTN3,BTN2,NO,  NO,       NO,   \
			TRNS,NO,  NO,  WH_D,WH_U,NO,  NO,  NO,  NO,  NO,  NO,            TRNS, \
			TRNS,TRNS,          NO,                      TRNS,TRNS),
};
const uint16_t PROGMEM fn_actions[] = {
	/* Poker Layout */
	/*  FN KEY                      LAYER */
	[0] = ACTION_LAYER_MOMENTARY(3),  // FN + Clusters
	[1] = ACTION_LAYER_MOMENTARY(4),  // FN + Mouse Keys
	[3] = ACTION_DEFAULT_LAYER_SET(0),  // qwerty (FN* KEY + \)
	[2] = ACTION_DEFAULT_LAYER_SET(1),  // (hardware) dvorak (FN* KEY + TAB)
	[4] = ACTION_DEFAULT_LAYER_SET(2),  // Inverted qwerty (FN* KEY + Backspace)
	// cut/copy/paste for software defined dvorak
	[5] = ACTION_MACRO(CUT), 
	[6] = ACTION_MACRO(COPY),
	[7] = ACTION_MACRO(PASTE),
};
