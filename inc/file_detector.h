// Include-Gardener
//
// Copyright (C) 2018  Christian Haettich [feddischson]
//
// This program is free software; you can redistribute it
// and/or modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation;
// either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will
// be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General
// Public License along with this program; if not, see
// <http://www.gnu.org/licenses/>.
//
#ifndef FILE_DETECTOR_H
#define FILE_DETECTOR_H

#include <regex>
#include <string>
#include <vector>

namespace INCLUDE_GARDENER {

/// @brief File_Detector class
class File_Detector {
 public:
  /// @brief Ctor TODO!
  File_Detector(const std::string &file_regex,
                const std::vector<std::string> &exclude_regex,
                int recursive_limit = 0);

  /// @brief  Default copy ctor!
  File_Detector(const File_Detector &other) = default;

  /// @brief  Default assignment operator!
  File_Detector &operator=(const File_Detector &rhs) = default;

  /// @brief  Default move constructor!
  File_Detector(File_Detector &&rhs) = default;

  /// @brief  Default move assignment operator!
  File_Detector &operator=(File_Detector &&rhs) = default;

  /// @brief Default dtor
  ~File_Detector() = default;

  /// @brief Returns exlcude regex list
  std::vector<std::regex> get_exclude_regex();

  /// @brief Returns true if the file shall be considered, otherwise false.
  bool use_file(const std::string &file) const;

  /// @brief  Runs through a given file path and proceedes all include files.
  /// @return True on success, false if the path doesn't exist.
  bool walk_tree(const std::string &base_path, const std::string &sub_path = "",
                 int recursive_cnt = 0);

 private:
  /// @brief Regular expression to check if a file shall be used.
  const std::regex file_regex;

  /// @brief List of regular expressions to check if a file shall not
  ///        be used.
  const std::vector<std::regex> exclude_regex;

  /// @brief Indicates if excludes are used.
  bool use_exclude_regex;

  /// @brief Helper function to initialize the exclude_regex vector.
  std::vector<std::regex> init_exclude_regex(
      const std::vector<std::string> &exclude_regex_list);

  /// @brief Helper function to check if a file should be excluded.
  bool exclude_regex_search(std::string) const;

  /// @brief Limit for the recursive file search.
  const int recursive_limit;

};  // class File_Detector

}  // namespace INCLUDE_GARDENER

#endif  // FILE_DETECTOR_H

// vim: filetype=cpp et ts=2 sw=2 sts=2
