/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "support/StringUtils.h"

namespace antlrcpp {

void replaceAll(std::string& str, std::string const& from, std::string const& to)
{
  if (from.empty())
    return;

  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'.
  }
}

std::string ws2s(std::wstring const& wstr) {

  return std::string(wstr.begin(), wstr.end());
}

std::wstring s2ws(const std::string &str) {
 // std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
 // std::wstring wide = converter.from_bytes(str);
  
  //return wide;
 return std::wstring(str.begin(), str.end());
}

} // namespace antrlcpp
