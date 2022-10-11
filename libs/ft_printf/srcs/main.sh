#! /bin/sh
clear
echo "------------------------------------------MAIN------------------------------------------"

gcc -Wall -Wextra -Werror *.c ../libft/*.c

./a.out

rm a.out