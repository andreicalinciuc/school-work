#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>

void afisare (char* path)
{
    int flag;
    struct stat st;
    struct passwd *pwd;
    char perm[10] = "---------";

    flag = stat (path, &st);
    if (flag !=0 ) return; //eroare la stat
    
    printf ("Nume: %s\n", path);

    printf ("Tip: ");
    switch (st.st_mode & S_IFMT)
    {
        case S_IFSOCK : printf ("Socket\n"); break;
        case S_IFLNK : printf ("Link\n"); break;
        case S_IFREG : printf ("Fisier obisnuit\n"); break;
        case S_IFBLK : printf ("Block device\n"); break;
        case S_IFCHR : printf ("Character device\n"); break;
        case S_IFIFO : printf ("FIFO\n"); break;
        case S_IFDIR : printf ("Director\n"); break;
        default: printf ("Unknown file type\n");
    }
    
    printf ("Dimensiune: %lld octeti\n", (long long) st.st_size);

    if (S_IRUSR & st.st_mode) perm[0]='r';
    if (S_IWUSR & st.st_mode) perm[1]='w';
    if (S_IXUSR & st.st_mode) perm[2]='x';
    if (S_IRGRP & st.st_mode) perm[3]='r';
    if (S_IWGRP & st.st_mode) perm[4]='w';
    if (S_IXGRP & st.st_mode) perm[5]='x';
    if (S_IROTH & st.st_mode) perm[6]='r';
    if (S_IWOTH & st.st_mode) perm[7]='w';
    if (S_IXOTH & st.st_mode) perm[8]='x';
    printf("Permisiuni: %s\n", perm);

    if ((pwd = getpwuid (st.st_uid)) != 0) printf ("Proprietar: %s (cu UID: %ld)\n", pwd->pw_name, (long) st.st_uid);
    else printf ("UID proprietar: %ld\n", (long) st.st_uid);

    printf("\n");
}

void procesare (char *path)
{
    int flag;
    DIR *dir;
    struct dirent *de;
    struct stat st;
    char nume[PATH_MAX];

    afisare (path);
    flag = stat (path, &st);
    if (flag != 0) return; //eroare la stat
    
    if (S_ISDIR (st.st_mode) != 0)
    {
        dir = opendir(path); if (dir == 0) return; //eroare deschidere director
        while (1)
        {
            de = readdir (dir);
            if (de == 0) break;
            if ((strcmp (de->d_name, ".") != 0) && (strcmp (de->d_name, "..") != 0))
            {
                sprintf (nume, "%s/%s", path, de->d_name);
                procesare (nume);
            }
        }
        closedir (dir);
    }
}

int main (int argc, char** argv)
{
    int flag;
    struct stat st;
    if (argc < 2) exit (1); //nu a fost dat directorul
    flag = stat (argv[1], &st);
    if (flag != 0) exit (2); //eroare la stat
    if (S_ISDIR (st.st_mode) == 0) exit(3); //nu este director
    procesare (argv[1]);
    return 0;
}
