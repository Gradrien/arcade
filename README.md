
![Logo](https://studyadv.s3.amazonaws.com/production/schools/covers/000/005/919/original/Enseigne_Epitech_2.png)

- [General Documentation](README.md)
- [Core implementation](./doc/Core.md)
- [Graphic library implementation](./doc/IGraphic.md)
- [Game library implementation](./doc/IGame.md)

# Arcade
Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of player scores.
Create your own clone of famous games. Your project should comply with a structure that separates the heart of your game launcher and its graphic dependencies.
You should dynamically load them with the help of the dl library.

## Before continuing...

This project is an EPITECH Project. If you are an EPITECH student, move out the way!

Nothing to see here... I don't want to be involved to your -42.

![Alt Text](https://media.tenor.com/ketvWma51gYAAAAd/john-cena-im-watching-you.gif)

If you're not, no worries! You're welcome here!

### Prerequisites

To use this project, you'll need a compiler that supports C++ 20 and Criterion for the unit tests.

* [Criterion Installation](https://criterion.readthedocs.io/en/master/setup.html)

3 different graphical libraries are also implemented:

- [Ncurses](https://ftp.gnu.org/pub/gnu/ncurses/)
- [SDL2](https://wiki.libsdl.org/SDL2/Installation)
- [SFML](https://www.sfml-dev.org/download.php)

## Usage

### Building program

Arcade is a B-OOP-400 EPITECH module project.
It is build with Makefile.

You can use this program as it follows:

```textmate
$> make
// Build the entire programm

$> make core
// Build the core programm

$> make graphics
// Build the different libraries

$> make games
// Build the different games

```

You can also launch unit tests by using the command below at root of the repository:

```textmate
$> make tests_run
// Compile and launch test binary
$> make coverage
// Show the code coverage
```

### Launch program

Launch Arcade by giving in argument the graphical library you want to use.\
Don't worry you can change it in the menu.

The library must be in a ```/lib``` folder at the **root** of the project.

```
$> ./arcade ./lib/[LIBRARY_NAME].so
```

### Key Bindings

Arcade provides multiple keybindings:

#### **General**

| Key      | Action        |
| --------- | --------------|
| M | Go to the menu |
| G | Switch to next game |
| N | Switch to next graphical library |
| Q | Quit Arcade |

#### **Username selection**

| Key      | Action        |
| --------- | --------------|
| ENTER | Confirm username |


#### **Menu**

| Key      | Action        |
| --------- | --------------|
| UP Arrow | Go up |
| DOWN Arrow | Go down |
| RIGHT Arrow | Go to the game selection |
| LEFT Arrow | Go to the graphical library selection |
| A | Apply selection and launch game |
| T | Change username |


#### **In game**

| Key      | Action        |
| --------- | --------------|
| UP Arrow | Go up |
| DOWN Arrow | Go down |
| RIGHT Arrow | Go to the right |
| LEFT Arrow | Go to the left |
| ESCAPE | Pause the game |
| R | Restart the game |


## Commit norm

The commits are normed thanks to a program made by [Adrien Ricou](https://github.com/Gradrien/Git-Shortcuts).

| Commit type       | Description        |
| --------- | --------------|
| [ADD] :rocket: | Deploying new code |
| [MODIFY] :sparkles: | Modifying code |
| [COD.STY] :zap: | Improving performance |
| [FIX] :bug: | Fixing a bug |
| [HANDLE] :sparkles: | Handling new features |
| [INCLUDE] :wrench: | Modifying user defined headers|
| [LIB] :wrench: | Modifying libraries files |
| [REMOVE] :fire: | Removing code or files |
| [UNIT.TESTS] :white_check_mark: | Added tests |
| [MERGE] :twisted_rightwards_arrows: | Merging branches |

**Emoji are available thanks to the Gitmoji tool

## Authors

We must shared our graphical and game library interfaces with an other project group. Please not that only the interfaces were shared and not the rest of the program. Neither the games nor the graphical libraries implementation were shared.

Here are the members:

* **Hippolyte David** - [HippolyteDavid](https://github.com/HippolyteDavid)
* **Elouan Savy-Camaret** - [ElouanSavy](https://github.com/ElouanSavy)
* **Adrien Ricou** - [Gradrien](https://github.com/Gradrien)

And the group we shared our interfaces with:

* **Nolann Bougrainville** - [NolannB14](https://github.com/NolannB14)
* **Kevin Demy** - [Sakutaroo](https://github.com/Sakutaroo)
* **Nils Martin** - [Nils](https://github.com/nilsmartin33)
