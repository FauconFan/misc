make -C ../libft/
cp ../libft/libft.a ./lib/
cp ../libft/libft.h ./includes/
make fclean -C ../libft/

make -C ../libperso/
cp ../libperso/libperso.a ./lib/
cp ../libperso/libperso.h ./includes/
make fclean -C ../libperso/