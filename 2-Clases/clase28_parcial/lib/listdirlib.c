#include <stdio.h>
#include <glob.h>


char **listardir(char* path){
	char b[200];
	glob_t globbuf;
	int err;

	// -- Genero el path completo --
	sprintf(b, "./%s/*.mp3", path);
	// -- glob() me devuelve un array con los nombres de los archivos .mp3 encontrados (ver man glob) --
	if((err = glob(b, GLOB_ERR, NULL, &globbuf)) == 0)
		return globbuf.gl_pathv;

	return NULL;
}


