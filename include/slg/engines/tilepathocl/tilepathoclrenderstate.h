/***************************************************************************
 * Copyright 1998-2018 by authors (see AUTHORS.txt)                        *
 *                                                                         *
 *   This file is part of LuxCoreRender.                                   *
 *                                                                         *
 * Licensed under the Apache License, Version 2.0 (the "License");         *
 * you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                 *
 *                                                                         *
 *     http://www.apache.org/licenses/LICENSE-2.0                          *
 *                                                                         *
 * Unless required by applicable law or agreed to in writing, software     *
 * distributed under the License is distributed on an "AS IS" BASIS,       *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
 * See the License for the specific language governing permissions and     *
 * limitations under the License.                                          *
 ***************************************************************************/

#ifndef _SLG_TILEPATHOCLRENDERSTATE_H
#define	_SLG_TILEPATHOCLRENDERSTATE_H

#if !defined(LUXRAYS_DISABLE_OPENCL)

#include <boost/serialization/version.hpp>
#include <boost/serialization/export.hpp>

#include "slg/slg.h"
#include "slg/renderstate.h"

namespace slg {

class TilePathOCLRenderState : public RenderState {
public:
	TilePathOCLRenderState(const u_int seed, TileRepository *tileRepository);
	virtual ~TilePathOCLRenderState();

	u_int bootStrapSeed;
	TileRepository *tileRepository;

	friend class boost::serialization::access;

private:
	// Used by serialization
	TilePathOCLRenderState() { }

	template<class Archive> void serialize(Archive &ar, const u_int version);
};

}

BOOST_CLASS_VERSION(slg::TilePathOCLRenderState, 1)

BOOST_CLASS_EXPORT_KEY(slg::TilePathOCLRenderState)

#endif

#endif	/* _SLG_TILEPATHOCLRENDERSTATE_H */
