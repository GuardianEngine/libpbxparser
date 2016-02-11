/*
 * libpbxparser
 * Copyright (c) 2016 Aurelien Bidon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "value.hpp"
#include <cstdint>

namespace pbx
{
	class PlistDecoder
	{
		uint64_t _index;
		std::string _str;
		
	public:
		static pbx::Dictionary parse(const std::string& str);
		
	private:
		PlistDecoder(const std::string& str);
		
		void _ignore_comment();
		void _ignore_whitespaces();
		static bool _is_whitespace(const char c);
		pbx::Dictionary _parse();
		pbx::Array _parse_array();
		void _parse_array_entry(pbx::Array& arr);
		pbx::Dictionary _parse_dictionary();
		void _parse_dictionary_entry(pbx::Dictionary& dict);
		std::string _parse_key();
		std::string _parse_literal();
		void _parse_padding();
		pbx::Value _parse_value();
	};
}