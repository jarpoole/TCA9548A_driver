
#ifndef TCA9548A_DEFS
#define TCA9548A_DEFS


#define TCA9548A_BASE_ADDR 0x70          ///< TCA9548A address when A0=0, A1=0, A2=0
#define TCA9548A_MINIMUM_RESET_TIME_US 1 ///< According to datasheet, minimum reset delay pulse is actually 6ns, but minimum reasonable microcontroller delay is 1us

// Define platform specific function pointers (return 0 for success, return non-zero for error)
typedef TCA9548A_FPTR_RTN_T (*tca9548a_read_reg_fptr_t)(uint8_t *reg_data, void* user_ptr);
typedef TCA9548A_FPTR_RTN_T (*tca9548a_write_reg_fptr_t)(uint8_t reg_data, void* user_ptr);
typedef TCA9548A_FPTR_RTN_T (*tca9548a_reset_gpio_fptr_t)(bool state, void* user_ptr);
typedef TCA9548A_FPTR_RTN_T (*tca9548a_delay_us_fptr_t)(uint32_t delay);

typedef struct {
	tca9548a_read_reg_fptr_t    read_reg;   ///< Pointer to the platform specific control register read function
	tca9548a_write_reg_fptr_t   write_reg;  ///< Pointer to the platform specific control register write function
	tca9548a_reset_gpio_fptr_t  reset_gpio; ///< Pointer to the platform specific reset GPIO control function
	tca9548a_delay_us_fptr_t    delay_us;   ///< Pointer to a platform specific delay functions
	void*                       user_ptr;   ///< (optional) Pointer to a user-defined hardware configuration struct
}tca9548a_platform_t;

typedef enum{
	TCA9548A_CHANNEL0     = (uint8_t)0b00000001,
	TCA9548A_CHANNEL1     = (uint8_t)0b00000010,
	TCA9548A_CHANNEL2     = (uint8_t)0b00000100,
	TCA9548A_CHANNEL3     = (uint8_t)0b00001000,
	TCA9548A_CHANNEL4     = (uint8_t)0b00010000,
	TCA9548A_CHANNEL5     = (uint8_t)0b00100000,
	TCA9548A_CHANNEL6     = (uint8_t)0b01000000,
	TCA9548A_CHANNEL7     = (uint8_t)0b10000001,
	TCA9548A_ALL_CHANNELS = (uint8_t)0b11111111,
} tca9548a_channel_t;

typedef enum{
	TCA9548A_CHANNEL_ENABLED,  ///< Used to bind a channel to the root bus
	TCA9548A_CHANNEL_DISABLED, ///< Used to release a channel from the root bus
} tca9548a_channel_mode_t;

///< Error codes for TCA9548A
typedef enum {
    TCA9548A_OK = 0,
    TCA9548A_ERR_UNKNOWN,
    TCA9548A_ERR_INVALID_ARG,
	TCA9548A_ERR_INVALID_STATE,
    TCA9548A_ERR_DEVICE_NOT_FOUND,
    TCA9548A_ERR_WRITE,
    TCA9548A_ERR_READ,
} tca9548a_err_t;

#endif