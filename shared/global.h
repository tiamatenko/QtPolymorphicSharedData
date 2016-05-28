/****************************************************************************
** global.h
**
** Copyright (c) 2015-2016, Korobov Sergiy.
** All rights reserved.
** Contact: Korobov Sergiy (tiamatenko@gmail.com)
**
** This file is part of the QtPolymorphicSharedData.
**
** The QtPolymorphicSharedData is free software:
** you can redistribute it and/or modify it under the terms of the
** Lesser GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** The QtPolymorphicSharedData is distributed in the hope
** that it will be useful, but WITHOUT ANY WARRANTY; without even the
** implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the Lesser GNU General Public License for more details.
**
** You should have received a copy of the Lesser GNU General Public License
** along with the QtPolymorphicSharedData.
** If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include "QtPolymorphicSharedData.h"

#ifdef USE_EXPLICIT_SHARED_DATA
typedef QtPolymorphicExplicitSharedType QtBasePolymorphicSharedType;
#else
typedef QtPolymorphicImplicitSharedType QtBasePolymorphicSharedType;
#endif

#endif // GLOBAL_H
