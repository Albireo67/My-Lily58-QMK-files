# Bootloader selection for Arduino Pro-Micro
BOOTLOADER = caterina

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no		# Console for debug
SPACE_CADET_ENABLE = no		# Space Cadet feature
GRAVE_ESC_ENABLE = yes 		# Grave+Esc combo feature
MAGIC_ENABLE = no		# Magic feature

LTO_ENABLE = yes		# Longer compile, smaller firmware

CAPS_WORD_ENABLE = yes		# Enable Caps Word feature
TAP_DANCE_ENABLE = yes		# Enable Tap Dance combos
SEND_STRING_ENABLE = yes	# Enable Send String commands
WPM_ENABLE = yes            # Enable words-per-minute counter

COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE= yes                # OLED display
OLED_DRIVER = ssd1306

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        ./lib/host_led_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/timelogger.c \
