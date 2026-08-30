#include "core/indy_hardware.hpp"

namespace indyemu {

IndyHardware::IndyHardware(MachineConfig config) : config_(std::move(config)) {
}

}  // namespace indyemu
