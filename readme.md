# My QMK Layouts + Install Guides - Updated on 2020/Apr/22

My custom layouts and guide for the following boards:

<<<<<<< HEAD
<<<<<<< HEAD
- Preonic
- Levinson
=======
This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b
=======
- Preonic rev2
- Levinson
- gherkin
- Planck rev6
>>>>>>> 92e320640a1b1447a474b0641ffd403645238b9e

## Installing Qmk

+ clone the qmk repo
+ follow the qmk official doc.

<<<<<<< HEAD
<<<<<<< HEAD
Install some programs for Windows 10.
=======
The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b
=======
### ubuntu installation
>>>>>>> 92e320640a1b1447a474b0641ffd403645238b9e

+ clone repo
+ create a venv in python
+ install qmk via pip
+ run the `qmk setup`
+ optional: run `util/qmk_install.sh`
+ update: run `make git-submodule`

## flashing

<<<<<<< HEAD
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
=======
+ test with default layouts first using dfu, avrdude or dfu-util (details below)
+ planck rev6 is dfu-util
+ levinson + gherkin are avrdude
+ preonic rev2 is dfu
>>>>>>> 92e320640a1b1447a474b0641ffd403645238b9e

## Customize your layout (the fun part)

Create your layout (example with the Preonic):

- Goto keyboards/preonic/keymaps
- Duplicate the **default** folder and name it whatever: e.g: 'myboardy'
- Edit your new folders keymap.c file to your liking.
- Run this to create your layouts hex file:

## Preonic Rev 2 (dfu)

### To create hex

```
make preonic/rev2:default
sudo make preonic/rev2:default
```

### To Flash

**IMPORTANT: Make sure to clice reset button before running below command**

```
make preonic/rev2:default:dfu
sudo make preonic/rev2:default:dfu
```

## levinson

### create hex file - levinson

- Create the hex file like the above **Preonic** (same method.)

### flashing - levinson

### To create hex

```
make levinson/rev2:default
```

### To Flash

```
make levinson/rev2:default:avrdude
```

+ flash both boards one by one.

**Note: for the levinson you may want be edit the config.h file too.**

### Levinson - Flash EE_HANDS

You can set up the levinson to use EE_HANDS, which means you can plug the usb cable on either board.

- After flashing the EE_HANDS setup, you will need to flash your layout again.
- You don't need to flash EE_HANDS everytime when you change layouts, only once.
- The required files are available in the **let's split** keyboard folder.
- Check out the posts below (make sure you have two eep files and double-check the port no. of your keyboard.)

https://github.com/qmk/qmk_firmware/blob/master/keyboards/lets_split/readme.md#setting-ee_hands-to-use-either-hands-as-master

https://leico.github.io/TechnicalNote/QMK/write-vitamins-avrdude


## Gherkin

### To create hex

```
make 40percentclub/gherkin:default
```

### To Flash

```
make 40percentclub/gherkin:default:avrdude
```

Note: Short the ground (GND) and reset (RST) pins when prompted.
<<<<<<< HEAD
=======
QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
>>>>>>> 738c6612ca0c5d0d95195af259abb1b6e3995b9b
=======

## Planck Rev 6 (dfu-util)

### To create hex

```
make planck/rev6:dvoraker
sudo make planck/rev6:dvoraker
```

### To Flash

**IMPORTANT: Make sure to clice reset button before running below command**

```
make planck/rev6:dvoraker:dfu-util
sudo make planck/rev6:dvoraker:dfu-util
```
>>>>>>> 92e320640a1b1447a474b0641ffd403645238b9e
