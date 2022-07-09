#ifndef _LIBDW3000_TYPES_H_
#define _LIBDW3000_TYPES_H_

#include <stddef.h>
#include <stdint.h>

typedef enum {dwSpiSpeedLow, dwSpiSpeedHigh} dwSpiSpeed_t;

typedef struct dwOps_s {
	/**
	 * Function that activates the chip-select, sends header, read data and
	 * disable the chip-select.
	 */
	void (*spiRead)(const void *header, size_t headerLength,
                                   void* data, size_t dataLength);

	/**
	 * Function that activates the chip-select, sends header, sends data and
	 * disable the chip-select.
	 */
	void (*spiWrite)(const void *header, size_t headerLength,
                                    const void* data, size_t dataLength);

	/**
	 * Sets the SPI bus speed. Take as argument:
	 *	 - dwSpiSpeedLow: <= 4MHz
	 *	 - dwSpiSpeedHigh: <= 20MHz
	 */
	void (*spiSetSpeed)(dwSpiSpeed_t speed);

	/**
	 * Waits at least 'delay' miliseconds.
	 */
	void (*delayms)(unsigned int delay);

	/**
	 * Resets the DW3000 by pulling the reset pin low and then releasing it.
	 * This function is optional, if not set softreset via SPI will be used.
	 */
	 void (*reset)(void);
} dwOps_t;

dwOps_t dwt_ops;
#endif