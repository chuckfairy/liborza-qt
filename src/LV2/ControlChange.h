/**
 * Control change for outputs
 */
#pragma once

namespace Orza { namespace LV2UI {

struct ControlChange {
    uint32_t index;
    uint32_t protocol;
    uint32_t size;
    uint8_t  body[];
};

} }
