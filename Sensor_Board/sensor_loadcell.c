#include "p33Exxxx.h"
#include "sensor_loadcell.h"
#include "sensor_pindefs.h"
#include "sensor_state.h"
#include <dma.h>
//#include "../libs/canaerospace/canaerospace/include/canaerospace/canaerospace.h"

loadcell_data loadcell_state;

inline void spi_wait() {
    while (loadcell_state.spi_state != SPI_IDLE);
}

return_value_t loadcell_init()
{
    unsigned i;
    loadcell_state.init_return = RET_OK;
    for(i=0;i<4;++i){
        loadcell_state.values[i] = 0l;
        loadcell_state.num_measurements[i] = 0;
    }

    SHD = 1;

    IFS0bits.SPI1IF = 0; // Clear the Interrupt Flag
    IEC0bits.SPI1IE = 0; // Disable the Interrupt

    // SPI1CON1 Register Settings
    SPI1CON1bits.DISSCK = 0; // Internal SPI clock is enabled
    SPI1CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 0; // Communication is byte-wide (8 bits)
    SPI1CON1bits.SMP = 0; // Input data is sampled at the middle of data output time

    SPI1CON1bits.CKE = 0; // Serial output data changes on transition
    // from Idle clock state to active clock state
    SPI1CON1bits.CKP = 1; // Idle state for clock is a high level;
    // active state is a low level
    SPI1CON1bits.MSTEN = 1; // Master mode enabled
    SPI1CON1bits.PPRE = 0b01;//0b01; // Primary prescale bit for SPI clock; 0b11 = 1:1;  0b10 = 4:1; 0b01 = 16:1; 0b00 = 64:1
    SPI1CON1bits.SPRE = 0b110;//0b011; // Secondary prescale bit for SPI clock; 0b111 = 1:1; 0b110 = 1:2 ... 0b000 = 1:8
    SPI1CON1bits.SSEN = 0; // Slave select pin disabled

    SPI1CON2bits.FRMEN = 0; // Frame mode disabled

    // SPISTAT Register Settings
    SPI1STATbits.SPIEN = 1; // Enable SPI module
    SPI1STATbits.SPISIDL = 0; // Continue module operation when device enters Idle mode

    // Interrupt Controller Settings
    SPI1STATbits.SPIROV = 0; // Clear SPI overflow bit
    IFS0bits.SPI1EIF = 0; // Clear SPI1 Error Interrupt Flag Status bit
    IPC2bits.SPI1IP = 0x06; // Set SPI1 Interrupt Priority Level to 1 = low priority
    IFS0bits.SPI1IF = 0; // Clear the Interrupt Flag
    IEC0bits.SPI1IE = 1; // Enable the Interrupt

    SG_DESELECT;
    loadcell_state.data_ready = 0;


    loadcell_state.spi_state = SPI_IDLE;

    uint8_t mode_byte_1 = 0;
    uint8_t mode_byte_2 = 0;
    uint8_t mode_byte_3 = 0;
    uint8_t config_byte_1;
    uint8_t config_byte_2;
    uint8_t config_byte_3;


    loadcell_state.spi_state = SPI_VARIOUS;
    SG_SELECT;
    for(i=0;i<65000;++i){
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
    }
    for(i=0;i<65000;++i){
        Nop();
        Nop();
    }
    //reset chip
    SPI1BUF = 0xFF;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = 0xFF;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = 0xFF;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = 0xFF;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = 0xFF;
    spi_wait();
    SG_DESELECT;
    for(i=0;i<65000;++i){
        Nop();
        Nop();
    }
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    for(i=0;i<65000;++i){
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
    }
    SG_SELECT;
    //write the MODE register
    SPI1BUF = SG_REG_MODE;
    spi_wait();
    mode_byte_1 = 0b00011101;//continuous mode, transmit status reg, MCLK2 is clock, average 2 (FS/2)

    mode_byte_2 = 0b00000100;//sinc4 enabled | no parity | no clock divide | no single | 60hz rejection

    mode_byte_3 = 1;//100Hz

    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = mode_byte_1;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = mode_byte_2;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = mode_byte_3;
    spi_wait();
    SG_DESELECT;
    for(i=0;i<65000;++i){
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
        Nop();Nop();
    }

    SG_SELECT;
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = SG_REG_CONFIG;
    spi_wait();
    //write the CONFIGURATION register
    config_byte_1 =  0b10000000;
    config_byte_2 =0b1111;//0b11110000;// 
    config_byte_3 = 0b01011000;
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = config_byte_1;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = config_byte_2;
    spi_wait();
    loadcell_state.spi_state = SPI_VARIOUS;
    SPI1BUF = config_byte_3;
    spi_wait();
    SG_DESELECT;
    for(i=0;i<65000;++i){
        Nop();
        Nop();
    }
    IC4CON1bits.ICM = 0b010; //interrupt on falling edge
    IC4CON2bits.TRIGSTAT = 0;
    for(i=0;i<65000;++i){
        Nop();
        Nop();
    }
    return loadcell_state.init_return;
}

