# include "lem_in.h"

int main(int argc, char **argv)
{
    t_data  data;

    printf("argc: %i\n", argc);

    init(&data, argv);
    if (parse_map(&data, stdin))
        return (EXIT_FAILURE); //error_displayer

    return (EXIT_SUCCESS);
}
