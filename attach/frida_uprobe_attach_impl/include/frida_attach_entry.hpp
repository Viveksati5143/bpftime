#ifndef _BPFTIME_FRIDA_ATTACH_ENTRY_HPP
#define _BPFTIME_FRIDA_ATTACH_ENTRY_HPP

#include "frida_uprobe_attach_impl.hpp"
namespace bpftime
{
namespace attach
{
// Used to represent an attach entry faced to users. It's related with a unique
// id, and holds a callback provided by the user
class frida_attach_entry {
	int self_id;
	callback_variant cb;
	void *function;

	class frida_internal_attach_entry *internal_attach;
	friend class frida_attach_impl;
	friend class frida_internal_attach_entry;

    public:
	// Get the specific attach type of this attach entry
	// Could be ATTACH_UPROBE, ATTACH_URETPROBE, ATTACH_UPROBE_OVERRIDE
	int get_type() const;
	frida_attach_entry(const frida_attach_entry &) = delete;
	frida_attach_entry &operator=(const frida_attach_entry &) = delete;
	// Create this attach entry with its id, callback function, and function address to hook
	frida_attach_entry(int id, callback_variant &&cb, void *function)
		: self_id(id), cb(cb), function(function)
	{
	}
	frida_attach_entry(frida_attach_entry &&) = default;
};
} // namespace attach
} // namespace bpftime

#endif
