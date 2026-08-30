#include "io/serial.hpp"

namespace indyemu {

SerialPort::SerialPort() {
    reset();
}

void SerialPort::reset() {
    fifo_.fill(0);
    head_ = 0;
    tail_ = 0;
    count_ = 0;
}

void SerialPort::writeByte(u8 value) {
    if (count_ >= fifo_.size()) {
        return;
    }
    fifo_[head_] = value;
    head_ = (head_ + 1u) % fifo_.size();
    ++count_;
}

u8 SerialPort::readByte() {
    if (count_ == 0u) {
        return 0u;
    }
    const u8 value = fifo_[tail_];
    tail_ = (tail_ + 1u) % fifo_.size();
    --count_;
    return value;
}

bool SerialPort::hasData() const {
    return count_ != 0u;
}

}  // namespace indyemu
