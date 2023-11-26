# Configuración QMK para mi teclado Lily 58 // My Lily58 split keyboard QMK config files

![Lily58 split keyboard](/source/20221027_085624.jpg)

[🇬🇧 Go To Description (English)](#-description)    

# 💡 Descripción
## Información Básica y Principios
Esta es mi primera configuración de [QMK firmware](https://github.com/qmk/qmk_firmware) para mi primer teclado ergonómico dividido: un [Lily58 Classic](https://github.com/kata0510/Lily58).

Elegí este modelo esperando tener una curva de aprendizaje más fácil, tras décadas de usar un teclado _normal_ que, en realidad, está basado en un diseño de hace 150 años.

NO soy un desarrollador/profesional de T.I., así que personalizar los ficheros en lenguaje C no ha sido fácil para mí. Si tampoco eres un profesional de T.I., te recomiendo encarecidamente que leas los [qmk docs](https://docs.qmk.fm/#/) con detenimiento y **varias veces**, para comprenderlo mejor antes de intentar grabar una configuración personalizada en tu teclado programable. Asimismo, explora otros repositorios `git` para buscar ejemplos de ayuda.

El objetivo real de tener un mapa de teclado personalizado es que sea útil para tu propio flujo de trabajo, y para mí esto se traduce en:

- Necesito una fila numérica con símbolos para evitar memorizar sus posiciones en capas ocultas.

- Necesito una capa para moverme con <kbd>←</kbd> <kbd>→</kbd> <kbd>↑</kbd> <kbd>↓</kbd> <kbd>Home</kbd> <kbd>End</kbd> <kbd>PgUp</kbd> <kbd>PgDown</kbd> en documentos de texto, emails y hojas de cálculo, para uso común, tanto en el trabajo como en casa. También he añadido movimientos del ratón en la misma capa. ¿Por qué? Bueno... no sé si lo usaré realmente, pero ¿por qué no?

- Necesito una capa `NUMPAD` para usarla en hojas de cálculo, etc., con teclas de función <kbd>F1</kbd> a <kbd>F12</kbd> accesibles en la misma capa.

- Minimizar el número de atajos ocultos, códigos de tecla, etc., para poder recordar todos.

- Reducir el desplazamiento de los dedos, particularmente para el meñique. Incrementar el uso de los dedos más ágiles y fuertes (p.ej. pulgar, índice, medio).



## Opciones de diseño elegidas

- Dada la dificultad de encontrar un conjunto de teclas de calidad en mi lengua materna (Español) con suficientes teclas de 1 unidad, me decidí por elegir un conjunto en inglés de EE.UU. en su lugar, y luego usar el [Mapeo US-International](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_us_international.h) de QMK para poder acceder a nuestra querida <kbd>Ñ</kbd>, a vocales acentuadas (<kbd>á</kbd> <kbd>é</kbd> <kbd>í</kbd> <kbd>ó</kbd> <kbd>ú</kbd> <kbd>ü</kbd>), y otros símbolos <kbd>¡</kbd> <kbd>¿</kbd>. A descatar que este mapeo permite escribir en otros idiomas como francés, alemán, etc. Si encuentras un conjunto de teclas en tu idioma, será más fácil usar el mapeo adecuado desde [aquí](https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras).

- Esa decisión **requiere que tu sistema operativo tenga la distribución de teclado en** `Inglés EE.UU. (con teclas muertas)` en Linux o `EE.UU. internacional` en Windows **para funcionar adecuadamente** y así reconocer los códigos de tecla enviados por este firmware personalizable. De otra forma, estarás perdido intentando encontrar dónde están los símbolos que intentas usar.

- La <kbd>Ñ</kbd> española es accesible con una pulsación larga en la <kbd>N</kbd> o usando <kbd>AltGr</kbd>+<kbd>N</kbd>. La exclamación inicial <kbd>¡</kbd> y la interrogación inicial <kbd>¿</kbd> son accesibles con una pulsación larga en <kbd>1</kbd> o <kbd>/</kbd> respectivamente, o usando <kbd>AltGr</kbd> con las mismas. La exclamación final <kbd>!</kbd> y la interrogación final <kbd>?</kbd> son accesibles en las mismas teclas usando <kbd>Shift</kbd>. 

- He movido algunos símbolos (p.ej. <kbd>|</kbd>, <kbd>/</kbd>, <kbd>?</kbd>, <kbd>\\</kbd>) de su lugar habitual por preferencia personal, lo que implica usar un perfil de teclas plano en todas las filas. El [perfil XDA](https://www.reddit.com/r/MechanicalKeyboards/comments/j484j5/keycap_profiles_i_compiled_a_direct_comparison/) fue el elegido para esto.

- Las teclas en el pulgar actuan como <kbd>Intro</kbd> y <kbd>Espacio</kbd> cuando se pulsan, y como <kbd>Shift</kbd> cuando se mantienen pulsadas.

- He movido <kbd>Retroceso</kbd> y <kbd>Suprimir</kbd> a las teclas centrales, para pulsarse con el dedo índice. 

- Estas teclas centrales también sirven como <kbd>Ctrl</kbd> cuando se mantienen pulsadas, porque uso a menudo <kbd>Ctrl</kbd> y <kbd>Shift</kbd> combinados con las teclas de dirección para hacer selecciones de texto o rango en documentos, emails u hojas de cálculo, así que me permite acceder a estas combinaciones con mis dedos índice y pulgar mientras uso la capa `MOVE`.

- No siendo un desarrollador, he _relegado_ en cierto modo los corchetes (<kbd>\[ \]</kbd> y las llaves <kbd>\{ \}</kbd>) a una posición menos relevante, aunque fácilmente accesible y con auto-cierre de los mismos vía funciones [`Tap Dance`](https://docs.qmk.fm/#/feature_tap_dance) o [`Send String`](https://docs.qmk.fm/#/feature_send_string), ya que he dejado solamente una de sus teclas visible.

- La función [GraveEscape](https://docs.qmk.fm/#/feature_grave_esc) también la uso para reducir el número de teclas. [CapsWord](https://docs.qmk.fm/#/feature_caps_word) la uso en la capa base QWERTY y CapsLock puede activarse/desactivarse en la capa MOVE.

- <kbd>Alt</kbd> y <kbd>AltGr</kbd> son teclas [OneShot](https://docs.qmk.fm/#/one_shot_keys), con lo que una pulsación las mantiene activas hasta que se pulsa otra tecla.

- La tecla <kbd>Win</kbd> de la derecha hace también de menú contextual <kbd>App</kbd> usando un `tap dance`.

- En la capa `NUMPAD`, un doble paréntesis <kbd>(</kbd> <kbd>)</kbd> se crea automáticamente usando [`Send String`](https://docs.qmk.fm/#/feature_send_string) y el cursor se mueve al medio entre ambos para un uso más fácil/rápido.

- Es posible también activar códigos `tap dance` para simular <kbd>Ctrl + tecla</kbd> para <kbd>Copiar</kbd>, <kbd>Cortar</kbd>, <kbd>Pegar</kbd>, etc. etc., y añadiendo el código `TD(TD_KC)` apropiado en el fichero `keymap.c`, por lo que esos códigos simulados serán añadidos a la letra correspondiente con una pulsación larga, por ejemplo, manteniendo pulsada la <kbd>C</kbd> por más de 200 ms (configurable como `TAPPING_TERM 200` en `config.h`), ejecutará <kbd>Ctrl + C</kbd>. Estos códigos pueden activarse/desactivarse con sus respectivos comandos en el fichero `tap_dance.c`.

Más información sobre los códigos de tecla y funciones disponibles [aquí](https://docs.qmk.fm/#/keycodes?id=basic-keycodes).



## Representación visual de cada capa

### Capa Base QWERTY 

```
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |  1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
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

### Capa MOVE

Activada al mantener pulsado el modificador `MO(_MOVE)` . Liberarlo para regresar a la capa `QWERTY`.

```
/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |      |      |Wh_Up |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | Btn1 |Ms_Up | Btn2 |      |                    |      | Home |  Up  | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS | Wh_L | Ms_L | Ms_D | Ms_R | Wh_R |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |      |      | Wh_D |      |      |-------|    |-------|      | End  | Ins  | PgDn |      |{ & } |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| ADJ  | /   +   /       \   +  \  |      | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```
### Capa NUMPAD 

Activada al mantener pulsado el modificador `MO(_NUMPAD)` . Liberarlo para regresar a la capa `QWERTY`.

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
 *                   | LGUI | OSMod|      | /   +   /       \   +  \  | ADJ  | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```

### Capa ADJUST 

Activada al mantener pulsados simultáneamente los modificadores `_MOVE` and `_NUMPAD`. Liberarlos para regresar a la capa `QWERTY`.

Imprimir Pantalla <kbd>PrtScr</kbd> está disponible en la letra P en esta misma capa.

No necesito ajustes RGB/Retroiluminación al usar la versión clásica del Lily58, por lo que sólo añadí controles de volumen <kbd>Mute</kbd>  <kbd>Vol Up</kbd>  <kbd>Vol Down</kbd>.

Un <kbd>Reset</kbd> del teclado está presente en una posición difícil de alcanzar, para evitar activación accidental, aunque la placa tiene un botón físico para ello.

```
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |PrtScr|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Mute | Vol- | Vol+ |      |-------,    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Ctrl |    |  Ctrl |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Shift  /       \Shift \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

```

## To-Do's

- La pantalla OLED secundaria no muestra la información esperada. Necesito investigarlo más.

## Problemas y Soporte

Estos ficheros han sido creados para mi uso personal, y los comparto en caso de que puedan ayudar a alguien. NO HAY NINGUNA garantía de que funcionen perfectamente y no se han probado en profundidad, por lo que podrían dañar tu teclado. Debes entender bien el código antes de poder usarlo.

Lamentablemente, no soy desarrollador de T.I., por lo que no seré capaz de ayudar con cualquier problema que pueda surgir si decides usar este firmware 'tal cual'.

Por favor, dirígete al equipo de soporte de QMK para consultas [aquí](https://docs.qmk.fm/#/support).


## Reconocimientos

- Primero de todo, mi gratitud al [Equipo de QMK's](https://github.com/qmk/qmk_firmware) por su estupendo programa.
- Mi agradecimiento también para kata0510 por diseñar y compartir el [Teclado dividido Lily58](https://github.com/kata0510/Lily58).
- He usado algo de código de las implementaciones hechas por [alvaro-prieto](https://github.com/alvaro-prieto/corne/tree/main/source) y [jufracaqui](https://github.com/jufracaqui/crkbd-qmk-ole-d); y Luna, la mascota del teclado, la he usado del código de [HellSingCoder](https://github.com/HellSingCoder), así que gracias a todos ellos también.
- También he usado esta carcasa para impresión 3D (https://www.thingiverse.com/thing:6014207)


[🇪🇸  Ir a Descripción (Español)](#-descripción) 

# 💡 Description
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

- Given the challenges to find a set of decent quality keycaps in my native language (Spanish) with enough 1-unit symbol/mod keys, I went ahead and got a US English set instead, and then used QMK's [US-International keymap](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_us_international.h) in order to access our beloved <kbd>Ñ</kbd> (like in España),  accented vowels (<kbd>á</kbd> <kbd>é</kbd> <kbd>í</kbd> <kbd>ó</kbd> <kbd>ú</kbd> <kbd>ü</kbd>), and symbols <kbd>¡</kbd> <kbd>¿</kbd>. Worth noting that this keymap would also help typing in  other non-English languages, such as French, German, etc. If you happen to find a decent keycaps set in your language, you will be better off using the relevant keymap from [here](https://github.com/qmk/qmk_firmware/tree/master/quantum/keymap_extras).

- The above choice **requires your operating system to have the keyboard layout set to** `US international (with dead keys)` in Linux or `US international` in Windows **to properly function** as to recognize the keycodes sent by this custom firmware. Otherwise, you will be lost trying to find where the appropriate symbols are actually located. 

- Spanish <kbd>Ñ</kbd> is accessible with a long press on regular <kbd>N</kbd> or using <kbd>AltGr</kbd>+<kbd>N</kbd>. Inverted exclamation <kbd>¡</kbd> and interrogation <kbd>¿</kbd> signs are accessible with a long press on regular <kbd>1</kbd> and <kbd>/</kbd> respectively, or using <kbd>AltGr</kbd> with them. Regular exclamation <kbd>!</kbd> and interrogation <kbd>?</kbd> signs are accessible in the same keys using <kbd>Shift</kbd>. 

- I've moved some symbols (e.g. <kbd>|</kbd>, <kbd>/</kbd>, <kbd>?</kbd>, <kbd>\\</kbd>) from their standard location for personal convenience, which required finding a "flattish" keycap profile across all rows. [XDA profile](https://www.reddit.com/r/MechanicalKeyboards/comments/j484j5/keycap_profiles_i_compiled_a_direct_comparison/) was the choice I made.

- Thumb keys will act as <kbd>Enter</kbd> and <kbd>Space</kbd> when tapped, and <kbd>Shift</kbd> when held down.

- Moved <kbd>BackSpace</kbd> and <kbd>Delete</kbd> to the middle keys, to be pressed by the index fingers. 

- These middle keys will also act as <kbd>Left Ctrl</kbd> and <kbd>Right Ctrl</kbd> when held down, because I intensively use <kbd>Ctrl</kbd> and <kbd>Shift</kbd> combined with the arrow/move keys to make text/range selections in documents, emails and spreadsheets, so it will allow me to easily reach those combinations with my index and thumb fingers while using the `MOVE` layer.

- Not being a developer, I somewhat _relegated_ the brackets (<kbd>\[ \]</kbd> <kbd>\{ \}</kbd>) to a less important position, though easily accessible and with auto-closing enabled via [`Tap Dance`](https://docs.qmk.fm/#/feature_tap_dance) or [`Send String`](https://docs.qmk.fm/#/feature_send_string) functions, as I only left one of the keys visible.

- [GraveEscape](https://docs.qmk.fm/#/feature_grave_esc) is also used to reduce number of keys.  [CapsWord](https://docs.qmk.fm/#/feature_caps_word) feature is used in the base QWERTY  layer and CapsLock can be enabled/disabled in the MOVE layer.

- <kbd>Alt</kbd> and <kbd>AltGr</kbd> are [OneShot keys](https://docs.qmk.fm/#/one_shot_keys) so one tap will keep it active until another key is pressed.

- <kbd>Win</kbd> key in the right half is coupled with context menu's <kbd>App</kbd> key through a `tap dance`.

- In `NUMPAD` layer, a double parenthesis <kbd>(</kbd> <kbd>)</kbd> is automatically created using [`Send String`](https://docs.qmk.fm/#/feature_send_string) with the cursor moving inside for easier/faster usage.

- It is possible also to enable some `tap dance` codes to simulate <kbd>Ctrl + key</kbd> for <kbd>Copy</kbd>, <kbd>Cut</kbd>, <kbd>Paste</kbd>, etc. etc., and adding the appropriate `TD(TD_KC)` codes in `keymap.c` files, so those codes will be added to the relevant letter as a long-press action, i.e. holding <kbd>C</kbd> down for more than 200 ms (user-defined as `TAPPING_TERM 200` in `config.h`), will trigger <kbd>Ctrl + C</kbd>. These codes can be enabled/disabled with their relevant commands commented out in `tap_dance.c` file.

Further info on keycodes is available in the docs [here](https://docs.qmk.fm/#/keycodes?id=basic-keycodes).


## Visual representation of each layer

### Base QWERTY layer

```
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |  1   |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  /   |
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

### MOVE layer

Activated by holding `MO(_MOVE)` modifier key down. Simply release to return to `QWERTY` layer.

```
/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GESC |      |      |Wh_Up |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      | Btn1 |Ms_Up | Btn2 |      |                    |      | Home |  Up  | PgUp |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS | Wh_L | Ms_L | Ms_D | Ms_R | Wh_R |-------.    ,-------|      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|Del/Ctl|    |BkS/Ctl|------+------+------+------+------+------|
 * |      |      |      | Wh_D |      |      |-------|    |-------|      | End  | Ins  | PgDn |      |{ & } |
 * `-----------------------------------------/Shift  /     \ Shift\-----------------------------------------'
 *                   | LGUI | OSMod| ADJ  | /   +   /       \   +  \  |      | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
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
 *                   | LGUI | OSMod|      | /   +   /       \   +  \  | ADJ  | OSMod| LGUI |
 *                   |      | LAlt |      |/ Enter /         \ Space\ |      | AltGR| (APP)|
 *                   `----------------------------'           '------''--------------------'
 */

```

### ADJUST layer

Activated by simultaneously holding `_MOVE` and `_NUMPAD` modifier keys down.

Print Screen <kbd>PrtScr</kbd> is accessible in letter P on this layer.

No need for RGB/Backlight adjustments in a Lily58 Classic version, so just added Volume controls <kbd>Mute</kbd>  <kbd>Vol Up</kbd>  <kbd>Vol Down</kbd>.

A keyboard <kbd>Reset</kbd> is also added at a difficult to reach position, to avoid accidental activation, though the PCB has a physical reset button.

```
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Reset |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |PrtScr|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Mute | Vol- | Vol+ |      |-------,    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Ctrl |    |  Ctrl |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Shift  /       \Shift \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

```

## To-Do's

- Secondary OLED display isn't showing the info as expected. Need to investigate further.

## Issues and support

These files were created for my personal use, and shared here in case they may help someone else. There is NO warranty of it working properly and may do harm to your keyboard as it is not fully tested. You should be able to understand the code in order to use it.

Unfortunately, I am not a developer, so I will not be able to support any issues that you may find if you decide to use this firmware 'as-is'.  

Please reach out to the QMK's team for support as per this [guide](https://docs.qmk.fm/#/support).


## Acknowledgments

- First and foremost, my gratitude to the [QMK's team](https://github.com/qmk/qmk_firmware) for their great piece of software.
- Also my gratitude to kata0510 for designing and sharing the [Lily58 split keyboard](https://github.com/kata0510/Lily58).
- I've borrowed some code from the implementations made by [alvaro-prieto](https://github.com/alvaro-prieto/corne/tree/main/source) and [jufracaqui](https://github.com/jufracaqui/crkbd-qmk-ole-d); and Luna, the keyboard pet, has been borrowed from [HellSingCoder](https://github.com/HellSingCoder), so kudos to them as well.
- I also borrowed Karl's 3D-printable case with wristrest (https://www.thingiverse.com/thing:6014207)
