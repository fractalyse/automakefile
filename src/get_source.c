#include "auto.h"

/* int		get_source(int fd) */
/* { */
/*   struct dirent	*entry; */
/*   DIR		*dir; */
/*   char		*path; */
  
/*   if ((dir = opendir("./src")) == NULL) */
/*     { */
/*       puts("Erreur lors de l'ouverture du dossier 'src'"); */
/*       return (-1); */
/*     } */
/*   while ((entry = readdir(dir)) != NULL) */
/*     { */


      /* if ((strncmp(&entry->d_name[0], ".", 1)) != 0) */
      /* 	if ((strncmp(&entry->d_name[strlen(entry->d_name) - 2], */
      /* 		     ".c", */
      /* 		     strlen(&entry->d_name[strlen(entry->d_name) - 2]))) == 0) */
/* 	  { */
/* write(fd, "src/", 4); */
/* 	    write(fd, entry->d_name, strlen(entry->d_name)); */
/* 	    write(fd, " \\", 2); */
/* 	    write(fd, "\n", 1); */
/* 	  } */
/*     } */
/*   closedir(dir); */
/*   return (0); */
/* } */

int		get_source(int fd, char *dirname)
{
  DIR           *dir;
  struct dirent *ent;
  char          *path;
  static int	i = 0;

  path = malloc(sizeof(char) * 4096);
  if ((dir = opendir(dirname)) == NULL)
    return (-1);
  while ((ent = readdir(dir)) != NULL)
    {
      if (ent->d_type == DT_DIR)
	{
	  strcat(strcat(strcat(path, dirname), "/"), ent->d_name);
	  if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
	    get_source(fd, path);
	}
      else
	{
	  if ((strncmp(&ent->d_name[strlen(ent->d_name) - 2],
		       ".c",
		       strlen(&ent->d_name[strlen(ent->d_name) - 2]))) == 0)
	    {
	      if (i != 0)
		write(fd,"\t\t", 2);
	      write(fd, dirname, strlen(dirname));
	      write(fd, "/", 1);
	      write(fd, ent->d_name, strlen(ent->d_name));
	      write(fd, " \\", 2);
	      write(fd, "\n", 1);
	      i++;
	    }
	}
      memset(path, '\0', 4096);
    }
  closedir(dir);
  return (0);
}
