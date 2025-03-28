#include <stdio.h>
#include <windows.h>
#include <tchar.h>

void listarPasta(const char* caminho, int nivel) {
    WIN32_FIND_DATA arquivo;
    HANDLE handle;
    char novoCaminho[1024];

    sprintf(novoCaminho, "%s\\*", caminho);

    handle = FindFirstFile(novoCaminho, &arquivo);
    
    if (handle == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir a pasta\n");
        return;
    }

    do {
        if (strcmp(arquivo.cFileName, ".") == 0 || strcmp(arquivo.cFileName, "..") == 0)
            continue;

        // Mostra a indentação conforme o nível
        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }

        printf("|-- %s\n", arquivo.cFileName);

        if (arquivo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            sprintf(novoCaminho, "%s\\%s", caminho, arquivo.cFileName);
            listarPasta(novoCaminho, nivel + 1);
        }
    } while (FindNextFile(handle, &arquivo) != 0);

    FindClose(handle);
}

int main() {
    printf("** LISTADOR DE PASTAS **\n");
    printf("Digite o caminho da pasta (ex: C:\\Users ou . para atual): ");
    
    char caminho[1024];
    scanf("%s", caminho);

    if (strcmp(caminho, ".") == 0) {
        GetCurrentDirectory(1024, caminho);
    }

    printf("\nConteudo de '%s':\n", caminho);
    listarPasta(caminho, 0);
    
    printf("\nFim\n");
    system("pause");
    return 0;
}