void __attribute__((__interrupt__, no_auto_psv)) _SPI1Interrupt(void) {
    SPI1STATbits.SPIROV = 0; // Clear SPI overflow bit
    switch (loadcell_state.spi_state) {
        case SPI_SG_READ_DATA_1:
            SPI1BUF = 0x0;
            loadcell_state.spi_state = SPI_SG_READ_DATA_2;
            break;
        case SPI_SG_READ_DATA_2:
            loadcell_state.sg_data_1 = SPI1BUF;
            SPI1BUF = 0x0;
            loadcell_state.spi_state = SPI_SG_READ_DATA_3;
            break;
        case SPI_SG_READ_DATA_3:
            loadcell_state.sg_data_2 = SPI1BUF;
            SPI1BUF = 0x0;
            loadcell_state.spi_state = SPI_SG_READ_DATA_4;
            break;
        case SPI_SG_READ_DATA_4:
            loadcell_state.sg_data_3 = SPI1BUF;
            SPI1BUF = 0x0;
            loadcell_state.spi_state = SPI_SG_READ_DATA_END;
            break;
        case SPI_SG_READ_DATA_END:
            loadcell_state.sg_status = SPI1BUF;
            loadcell_state.spi_state = SPI_IDLE;

            //copy the data to the right location
            if(!(loadcell_state.sg_status&0b10000000)){
                loadcell_state.error = (loadcell_state.sg_status&0b1000000)>0; //error
                //ready bit is not set, so data is available
                if(!(loadcell_state.sg_status&0b00000100))
                {
                    //one of the correct channels was converted, store the result
                    loadcell_state.values[loadcell_state.sg_status&0b11] =
                            (((uint32_t)(loadcell_state.sg_data_1&0xFF))<<16)
                            | (((uint32_t)(loadcell_state.sg_data_2&0xFF))<<8)
                            | (((uint32_t)(loadcell_state.sg_data_3&0xFF)));
                    loadcell_state.num_measurements[loadcell_state.sg_status&0b11]++;

                }
            }
//            if(loadcell_state.sg_status ||loadcell_state.sg_data_1 || loadcell_state.sg_data_2 || loadcell_state.sg_data_3 ) {
//                loadcell_state.error = 1;
//            }

            SG_DESELECT;
            
            loadcell_state.data_ready = 0;
            IEC2bits.IC4IE = 1;
            IFS2bits.IC4IF = 0; 
            SG_SELECT;
            break;
        case SPI_VARIOUS:
            loadcell_state.spi_state = SPI_IDLE;
            break;
        default:
            loadcell_state.spi_state = SPI_IDLE;
            break;
    };

    IFS0bits.SPI1EIF = 0; // Clear SPI1 Fault Interrupt Flag Status bit
    IFS0bits.SPI1IF = 0; // Clear the interrupt Flag
}

inline uint8_t spi_is_busy() {
    return loadcell_state.spi_state != SPI_IDLE;
}

void loadcell_start()
{
    SG_SELECT;
    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
    IFS2bits.IC4IF = 0; // Clear the IC1 interrupt status flag
    IEC2bits.IC4IE = 1; // Enable IC1 interrupts
    _IC4Interrupt();
}

void __attribute__((__interrupt__, no_auto_psv)) _IC4Interrupt(void) {

    if((!loadcell_state.data_ready) && (!SG_MISO) ){
        //disable interrupt
        IEC2bits.IC4IE = 0;
        //read data register
        loadcell_state.data_ready = 1;
        loadcell_state.spi_state = SPI_SG_READ_DATA_1;
        SPI1BUF = SG_REG_DATA | 0b01000000;
    }
    IFS2bits.IC4IF = 0; // Reset respective interrupt flag
}