
filegroup(
    name = "all_headers",
    srcs = glob(
        include = ["*.h"],
    ),
    visibility = ["//src/main:__pkg__"],
)

cc_library(
    name = "kips_algs_lib",
    srcs = [":all_headers"],
    hdrs = ["merge_sort.h"],
    linkstatic = 1,
    visibility = ["//visibility:public"],
)

