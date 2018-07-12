/*
 * (C) Copyright 2018 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#include <mpi.h>
#include "src/GetValuesTrajFV3JEDI.h"
#include "oops/util/Logger.h"
#include "Fortran.h"
#include "eckit/config/Configuration.h"

// -----------------------------------------------------------------------------
namespace fv3jedi {
// -----------------------------------------------------------------------------
GetValuesTrajFV3JEDI::GetValuesTrajFV3JEDI() {
  oops::Log::trace() << "GetValuesTrajFV3JEDI constructor starting"
                     << std::endl;
  fv3jedi_getvaltraj_setup_f90(keyGetValuesTraj_);
  oops::Log::trace() << "GetValuesTrajFV3JEDI constructor done"
                     << keyGetValuesTraj_ << std::endl;
}
// -----------------------------------------------------------------------------
GetValuesTrajFV3JEDI::~GetValuesTrajFV3JEDI() {
  oops::Log::trace() << "GetValuesTrajFV3JEDI destructor starting"
                     << std::endl;
  fv3jedi_getvaltraj_delete_f90(keyGetValuesTraj_);
  oops::Log::trace() << "GetValuesTrajFV3JEDI destructor done" << std::endl;
}
// -----------------------------------------------------------------------------
}  // namespace fv3jedi