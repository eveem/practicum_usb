#include <avr/io.h>
#include <avr/interrupt.h>  /* for sei() */
#include <util/delay.h>     /* for _delay_ms() */
#include <avr/pgmspace.h>   /* required by usbdrv.h */

#include "test.h"
#include "usbdrv.h"

#define RQ_SET_GREEN_LED   0

/* ------------------------------------------------------------------------- */
/* ----------------------------- USB interface ----------------------------- */
/* ------------------------------------------------------------------------- */
usbMsgLen_t usbFunctionSetup(uint8_t data[8])
{
    usbRequest_t *rq = (void *)data;

    if (rq->bRequest == RQ_SET_GREEN_LED)
    {
        uint8_t led_val = rq->wValue.bytes[0];
        uint8_t led_no  = rq->wIndex.bytes[0];
        set_green_led(led_no, led_val);
        return 0;
    }

    /* default for not implemented requests: return no data back to host */
    return 0;
}

/* ------------------------------------------------------------------------- */
int main(void)
{
    init_peripheral();

    usbInit();

    /* enforce re-enumeration, do this while interrupts are disabled! */
    usbDeviceDisconnect();
    _delay_ms(300);
    usbDeviceConnect();

    /* enable global interrupts */
    sei();

    /* main event loop */
    for(;;)
    {
        usbPoll();
    }

    return 0;
}

/* ------------------------------------------------------------------------- */
