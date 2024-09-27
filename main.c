#include "header/header.h"

int main() {
    const char *home = getenv("HOME");
    char sdk_path[512];
    const char *java_home = "/usr/lib/jvm/java-17-openjdk-amd64";
    const char *emulator_path = "/home/user/Android/Sdk/emulator";
    const char *current_path = getenv("PATH");
    char new_path[4096];
    char command[512];
    char manual_command[256];
    char emulator_command[1024];


    if (home == NULL) {
        fprintf(stderr, "Erro: Variável de ambiente HOME não encontrada.\n");
        return 1;
    }

    snprintf(sdk_path, sizeof(sdk_path), "%s/Android/Sdk/cmdline-tools/latest/bin", home);
    setenv("JAVA_HOME", java_home, 1);
    snprintf(new_path, sizeof(new_path), "%s/bin:%s:%s:%s/platform-tools:%s/tools/bin:%s:%s",
             java_home, sdk_path, sdk_path, sdk_path, sdk_path, sdk_path, current_path);
    setenv("PATH", new_path, 1);

    while (1) {
        printf("🥑 > ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Saindo...\n");
            break;
        }

        if (strcmp(command, "help") == 0) {
            display_help();
            continue;
        }

        if (strncmp(command, "manual ", 7) == 0) {
            sscanf(command, "manual %s", manual_command);
            display_manual(manual_command);
            continue;
        }

        if (strncmp(command, "emulator", 8) == 0) {
            snprintf(emulator_command, sizeof(emulator_command), "%s/%s", emulator_path, command);

            int status = system(emulator_command);
            if (status == -1) {
                perror("Erro ao executar comando do emulator");
            }
        } else {
            int status = system(command);
            if (status == -1) {
                perror("Erro ao executar comando");
            }
        }
    }

    return 0;
}
