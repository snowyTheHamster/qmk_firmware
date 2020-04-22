# My QMK Layouts + Install Guides - Updated on 2020/Apr/22

My custom layouts and guide for the following boards:

- Preonic rev2
- Levinson
- gherkin
- Planck rev6

## Installing Qmk

+ clone the qmk repo
+ follow the qmk official doc.

### ubuntu installation

+ clone repo
+ create a venv in python
+ install qmk via pip
+ run the `qmk setup`
+ optional: run `util/qmk_install.sh`
+ update: run `make git-submodule`

## flashing

+ test with default layouts first using dfu, avrdude or dfu-util (details below)
+ planck rev6 is dfu-util
+ levinson + gherkin are avrdude
+ preonic rev2 is dfu

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
