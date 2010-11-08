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
#ifndef __itkDICOMSCU_h
#define __itkDICOMSCU_h

#include "itkLightProcessObject.h"

#include "itkDICOMDataSet.h"
#include "itkDICOMQuery.h"

#include <string>

namespace itk
{

/** \class DICOMBase
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT DICOMSCU : public Object
{
public:
  /** Standard class typedefs. */
  typedef DICOMSCU           Self;
  typedef Object             Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMSCU, Superclass);

  DICOMSCU() {}
  ~DICOMSCU() {}

  /** hostname of DICOM peer. */
  itkSetStringMacro(Peer);
  itkGetStringMacro(Peer);

  /** tcp/ip port number of peer */
  itkSetMacro(Port, unsigned int);
  itkGetMacro(Port, unsigned int);

  /** tcp/ip port number for incoming association */
  itkSetMacro(IncomingPort, unsigned int);
  itkGetMacro(IncomingPort, unsigned int);

  /** application entity titles: */
  /** set calling AE title */
  itkSetStringMacro(AETitle);
  itkGetStringMacro(AETitle);

  /** set called AE title */
  itkSetStringMacro(CalledAETitle);
  itkGetStringMacro(CalledAETitle);

  /** other network options: */

  /// timeout for connection requests.
  /// 0 => unlimited
  itkSetMacro(Timeout, unsigned int);
  itkGetMacro(Timeout, unsigned int);

  /// timeout for ACSE messages
  itkSetMacro(ACSETimeout, unsigned int);
  itkGetMacro(ACSETimeout, unsigned int);

  /// timeout for DIMSE messages
  itkSetMacro(DIMSETimeout, unsigned int);
  itkGetMacro(DIMSETimeout, unsigned int);

  /// set max receive pdu to n bytes
  itkSetMacro(MaxPDU, unsigned int);
  itkGetMacro(MaxPDU, unsigned int);

  virtual void SendEcho() = 0;

  typedef std::vector< std::string > FilenamesContainer;
  virtual void SendStore(FilenamesContainer const & array) = 0;

  typedef std::vector< DICOMDataSet > DICOMDataSetContainer;
  virtual DICOMDataSetContainer const & SendFind( itk::DICOMQuery const & query ) = 0;

  virtual void SendMove( DICOMDataSetContainer const & array ) = 0;

private:
  std::string  m_Peer;
  unsigned int m_Port;
  unsigned int m_IncomingPort;
  std::string  m_AETitle;
  std::string  m_CalledAETitle;
  unsigned int m_Timeout;
  unsigned int m_ACSETimeout;
  unsigned int m_DIMSETimeout;
  unsigned int m_MaxPDU;

private:
  DICOMSCU(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkDICOMSCU_h
