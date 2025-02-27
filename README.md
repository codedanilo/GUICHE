# Sistema de Guichê com Display e Buzzer

**Discente**: Danilo Silveira

## Descrição do Projeto

Este projeto consiste em um sistema de guichê que utiliza uma placa **Raspberry Pi Pico**, um **display OLED SSD1306** e um **buzzer ativo** para simular a chamada de senhas em um ambiente de atendimento. O sistema exibe o número do guichê e a senha atual no display OLED, e ao pressionar um botão, a senha é incrementada, o display é atualizado e o buzzer emite um som curto e alto, simulando a chamada de uma nova senha.

## Funcionalidades

### Exibição no Display:
- Mostra o número do guichê e a senha atual no display OLED.

### Chamada de Senha:
- Ao pressionar o botão, a senha é incrementada e o display é atualizado.

### Alerta Sonoro:
- O buzzer emite um som alto e curto a cada chamada de senha.

## Componentes Utilizados

- **Raspberry Pi Pico**: Microcontrolador principal.
- **Display OLED SSD1306**: Exibe as informações do guichê e da senha.
- **Buzzer Ativo**: Emite o som de alerta.
- **Botão**: Simula a chamada de uma nova senha.
- **Resistores e Jumpers**: Conexões e ajustes de tensão.

## Esquema de Conexões

| Componente                | Pino no Raspberry Pi Pico |
|---------------------------|---------------------------|
| Display OLED SDA           | GP14                      |
| Display OLED SCL           | GP15                      |
| Buzzer                     | GP21                      |
| Botão                      | GP5                       |

## Como Executar o Projeto

### Montagem do Hardware:
1. Conecte o **display OLED**, o **buzzer** e o **botão** ao **Raspberry Pi Pico** conforme o esquema de conexões acima.

### Configuração do Ambiente:
1. Instale o **Pico SDK** e configure o ambiente de desenvolvimento utilizando **VS Code** com a extensão **Pico SDK**.
2. Assegure-se de que o ambiente de desenvolvimento esteja corretamente configurado para a Raspberry Pi Pico.

### Compilação e Upload:
1. Compile o código utilizando o **Pico SDK**.
2. Faça o upload do binário gerado para o **Raspberry Pi Pico**.

### Testes:
1. Pressione o **botão** para simular a chamada de senha.
2. Verifique se o **display** é atualizado com o número da senha e guichê.
3. Confirme que o **buzzer** emite um som curto e alto após cada pressionamento do botão.

## Vídeo de Demonstração

[Link para o vídeo de demonstração](#)  
https://youtube.com/shorts/NYsHZz55U3U

## Código-Fonte

O código-fonte do projeto está disponível no repositório:

[Repositório do Projeto](#)  
*(Substitua pelo link do repositório, se aplicável)*

## Referências

- [Documentação do Raspberry Pi Pico](https://www.raspberrypi.org/documentation/microcontrollers/)
- [Datasheet do Display OLED SSD1306](https://www.adafruit.com/product/938)
- [Documentação do Pico SDK](https://www.raspberrypi.org/documentation/pico-sdk/)

## Autor

**Danilo Silveira**  
Discente do curso de Sistemas Embarcados
Contato: dansilver32a@gmail.com

