Sistema de Chamada de Emergência para Leitos Hospitalares

Este projeto consiste em um sistema de chamada de emergência para leitos de hospitais. O acionamento é feito por um botão físico no leito do paciente e a chamada é enviada em tempo real para um posto central, garantindo uma resposta rápida e eficiente da equipe médica. A solução foi desenvolvida utilizando a plataforma ESP32, que oferece conectividade Wi-Fi para uma comunicação robusta e sem fio.

🌟 Funcionalidades

    Acionamento Simples e Preciso: Um botão físico no leito do paciente aciona a chamada de emergência, que identifica o leito exato que solicitou o atendimento.

    Comunicação sem Fio (Wi-Fi): Utiliza a conectividade Wi-Fi do ESP32 para enviar as chamadas de emergência de forma confiável para o painel de monitoramento central.

    Protocolo de Comunicação MQTT: A troca de mensagens entre os leitos e o painel central é feita através do protocolo MQTT, ideal para projetos de IoT por ser leve e eficiente.

    Sincronização de Horário: O sistema sincroniza o horário via NTP (Network Time Protocol) para registrar o momento exato de cada chamada, permitindo um registro preciso do tempo de resposta.

    Gestão de Botões: A biblioteca Button2 é utilizada para gerenciar os botões, garantindo um manuseio preciso e evitando acionamentos falsos.

    Registro de Chamadas em JSON: Os dados das chamadas são formatados em JSON antes de serem enviados, um padrão moderno para facilitar a integração com outras aplicações.

⚙️ Tecnologias Utilizadas

    Hardware: ESP32

    Linguagem de Programação: C++

    Framework: Arduino Core para ESP32

    Bibliotecas:

        WiFi.h

        PubSubClient.h (para comunicação MQTT)

        ArduinoJson.h (para serialização de dados)

        Button2.h (para manuseio dos botões)

        time.h (para sincronização NTP)
