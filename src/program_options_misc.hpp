/**
 * Metagenomics Canopy Clustering Implementation
 *
 * Copyright (C) 2013, 2014 Piotr Dworzynski (piotr@cbs.dtu.dk), Technical University of Denmark
 *
 * This file is part of Metagenomics Canopy Clustering Implementation.
 *
 * Metagenomics Canopy Clustering Implementation is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Metagenomics Canopy Clustering Implementation is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <fstream>
#include <limits>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/join.hpp>

using namespace std;

template <typename T>
bool check_if_within_bounds(string option_name, T value, T lower, T higher){
    if( value >= lower - numeric_limits<T>::epsilon() && value <= higher + numeric_limits<T>::epsilon()){
        return true;
    }else{ 
        _log(logERR) << "Option: \"" << option_name << "\" must be a value within range: <" << lower << ";" << higher << ">";
        exit(1);
    }
}

bool check_if_file_is_readable(string option_name, string path){
    ifstream file;
	file.open(path.c_str(), ios::in);
	
	if (file.good()) {
		file.close();
		return true;
	} else {
        _log(logERR) << "Option: \"" << option_name << "\" must be accessible and readable.";
        exit(1);
    }
}

bool check_if_file_is_writable(string option_name, string path){
    ofstream file;
    file.open(path.c_str(), ios::out | ios::trunc);

    if (file.good()) {
		file.close();
		return true;
	} else {
        _log(logERR) << "Option: \"" << option_name << "\" must be accessible and writable.";
        exit(1);
    }
}

bool check_if_one_of(string option_name, string value, vector<string> valid_options){
    BOOST_FOREACH(string valid_opt, valid_options){
        if( value == valid_opt){
            return true;
        }
    }
    _log(logERR) << "Option: \"" << option_name << "\" must be one of:" << boost::algorithm::join(valid_options, ", ");
    exit(1);
}
    

