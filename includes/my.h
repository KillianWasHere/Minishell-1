/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** header file for the project
*/

#ifndef MY_H_
    #define MY_H_
    #include "env_struct.h"

void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char *str);
char *my_strdup(char *src);
char **get_words(char *buffer);
void my_put_nbr(int nb);
int check_built_in(char **my_args, char **env, env_struct_t *data);
void free_my_array(char **my_args);
int display_exit_error(int status);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
int display_exit_error(int status);
void display_env(char **my_env);
void get_env_to_add(char **my_args, env_struct_t *data);
void get_env_to_rm(char **my_args, env_struct_t *data);
void get_used_built_in(char **my_args, env_struct_t *data);
char *get_command_location(char **my_args, char **env);
int check_if_file_exist(char *my_args);
char **my_array_dup(char **array, int nb_lines_to_add);
int tty_shell(char **env, env_struct_t *data);
void write_error(char *command);
int check_env_name(char *env_name);
void check_space_tab(char **my_args);
void cd_built_in(env_struct_t *data, char **my_args);
void edit_env(char **my_args, int nb_line, char *line_to_edit,
    env_struct_t *data);
char *get_env_line_as_char(char *to_find, env_struct_t *data);
int get_env_line_as_int(char *to_find, env_struct_t *data);
char *my_revstr(char *str);

#endif /* MY_H_*/
