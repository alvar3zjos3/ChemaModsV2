#pragma once
#include "gta/enums.hpp"

namespace big
{
	const std::map<eGameLanguage, const std::string_view> languages = {
	    {eGameLanguage::ENGLISH, "Inglés"},
	    {eGameLanguage::FRENCH, "Francés"},
	    {eGameLanguage::GERMAN, "Alemán"},
	    {eGameLanguage::ITALIAN, "Italiano"},
	    {eGameLanguage::SPANISH, "Español (España)"},
	    {eGameLanguage::BRAZILIAN_PORTUGUESE, "Portugués (Brasil)"},
	    {eGameLanguage::POLISH, "Polaco"},
	    {eGameLanguage::RUSSIAN, "Ruso"},
	    {eGameLanguage::KOREAN, "Coreano"},
	    {eGameLanguage::TRADITIONAL_CHINESE, "Chino (Tradicional)"},
	    {eGameLanguage::JAPANESE, "Japonés"},
	    {eGameLanguage::MEXICAN_SPANISH, "Español (México)"},
	    {eGameLanguage::SIMPLIFIED_CHINESE, "Chino (Simplificado)"},
	};
}
