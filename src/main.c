#include "auto.h"

int		main(int ac, char **av)
{
  if (ac == 1 || ac > 2)
    {
      puts("Entrez le nom du binaire en parametre.");
      return (-1);
    }
  else if (ac == 2)
    if (open_file(av[1]) == -1)
      {
	puts("Erreur lors de la création du fichier.");
	return (-1);
      }
  return (0);
}
