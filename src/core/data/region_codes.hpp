#pragma once

namespace big
{
	struct RegionType
	{
		uint32_t id;
		const char name[22];
	};

	const RegionType regions[] = {
	    {0, "CIS"},
	    {1, "Sudamérica"},
	    {2, "Este de EE.UU."},
	    {3, "Europa"},
	    {4, "China"},
	    {5, "Australia"},
	    {6, "Oeste de EE.UU."},
	    {7, "Japón"},
	    {8, "Desconocido"},
	};
}