
#include "tca9548a.h"

//tca9548a_err_t tca9548a_init(tca9548a_platform_t*);
//tca9548a_err_t tca9548a_deinit(tca9548a_platform_t*);

tca9548a_err_t tca9548a_check_connectivity(tca9548a_platform_t* platform){
    return TCA9548A_OK;
}


/**
 * @brief Checks if the channel(s) provided are enabled. Does not modify
 * the state of the multiplexer
 *
 * @param[in] channels      : Boolean OR of the channel selectors
 * @param[in] mode          : Either enabled or disabled
 * @param[in] platform      : Number of microseconds to delay
 *
 * @retval TCA9548A_OK                -> All channels
 * @retval TCA9548A_ERR_INVALID_STATE -> No interrupt
 */
tca9548a_err_t tca9548a_are_channels_configured(tca9548a_channel_t channels, tca9548a_channel_mode_t mode, tca9548a_platform_t* platform){
    
    TCA9548A_FPTR_RTN_T platform_err;
    uint8_t reg;

    platform_err = platform->read_reg(&reg, platform->user_ptr);
    if(platform_err != 0){
        return TCA9548A_ERR_READ;
    }

    if( (mode == TCA9548A_CHANNEL_ENABLED) && ((channels & reg) == channels) ){
        return TCA9548A_OK;
    }else if( (mode == TCA9548A_CHANNEL_DISABLED) && ((channels & ~reg) == channels) ){
        return TCA9548A_OK;
    }else{
        return TCA9548A_ERR_INVALID_STATE;
    }
}


/**
 * @brief Configures the provided channels as enabled or disabled
 *
 * @param[in] channels      : Boolean OR of the channel selectors
 * @param[in] mode          : Either enabled or disabled
 * @param[in] platform      : Number of microseconds to delay
 *
 * @retval TCA9548A_OK          -> All channels successfully configured
 * @retval TCA9548A_ERR_READ    -> Failed to read previous multiplexer configuration
 * @retval TCA9548A_ERR_WRITE   -> Failed to write new multiplexer configuration
 */
tca9548a_err_t tca9548a_configure_channels(tca9548a_channel_t channels, tca9548a_channel_mode_t mode, tca9548a_platform_t* platform){

    TCA9548A_FPTR_RTN_T platform_err;
    uint8_t reg;

    platform_err = platform->read_reg(&reg, platform->user_ptr);
    if(platform_err != 0){
        return TCA9548A_ERR_READ;
    }

    if(mode == TCA9548A_CHANNEL_ENABLED){
        reg |= channels;
    }else{
        reg &= ~channels;
    }

    platform_err = platform->write_reg(reg, platform->user_ptr);
    if(platform_err != 0){
        return TCA9548A_ERR_WRITE;
    }

    return TCA9548A_OK;
}