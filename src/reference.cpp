#include "git2cpp/reference.h"

extern "C"
{
    #include <git2/refs.h>
}

namespace git
{
    Reference::~Reference()
    {
        git_reference_free(ref_);
    }

    Reference::Reference(git_reference * ref)
        : ref_(ref)
    {}

    const char * Reference::name() const
    {
        return git_reference_name(ref_);
    }

    git_ref_t Reference::type() const
    {
        return git_reference_type(ref_);
    }

    git_oid const & Reference::target() const
    {
        return *git_reference_target(ref_);
    }

    const char * Reference::symbolic_target() const
    {
        return git_reference_symbolic_target(ref_);
    }
}
