#ifndef LIBFT_H
#define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <math.h>

//t_list	*ft_lstnew(char *content);
//void	ft_lstdelone(t_list *lst, void (*del)(void *));
//int		ft_lst_size(t_list **lst_a);
//int		ft_lstclear(t_list **list);
//int		ft_lstadd_back(t_list **lst, char *str);

size_t	ft_strlen(const char *str);
size_t	ft_len_array(char **array);
size_t	ft_strchr_count(const char *str, char chr);
size_t	ft_strcpy(char *str_out, const char *str_in);
int		ft_clear_arrray(char **array);
int		ft_atoi(const char *str, int *i);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(char *s, char c);
char	*ft_strrchr(char *str, char c);
char	*ft_itoa_uns(unsigned int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	**ft_split(const char *str, char c);
char	*get_next_line(int fd);

#endif
