
#ifndef TCA9548A_DEFS
#define TCA9548A_DEFS


// Define platform specific function pointers (return 0 for success, return non-zero for error)
typedef TCA9548A_FPTR_RTN_T (*tca9548a_read_reg_fptr_t)(uint8_t dev_addr, uint8_t *reg_data);
typedef TCA9548A_FPTR_RTN_T (*tca9548a_write_reg_fptr_t)(uint8_t dev_addr, uint8_t reg_data);

struct tca9548a_platform_t{
	tca9548a_read_reg_fptr_t    read_reg;   ///< Pointer to the platform specific control register read function
	tca9548a_write_reg_fptr_t   write_reg;  ///< Pointer to the platform specific control register write function
	void*                       user_ptr;   ///< (optional) Pointer to a user-defined hardware configuration struct
};

#endif