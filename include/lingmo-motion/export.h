#pragma once

#include <QtCore/qglobal.h>

#if defined(LINGMO_MOTION_LIBRARY)
#  define LINGMO_MOTION_EXPORT Q_DECL_EXPORT
#else
#  define LINGMO_MOTION_EXPORT Q_DECL_IMPORT
#endif
