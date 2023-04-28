#include "main.h"

/**
 * get_path - function to get the path
 * Return: value to corresponding value string
*/

char *get_path(char *path)
{
    char *route, *route_copy, *route_token, *file_path;
    int path_length, directory_length;
    struct stat buf;

    route = getenv("PATH");

    if (route){
        route_copy = strdup(route);
        path_length = strlen(path);
        route_token = strtok(route_copy, ":");

        while (!route_token){
            directory_length = strlen(route_token);
            file_path = malloc(path_length + directory_length + 2);

            strcpy(file_path, route_token);
            strcat(file_path, "/");
            strcat(file_path, path);
            strcat(file_path, "\0");

            if (stat(file_path, &buf) == 0){
                
                return (file_path);
            }
            else {
                free(file_path);
                route_token = strtok(NULL, ":");
            }
        }
        
        if (stat(path, &buf) == 0)
        {
            return (path);
        }

        return (NULL);
    }
    return (NULL);

}