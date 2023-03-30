/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** tests_menu
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Menu.hpp"

Test(MenuTest, coreStateNotModifiedWhenNotTyping)
{
  Menu menu;
  Core core("./lib/arcade_sdl2.so");
  eventKey evt = eventKey::DELETE;
  menu.handleUserInput(evt, core);
  cr_expect_eq(core.getCoreState(), GState::MENU);
}

Test(MenuTest, deleteCharIsCalledOnDeleteKey)
{
  Menu menu;
  Core core("./lib/arcade_sdl2.so");
  eventKey evt = eventKey::DELETE;
  menu.handleUserInput(evt, core);
  cr_expect_eq(menu.getUserName(), ""); // text should be empty
}

Test(MenuTest, coreStateIsSetToQuitOnQuitKey)
{
  Menu menu;
  Core core("./lib/arcade_sdl2.so");
  eventKey evt = eventKey::QUIT;
  menu.handleUserInput(evt, core);
  cr_expect_eq(core.getCoreState(), GState::QUIT); // core state should be set to QUIT
}

Test(MenuTest, characterIsAddedToUserNameOnValidKey)
{
  Menu menu;
  Core core("./lib/arcade_sdl2.so");
  eventKey evt = eventKey::A;
  menu.handleUserInput(evt, core);
  cr_expect_eq(menu.getUserName(), "a"); // text should be empty
}