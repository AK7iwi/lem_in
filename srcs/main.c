# include "lem_in.h"

int main(int argc, char **argv)
{
    t_data  data;

    printf("argc: %i\n", argc);

    init(&data, argv);
    //data.map = get_next_line(stdin);   

    return (EXIT_SUCCESS);
}