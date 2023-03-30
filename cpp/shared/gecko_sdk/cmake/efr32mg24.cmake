set(NAME "yzlite_reram_sdk_device_efr32mg24")
add_library(${NAME})
add_library(yzlite::reram_sdk::device_efr32mg24 ALIAS ${NAME})

target_include_directories(${NAME}
PUBLIC
    Include
)


target_sources(${NAME}
PRIVATE
    Source/system_efr32mg24.c
    Source/startup_efr32mg24.c
)

yzlite_get(SILABS_PART_NUMBER)
if(NOT SILABS_PART_NUMBER)
    yzlite_error("Must define variable SILABS_PART_NUMBER, e.g.: yzlite_set(SILABS_PART_NUMBER EFR32MG24A010F1536GM48)")
endif()

target_compile_options(${NAME}
PUBLIC
    -mcmse
)

target_compile_definitions(${NAME}
PUBLIC
    __START=_start
    __PROGRAM_START=_dummy
    ${SILABS_PART_NUMBER}
)


target_link_libraries(${NAME}
PRIVATE
    ${YZLITE_PLATFORM}
)