README do Projeto: Sistema de Monitoramento de Pulso com ESP32
Visão Geral
Este projeto demonstra um sistema completo para monitorar a frequência cardíaca (pulso) usando um microcontrolador ESP32. O sistema é um exemplo prático de Internet das Coisas (IoT), onde um hardware de baixo custo coleta dados fisiológicos e os transmite para a nuvem para monitoramento ou análise. O projeto inclui a montagem do hardware, a programação do ESP32 para simular a leitura do pulso e o envio dos dados via Wi-Fi para um serviço web externo (webhook).

Componentes de Hardware
A montagem do projeto é simples e utiliza componentes amplamente disponíveis no mercado de eletrônica. Os principais componentes de hardware são:

ESP32: Um microcontrolador popular conhecido por seu baixo consumo de energia, Wi-Fi e Bluetooth integrados. Ele funciona como o cérebro do sistema, processando os dados do sensor e gerenciando a comunicação sem fio.

Sensor de Pulso: Um sensor que mede o pulso cardíaco. No ambiente de simulação do Wokwi, ele é simulado para fornecer leituras analógicas que variam com a frequência cardíaca.

Protoboard e Fios Conectores: Utilizados para montar e conectar os componentes sem a necessidade de solda.

Diagrama de Conexão
O diagrama abaixo ilustra a conexão dos componentes para o funcionamento do sistema. As conexões são diretas e seguem um padrão simples, garantindo a integridade dos dados e da energia.

Energia: As linhas de energia (VCC) e aterramento (GND) do ESP32 são conectadas à protoboard para fornecer energia ao sistema. O sensor de pulso é, por sua vez, alimentado por essas mesmas linhas.

Dados: O pino de dados do sensor de pulso é conectado ao pino de entrada analógica GPIO 34 do ESP32.

Monitoramento Serial: A conexão USB do ESP32 é usada para comunicação serial, permitindo a depuração e o monitoramento em tempo real dos dados processados.

Software e Programação
O software do projeto é desenvolvido para o ambiente de programação da IDE do Arduino. Ele utiliza bibliotecas específicas para gerenciar a conectividade Wi-Fi e as requisições HTTP, além de uma biblioteca para o sensor de pulso.

Bibliotecas Utilizadas:
WiFi.h: Essencial para a conexão do ESP32 a uma rede Wi-Fi, permitindo a comunicação sem fio com a internet.

HTTPClient.h: Usada para fazer as requisições HTTP POST para enviar os dados coletados ao servidor externo.

PulseSensorPlayground.h: Uma biblioteca específica para o sensor de pulso, que simplifica a leitura e o processamento dos dados do sensor.

Lógica de Programação
O código segue um fluxo de trabalho em loop contínuo:

Inicialização (setup): A função de configuração inicializa a comunicação serial e tenta conectar o ESP32 à rede Wi-Fi especificada. A barra de progresso no monitor serial informa o status da conexão.

Leitura do Sensor (loop): A função principal do loop continuamente lê o valor do pino de entrada analógica (GPIO 34) conectado ao sensor de pulso.

Processamento de Dados: O valor analógico bruto do sensor (que varia de 0 a 4095) é mapeado para um intervalo de BPM (por exemplo, 60 a 120), simulando uma frequência cardíaca realista.

Transmissão para o Servidor: Se a conexão Wi-Fi estiver ativa, o ESP32 cria um objeto HTTPClient e configura uma requisição POST. Os dados de BPM são formatados em uma string JSON e enviados para um webhook pré-configurado.

Tratamento de Erros: Após o envio, o código verifica o código de resposta da requisição HTTP. Uma resposta positiva indica sucesso, enquanto um código de erro indica uma falha na transmissão. As mensagens de status são impressas no monitor serial para facilitar a depuração.

Intervalo de Envio: Um atraso de 10 segundos é adicionado ao final do loop para controlar a frequência de envio dos dados, evitando sobrecarregar a rede ou o serviço web com requisições excessivas.

Como Executar o Projeto
Para replicar este projeto, você pode usar o simulador online do Wokwi ou montar o hardware físico.

No Wokwi: Abra o projeto no simulador, e ele já estará pré-configurado. Apenas inicie a simulação.

Com Hardware Físico:

Conecte o ESP32 ao seu computador.

Abra o código na IDE do Arduino.

Certifique-se de ter as bibliotecas necessárias instaladas.

Carregue o código para o ESP32.

Monitore o status e os dados no monitor serial.

Este projeto é um excelente ponto de partida para estudantes e entusiastas que desejam aprender sobre a integração de hardware, software e serviços web. Ele pode ser expandido para incluir outros sensores, diferentes métodos de comunicação (como MQTT) ou integração com plataformas de IoT mais robustas.
