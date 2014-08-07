/* 
 * File:   power_pindef.c
 * Author: jonathan
 *
 * Created on March 20, 2014, 2:11 PM
 */

#include "power_pindef.h"

return_value_t pin_init() {

    //Set all pins to input
    TRISA = 0xFFFF;
    TRISB = 0xFFFF;
    TRISC = 0xFFFF;
    TRISD = 0xFFFF;
    TRISE = 0xFFFF;
    TRISF = 0xFFFF;
    TRISG = 0xFFFF;

    //Configure all analog ports as digital I/O
    ANSELA = 0x0;
    ANSELB = 0x0;
    ANSELC = 0x0;
    ANSELE = 0x0;

    //Watchdog
    PTGCONbits.PTGWDT = 0b000; //watchdog disabled

    //LEDs
    TRISAbits.TRISA12 = 0;  //LED_R
    TRISAbits.TRISA11 = 0;  //LED_G
    TRISAbits.TRISA0 = 0;   //LED_B
    TRISAbits.TRISA1 = 0;   //LED_STATUS

    //Power & Motor Enable Pins
    TRISDbits.TRISD5 = 0;   //EN_BACKUP_5V5
    TRISDbits.TRISD6 = 0;   //EN_VBAT_5V5
    TRISAbits.TRISA10 = 0;  //VBAT_5V5_EN
    TRISAbits.TRISA8 = 0;   //KILLSWITCH_uC
    TRISEbits.TRISE15 = 0;  //EN_MOTOR_CURRENT

    //5V5 Output Control Pins
    TRISBbits.TRISB9 = 0;   //EN_OUT_1
    TRISCbits.TRISC6 = 0;   //EN_OUT_2
    TRISCbits.TRISC13 = 0;  //EN_OUT_3
    TRISBbits.TRISB8 = 0;   //EN_OUT_4

    //ANALOG PINS
    ANSELCbits.ANSC0 = 1;
    ANSELCbits.ANSC1 = 1;
    ANSELCbits.ANSC2 = 1;
    ANSELCbits.ANSC11 = 1;

    //UART 1
    _RP37R = 0b000001;              //U1TX to pin RP37/RB5 = EX_6
    RPINR18bits.U1RXR = 0b0100110;  //U1RX to pin RP38/RB6 = EX_10

     /*
     * CAN
     */
    TRISCbits.TRISC6 = 0; //TX = output
    _RP56R = 0b001110;//TX
    RPINR26bits.C1RXR = 55; //RX RP55

    return RET_OK;
}

