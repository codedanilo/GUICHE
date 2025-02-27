#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"  // Certifique-se de que o caminho está correto

#define I2C_PORT i2c1
#define I2C_SDA_PIN 14
#define I2C_SCL_PIN 15

#define BUTTON_PIN 5
#define BUZZER_PIN 21

#define DEBOUNCE_DELAY_MS 50

#define LARGURA_DISPLAY 128
#define ALTURA_DISPLAY 64
#define ENDERECO_SSD1306 0x3C

volatile bool button_pressed = false;
volatile uint32_t last_button_press_time = 0;

void button_isr(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_button_press_time > DEBOUNCE_DELAY_MS) {
        button_pressed = true;
        last_button_press_time = current_time;
    }
}

void init_hardware() {
    stdio_init_all();

    // Inicializa o I2C
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    // Configura o botão com interrupção
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_isr);

    // Configura o buzzer ativo
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
    gpio_put(BUZZER_PIN, 0);  // Garante que o buzzer comece desligado
}

void update_display(ssd1306_t *display, uint8_t guiche, uint16_t senha) {
    char buffer[32];

    // Limpa o display (preenche com preto)
    ssd1306_fill(display, false);

    // Exibe o número do guichê
    snprintf(buffer, sizeof(buffer), "GUICHE %02d", guiche);
    ssd1306_draw_string(display, buffer, 0, 0); // Linha 0

    // Exibe a senha atual
    snprintf(buffer, sizeof(buffer), "SENHA %04d", senha);
    ssd1306_draw_string(display, buffer, 0, 16); // Linha 16

    // Envia os dados para o display
    ssd1306_send_data(display);
}

void beep() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(100);            // Mantém ligado por 100 ms
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}

int main() {
    init_hardware();

    // Inicializa o display SSD1306
    ssd1306_t display;
    ssd1306_init(&display, LARGURA_DISPLAY, ALTURA_DISPLAY, false, ENDERECO_SSD1306, I2C_PORT);

    // Limpa o display (preenche com preto)
    ssd1306_fill(&display, false);
    ssd1306_send_data(&display);

    uint8_t guiche = 1;
    uint16_t senha = 0;

    update_display(&display, guiche, senha);

    while (1) {
        if (button_pressed) {
            button_pressed = false;
            senha++;
            update_display(&display, guiche, senha);
            beep();  // Gera o som do buzzer
        }
        sleep_ms(10);
    }

    return 0;
}