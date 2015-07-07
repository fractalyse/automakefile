#include "auto.h"

int		open_file(char *bin)
{
  int		fd;

  if ((fd = open("Makefile", O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
    return (-1);
  if (write_makefile_to_file(bin, fd) == -1)
    {
      puts("Erreur lors de l'écriture dans le fichier.");
      return (-1);
    }
  close(fd);
  return (0);
}
