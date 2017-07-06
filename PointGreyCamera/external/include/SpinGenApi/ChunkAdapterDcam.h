//=============================================================================
// Copyright � 2016 Point Grey Research, Inc. All Rights Reserved.
//
// This software is the confidential and proprietary information of 
// Point Grey Research, Inc. ("Confidential Information"). You shall not
// disclose such Confidential Information and shall use it only in 
// accordance with the terms of the "License Agreement" that you 
// entered into with PGR in connection with this software.
//
// UNLESS OTHERWISE SET OUT IN THE LICENSE AGREEMENT, THIS SOFTWARE IS 
// PROVIDED ON AN �AS-IS� BASIS AND POINT GREY RESEARCH INC. MAKES NO 
// REPRESENTATIONS OR WARRANTIES ABOUT THE SOFTWARE, EITHER EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY IMPLIED WARRANTIES OR 
// CONDITIONS OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR 
// NON-INFRINGEMENT. POINT GREY RESEARCH INC. SHALL NOT BE LIABLE FOR ANY 
// DAMAGES, INCLUDING BUT NOT LIMITED TO ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR ANY LOSS OF PROFITS, 
// REVENUE, DATA OR DATA USE, ARISING OUT OF OR IN CONNECTION WITH THIS 
// SOFTWARE OR OTHERWISE SUFFERED BY YOU AS A RESULT OF USING, MODIFYING 
// OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
//=============================================================================

/**
\file
\brief    Declaration of the CChunkAdapterDcam class.
\ingroup Spinnaker_GenApi_PublicUtilities
*/

#ifndef SPINNAKER_GENAPI_CHUNKADAPTERDCAM_H
#define SPINNAKER_GENAPI_CHUNKADAPTERDCAM_H

#include "GCTypes.h"
#include "ChunkAdapter.h"
#include "Compatibility.h"

namespace Spinnaker
{
	namespace GenApi
	{
 	void SPINNAKER_API SET_GUID(SPIN_GUID& name, uint32_t l, uint16_t w1, uint16_t w2, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6, uint8_t b7, uint8_t b8);

    // make sure everything is properly packed
#   pragma pack(push, 1)

		typedef struct DCAM_CHUNK_TRAILER
		{
			SPIN_GUID     ChunkID;
			uint32_t ChunkLength;
			uint32_t InverseChunkLength;
		} DCAM_CHUNK_TRAILER;

		typedef struct DCAM_CHECKSUM
		{
			uint32_t CRCChecksum;
		} DCAM_CHECKSUM;

		// restore the previous packing
#   pragma pack(pop)
		/* ------------------------------------------- */

		//! Connects a chunked DCAM buffer to a node map
		class SPINNAKER_API CChunkAdapterDcam : public  CChunkAdapter
		{

		public:
			//! Constructor
			CChunkAdapterDcam(INodeMap* pNodeMap = NULL, int64_t MaxChunkCacheSize = -1);

			//! Destructor
			virtual ~CChunkAdapterDcam();

			//! Checks if a buffer contains chunks in a known format
			virtual bool CheckBufferLayout(uint8_t *pBuffer, int64_t BufferLength);

			//! Attaches a buffer to the matching ChunkPort
			virtual void AttachBuffer(uint8_t *pBuffer, int64_t BufferLength, AttachStatistics_t *pAttachStatistics = NULL);

			//! Checks if buffer has a CRC attached
			bool HasCRC(uint8_t *pBuffer, int64_t BufferLength);

			//! Checks CRC sum of buffer
			bool CheckCRC(uint8_t *pBuffer, int64_t BufferLength);
		};
	}
}

#endif // SPINNAKER_GENAPI_CHUNKADAPTERDCAM_H
