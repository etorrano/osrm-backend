/*

Copyright (c) 2013, Project OSRM, Dennis Luxen, others
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef EXTRACTOR_CALLBACKS_H
#define EXTRACTOR_CALLBACKS_H

#include "../typedefs.h"

#include <boost/unordered_map.hpp>
#include <string>

struct ExternalMemoryNode;
class ExtractionContainers;
struct ExtractionWay;
struct InputRestrictionContainer;

class ExtractorCallbacks
{
  private:
    boost::unordered_map<std::string, NodeID> &string_map;
    ExtractionContainers &external_memory;

  public:
    ExtractorCallbacks() = delete;
    ExtractorCallbacks(const ExtractorCallbacks &) = delete;
    explicit ExtractorCallbacks(ExtractionContainers &extraction_containers,
                                boost::unordered_map<std::string, NodeID> &string_map);

    // warning: caller needs to take care of synchronization!
    void ProcessNode(const ExternalMemoryNode &node);

    // warning: caller needs to take care of synchronization!
    bool ProcessRestriction(const InputRestrictionContainer &restriction);

    // warning: caller needs to take care of synchronization!
    void ProcessWay(ExtractionWay &way);
};

#endif /* EXTRACTOR_CALLBACKS_H */
