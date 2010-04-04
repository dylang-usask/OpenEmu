//
// Copyright (c) 2004 K. Wilkins
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

//////////////////////////////////////////////////////////////////////////////
//                       Handy - An Atari Lynx Emulator                     //
//                          Copyright (c) 1996,1997                         //
//                                 K. Wilkins                               //
//////////////////////////////////////////////////////////////////////////////
// ROM emulation class                                                      //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// This class emulates the system ROM (512B), the interface is pretty       //
// simple: constructor, reset, peek, poke.                                  //
//                                                                          //
//    K. Wilkins                                                            //
// August 1997                                                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
// Revision History:                                                        //
// -----------------                                                        //
//                                                                          //
// 01Aug1997 KW Document header added & class documented.                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#define ROM_CPP

//#include <crtdbg.h>
//#define   TRACE_ROM

#include <string.h>
#include <errno.h>
#include "system.h"
#include "rom.h"

CRom::CRom(const char *romfile)
{
	mWriteEnable=FALSE;
	Reset();

	// Initialise ROM
	for(int loop=0;loop<ROM_SIZE;loop++) mRomData[loop]=DEFAULT_ROM_CONTENTS;

	// Load up the file

	FILE	*fp;

	if((fp=fopen(romfile,"rb"))==NULL)
	{
		std::string message;

		MDFN_PrintError("The Lynx Boot ROM image(%s) couldn't be opened: %s\n", romfile, strerror(errno));
		throw(0);
	}

	// Read in the 512 bytes

	if(fread(mRomData,sizeof(char),ROM_SIZE,fp)!=ROM_SIZE)
	{
                std::string message;

                MDFN_PrintError("The Lynx Boot ROM image(%s) couldn't be read: %s\n", romfile, strerror(errno));
                throw(0);    
	}

	fclose(fp);
}

void CRom::Reset(void)
{
	// Nothing to do here
}


//END OF FILE
