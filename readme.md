# My Custom QMK Keyboard Layouts

My custom layouts and guide for the following boards:

<<<<<<< HEAD
- Preonic
- Levinson
=======
This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b

I map the same layout across all the boards. Implemented for 4x12 keyboards.

## 1. Installing QMK

<<<<<<< HEAD
Install some programs for Windows 10.
=======
The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b

goto: <a href="https://docs.qmk.fm/#/newbs_getting_started">https://docs.qmk.fm/#/newbs_getting_started</a>

- Install git on your pc (optional)
- Download and install msys2 from (msys2)[https://docs.qmk.fm/#/newbs_getting_started]
- Create a folder on your pc. Clone or copy the qmk repo: (https://github.com/qmk/qmk_firmware)[https://github.com/qmk/qmk_firmware]
- Install the msys stuff according to the guide (run this from the qmk directory):

```
./util/qmk_install.sh
```

- Also run this from the qmk directory if the next step fails:

<<<<<<< HEAD
```
util/msys2_install.sh
```

## 2. Make a hex file

- To create a hex for the (default) Preonic keyboard:

```
make preonic:default
```

This should generate a hex file that you can flash to your preonic keyboard. If you want to flash your keyboard with the default layout, Skip ahead to step 3.

If you want to create your own layout follow the next step.

## Customize your layout (the fun part)

Create your layout (example with the Preonic):

- Goto keyboards/preonic/keymaps
- Duplicate the **default** folder and name it whatever: e.g: 'myboardy'
- Edit your new folders keymap.c file to your liking.
- Run this to create your layouts hex file:

```
make preonic:myboardy
```

- This will create a hex file in the **root** of the Qmk project folder.

## 3. To Flash:

(**note: the flashing procedure has changed for some boards like the Preonic**)

the new example:

```
make preonic/rev4:default:dfu
make preonic:default:dfu
```

or

```
make preonic/rev4:myboardy:dfu
make preonic:myboardy:dfu
```

## My example with the Preonic

- connect keyboard to pc via usb

```
make preonic:default:dfu
```

- Press the reset button on the keyboard when prompted.
- The board should now be flashed with the layout.
- Test it out to make sure it's all working.

- So for the Preonic, you only need to run two commands: 1: creating a hex, 2: flashing the board.
- Run the commands from the root of the qmk project folder.
- If you change your layout, save it and create the hex again, then flash it.

If you can flash the default hex but not your custom hex, make sure you don't have any errors on your file. 

## levinson 

### create hex file - levinson

- Create the hex file like the above **Preonic** (same method.)

### flashing - levinson

To flash, add avrdude at the end:

```
make levinson/rev2:default:avrdude
```

or 

```
make levinson/rev2:myboardy:avrdude
```

## Example Flashing the levinson

- connect one board to pc via usb

```
make levinson/rev2:myboardy:avrdude
```

- Press the reset button on the keyboard when prompted.
- Your board should now have the flashed layout.
- Repeat the process with the other board.

**Note: for the levinson you may want be edit the config.h file too.**


### Levinson - Flash EE_HANDS

You can set up the levinson to use EE_HANDS, which means you can plug the usb cable on either board.

- After flashing the EE_HANDS setup, you will need to flash your layout again.
- You don't need to flash EE_HANDS everytime when you change layouts, only once.
- The required files are available in the **let's split** keyboard folder.
- Check out the posts below (make sure you have two eep files and double-check the port no. of your keyboard.)

https://github.com/qmk/qmk_firmware/blob/master/keyboards/lets_split/readme.md#setting-ee_hands-to-use-either-hands-as-master

https://leico.github.io/TechnicalNote/QMK/write-vitamins-avrdude


## New section for the Gherkin

### To create hex

```
make 40percentclub/gherkin:default
```

### To Flash

```
make 40percentclub/gherkin:default:avrdude
```

Note: Short the ground (GND) and reset (RST) pins when prompted.
=======
QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b
