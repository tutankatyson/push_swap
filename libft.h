/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:18:56 by jorsanch          #+#    #+#             */
/*   Updated: 2022/12/13 17:09:41 by jorsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*	ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list	*	ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*	ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*	ft_strchr(const char *s, int c);
char	*	ft_strrchr(const char *s, int c);
char	*	ft_strdup(const char *s1);
char	*	ft_substr(char const *s, unsigned int start, size_t len);
char	*	ft_strjoin(char const *s1, char const *s2);
char	*	ft_strtrim(char const *s1, char const *set);
char	**	ft_split(char const *s, char c);
char	*	ft_itoa(int n);
char	*	ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*	ft_strnstr(const char *haystack, const char *needle, size_t len);

void		ft_bzero(void *s, size_t n);
void	*	ft_memset(void *b, int c, size_t len);
void	*	ft_memcpy(void *dst, const void *src, size_t n);
void	*	ft_memmove(void *dst, const void *src, size_t len);
void	*	ft_memchr(const void *s, int c, size_t n);
void	*	ft_calloc(size_t count, size_t size);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

int			ft_putnbrbase(long int n, char *base);
char	*	ft_uitoa(unsigned int n);

#endif


/****** ** ** * * * C O M B I N A T O R I A   D E   4 * * * ** ** *******************

		<		>		s
1234	2341 	4123	2134		OK	     º1	  º2   º3	º4   º5   º6    º7    
1243								>>s>> 	2341 3412 4312 3124 1234
1324								<s>		3241 2341 1234
1342								>s		2134 1234
1423								s<		4123 1234
1432								s>>s> 	4132 1324 3241 2341 1234
------------------------------------------------------------------------------------
2134	1342	4213	X			s		1234
2143	1432	3214	1243		s>>s>>	1243 2341 4312 3412 4123 1234
2314								>>s<	4231 1423 4123 1234 	
2341	3412	X		3241		>		1234
2413								>s>		3241 2341 1234
2431								<s>>	4312 3412 2341 1234
------------------------------------------------------------------------------------
3124								>s>>	4312 3412 2341 1234
3142								s>s		1342 2134 1234
3214					2314		<s>>s>>	2143 1243 2431 4312 3412 4123 1234
3241								s<		2341 1234
3412								>> 		2341 1234
3421								>>s		1342 2134 1234
------------------------------------------------------------------------------------
4123	X		3412	1423		<		1234
4132								>>s>	1324 3241 2341 1234
4213								<s		2134 1234
4231								>s<		1423 4123 1234
4312								>> 		3124 1234
4321								>s>>s>	1432 4132 1324 3241 2341 1234
------------------------------------------------------------------------------------

--- Ultimo termino ordenado

1234
2134		s			1234
1324		<s>			3241 2341 1234

1324		psP			324  234  1234		
						1	 1
						
2314		>>s<		4231 1423 4123 1234 	
3124		>s>>		4312 3412 2341 1234


3214		<s>>s>>		2143 1243 2431 4312 3412 4123 1234
			s2ss2






***** ** * * * * C O M B I N A T O R I A   D E   A L G O R I T M O S * * * * ** *****

Psp		(swap^2)	->> Equivale a un swap de 2º x 3º
PPspp	(swap^3)	->> Equivale a un swap de 3º x 4º





******* ** ** * * * C O M B I N A T O R I A   D E   5 * * * ** ** *******************

12345
12354
12435
12453
12534
12543

13245
13254
13425
13452
13524
13542

14235
14253
14325
14352
14523
14532
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
15234
15243
15324
15342
15423
15432
---------------------------------------------------------------------------------------
31
31
32
32
34
34
35
35

41
41
42
42
43
43
45
45

51
51
52
52
53
53
54
54

*/