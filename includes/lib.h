#pragma once

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define DELAY 550000

typedef struct s_list {
	void			*data;
	struct s_list	*next;
} t_list;