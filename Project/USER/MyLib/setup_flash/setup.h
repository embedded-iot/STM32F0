#ifndef __SETUP_H
#define __SETUP_H
#include <stdint.h>

#define    UP           GPIOA
#define    DOW          GPIOB
#define    Mode          GPIO_Pin_6
#define    Address1      0x08006C00
#define    Address2      0x08007A00


void Setup_Config(void);
void quet_phim(void);
void setup1 (void);
void setup2 (void);
void write_data_flash(uint32_t address, uint16_t data);

#endif

