/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkGDCMSCU.h"

namespace itk
{

class GDCMSCUInternals
{
public:
  GDCMSCU::DICOMDataSetContainer m_Array;
};

GDCMSCU::GDCMSCU()
{
  m_Internal = new GDCMSCUInternals;
}

GDCMSCU::~GDCMSCU()
{
  delete m_Internal;
}

void GDCMSCU::SendEcho()
{
}

void GDCMSCU::SendStore(FilenamesContainer const & array)
{
}

GDCMSCU::DICOMDataSetContainer const & GDCMSCU::SendFind( itk::DICOMQuery const & query )
{
  return m_Internal->m_Array;
}

void GDCMSCU::SendMove( DICOMDataSetContainer const & array )
{
}

void GDCMSCU::PrintSelf(std::ostream & os, Indent indent) const
{
}

} // end namespace itk
