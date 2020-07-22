#ifndef __POLYTRACKER_H__
#define __POLYTRACKER_H__

#define POLYTRACKER_VERSION_MAJOR 2
#define POLYTRACKER_VERSION_MINOR 0
#define POLYTRACKER_VERSION_REVISION 0

// If there is a suffix, it should always start with a hypen, like "-alpha2.2".
// If there is no suffix, set POLYTRACKER_VERSION_SUFFIX to an empty string.
#define POLYTRACKER_VERSION_SUFFIX "-alpha2.2"

/**********************************************************************************/

#define PF_STR_HELPER(s) #s
#define PF_MAKE_STR(s) PF_STR_HELPER(s)

#define POLYTRACKER_VERSION                                                    \
  PF_MAKE_STR(POLYTRACKER_VERSION_MAJOR)                                       \
  "." PF_MAKE_STR(POLYTRACKER_VERSION_MINOR) "." PF_MAKE_STR(                  \
      POLYTRACKER_VERSION_REVISION)

#endif
