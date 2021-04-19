(cd ../libft/ && make)
gcc -Wall -Werror -Wextra minishell.c split_command.c ../libft/libft.a
(cd ../libft/ && make fclean)
clear
echo "Prompt loop : CTRL+D OR CTRL+C to quit\n"
./a.out