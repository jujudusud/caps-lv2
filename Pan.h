/*
	Pan.h

	Copyright 2004-11 Tim Goetze <tim@quitte.de>

	http://quitte.de/dsp/

	Panorama with width synthesis,
	stereo image width reduction

*/
/*
	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
	02111-1307, USA or point your web browser to http://www.gnu.org.
*/

#ifndef PAN_H
#define PAN_H

#include "dsp/Delay.h"
#include "dsp/IIR2.h"

class Wider
: public Plugin
{
	public:
		sample_t pan;
		sample_t width;
		sample_t gain_l, gain_r;

		DSP::IIR2<sample_t> ap[3];

		void cycle (uint frames);

		inline void set_pan (sample_t);

	public:
		static PortInfo port_info [];

		void init();
		void activate();
};

/* stereo width reduction */
class Narrower
: public Plugin
{
	public:
		sample_t strength;

		void cycle (uint frames);

	public:
		static PortInfo port_info [];

		void init() {}
		void activate() {}
};

#endif /* PAN_H */
