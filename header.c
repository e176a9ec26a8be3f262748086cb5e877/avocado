#include "header/header.h"

void display_help() {
    printf("\nComandos Disponíveis:\n");
    printf("--------------------------------------------------\n");
    printf("help                         - Exibe esta ajuda.\n");
    printf("manual [comando]             - Exibe o manual detalhado do comando.\n");
    printf("avdmanager                   - Gerencia dispositivos virtuais Android.\n");
    printf("sdkmanager                   - Gerencia pacotes e plataformas do SDK do Android.\n");
    printf("adb                          - Ferramenta de debug do Android para interagir com dispositivos.\n");
    printf("emulator                     - Inicia e gerencia emuladores Android.\n");
    printf("exit                         - Sai do terminal.\n");
    printf("--------------------------------------------------\n");
    printf("Digite 'manual [comando]' para mais informações sobre um comando específico.\n");
}

void display_manual(const char *command) {
    if (strcmp(command, "avdmanager") == 0) {
        printf("\nManual: avdmanager\n");
        printf("--------------------------------------------------\n");
        printf("Comando: avdmanager\n");
        printf("Descrição: Gerencia dispositivos virtuais Android (AVDs).\n");
        printf("Uso:\n");
        printf("  avdmanager list avd                       - Lista todos os AVDs disponíveis.\n");
        printf("  avdmanager create avd -n <nome> -k <pacote> - Cria um novo AVD.\n");
        printf("  avdmanager delete avd -n <nome>           - Exclui um AVD existente.\n");
        printf("--------------------------------------------------\n");
    } else if (strcmp(command, "sdkmanager") == 0) {
        printf("\nManual: sdkmanager\n");
        printf("--------------------------------------------------\n");
        printf("Comando: sdkmanager\n");
        printf("Descrição: Gerencia pacotes e plataformas do SDK do Android.\n");
        printf("Uso:\n");
        printf("  sdkmanager --list                         - Lista todos os pacotes disponíveis.\n");
        printf("  sdkmanager \"platforms;android-30\"       - Instala a plataforma Android 30.\n");
        printf("  sdkmanager --update                       - Atualiza todos os pacotes instalados.\n");
        printf("--------------------------------------------------\n");
    } else if (strcmp(command, "adb") == 0) {
        printf("\nManual: adb\n");
        printf("--------------------------------------------------\n");
        printf("Comando: adb\n");
        printf("Descrição: Ferramenta de debug do Android para interagir com dispositivos.\n");
        printf("Uso:\n");
        printf("  adb devices                               - Lista dispositivos conectados.\n");
        printf("  adb install <arquivo.apk>                 - Instala um APK em um dispositivo conectado.\n");
        printf("  adb shell                                 - Abre um shell no dispositivo.\n");
        printf("--------------------------------------------------\n");
    } else if (strcmp(command, "emulator") == 0) {
        printf("\nManual: emulator\n");
        printf("--------------------------------------------------\n");
        printf("Comando: emulator\n");
        printf("Descrição: Inicia e gerencia emuladores Android.\n");
        printf("Uso:\n");
        printf("  emulator -list-avds                       - Lista todos os AVDs disponíveis.\n");
        printf("  emulator -avd <nome_do_avd>               - Inicia um AVD específico.\n");
        printf("  emulator -wipe-data                       - Apaga todos os dados do AVD.\n");
        printf("--------------------------------------------------\n");
    } else {
        printf("Erro: Manual não encontrado para o comando '%s'.\n", command);
    }
}
