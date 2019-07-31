#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "libfts.h"

#define DATA_SIZE	42
#define NB_ROUNDS	32

static void		print_data(uint8_t *data, size_t len)
{
	size_t		i;

	i = 0;
	while (i != len)
	{
		if (i != 0)
		{
			if (i % 16 == 0)
				printf("\n");
			else
				printf(" ");
		}
		printf("%02x", data[i] & 0xFF);
		++i;
	}
	printf("\n");
}

int				main(void)
{
	uint8_t		data[DATA_SIZE];
	uint8_t		copy_original[DATA_SIZE];
	uint8_t		key[16];

	ft_getrandom(data, DATA_SIZE);
	ft_getrandom(key, 16);
	ft_memcpy(copy_original, data, DATA_SIZE);
	printf("Key:\n");
	print_data(key, 16);
	printf("\n");

	printf("Init:\n");
	print_data(data, DATA_SIZE);
	printf("\n");

	ft_rc5_encrypt(data, DATA_SIZE, key, NB_ROUNDS);
	printf("After encryption:\n");
	print_data(data, DATA_SIZE);
	printf("\n");

	ft_rc5_decrypt(data, DATA_SIZE, key, NB_ROUNDS);
	printf("After decryption:\n");
	print_data(data, DATA_SIZE);
	printf("\n");

	int		ret = ft_memcmp(data, copy_original, DATA_SIZE);
	if (ret == 0)
		printf("RC5 OK all good\n");
	else
		printf("================= SOMETHING WENT WRONG =================\n");
	return (ret);
}
