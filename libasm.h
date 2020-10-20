/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:21:46 by gbroccol          #+#    #+#             */
/*   Updated: 2020/10/18 20:21:49 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

size_t							ft_strlen(const char *str);
char							*ft_strcpy(char *dest,const char *src);
int								ft_strcmp(const char *s1, const char *s2);
ssize_t							ft_write(int fd, void *buf, size_t count);
ssize_t							ft_read(int fd, void *buf, size_t count);
char							*ft_strdup(const char *s);

# define STRLEN(s)				ft_strlen(s);
# define STRCPY(s1, s2)			ft_strcpy(s1, s2);
# define STRCMP(s1, s2)			ft_strcmp(s1, s2);
# define WRITE(fd, buff, count)	ft_write(fd, buff, count);
# define READ(fd, buff, count)	ft_read(fd, buff, count);
# define STRDUP(s)				ft_strdup(s);

#endif
