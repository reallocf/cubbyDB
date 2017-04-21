/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csummers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:52:09 by csummers          #+#    #+#             */
/*   Updated: 2016/11/05 21:52:10 by csummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define BUFF_SIZE 1
# define MAX_FD 2048
# define LLONG_MAX 9223372036854775807
# define LLONG_MIN -9223372036854775807
# define F(x) (x=='-'||x=='+'||x==' '||x=='0'||x=='#')
# define L(x) (x=='h'||x=='l'||x=='j'||x=='z')
# define SN(x) (x=='d'||x=='i')
# define UN(x) (x=='o'||x=='u'||x=='x'||x=='X'||x=='b'||x=='p')
# define CAP(x) (x=='D'||x=='O'||x=='U'||x=='S'||x=='C')
# define NUM(x) (x=='d'||x=='i'||x=='o'||x=='u'||x=='x'||x=='X'||x=='b'||x=='p')
# define STR(x) (x=='s'||x=='c')
# define HASH(x) (x=='o'||x=='x'||x=='X'||x=='p')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buff
{
	char			*s;
	char			*p;
	int				is_s;
	int				is_f;
	long long		old_r_s;
}					t_buff;

typedef struct		s_flag
{
	char			c;
	char			len_mod;
	char			*output;
	int				f_wide;
	wchar_t			*woutput;
	size_t			output_len;
	size_t			woutput_len;
	size_t			wide_dims_adj;
	int				f_ascii;
	int				f_width;
	size_t			width;
	int				f_prec;
	size_t			prec;
	int				f_minus;
	int				f_plus;
	int				f_space;
	int				f_zero;
	int				f_hash;
}					t_flag;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putstrarr(char **arr);
char				**ft_strarrnew(size_t size);
void				ft_strarrdel(char ***arr);
size_t				ft_strarrlen(char **arr);
char				*ft_realloc_c(char **s, char c);
char				**ft_realloc_s(char ***arr, char *s);
uintmax_t			ft_pow(uintmax_t base, uintmax_t exp);
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
void				pf_get_flag_info(const char **format, t_flag *flag);
void				pf_get_conv_spec(const char **format, t_flag *flag);
void				pf_conv_s_num(t_flag *flag, intmax_t n);
void				pf_conv_u_num(t_flag *flag, uintmax_t n);
void				pf_conv_char(t_flag *flag, int n);
void				pf_conv_wchar(t_flag *flag, wchar_t n);
void				pf_conv_str(t_flag *flag, char *s);
void				pf_conv_wstr(t_flag *flag, wchar_t *s);
char				*pf_imtoa_base(intmax_t im, uintmax_t um,
									unsigned int base, int c);
size_t				pf_wstrlen(wchar_t *s);
size_t				pf_wlen(wchar_t *s);
size_t				pf_wide_dims_adj(t_flag *flag);
int					pf_is_ascii(wchar_t *s);
void				pf_apply_width(t_flag *flag);
void				pf_print_width(t_flag *flag);
void				pf_print_many_chars(char c, size_t n);
void				pf_printer(char *output, wchar_t *woutput, size_t len);

int					g_fd;
int					g_ret;
va_list				g_ap;

#endif
