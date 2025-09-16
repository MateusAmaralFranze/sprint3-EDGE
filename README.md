

***

### Resumo do Projeto

Este projeto foi criado para simular um sistema de monitoramento fisiológico, especificamente um sensor de frequência de pulso. O componente principal é um **microcontrolador ESP32**, uma placa versátil e poderosa com Wi-Fi integrado. A função primária do projeto é:

1.  **Ler um valor analógico** de um sensor de pulso simulado.
2.  **Converter esse valor analógico em uma medição de batimentos por minuto (BPM)**.
3.  **Transmitir os dados de BPM** para um servidor externo por meio de uma requisição HTTP POST.

Essa configuração é ideal para demonstrar aplicações de Internet das Coisas (IoT), onde um dispositivo coleta dados de um sensor e se comunica com um serviço web para armazenamento, análise ou exibição em tempo real.

***

### Detalhamento Técnico

#### 1. Bibliotecas e Configuração
O projeto depende de várias bibliotecas principais:

* `WiFi.h`: Gerencia a conexão do ESP32 a uma rede Wi-Fi. O código está configurado para se conectar a um SSID e senha específicos.
* `HTTPClient.h`: Permite que o ESP32 faça requisições HTTP, atuando como um cliente para enviar dados a um servidor remoto.
* `PulseSensorPlayground.h`: Provavelmente é uma biblioteca simulada no ambiente Wokwi, feita para imitar o comportamento de um sensor de pulso físico.

A função `setup()` inicializa a comunicação serial para depuração e, em seguida, conecta o ESP32 à rede Wi-Fi designada.

#### 2. Simulação e Processamento de Dados
A função `loop()` é o centro da lógica do projeto. Ela realiza repetidamente as seguintes ações:

* `analogRead(pulsePin)`: Lê um valor do sensor de pulso simulado conectado ao pino GPIO 34. Esse valor é uma representação analógica do "pulso".
* `map(sensorValue, 0, 4095, 60, 120)`: Esta função crucial ajusta a leitura analógica bruta (que varia de 0 a 4095 para o ADC do ESP32) para uma faixa de BPM mais significativa, simulando um valor entre 60 e 120 BPM.

#### 3. Transmissão de Dados (HTTP POST)
Após o cálculo do valor de BPM, o ESP32 o envia para um servidor remoto.

* `HTTPClient http`: Uma instância da biblioteca `HTTPClient` é criada para gerenciar a requisição.
* `http.begin(serverUrl)`: A requisição é direcionada para a URL do webhook especificada.
* `http.addHeader(...)`: O cabeçalho `Content-Type` é definido como `application/json`, indicando que os dados enviados estão em formato JSON.
* `http.POST(jsonData)`: A string JSON preparada, que inclui o valor de BPM, é enviada para o webhook.
* **Tratamento de Erros**: O código verifica o `httpResponseCode` para determinar se a transmissão foi bem-sucedida (`> 0`) ou se ocorreu um erro. Mensagens de status são exibidas no monitor serial para feedback em tempo real.

Um `delay(10000)` foi incluído para garantir que os dados sejam enviados a cada 10 segundos, evitando sobrecarregar o servidor com requisições.
