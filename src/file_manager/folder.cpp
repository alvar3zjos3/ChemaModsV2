#include "folder.hpp"

namespace big
{
	folder::folder(const std::filesystem::path& folder_path) :
	    m_folder_path(folder_path)
	{
	}

	file folder::get_file(std::filesystem::path file_path) const
	{
		if (file_path.is_absolute())
			throw std::invalid_argument("folder#get_file requiere una ruta relativa.");
		if (file_path.string().contains(".."))
			throw std::invalid_argument("No se permite el recorrido de rutas relativas, evita usar \"..\" en rutas de archivos.");

		return file(m_folder_path / file_path);
	}

	folder folder::get_folder(std::filesystem::path folder_path) const
	{
		if (folder_path.is_absolute())
			throw std::invalid_argument("folder#get_folder requiere una ruta relativa.");
		if (folder_path.string().contains(".."))
			throw std::invalid_argument("No se permite el recorrido de rutas relativas, evita usar \"..\" en rutas de archivos.");
		return folder(m_folder_path / folder_path);
	}

	const std::filesystem::path folder::get_path() const
	{
		return m_folder_path;
	}
}