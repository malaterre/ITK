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
#ifndef __itkGDCMDataSet_h
#define __itkGDCMDataSet_h

#include "itkDICOMDataSet.h"

#include <string>

namespace itk
{
class GDCMDataSetInternals;

/** \class DICOMBase
 * \brief Abstract superclass defines image DICOM interface.
 */
class ITK_EXPORT GDCMDataSet : public DICOMDataSet
{
public:
  /** Standard class typedefs. */
  typedef GDCMDataSet        Self;
  typedef Object             Superclass;
  typedef SmartPointer<Self> Pointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GDCMDataSet, Superclass);

  GDCMDataSet();
  ~GDCMDataSet();

private:
  GDCMDataSetInternals *m_Internal;

private:
  GDCMDataSet(const Self&);      //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};

} // end namespace itk

#endif // __itkGDCMDataSet_h
