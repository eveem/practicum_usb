#define IS_SWITCH_PRESSED() (!(PINC & (1<<PC3)))

void init_peripheral();
void set_green_led(uint8_t pin, uint8_t state);
