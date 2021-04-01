
#ifndef TCA9548A_H
#define TCA9548A_H

#include <stdint.h>
#include <stdbool.h>

// User provided config directory in directory above submodule
#include "../../tca9548a_config.h"

// Driver constants and types
#include "tca9548a_defs.h"

tca9548a_err_t tca9548a_are_channels_configured(tca9548a_channel_t, tca9548a_channel_mode_t, tca9548a_platform_t*);
tca9548a_err_t tca9548a_configure_channels(tca9548a_channel_t, tca9548a_channel_mode_t, tca9548a_platform_t*);
tca9548a_err_t tca9548a_reset(tca9548a_platform_t*);

#endif