#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#define MAX 922337203685477580
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				t_list;
int		ft_atoi(const char *str);
int check_dup(int ac,char **av);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
int check_dig(int ac,char **av);
char	*ft_strjoin(char const *s1, char const *s2);
char	**splitargs(int ac, char **av);
#endif
