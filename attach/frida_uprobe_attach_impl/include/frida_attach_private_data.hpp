#ifndef _BPFTIME_FRIDA_ATTACH_PRIVATE_DATA_HPP
#define _BPFTIME_FRIDA_ATTACH_PRIVATE_DATA_HPP
#include "attach_private_data.hpp"
#include <cstdint>
namespace bpftime
{
namespace attach
{
// Private data for frida uprobe attach
struct frida_attach_private_data final : public attach_private_data {
    // The address to hook
	uint64_t addr;
    // The input string should be an decimal integer in string format, indicating the function address to hook.
	int initialize_from_string(const std::string_view &sv);
};
} // namespace attach
} // namespace bpftime

#endif
