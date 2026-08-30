#include "config/indy_config.hpp"

#include <cassert>

int main() {
    const auto root = indyemu::configRoot();
    const auto prom = indyemu::embeddedPromPath();
    const auto profile = indyemu::defaultProfileToml("default");

    assert(!root.empty());
    assert(prom.filename() == "prom_embedded.bin");
    assert(profile.find("[machine]") != std::string::npos);
    assert(profile.find("ram_bytes = 134217728") != std::string::npos);
    return 0;
}
