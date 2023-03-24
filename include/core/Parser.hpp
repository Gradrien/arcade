/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Parser
*/

/****************************************************************
 * @file Parser.hpp
 * @brief Parser class
 * @details This class is used to parse the arguments and the env
 * @version 0.1
 * @date 2021-03-15
 * ***************************************************************/
#ifndef PARSER_HPP_
#define PARSER_HPP_

/****************************************************************
 * @brief Parse the arguments
 * @param ac
 * @param av
 * @details This function is used to parse the arguments
 * @return int
 * ************************************************/
int checkArgs(int ac, char **av);
/****************************************************************
 * @brief Parse the env
 * @param env
 * @details This function is used to parse the env
 * @return int
 * ************************************************/
int checkEnv(char **env);

/****************************************************************
 * @brief Display the usage
 * @details This function is used to display the usage
 * ************************************************/
void displayUsage();

/****************************************************************
 * @brief Check the library
 * @param library
 * @details This function is used to check the library
 * @return int
 * ************************************************/
int checkLibrary(const char *library);

#endif /* !PARSER_HPP_ */
