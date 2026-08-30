#include "io/register_map.hpp"
#include "io/serial.hpp"
#include "io/system_controller.hpp"
#include "system/interrupt_controller.hpp"
#include "system/timer.hpp"

#include <cassert>
#include <iostream>

int main() {
    indyemu::RegisterMap regs;
    regs.nvram_regs[0] = 0x08006912u;
    regs.nvram_regs[1] = 0x003456u;

    assert(regs.nvram_regs[0] == 0x08006912u);
    assert(regs.nvram_regs[1] == 0x003456u);

    indyemu::SystemController sys;
    std::array<std::uint8_t, 6> mac = {0x08u, 0x00u, 0x69u, 0x12u, 0x34u, 0x56u};
    sys.setMacAddress(mac);
    assert(sys.macAddress()[0] == 0x08u);
    assert(sys.macAddress()[5] == 0x56u);

    indyemu::TimerDevice timer;
    timer.setPeriod(100u);
    timer.tick();
    assert(timer.elapsedTicks() == 1u);

    indyemu::InterruptController irq;
    irq.trigger(5u);
    assert(irq.pendingMask() != 0u);
    irq.clear(5u);
    assert(irq.pendingMask() == 0u);

    indyemu::SerialPort serial;
    serial.writeByte('A');
    assert(serial.readByte() == 'A');

    std::cout << "hardware shell ok\n";
    return 0;
}
