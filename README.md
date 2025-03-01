# Pipex

## Description
C'est un projet qui consiste à reproduire le comportement du pipe (`|`) en ligne de commande sous Unix. Il permet d'exécuter deux commandes en les chaînant via un tube (pipe).

## Compilation

```sh
make
```

Cela générera l'exécutable `pipex`.

## Utilisation

```sh
./pipex infile cmd1 cmd2 outfile
```

- `infile` : Fichier d'entrée.
- `cmd1` : Première commande à exécuter.
- `cmd2` : Deuxième commande à exécuter.
- `outfile` : Fichier de sortie.

Exemple d'exécution :

```sh
./pipex input.txt "cat" "grep hello" output.txt
```

Equivalent en shell :

```sh
< input.txt cat | grep hello > output.txt
```

## Gestion des erreurs
- Vérification des arguments
- Gestion des erreurs d'ouverture de fichiers
- Gestion des erreurs d'exécution de commandes
- Gestion des erreurs liées aux pipes et aux processus

## Ressources utiles
- `man 2 pipe`
- `man 2 fork`
- `man 2 dup2`
- `man 3 execve`
- `man 2 waitpid`

## Auteur
- [Herimamy12](https://github.com/Herimamy12)
