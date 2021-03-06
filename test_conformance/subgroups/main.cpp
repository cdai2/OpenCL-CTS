//
// Copyright (c) 2017 The Khronos Group Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "../../test_common/harness/compat.h"

#include <stdio.h>
#include <string.h>
#include "procs.h"
#include "../../test_common/harness/testHarness.h"

MTdata gMTdata;

test_definition test_list[] = {
    ADD_TEST( sub_group_info ),
    ADD_TEST( work_item_functions ),
    ADD_TEST( work_group_functions ),
    ADD_TEST( barrier_functions ),
};

const int test_num = ARRAY_SIZE( test_list );

static test_status checkSubGroupsExtension(cl_device_id device)
{
    if (!is_extension_available(device, "cl_khr_subgroups")) {
        log_error("'cl_khr_subgroups' is a required extension, failing.\n");
        return TEST_FAIL;
    }

    return TEST_PASS;
}

int main(int argc, const char *argv[])
{
    gMTdata = init_genrand(0);
    return runTestHarnessWithCheck(argc, argv, test_num, test_list, false, false, NULL, checkSubGroupsExtension);
}

