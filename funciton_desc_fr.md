Bibliothèque readline

readline
Description : Lit une ligne de texte depuis l'entrée standard avec un prompt.
Prototype : char *readline(const char *prompt);

rl_clear_history
Description : Efface l'historique des commandes.
Prototype : void rl_clear_history(void);

rl_on_new_line
Description : Prépare readline à afficher une nouvelle ligne.
Prototype : int rl_on_new_line(void);

rl_replace_line
Description : Remplace la ligne actuelle par une nouvelle.
Prototype : int rl_replace_line(const char *text, int clear_undo);

rl_redisplay
Description : Redisplay la ligne actuelle.
Prototype : void rl_redisplay(void);

add_history
Description : Ajoute une ligne à l'historique des commandes.
Prototype : void add_history(const char *line);



Fonctions de base d'E/S

printf
Description : Formate et imprime des données sur la sortie standard.
Prototype : int printf(const char *format, ...);

malloc
Description : Alloue de la mémoire dynamique.
Prototype : void *malloc(size_t size);

free
Description : Libère la mémoire allouée par malloc.
Prototype : void free(void *ptr);

write
Description : Écrit des données sur un descripteur de fichier.
Prototype : ssize_t write(int fd, const void *buf, size_t count);

access
Description : Vérifie l'accès à un fichier.
Prototype : int access(const char *pathname, int mode);

open
Description : Ouvre un fichier.
Prototype : int open(const char *pathname, int flags, ...);

read
Description : Lit des données depuis un descripteur de fichier.
Prototype : ssize_t read(int fd, void *buf, size_t count);

close
Description : Ferme un descripteur de fichier.
Prototype : int close(int fd);



Fonctions de gestion de processus

fork
Description : Crée un nouveau processus en dupliquant le processus appelant.
Prototype : pid_t fork(void);

wait
Description : Attends qu'un processus enfant se termine.
Prototype : pid_t wait(int *status);

waitpid
Description : Attends qu'un processus spécifique se termine.
Prototype : pid_t waitpid(pid_t pid, int *status, int options);

wait3
Description : Attends qu'un processus se termine avec des informations d'utilisation.
Prototype : pid_t wait3(int *status, int options, struct rusage *rusage);

wait4
Description : Comme wait3, mais pour un processus spécifique.
Prototype : pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);



Gestion des signaux

signal
Description : Définit un gestionnaire de signaux.
Prototype : void (*signal(int sig, void (*handler)(int)))(int);

sigaction
Description : Examine ou modifie l'action associée à un signal.
Prototype : int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

sigemptyset
Description : Initialise un ensemble de signaux à être vide.
Prototype : int sigemptyset(sigset_t *set);

sigaddset
Description : Ajoute un signal à un ensemble de signaux.
Prototype : int sigaddset(sigset_t *set, int signum);

kill
Description : Envoie un signal à un processus ou à un groupe de processus.
Prototype : int kill(pid_t pid, int sig);



Fonctions de sortie

exit
Description : Termine le processus.
Prototype : void exit(int status);



Fonctions de gestion de répertoire

getcwd
Description : Récupère le répertoire de travail actuel.
Prototype : char *getcwd(char *buf, size_t size);

chdir
Description : Change le répertoire de travail actuel.
Prototype : int chdir(const char *path);



Fonctions de gestion des fichiers

stat
Description : Obtient le statut d'un fichier.
Prototype : int stat(const char *path, struct stat *buf);

lstat
Description : Comme stat, mais pour les liens symboliques.
Prototype : int lstat(const char *path, struct stat *buf);

fstat
Description : Obtient le statut d'un fichier ouvert.
Prototype : int fstat(int fd, struct stat *buf);

unlink
Description : Supprime un fichier.
Prototype : int unlink(const char *pathname);



Fonctions d'exécution

execve
Description : Exécute un programme.
Prototype : int execve(const char *pathname, char *const argv[], char *const envp[]);



Fonctions de gestion des descripteurs de fichier

dup
Description : Duplique un descripteur de fichier.
Prototype : int dup(int oldfd);

dup2
Description : Duplique un descripteur de fichier vers un autre descripteur spécifique.
Prototype : int dup2(int oldfd, int newfd);



Fonctions de gestion des pipes

pipe

Description : Crée un tube de communication inter-processus (pipe).
Prototype : int pipe(int pipefd[2]);



Fonctions de gestion des répertoires

opendir
Description : Ouvre un répertoire.
Prototype : DIR *opendir(const char *name);

readdir
Description : Lit une entrée de répertoire.
Prototype : struct dirent *readdir(DIR *dirp);

closedir
Description : Ferme un répertoire.
Prototype : int closedir(DIR *dirp);



Fonctions d'affichage d'erreurs

strerror
Description : Renvoie une chaîne de caractères décrivant une erreur.
Prototype : char *strerror(int errnum);

perror
Description : Affiche un message d'erreur sur la sortie d'erreur standard.
Prototype : void perror(const char *s);



Fonctions de gestion des terminaux

isatty
Description : Teste si un descripteur de fichier est associé à un terminal.
Prototype : int isatty(int fd);

ttyname
Description : Renvoie le nom de fichier du terminal associé à un descripteur de fichier.
Prototype : char *ttyname(int fd);

ttyslot
Description : Renvoie le numéro de la ligne terminal.
Prototype : int ttyslot(void);

ioctl
Description : Contrôle le périphérique.
Prototype : int ioctl(int fd, unsigned long request, ...);



Fonctions de gestion des variables d'environnement

getenv
Description : Récupère la valeur d'une variable d'environnement.
Prototype : char *getenv(const char *name);



Fonctions de gestion des attributs du terminal

tcsetattr
Description : Définit les attributs du terminal.
Prototype : int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);

tcgetattr
Description : Récupère les attributs du terminal.
Prototype : int tcgetattr(int fd, struct termios *termios_p);



Fonctions de gestion des capacités du terminal

tgetent
Description : Récupère l'entrée de la base de données du terminal.
Prototype : int tgetent(char *bp, const char *name);

tgetflag
Description : Récupère une capacité booléenne du terminal.
Prototype : int tgetflag(const char *id);

tgetnum
Description : Récupère une capacité numérique du terminal.
Prototype : int tgetnum(const char *id);

tgetstr
Description : Récupère une capacité de chaîne du terminal.
Prototype : char *tgetstr(const char *id, char **area);

tgoto
Description : Construit une chaîne de curseur pour une capacité donnée.
Prototype : char *tgoto(const char *cap, int col, int row);

tputs
Description : Sortie des chaînes de capacité du terminal.
Prototype : int tputs(const char *str, int affcnt, int (*putc)(int));