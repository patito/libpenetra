#include <string.h>

#include <penetra/error.h>
#include <penetra/types.h>
#include <penetra/optional.h>


_u32 penetra_optional_get_magic(PenetraOptional32 *opt, _u16 *magic)
{
	if (NULL == opt) {
		return PENETRA_EINVAL;	
	}
	
	if (NULL == magic) {
		return PENETRA_EINVAL;
	}

	*magic = opt->Magic;

	return PENETRA_SUCCESS;
}

