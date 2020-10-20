/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:53:34 by gbroccol          #+#    #+#             */
/*   Updated: 2020/10/18 19:55:13 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main()
{
	char	dest[50];
	int		ans_int;
	char	*ans_str;
	int		fd;
	char	buff[100];
	// char	buff_null;
	char	check[100];
	ssize_t	ret;

	printf("\n----------ft_strlen--------\n");
	printf("01)standard: %d\n", (int)strlen(""));
	ans_int = STRLEN("");
	printf("01)      my: %d\n", ans_int);
	printf("02)standard: %d\n", (int)strlen("kekw"));
	ans_int = STRLEN("kekw");
	printf("02)      my: %d\n", ans_int);

	printf("\n----------ft_strcpy--------\n");
	printf("01)standard: %s\n", strcpy(dest, ""));
	ans_str = STRCPY(dest, "");
	printf("01)      my: %s\n", ans_str);
	printf("02)standard: %s\n", strcpy(dest, "kekw"));
	ans_str = STRCPY(dest, "kekw");
	printf("02)      my: %s\n", ans_str);
	printf("03)standard: %s\n", strcpy(dest, "6661366613666"));
	ans_str = STRCPY(dest, "6661366613666");
	printf("03)      my: %s\n", ans_str);
	printf("04)standard: 6661366613666\n");
	ans_str = STRCPY(dest, NULL);
	printf("04)      my: %s\n", ans_str);

	printf("\n----------ft_strcmp--------\n");
	printf("01)standard: %d\n", strcmp("", ""));
	ans_int = STRCMP("", "");
	printf("01)      my: %d\n", ans_int);
	printf("02)standard: %d\n", strcmp("kekw", "kekw"));
	ans_int = STRCMP("kekw", "kekw");
	printf("02)      my: %d\n", ans_int);
	printf("03)standard: %d\n", strcmp("abcb", "abcdc"));
	ans_int = STRCMP("abcb", "abcdc");
	printf("03)      my: %d\n", ans_int);
	printf("04)standard: %d\n", strcmp("c", "b"));
	ans_int = STRCMP("c", "b");
	printf("04)      my: %d\n", ans_int);
	printf("05)standard: 0\n");
	ans_int = STRCMP(NULL, NULL);
	printf("05)      my: %d\n", ans_int);
	printf("06)standard: 0\n");
	ans_int = STRCMP("kekw", NULL);
	printf("06)      my: %d\n", ans_int);
	printf("07)standard: 0\n");
	ans_int = STRCMP(NULL, "kekw");
	printf("07)      my: %d\n", ans_int);

	printf("\n----------ft_write---------\n");
	printf("\n01)standard: %zd\n", write(1, "", 0));
	ans_int = WRITE(1, "", 0);
	printf("\n01)      my: %d\n", ans_int);

	printf("\n02)standard: %zd\n", write(1, "2ekw", 4));
	ans_int = WRITE(1, "2ekw", 4);
	printf("\n02)      my: %d\n", ans_int);
	printf("\n03)standard: %zd\n", write(1, "3ekw", 3));
	ans_int = WRITE(1, "3ekw", 3);
	printf("\n03)      my: %d\n", ans_int);
	printf("\n04)standard: %zd\n", write(1, "4ekw", 6));
	ans_int = WRITE(1, "4ekw", 6);
	printf("\n04)      my: %d\n", ans_int);
	printf("\n05)standard: %zd %s\n", write(1, NULL, 6), strerror(errno));
	ans_int = WRITE(1, NULL, 6);
	printf("\n05)      my: %d %s\n", ans_int, strerror(errno));
	
	printf("\n----------ft_read----------\n");

	fd = open("main.c", O_RDONLY);
	ret = read(fd, buff, 8);
	printf("01)standard: %zd - %s\n", ret, strncpy(check, buff, 8));
	close(fd);

	fd = open("main.c", O_RDONLY);
	ret = READ(fd, buff, 8);
	printf("01)      my: %zd - %s\n", ret, strncpy(check, buff, 8));
	close(fd);

	fd = open("libasm.h", O_RDONLY);
	ret = read(fd, buff, 50);
	printf("02)standard: %zd - %s\n", ret, strncpy(check, buff, 50));
	close(fd);

	fd = open("libasm.h", O_RDONLY);
	ret = READ(fd, buff, 50);
	printf("02)      my: %zd - %s\n", ret, strncpy(check, buff, 50));
	close(fd);

	fd = open("libasm.h", O_RDONLY);
	ret = read(fd, NULL, 50);
	printf("03)standard: %zd %s\n", ret, strerror(errno));
	close(fd);

	fd = open("libasm.h", O_RDONLY);
	ret = READ(fd, NULL, 50);
	printf("03)      my: %zd %s\n", ret, strerror(errno));
	close(fd);
	
	// fd = open("main.c", O_RDONLY);
	// ret = read(fd, NULL, 8);
	// printf("04..)standard: %zd - %s\n", ret, strncpy(check, NULL, 8));
	// close(fd);

	// fd = open("main.c", O_RDONLY);
	// ret = READ(fd, NULL, 8);
	// printf("04..)      my: %zd - %s\n", ret, strncpy(check, NULL, 8));
	// close(fd);



	printf("\n----------ft_strdup---------\n");
	printf("01)standart: %s\n", strdup(""));
	ans_str = STRDUP("");
	printf("01)      my: %s\n", ans_str);

	printf("02)standart: %s\n", strdup("kekw"));
	ans_str = STRDUP("kekw");
	printf("02)      my: %s\n", ans_str);

	printf("03)standart: %s\n", strdup("6661366613666"));
	ans_str = STRDUP("6661366613666");
	printf("03)      my: %s\n", ans_str);

	printf("04)standart: (null)\n");
	ans_str = STRDUP(NULL);
	printf("04)      my: %s\n", ans_str);
	return(0);
}
