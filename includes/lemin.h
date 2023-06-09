/*
** EPITECH PROJECT, 2023
** lemin.h
** File description:
** lib function for the project lemin
*/

#ifndef LEMIN_H_
    #define LEMIN_H_
    #define UNUSED __attribute__((unused))
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include "tools.h"

    typedef enum {
        ANTS = 1,
        START = 2,
        END = 3,
        ROOM = 4,
        TUNNELS = 5,
        NO_ROOM = 6
    } error;

    typedef struct algo_s {
        int *visited;
        int *distance;
        int *queue;
        int back;
        int front;
    } algo_t;

    typedef struct file_info_s {
        int ants;
        int *start;
        int *end;
        int **room;
        int nb_room;
        int **tunnels;
        int nb_tunnels;
        int nb_start;
        int nb_end;
        int loca;
        int i;
        int err_coor;
        int err_name;
        int return_value;
    } file_info_t;

    typedef struct solve_tab_s {
        int **tab;
        int length;
        int *visited;
        int here;
    } solve_tab_t;



    /* ALGO/TAB */
//create_tab.c
    int **fill_tunnels(int **array, file_info_t *info);
    int **fill_tab(int **array, file_info_t *info);
    int **init_tab(int **array, file_info_t *info);
    int **alloc_tab(file_info_t *info);
    int process_algo_lemin(file_info_t *info);

//change_tab_value.c
    int search_final_way(solve_tab_t *tab, int j, file_info_t *info);
    int start_visited(solve_tab_t *tab, file_info_t *info);
    int end_visited(solve_tab_t *tab, file_info_t *info);
    int start_visited_second(solve_tab_t *tab, file_info_t *info);

//start_algo.c
    void search_end(solve_tab_t *tab, int j, file_info_t *info);
    int search_start(solve_tab_t *tab, int j, file_info_t *info);
    void mark_line_second(solve_tab_t *tab, int i, file_info_t *info);
    void mark_line(solve_tab_t *tab, int i, file_info_t *info);

//display_path.c
    void display_path(file_info_t *info, int *way);

//test_bfs.c
    int bfs_main(file_info_t *info, solve_tab_t *tab);

//fill_visited.c
    void fill_visited(solve_tab_t *tab, file_info_t *info);
    int search_nb_three(solve_tab_t *tab, file_info_t *info);

    /* DISPLAY_INFORMATION */
//display_parsing.c
    int display_tunnels(file_info_t *info);
    int display_rooms(file_info_t *info);
    int display_parsing(file_info_t *info);

//display_info.c
    int display_room_find(char *str);
    void display_end(char *str);
    void display_start(char *str);
    int display_rooms_error(char **tab, int start, int end);
    void display_info(file_info_t *info, int error, char **tab);


    /* ERROR */
//check_room.c
    int check_room_coordinate(file_info_t *info, int i);
    int check_room_name(file_info_t *info, int i);
    void check_room_error(file_info_t *info);

//error.c
    int manage_error(void);
    int manage_usage(void);


    /* PARSING */
//body_lemin.c
    int start_lemin(char *buffer);

//check_no_pipe_room.c
    int check_no_pipe_room(file_info_t *info, char **tab);

//count.c
    int count_nbr_tunnels(file_info_t *info, char **tab);
    int count_nbr_room(file_info_t *info, char **tab);

//error_handling_tab.c
    int check_tunnel(char **tab);
    int check_room(char **tab);
    int check_room_tunnel(char *str);
    int check_start_end(char **tab, unsigned int *y, int *a, int *b);
    int error_handling_tab(char **tab);

//fill_element.c
    void fill_room_end(file_info_t *info);
    void fill_room_start(file_info_t *info);

//get_ants.c
    void get_ants(file_info_t *info, char **tab);

//init_struct.c
    int *init_pos(file_info_t *info);
    int init_tunnels(file_info_t *info);
    int init_room(file_info_t *info);

//open_read_file.c
    char *recup_of_file_content(void);

//display_no_room.c
    void display_no_room(char **tab, file_info_t *info);

//parsing.c
    int get_tunnel(file_info_t *info, char **tab);
    int get_room(file_info_t *info, char *str);
    int get_room_tunnel(file_info_t *info, char *str);
    int get_start_end(file_info_t *info, char **tab, unsigned int *y);
    int create_parsing(file_info_t *info, char **tab);

//check_file.c
    int check_file(char **tab, int a, int b);

//recup_nbr.c
    int recup_nbr(int y, char *tab);


    /* OTHER */
//getnbr.c
    int getnbr(char c);

//my_strcat.c
    char *my_strcat(char *dest, char const *src);

//my_put_nbr.c
    int my_put_nbr(int nb);

#endif /* LEM_IN_H_ */
