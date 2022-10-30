# My Lily58 split keyboard QMK config files

![Lily58 split keyboard](/source/20221027_085624.jpg)

## Basic information and principles

This is my first [QMK firmware](https://github.com/qmk/qmk_firmware) for my first ever mechanical ergonomic split keyboard: a [Lily58 Classic](https://github.com/kata0510/Lily58).

I picked this one up expecting to have a relatively easy learning curve, after decades of using _normal_ staggered keyboards which in reality are based on a 150-year old design.

I am NOT a Developer/IT professional, so customizing these C-language config files hasn't been easy for me. If you're coming from a non-pro background like me, I strongly suggest you to read the [qmk docs](https://docs.qmk.fm/#/) carefully and **several times**, to get a better understanding before attempting to flash your keyboard with a custom firmware. Also, explore other `git` repositories for examples to help you.

The ultimate goal is to have a keyboard layout that is useful for your very own workflows, and for me this translated into:

- Need a number row with symbols to avoid memorizing their position in hidden layers.

- Need one layer for moving around with <kbd>←</kbd> <kbd>→</kbd> <kbd>↑</kbd> <kbd>↓</kbd> <kbd>Home</kbd> <kbd>End</kbd> <kbd>PgUp</kbd> <kbd>PgDown</kbd> in text documents, email and spreadsheets, for my regular usage, both at work and at home. I also added mouse movement keys in the same layer. Why?  Well... not sure if I will end up using it at all but, why not?

- Need a `NUMPAD` layer to use it in spreadsheets, etc., with Function keys <kbd>F1</kbd> to <kbd>F12</kbd> also accessible in the same layer.

- Minimize the number of hidden shortcuts, keycodes, etc., as to easily remember them all.

- Reduce finger travel/movement, particularly for the pinky. Increase usage of stronger and more agile fingers (e.g. thumb, index, middle).


## Design choices made

- Given the challenges to find a set of decent quality keycaps in my native language (Spanish) with enough 1-unit symbol/mod keys, I went ahead and got a US English set instead, and then used QMK's [US-International keymap](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_us_international.h) in order to access our beloved <kbd>Ñ</kbd> (like in España),  accented vowels (<kbd>á</kbd> <kbd>é</kbd> <kbd>í</kbd> <kbd>ó</kbd> <kbd>ú</kbd> <kbd>ü</kbd>), and symbols <kbd>¡</kbd> <kbd>¿</kbd> using <kbd>AltGr</kbd>. Worth noting that this keymap would also help typing in  other non-English languages, such as French, German, etc. If you happen to find a decent keycaps set in your language, you will be better off using the relevant keymap from [here](https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras).

- The above choice **requires your operating system to have the keyboard layout set to** `US international (with dead keys)` in Linux or `US international` in Windows **to properly function** as to recognize the keycodes sent by this custom firmware. Otherwise, you will be lost trying to find where the appropriate symbols are actually located. 

- I've moved some symbols (e.g. <kbd>|</kbd>, <kbd>/</kbd>, <kbd>?</kbd>, <kbd>\\</kbd>) from their standard location for personal convenience, which required finding a "flattish" keycap profile across all rows. [XDA profile](https://www.reddit.com/r/MechanicalKeyboards/comments/j484j5/keycap_profiles_i_compiled_a_direct_comparison/) was the choice I made.

- Thumb keys will act as <kbd>Enter</kbd> and <kbd>Space</kbd> when tapped, and <kbd>Shift</kbd> when held down.

- Moved <kbd>BackSpace</kbd> and <kbd>Delete</kbd> to the middle keys, to be pressed by the index fingers. 

- These middle keys will also act as <kbd>Left Ctrl</kbd> and <kbd>Right Ctrl</kbd> when held down, because I intensively use <kbd>Ctrl</kbd> and <kbd>Shift</kbd> combined with the arrow/move keys to make text/range selections in documents, emails and spreadsheets, so it will allow me to easily reach those combinations with my index and thumb fingers while using the `MOVE` layer.

- Not being a developer, I somewhat _relegated_ the brackets (<kbd>\[ \]</kbd> <kbd>\{ \}</kbd>) to a less important position, though easily accessible and with auto-closing enabled via [`Tap Dance`](https://docs.qmk.fm/#/feature_tap_dance) or [`Send String`](https://docs.qmk.fm/#/feature_send_string) functions, as I only left one of the keys visible.

- [GraveEscape](https://docs.qmk.fm/#/feature_grave_esc) is also used to reduce number of keys, as well as [CapsWord](https://docs.qmk.fm/#/feature_caps_word) and CapsLock in the same key using [tap dance](https://docs.qmk.fm/#/feature_tap_dance).

- <kbd>Alt</kbd> and <kbd>AltGr</kbd> are [OneShot keys](https://docs.qmk.fm/#/one_shot_keys) so one tap will keep it active until another key is pressed.

- <kbd>Win</kbd> key in the right half is coupled with context menu's <kbd>App</kbd> key through a `tap dance`.

- In `NUMPAD` layer, a double parenthesis <kbd>(</kbd> <kbd>)</kbd> is automatically created using [`Send String`](https://docs.qmk.fm/#/feature_send_string) with the cursor moving inside for easier/faster usage.

- It is possible also to enable some `tap dance` codes to simulate <kbd>Ctrl + key</kbd> for <kbd>Copy</kbd>, <kbd>Cut</kbd>, <kbd>Paste</kbd>, etc. etc., by uncommenting the relevant sections in `tap_dance.c` and adding the appropriate `TD(TD_KC)` codes in `keymap.c` files, so those codes will be added to the relevant letter as a long-press action, i.e. holding <kbd>C</kbd> down for more than 200 ms (user-defined as `TAPPING_TERM 200` in `config.h`), will trigger <kbd>Ctrl + C</kbd>. These codes are currently disabled with their relevant commands commented out.

Further info on keycodes is available in the docs [here](https://docs.qmk.fm/#/keycodes?id=basic-keycodes).


## Visual representation of each layer

### Base QWERTY layer

```
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CAPWRD|  A   |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   '  |  -   |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |  \   |  Z   |   X  |   C  |   V  |   B  |-------|    |-------|N or Ñ|   M  |   ,  |   .  |   ;  |[ & ] |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| NUM  | /   +   /       \   +  \  | MOVE | OSMod| LGUI |
 *                   |      | LAlt | PAD  |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```

### NUMPAD layer

Activated by holding `MO(_NUMPAD)` modifier key down. Simply release to return to `QWERTY` layer.

```
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |      |      |      |      | Ins  |                    |   ^  |   7  |   8  |   9  |( & ) |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F9  |  F10 |  F11 |  F12 |      |                    |      |   4  |   5  |   6  |   *  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------|      |   1  |   2  |   3  |   +  |  -   |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |-------|    |-------|      |   0  |   ,  |   .  |      |Enter |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| NUM  | /   +   /       \   +  \  | MOVE | OSMod| LGUI |
 *                   |      | LAlt | PAD  |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```

### MOVE layer

Activated by holding `MO(_MOVE)` modifier key down. Simply release to return to `QWERTY` layer.

```
/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |      |      |Wh_Up |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | Btn1 |Ms_Up | Btn2 |      |                    |      | Home |  Up  | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Wh_L | Ms_L | Ms_D | Ms_R | Wh_R |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |      |      | Wh_D |      |      |-------|    |-------|      | End  | Ins  | PgDn |      |{ & } |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| NUM  | /   +   /       \   +  \  | MOVE | OSMod| LGUI |
 *                   |      | LAlt | PAD  |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```

### ADJUST layer

Activated by simultaneously holding `_MOVE` and `_NUMPAD` modifier keys down.

No need for RGB/Backlight adjustments in a Lily58 Classic version, so just added Volume controls <kbd>Mute</kbd>  <kbd>Vol Up</kbd>  <kbd>Vol Down</kbd>.

A keyboard <kbd>Reset</kbd> is also added at a difficult to reach position, to avoid accidental activation, though the PCB has a physical reset button.

```
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Mute | Vol- | Vol+ |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

```


## To-Do's

- Secondary OLED display isn't showing the info as expected. Need to investigate further.
- `Caps Lock` not working in tap dance combination with `Caps Word`. Need to investigate further.

## Issues and support

These files were created for my personal use, and shared here in case they may help someone else. There is NO warranty of it working properly and may do harm to your keyboard as it is not fully tested. You should be able to understand the code in order to use it.

Unfortunately, I am not a developer, so I will not be able to support any issues that you may find if you decide to use this firmware 'as-is'.  

Please reach out to the QMK's team for support as per this [guide](https://docs.qmk.fm/#/support).


## Acknowledgments

- First and foremost, my gratitude to the [QMK's team](https://github.com/qmk/qmk_firmware) for their great piece of software.
- Also my gratitude to kata0510 for designing and sharing the [Lily58 split keyboard](https://github.com/kata0510/Lily58).
- I've borrowed some code from the implementations made by [alvaro-prieto](https://github.com/alvaro-prieto/corne/tree/main/source) and [jufracaqui](https://github.com/jufracaqui/crkbd-qmk-ole-d), and Luna, the keyboard pet, has been borrowed from [HellSingCoder](https://github.com/HellSingCoder), so kudos to them as well.

