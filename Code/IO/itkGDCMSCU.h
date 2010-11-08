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
#ifndef __itkGDCMSCU_h
#define __itkGDCMSCU_h

#include "itkDICOMSCU.h"

#include <string>

namespace itk
{
class GDCMSCUInternals;

/** \class GDCMSCU
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT GDCMSCU : public DICOMSCU
{
public:
  /** Standard class typedefs. */
  typedef GDCMSCU            Self;
  typedef DICOMSCU           Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GDCMSCU, Superclass);

  GDCMSCU();
  ~GDCMSCU();
  void PrintSelf(std::ostream & os, Indent indent) const;

  void SendEcho();

  typedef std::vector< std::string > FilenamesContainer;
  void SendStore(FilenamesContainer const & array);

  typedef std::vector< DICOMDataSet > DICOMDataSetContainer;
  DICOMDataSetContainer const & SendFind( itk::DICOMQuery const & query );

  void SendMove( DICOMDataSetContainer const & array );

private:
  GDCMSCUInternals *m_Internal;

private:
  GDCMSCU(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkGDCMSCU_h
