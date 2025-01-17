/*
 *  BoardDeviceView.hpp
 *  Copyright 2021 ItJustWorksTM
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#ifndef LIBSMCE_BOARDDEVICEVIEW_HPP
#define LIBSMCE_BOARDDEVICEVIEW_HPP

#include <cstddef>
#include <string_view>
#include "SMCE/SMCE_iface.h"
#include "SMCE/fwd.hpp"
#include "SMCE_rt/internal/BoardDeviceAllocationBases.hpp"

#include "SMCE/BoardView.hpp"
#include "SMCE/internal/BoardData.hpp"
#include "SMCE/internal/BoardDeviceView.hpp"

namespace smce {

/// \internal
class SMCE_API BoardDeviceView {
    BoardData* m_bdat{};

  public:
    explicit BoardDeviceView(BoardView& bv) noexcept;

    [[nodiscard]] smce_rt::BoardDeviceAllocationPtrBases getBases(std::string_view dev_name);

    /// Object validity check
    [[nodiscard]] bool valid() noexcept { return m_bdat; }

    smce_rt::BoardDeviceAllocationPtrBases allocateMemory(smce_rt::BoardDeviceAllocationPtrBases, const auto&);
};

} // namespace smce

#endif // LIBSMCE_BOARDDEVICEVIEW_HPP
