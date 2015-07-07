#include "auto.h"

int		get_include(int fd)
{
  struct dirent	*entry;
  DIR		*dir;
  int		c;
  
  if ((dir = opendir("./include")) == NULL)
    {
      puts("Erreur lors de l'ouverture du dossier 'include'");
      return (-1);
    }
  while ((entry = readdir(dir)) != NULL)
    {
      if (strcmp(&entry->d_name[strlen(entry->d_name) - 2], ".h") == 0)
	{
	  write(fd, "-L", 2);
	  c = -1;
	  while ((strncmp(&entry->d_name[++c], ".h", 2)) != 0 && entry->d_name[c])
	    write(fd, &entry->d_name[c], 1);
	  write(fd, " ", 1);
	}
    }
  closedir(dir);
  return (0);
}
