#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>

const char *target;

void procesare (char *path)
{
    int flag;
    DIR *dir;
    struct dirent *de;
    struct stat st;
    char nume[PATH_MAX];

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
                if (strcmp (de->d_name, target) == 0) printf ("%s\n", nume);
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
    struct passwd *pw;
    const char* homedir;
    if (argc < 2) exit (1); //nu a fost dat fisierul target
    pw = getpwuid(getuid());
    homedir = pw->pw_dir;
    target = argv[1];
    procesare (homedir);
    return 0;
}
