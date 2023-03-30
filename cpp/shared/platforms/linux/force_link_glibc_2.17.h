/**
 * For more details, refer to:
 * https://github.com/wheybags/glibc_version_header
 */
#if !defined(SET_GLIBC_LINK_VERSIONS_HEADER) && !defined(__ASSEMBLER__)
#define SET_GLIBC_LINK_VERSIONS_HEADER
__asm__(".symver _Exit,_Exit@GLIBC_2.2.5");
__asm__(".symver _IO_2_1_stderr_,_IO_2_1_stderr_@GLIBC_2.2.5");
__asm__(".symver _IO_2_1_stdin_,_IO_2_1_stdin_@GLIBC_2.2.5");
__asm__(".symver _IO_2_1_stdout_,_IO_2_1_stdout_@GLIBC_2.2.5");
__asm__(".symver _IO_adjust_column,_IO_adjust_column@GLIBC_2.2.5");
__asm__(".symver _IO_adjust_wcolumn,_IO_adjust_wcolumn@GLIBC_2.2.5");
__asm__(".symver _IO_default_doallocate,_IO_default_doallocate@GLIBC_2.2.5");
__asm__(".symver _IO_default_finish,_IO_default_finish@GLIBC_2.2.5");
__asm__(".symver _IO_default_pbackfail,_IO_default_pbackfail@GLIBC_2.2.5");
__asm__(".symver _IO_default_uflow,_IO_default_uflow@GLIBC_2.2.5");
__asm__(".symver _IO_default_xsgetn,_IO_default_xsgetn@GLIBC_2.2.5");
__asm__(".symver _IO_default_xsputn,_IO_default_xsputn@GLIBC_2.2.5");
__asm__(".symver _IO_do_write,_IO_do_write@GLIBC_2.2.5");
__asm__(".symver _IO_doallocbuf,_IO_doallocbuf@GLIBC_2.2.5");
__asm__(".symver _IO_fclose,_IO_fclose@GLIBC_2.2.5");
__asm__(".symver _IO_fdopen,_IO_fdopen@GLIBC_2.2.5");
__asm__(".symver _IO_feof,_IO_feof@GLIBC_2.2.5");
__asm__(".symver _IO_ferror,_IO_ferror@GLIBC_2.2.5");
__asm__(".symver _IO_fflush,_IO_fflush@GLIBC_2.2.5");
__asm__(".symver _IO_fgetpos,_IO_fgetpos@GLIBC_2.2.5");
__asm__(".symver _IO_fgetpos64,_IO_fgetpos64@GLIBC_2.2.5");
__asm__(".symver _IO_fgets,_IO_fgets@GLIBC_2.2.5");
__asm__(".symver _IO_file_attach,_IO_file_attach@GLIBC_2.2.5");
__asm__(".symver _IO_file_close,_IO_file_close@GLIBC_2.2.5");
__asm__(".symver _IO_file_close_it,_IO_file_close_it@GLIBC_2.2.5");
__asm__(".symver _IO_file_doallocate,_IO_file_doallocate@GLIBC_2.2.5");
__asm__(".symver _IO_file_finish,_IO_file_finish@GLIBC_2.2.5");
__asm__(".symver _IO_file_fopen,_IO_file_fopen@GLIBC_2.2.5");
__asm__(".symver _IO_file_init,_IO_file_init@GLIBC_2.2.5");
__asm__(".symver _IO_file_jumps,_IO_file_jumps@GLIBC_2.2.5");
__asm__(".symver _IO_file_open,_IO_file_open@GLIBC_2.2.5");
__asm__(".symver _IO_file_overflow,_IO_file_overflow@GLIBC_2.2.5");
__asm__(".symver _IO_file_read,_IO_file_read@GLIBC_2.2.5");
__asm__(".symver _IO_file_seek,_IO_file_seek@GLIBC_2.2.5");
__asm__(".symver _IO_file_seekoff,_IO_file_seekoff@GLIBC_2.2.5");
__asm__(".symver _IO_file_setbuf,_IO_file_setbuf@GLIBC_2.2.5");
__asm__(".symver _IO_file_stat,_IO_file_stat@GLIBC_2.2.5");
__asm__(".symver _IO_file_sync,_IO_file_sync@GLIBC_2.2.5");
__asm__(".symver _IO_file_underflow,_IO_file_underflow@GLIBC_2.2.5");
__asm__(".symver _IO_file_write,_IO_file_write@GLIBC_2.2.5");
__asm__(".symver _IO_file_xsputn,_IO_file_xsputn@GLIBC_2.2.5");
__asm__(".symver _IO_flockfile,_IO_flockfile@GLIBC_2.2.5");
__asm__(".symver _IO_flush_all,_IO_flush_all@GLIBC_2.2.5");
__asm__(".symver "
        "_IO_flush_all_linebuffered,_IO_flush_all_linebuffered@GLIBC_2.2.5");
__asm__(".symver _IO_fopen,_IO_fopen@GLIBC_2.2.5");
__asm__(".symver _IO_fprintf,_IO_fprintf@GLIBC_2.2.5");
__asm__(".symver _IO_fputs,_IO_fputs@GLIBC_2.2.5");
__asm__(".symver _IO_fread,_IO_fread@GLIBC_2.2.5");
__asm__(".symver _IO_free_backup_area,_IO_free_backup_area@GLIBC_2.2.5");
__asm__(".symver _IO_free_wbackup_area,_IO_free_wbackup_area@GLIBC_2.2.5");
__asm__(".symver _IO_fsetpos,_IO_fsetpos@GLIBC_2.2.5");
__asm__(".symver _IO_fsetpos64,_IO_fsetpos64@GLIBC_2.2.5");
__asm__(".symver _IO_ftell,_IO_ftell@GLIBC_2.2.5");
__asm__(".symver _IO_ftrylockfile,_IO_ftrylockfile@GLIBC_2.2.5");
__asm__(".symver _IO_funlockfile,_IO_funlockfile@GLIBC_2.2.5");
__asm__(".symver _IO_fwrite,_IO_fwrite@GLIBC_2.2.5");
__asm__(".symver _IO_getc,_IO_getc@GLIBC_2.2.5");
__asm__(".symver _IO_getline,_IO_getline@GLIBC_2.2.5");
__asm__(".symver _IO_getline_info,_IO_getline_info@GLIBC_2.2.5");
__asm__(".symver _IO_gets,_IO_gets@GLIBC_2.2.5");
__asm__(".symver _IO_init,_IO_init@GLIBC_2.2.5");
__asm__(".symver _IO_init_marker,_IO_init_marker@GLIBC_2.2.5");
__asm__(".symver _IO_init_wmarker,_IO_init_wmarker@GLIBC_2.2.5");
__asm__(".symver _IO_iter_begin,_IO_iter_begin@GLIBC_2.2.5");
__asm__(".symver _IO_iter_end,_IO_iter_end@GLIBC_2.2.5");
__asm__(".symver _IO_iter_file,_IO_iter_file@GLIBC_2.2.5");
__asm__(".symver _IO_iter_next,_IO_iter_next@GLIBC_2.2.5");
__asm__(".symver _IO_least_wmarker,_IO_least_wmarker@GLIBC_2.2.5");
__asm__(".symver _IO_link_in,_IO_link_in@GLIBC_2.2.5");
__asm__(".symver _IO_list_all,_IO_list_all@GLIBC_2.2.5");
__asm__(".symver _IO_list_lock,_IO_list_lock@GLIBC_2.2.5");
__asm__(".symver _IO_list_resetlock,_IO_list_resetlock@GLIBC_2.2.5");
__asm__(".symver _IO_list_unlock,_IO_list_unlock@GLIBC_2.2.5");
__asm__(".symver _IO_marker_delta,_IO_marker_delta@GLIBC_2.2.5");
__asm__(".symver _IO_marker_difference,_IO_marker_difference@GLIBC_2.2.5");
__asm__(".symver _IO_padn,_IO_padn@GLIBC_2.2.5");
__asm__(".symver _IO_peekc_locked,_IO_peekc_locked@GLIBC_2.2.5");
__asm__(".symver _IO_popen,_IO_popen@GLIBC_2.2.5");
__asm__(".symver _IO_printf,_IO_printf@GLIBC_2.2.5");
__asm__(".symver _IO_proc_close,_IO_proc_close@GLIBC_2.2.5");
__asm__(".symver _IO_proc_open,_IO_proc_open@GLIBC_2.2.5");
__asm__(".symver _IO_putc,_IO_putc@GLIBC_2.2.5");
__asm__(".symver _IO_puts,_IO_puts@GLIBC_2.2.5");
__asm__(".symver _IO_remove_marker,_IO_remove_marker@GLIBC_2.2.5");
__asm__(".symver _IO_seekmark,_IO_seekmark@GLIBC_2.2.5");
__asm__(".symver _IO_seekoff,_IO_seekoff@GLIBC_2.2.5");
__asm__(".symver _IO_seekpos,_IO_seekpos@GLIBC_2.2.5");
__asm__(".symver _IO_seekwmark,_IO_seekwmark@GLIBC_2.2.5");
__asm__(".symver _IO_setb,_IO_setb@GLIBC_2.2.5");
__asm__(".symver _IO_setbuffer,_IO_setbuffer@GLIBC_2.2.5");
__asm__(".symver _IO_setvbuf,_IO_setvbuf@GLIBC_2.2.5");
__asm__(".symver _IO_sgetn,_IO_sgetn@GLIBC_2.2.5");
__asm__(".symver _IO_sprintf,_IO_sprintf@GLIBC_2.2.5");
__asm__(".symver _IO_sputbackc,_IO_sputbackc@GLIBC_2.2.5");
__asm__(".symver _IO_sputbackwc,_IO_sputbackwc@GLIBC_2.2.5");
__asm__(".symver _IO_sscanf,_IO_sscanf@GLIBC_2.2.5");
__asm__(".symver _IO_str_init_readonly,_IO_str_init_readonly@GLIBC_2.2.5");
__asm__(".symver _IO_str_init_static,_IO_str_init_static@GLIBC_2.2.5");
__asm__(".symver _IO_str_overflow,_IO_str_overflow@GLIBC_2.2.5");
__asm__(".symver _IO_str_pbackfail,_IO_str_pbackfail@GLIBC_2.2.5");
__asm__(".symver _IO_str_seekoff,_IO_str_seekoff@GLIBC_2.2.5");
__asm__(".symver _IO_str_underflow,_IO_str_underflow@GLIBC_2.2.5");
__asm__(".symver _IO_sungetc,_IO_sungetc@GLIBC_2.2.5");
__asm__(".symver _IO_sungetwc,_IO_sungetwc@GLIBC_2.2.5");
__asm__(".symver _IO_switch_to_get_mode,_IO_switch_to_get_mode@GLIBC_2.2.5");
__asm__(
    ".symver "
    "_IO_switch_to_main_wget_area,_IO_switch_to_main_wget_area@GLIBC_2.2.5");
__asm__(".symver "
        "_IO_switch_to_wbackup_area,_IO_switch_to_wbackup_area@GLIBC_2.2.5");
__asm__(".symver _IO_switch_to_wget_mode,_IO_switch_to_wget_mode@GLIBC_2.2.5");
__asm__(".symver _IO_un_link,_IO_un_link@GLIBC_2.2.5");
__asm__(".symver _IO_ungetc,_IO_ungetc@GLIBC_2.2.5");
__asm__(".symver _IO_unsave_markers,_IO_unsave_markers@GLIBC_2.2.5");
__asm__(".symver _IO_unsave_wmarkers,_IO_unsave_wmarkers@GLIBC_2.2.5");
__asm__(".symver _IO_vfprintf,_IO_vfprintf@GLIBC_2.2.5");
__asm__(".symver _IO_vfscanf,_IO_vfscanf@GLIBC_2.2.5");
__asm__(".symver _IO_vsprintf,_IO_vsprintf@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_doallocate,_IO_wdefault_doallocate@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_finish,_IO_wdefault_finish@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_pbackfail,_IO_wdefault_pbackfail@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_uflow,_IO_wdefault_uflow@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_xsgetn,_IO_wdefault_xsgetn@GLIBC_2.2.5");
__asm__(".symver _IO_wdefault_xsputn,_IO_wdefault_xsputn@GLIBC_2.2.5");
__asm__(".symver _IO_wdo_write,_IO_wdo_write@GLIBC_2.2.5");
__asm__(".symver _IO_wdoallocbuf,_IO_wdoallocbuf@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_jumps,_IO_wfile_jumps@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_overflow,_IO_wfile_overflow@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_seekoff,_IO_wfile_seekoff@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_sync,_IO_wfile_sync@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_underflow,_IO_wfile_underflow@GLIBC_2.2.5");
__asm__(".symver _IO_wfile_xsputn,_IO_wfile_xsputn@GLIBC_2.2.5");
__asm__(".symver _IO_wmarker_delta,_IO_wmarker_delta@GLIBC_2.2.5");
__asm__(".symver _IO_wsetb,_IO_wsetb@GLIBC_2.2.5");
__asm__(".symver _LIB_VERSION,_LIB_VERSION@GLIBC_2.2.5");
__asm__(".symver __acos_finite,__acos_finite@GLIBC_2.15");
__asm__(".symver __acosf_finite,__acosf_finite@GLIBC_2.15");
__asm__(".symver __acosh_finite,__acosh_finite@GLIBC_2.15");
__asm__(".symver __acoshf_finite,__acoshf_finite@GLIBC_2.15");
__asm__(".symver __acoshl_finite,__acoshl_finite@GLIBC_2.15");
__asm__(".symver __acosl_finite,__acosl_finite@GLIBC_2.15");
__asm__(".symver __adjtimex,__adjtimex@GLIBC_2.2.5");
__asm__(".symver __after_morecore_hook,__after_morecore_hook@GLIBC_2.2.5");
__asm__(".symver __arch_prctl,__arch_prctl@GLIBC_2.2.5");
__asm__(".symver __argz_count,__argz_count@GLIBC_2.2.5");
__asm__(".symver __argz_next,__argz_next@GLIBC_2.2.5");
__asm__(".symver __argz_stringify,__argz_stringify@GLIBC_2.2.5");
__asm__(".symver __asin_finite,__asin_finite@GLIBC_2.15");
__asm__(".symver __asinf_finite,__asinf_finite@GLIBC_2.15");
__asm__(".symver __asinl_finite,__asinl_finite@GLIBC_2.15");
__asm__(".symver __asprintf,__asprintf@GLIBC_2.2.5");
__asm__(".symver __asprintf_chk,__asprintf_chk@GLIBC_2.8");
__asm__(".symver __assert,__assert@GLIBC_2.2.5");
__asm__(".symver __assert_fail,__assert_fail@GLIBC_2.2.5");
__asm__(".symver __assert_perror_fail,__assert_perror_fail@GLIBC_2.2.5");
__asm__(".symver __atan2_finite,__atan2_finite@GLIBC_2.15");
__asm__(".symver __atan2f_finite,__atan2f_finite@GLIBC_2.15");
__asm__(".symver __atan2l_finite,__atan2l_finite@GLIBC_2.15");
__asm__(".symver __atanh_finite,__atanh_finite@GLIBC_2.15");
__asm__(".symver __atanhf_finite,__atanhf_finite@GLIBC_2.15");
__asm__(".symver __atanhl_finite,__atanhl_finite@GLIBC_2.15");
__asm__(".symver __b64_ntop,__b64_ntop@GLIBC_2.2.5");
__asm__(".symver __b64_pton,__b64_pton@GLIBC_2.2.5");
__asm__(".symver __backtrace,__backtrace@GLIBC_2.2.5");
__asm__(".symver __backtrace_symbols,__backtrace_symbols@GLIBC_2.2.5");
__asm__(".symver __backtrace_symbols_fd,__backtrace_symbols_fd@GLIBC_2.2.5");
__asm__(".symver __bsd_getpgrp,__bsd_getpgrp@GLIBC_2.2.5");
__asm__(".symver __bzero,__bzero@GLIBC_2.2.5");
__asm__(".symver __check_rhosts_file,__check_rhosts_file@GLIBC_2.2.5");
__asm__(".symver __chk_fail,__chk_fail@GLIBC_2.3.4");
__asm__(".symver __clog10,__clog10@GLIBC_2.2.5");
__asm__(".symver __clog10f,__clog10f@GLIBC_2.2.5");
__asm__(".symver __clog10l,__clog10l@GLIBC_2.2.5");
__asm__(".symver __clone,__clone@GLIBC_2.2.5");
__asm__(".symver __close,__close@GLIBC_2.2.5");
__asm__(".symver __cmsg_nxthdr,__cmsg_nxthdr@GLIBC_2.2.5");
__asm__(".symver __confstr_chk,__confstr_chk@GLIBC_2.4");
__asm__(".symver __connect,__connect@GLIBC_2.2.5");
__asm__(".symver __cosh_finite,__cosh_finite@GLIBC_2.15");
__asm__(".symver __coshf_finite,__coshf_finite@GLIBC_2.15");
__asm__(".symver __coshl_finite,__coshl_finite@GLIBC_2.15");
__asm__(".symver __ctype_b_loc,__ctype_b_loc@GLIBC_2.3");
__asm__(".symver __ctype_get_mb_cur_max,__ctype_get_mb_cur_max@GLIBC_2.2.5");
__asm__(".symver __ctype_tolower_loc,__ctype_tolower_loc@GLIBC_2.3");
__asm__(".symver __ctype_toupper_loc,__ctype_toupper_loc@GLIBC_2.3");
__asm__(".symver __curbrk,__curbrk@GLIBC_2.2.5");
__asm__(".symver __cxa_at_quick_exit,__cxa_at_quick_exit@GLIBC_2.10");
__asm__(".symver __cxa_atexit,__cxa_atexit@GLIBC_2.2.5");
__asm__(".symver __cxa_finalize,__cxa_finalize@GLIBC_2.2.5");
__asm__(
    ".symver __cyg_profile_func_enter,__cyg_profile_func_enter@GLIBC_2.2.5");
__asm__(".symver __cyg_profile_func_exit,__cyg_profile_func_exit@GLIBC_2.2.5");
__asm__(".symver __daylight,__daylight@GLIBC_2.2.5");
__asm__(".symver __dcgettext,__dcgettext@GLIBC_2.2.5");
__asm__(".symver __default_morecore,__default_morecore@GLIBC_2.2.5");
__asm__(".symver __dgettext,__dgettext@GLIBC_2.2.5");
__asm__(".symver __dn_comp,__dn_comp@GLIBC_2.2.5");
__asm__(".symver __dn_count_labels,__dn_count_labels@GLIBC_2.2.5");
__asm__(".symver __dn_expand,__dn_expand@GLIBC_2.2.5");
__asm__(".symver __dn_skipname,__dn_skipname@GLIBC_2.2.5");
__asm__(".symver __dprintf_chk,__dprintf_chk@GLIBC_2.8");
__asm__(".symver __dup2,__dup2@GLIBC_2.2.5");
__asm__(".symver __duplocale,__duplocale@GLIBC_2.2.5");
__asm__(".symver __endmntent,__endmntent@GLIBC_2.2.5");
__asm__(".symver __environ,__environ@GLIBC_2.2.5");
__asm__(".symver __errno_location,__errno_location@GLIBC_2.2.5");
__asm__(".symver __exp10_finite,__exp10_finite@GLIBC_2.15");
__asm__(".symver __exp10f_finite,__exp10f_finite@GLIBC_2.15");
__asm__(".symver __exp10l_finite,__exp10l_finite@GLIBC_2.15");
__asm__(".symver __exp2_finite,__exp2_finite@GLIBC_2.15");
__asm__(".symver __exp2f_finite,__exp2f_finite@GLIBC_2.15");
__asm__(".symver __exp2l_finite,__exp2l_finite@GLIBC_2.15");
__asm__(".symver __exp_finite,__exp_finite@GLIBC_2.15");
__asm__(".symver __expf_finite,__expf_finite@GLIBC_2.15");
__asm__(".symver __expl_finite,__expl_finite@GLIBC_2.15");
__asm__(".symver __fbufsize,__fbufsize@GLIBC_2.2.5");
__asm__(".symver __fcntl,__fcntl@GLIBC_2.2.5");
__asm__(".symver __fdelt_chk,__fdelt_chk@GLIBC_2.15");
__asm__(".symver __fdelt_warn,__fdelt_warn@GLIBC_2.15");
__asm__(".symver __fentry__,__fentry__@GLIBC_2.13");
__asm__(".symver __ffs,__ffs@GLIBC_2.2.5");
__asm__(".symver __fgets_chk,__fgets_chk@GLIBC_2.4");
__asm__(".symver __fgets_unlocked_chk,__fgets_unlocked_chk@GLIBC_2.4");
__asm__(".symver __fgetws_chk,__fgetws_chk@GLIBC_2.4");
__asm__(".symver __fgetws_unlocked_chk,__fgetws_unlocked_chk@GLIBC_2.4");
__asm__(".symver __finite,__finite@GLIBC_2.2.5");
__asm__(".symver __finitef,__finitef@GLIBC_2.2.5");
__asm__(".symver __finitel,__finitel@GLIBC_2.2.5");
__asm__(".symver __flbf,__flbf@GLIBC_2.2.5");
__asm__(".symver __fmod_finite,__fmod_finite@GLIBC_2.15");
__asm__(".symver __fmodf_finite,__fmodf_finite@GLIBC_2.15");
__asm__(".symver __fmodl_finite,__fmodl_finite@GLIBC_2.15");
__asm__(".symver __fork,__fork@GLIBC_2.2.5");
__asm__(".symver __fp_nquery,__fp_nquery@GLIBC_2.2.5");
__asm__(".symver __fp_query,__fp_query@GLIBC_2.2.5");
__asm__(".symver __fp_resstat,__fp_resstat@GLIBC_2.2.5");
__asm__(".symver __fpclassify,__fpclassify@GLIBC_2.2.5");
__asm__(".symver __fpclassifyf,__fpclassifyf@GLIBC_2.2.5");
__asm__(".symver __fpclassifyl,__fpclassifyl@GLIBC_2.2.5");
__asm__(".symver __fpending,__fpending@GLIBC_2.2.5");
__asm__(".symver __fprintf_chk,__fprintf_chk@GLIBC_2.3.4");
__asm__(".symver __fpu_control,__fpu_control@GLIBC_2.2.5");
__asm__(".symver __fpurge,__fpurge@GLIBC_2.2.5");
__asm__(".symver __fread_chk,__fread_chk@GLIBC_2.7");
__asm__(".symver __fread_unlocked_chk,__fread_unlocked_chk@GLIBC_2.7");
__asm__(".symver __freadable,__freadable@GLIBC_2.2.5");
__asm__(".symver __freading,__freading@GLIBC_2.2.5");
__asm__(".symver __free_fdresult,__free_fdresult@GLIBC_2.2.5");
__asm__(".symver __free_hook,__free_hook@GLIBC_2.2.5");
__asm__(".symver __freelocale,__freelocale@GLIBC_2.2.5");
__asm__(".symver __fsetlocking,__fsetlocking@GLIBC_2.2.5");
__asm__(".symver __fwprintf_chk,__fwprintf_chk@GLIBC_2.4");
__asm__(".symver __fwritable,__fwritable@GLIBC_2.2.5");
__asm__(".symver __fwriting,__fwriting@GLIBC_2.2.5");
__asm__(".symver __fxstat,__fxstat@GLIBC_2.2.5");
__asm__(".symver __fxstat64,__fxstat64@GLIBC_2.2.5");
__asm__(".symver __fxstatat,__fxstatat@GLIBC_2.4");
__asm__(".symver __fxstatat64,__fxstatat64@GLIBC_2.4");
__asm__(".symver __gamma_r_finite,__gamma_r_finite@GLIBC_2.15");
__asm__(".symver __gammaf_r_finite,__gammaf_r_finite@GLIBC_2.15");
__asm__(".symver __gammal_r_finite,__gammal_r_finite@GLIBC_2.15");
__asm__(".symver __getauxval,__getauxval@GLIBC_2.16");
__asm__(".symver __getcwd_chk,__getcwd_chk@GLIBC_2.4");
__asm__(".symver __getdelim,__getdelim@GLIBC_2.2.5");
__asm__(".symver __getdomainname_chk,__getdomainname_chk@GLIBC_2.4");
__asm__(".symver __getgroups_chk,__getgroups_chk@GLIBC_2.4");
__asm__(".symver __gethostname_chk,__gethostname_chk@GLIBC_2.4");
__asm__(".symver __getlogin_r_chk,__getlogin_r_chk@GLIBC_2.4");
__asm__(".symver __getmntent_r,__getmntent_r@GLIBC_2.2.5");
__asm__(".symver __getpagesize,__getpagesize@GLIBC_2.2.5");
__asm__(".symver __getpgid,__getpgid@GLIBC_2.2.5");
__asm__(".symver __getpid,__getpid@GLIBC_2.2.5");
__asm__(".symver __gets_chk,__gets_chk@GLIBC_2.3.4");
__asm__(".symver __gettimeofday,__gettimeofday@GLIBC_2.2.5");
__asm__(".symver __getwd_chk,__getwd_chk@GLIBC_2.4");
__asm__(".symver __gmtime_r,__gmtime_r@GLIBC_2.2.5");
__asm__(".symver __h_errno_location,__h_errno_location@GLIBC_2.2.5");
__asm__(".symver __hostalias,__hostalias@GLIBC_2.2.5");
__asm__(".symver __hypot_finite,__hypot_finite@GLIBC_2.15");
__asm__(".symver __hypotf_finite,__hypotf_finite@GLIBC_2.15");
__asm__(".symver __hypotl_finite,__hypotl_finite@GLIBC_2.15");
__asm__(".symver __isalnum_l,__isalnum_l@GLIBC_2.2.5");
__asm__(".symver __isalpha_l,__isalpha_l@GLIBC_2.2.5");
__asm__(".symver __isascii_l,__isascii_l@GLIBC_2.2.5");
__asm__(".symver __isblank_l,__isblank_l@GLIBC_2.2.5");
__asm__(".symver __iscntrl_l,__iscntrl_l@GLIBC_2.2.5");
__asm__(".symver __isctype,__isctype@GLIBC_2.3");
__asm__(".symver __isdigit_l,__isdigit_l@GLIBC_2.2.5");
__asm__(".symver __isgraph_l,__isgraph_l@GLIBC_2.2.5");
__asm__(".symver __isinf,__isinf@GLIBC_2.2.5");
__asm__(".symver __isinff,__isinff@GLIBC_2.2.5");
__asm__(".symver __isinfl,__isinfl@GLIBC_2.2.5");
__asm__(".symver __islower_l,__islower_l@GLIBC_2.2.5");
__asm__(".symver __isnan,__isnan@GLIBC_2.2.5");
__asm__(".symver __isnanf,__isnanf@GLIBC_2.2.5");
__asm__(".symver __isnanl,__isnanl@GLIBC_2.2.5");
__asm__(".symver __isoc99_fscanf,__isoc99_fscanf@GLIBC_2.7");
__asm__(".symver __isoc99_fwscanf,__isoc99_fwscanf@GLIBC_2.7");
__asm__(".symver __isoc99_scanf,__isoc99_scanf@GLIBC_2.7");
__asm__(".symver __isoc99_sscanf,__isoc99_sscanf@GLIBC_2.7");
__asm__(".symver __isoc99_swscanf,__isoc99_swscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vfscanf,__isoc99_vfscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vfwscanf,__isoc99_vfwscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vscanf,__isoc99_vscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vsscanf,__isoc99_vsscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vswscanf,__isoc99_vswscanf@GLIBC_2.7");
__asm__(".symver __isoc99_vwscanf,__isoc99_vwscanf@GLIBC_2.7");
__asm__(".symver __isoc99_wscanf,__isoc99_wscanf@GLIBC_2.7");
__asm__(".symver __isprint_l,__isprint_l@GLIBC_2.2.5");
__asm__(".symver __ispunct_l,__ispunct_l@GLIBC_2.2.5");
__asm__(".symver __isspace_l,__isspace_l@GLIBC_2.2.5");
__asm__(".symver __isupper_l,__isupper_l@GLIBC_2.2.5");
__asm__(".symver __iswalnum_l,__iswalnum_l@GLIBC_2.2.5");
__asm__(".symver __iswalpha_l,__iswalpha_l@GLIBC_2.2.5");
__asm__(".symver __iswblank_l,__iswblank_l@GLIBC_2.2.5");
__asm__(".symver __iswcntrl_l,__iswcntrl_l@GLIBC_2.2.5");
__asm__(".symver __iswctype,__iswctype@GLIBC_2.2.5");
__asm__(".symver __iswctype_l,__iswctype_l@GLIBC_2.2.5");
__asm__(".symver __iswdigit_l,__iswdigit_l@GLIBC_2.2.5");
__asm__(".symver __iswgraph_l,__iswgraph_l@GLIBC_2.2.5");
__asm__(".symver __iswlower_l,__iswlower_l@GLIBC_2.2.5");
__asm__(".symver __iswprint_l,__iswprint_l@GLIBC_2.2.5");
__asm__(".symver __iswpunct_l,__iswpunct_l@GLIBC_2.2.5");
__asm__(".symver __iswspace_l,__iswspace_l@GLIBC_2.2.5");
__asm__(".symver __iswupper_l,__iswupper_l@GLIBC_2.2.5");
__asm__(".symver __iswxdigit_l,__iswxdigit_l@GLIBC_2.2.5");
__asm__(".symver __isxdigit_l,__isxdigit_l@GLIBC_2.2.5");
__asm__(".symver __ivaliduser,__ivaliduser@GLIBC_2.2.5");
__asm__(".symver __j0_finite,__j0_finite@GLIBC_2.15");
__asm__(".symver __j0f_finite,__j0f_finite@GLIBC_2.15");
__asm__(".symver __j0l_finite,__j0l_finite@GLIBC_2.15");
__asm__(".symver __j1_finite,__j1_finite@GLIBC_2.15");
__asm__(".symver __j1f_finite,__j1f_finite@GLIBC_2.15");
__asm__(".symver __j1l_finite,__j1l_finite@GLIBC_2.15");
__asm__(".symver __jn_finite,__jn_finite@GLIBC_2.15");
__asm__(".symver __jnf_finite,__jnf_finite@GLIBC_2.15");
__asm__(".symver __jnl_finite,__jnl_finite@GLIBC_2.15");
__asm__(
    ".symver "
    "__key_decryptsession_pk_LOCAL,__key_decryptsession_pk_LOCAL@GLIBC_2.2.5");
__asm__(
    ".symver "
    "__key_encryptsession_pk_LOCAL,__key_encryptsession_pk_LOCAL@GLIBC_2.2.5");
__asm__(".symver __key_gendes_LOCAL,__key_gendes_LOCAL@GLIBC_2.2.5");
__asm__(".symver __lgamma_r_finite,__lgamma_r_finite@GLIBC_2.15");
__asm__(".symver __lgammaf_r_finite,__lgammaf_r_finite@GLIBC_2.15");
__asm__(".symver __lgammal_r_finite,__lgammal_r_finite@GLIBC_2.15");
__asm__(".symver __libc_allocate_rtsig,__libc_allocate_rtsig@GLIBC_2.2.5");
__asm__(".symver __libc_calloc,__libc_calloc@GLIBC_2.2.5");
__asm__(".symver __libc_current_sigrtmax,__libc_current_sigrtmax@GLIBC_2.2.5");
__asm__(".symver __libc_current_sigrtmin,__libc_current_sigrtmin@GLIBC_2.2.5");
__asm__(".symver __libc_free,__libc_free@GLIBC_2.2.5");
__asm__(".symver __libc_freeres,__libc_freeres@GLIBC_2.2.5");
__asm__(".symver __libc_init_first,__libc_init_first@GLIBC_2.2.5");
__asm__(".symver __libc_mallinfo,__libc_mallinfo@GLIBC_2.2.5");
__asm__(".symver __libc_malloc,__libc_malloc@GLIBC_2.2.5");
__asm__(".symver __libc_mallopt,__libc_mallopt@GLIBC_2.2.5");
__asm__(".symver __libc_memalign,__libc_memalign@GLIBC_2.2.5");
__asm__(".symver __libc_pvalloc,__libc_pvalloc@GLIBC_2.2.5");
__asm__(".symver __libc_realloc,__libc_realloc@GLIBC_2.2.5");
__asm__(".symver __libc_sa_len,__libc_sa_len@GLIBC_2.2.5");
__asm__(".symver __libc_stack_end,__libc_stack_end@GLIBC_2.2.5");
__asm__(".symver __libc_start_main,__libc_start_main@GLIBC_2.2.5");
__asm__(".symver __libc_valloc,__libc_valloc@GLIBC_2.2.5");
__asm__(".symver __loc_aton,__loc_aton@GLIBC_2.2.5");
__asm__(".symver __loc_ntoa,__loc_ntoa@GLIBC_2.2.5");
__asm__(".symver __log10_finite,__log10_finite@GLIBC_2.15");
__asm__(".symver __log10f_finite,__log10f_finite@GLIBC_2.15");
__asm__(".symver __log10l_finite,__log10l_finite@GLIBC_2.15");
__asm__(".symver __log2_finite,__log2_finite@GLIBC_2.15");
__asm__(".symver __log2f_finite,__log2f_finite@GLIBC_2.15");
__asm__(".symver __log2l_finite,__log2l_finite@GLIBC_2.15");
__asm__(".symver __log_finite,__log_finite@GLIBC_2.15");
__asm__(".symver __logf_finite,__logf_finite@GLIBC_2.15");
__asm__(".symver __logl_finite,__logl_finite@GLIBC_2.15");
__asm__(".symver __longjmp_chk,__longjmp_chk@GLIBC_2.11");
__asm__(".symver __lseek,__lseek@GLIBC_2.2.5");
__asm__(".symver __lxstat,__lxstat@GLIBC_2.2.5");
__asm__(".symver __lxstat64,__lxstat64@GLIBC_2.2.5");
__asm__(".symver __malloc_hook,__malloc_hook@GLIBC_2.2.5");
__asm__(
    ".symver __malloc_initialize_hook,__malloc_initialize_hook@GLIBC_2.2.5");
__asm__(".symver __mbrlen,__mbrlen@GLIBC_2.2.5");
__asm__(".symver __mbrtowc,__mbrtowc@GLIBC_2.2.5");
__asm__(".symver __mbsnrtowcs_chk,__mbsnrtowcs_chk@GLIBC_2.4");
__asm__(".symver __mbsrtowcs_chk,__mbsrtowcs_chk@GLIBC_2.4");
__asm__(".symver __mbstowcs_chk,__mbstowcs_chk@GLIBC_2.4");
__asm__(".symver __memalign_hook,__memalign_hook@GLIBC_2.2.5");
__asm__(".symver __memcpy_chk,__memcpy_chk@GLIBC_2.3.4");
__asm__(".symver __memmove_chk,__memmove_chk@GLIBC_2.3.4");
__asm__(".symver __mempcpy,__mempcpy@GLIBC_2.2.5");
__asm__(".symver __mempcpy_chk,__mempcpy_chk@GLIBC_2.3.4");
__asm__(".symver __mempcpy_small,__mempcpy_small@GLIBC_2.2.5");
__asm__(".symver __memset_chk,__memset_chk@GLIBC_2.3.4");
__asm__(".symver __monstartup,__monstartup@GLIBC_2.2.5");
__asm__(".symver __morecore,__morecore@GLIBC_2.2.5");
__asm__(".symver __mq_open_2,__mq_open_2@GLIBC_2.7");
__asm__(".symver __nanosleep,__nanosleep@GLIBC_2.2.6");
__asm__(".symver __newlocale,__newlocale@GLIBC_2.2.5");
__asm__(".symver __nis_default_access,__nis_default_access@GLIBC_2.2.5");
__asm__(".symver __nis_default_group,__nis_default_group@GLIBC_2.2.5");
__asm__(".symver __nis_default_owner,__nis_default_owner@GLIBC_2.2.5");
__asm__(".symver __nis_default_ttl,__nis_default_ttl@GLIBC_2.2.5");
__asm__(".symver __nis_finddirectory,__nis_finddirectory@GLIBC_2.2.5");
__asm__(".symver __nis_hash,__nis_hash@GLIBC_2.2.5");
__asm__(".symver __nisbind_connect,__nisbind_connect@GLIBC_2.2.5");
__asm__(".symver __nisbind_create,__nisbind_create@GLIBC_2.2.5");
__asm__(".symver __nisbind_destroy,__nisbind_destroy@GLIBC_2.2.5");
__asm__(".symver __nisbind_next,__nisbind_next@GLIBC_2.2.5");
__asm__(".symver __nl_langinfo_l,__nl_langinfo_l@GLIBC_2.2.5");
__asm__(".symver __nss_configure_lookup,__nss_configure_lookup@GLIBC_2.2.5");
__asm__(".symver __nss_database_lookup,__nss_database_lookup@GLIBC_2.2.5");
__asm__(".symver __nss_group_lookup,__nss_group_lookup@GLIBC_2.2.5");
__asm__(".symver "
        "__nss_hostname_digits_dots,__nss_hostname_digits_dots@GLIBC_2.2.5");
__asm__(".symver __nss_hosts_lookup,__nss_hosts_lookup@GLIBC_2.2.5");
__asm__(".symver __nss_next,__nss_next@GLIBC_2.2.5");
__asm__(".symver __nss_passwd_lookup,__nss_passwd_lookup@GLIBC_2.2.5");
__asm__(".symver __obstack_printf_chk,__obstack_printf_chk@GLIBC_2.8");
__asm__(".symver __obstack_vprintf_chk,__obstack_vprintf_chk@GLIBC_2.8");
__asm__(".symver __open,__open@GLIBC_2.2.5");
__asm__(".symver __open64,__open64@GLIBC_2.2.5");
__asm__(".symver __open64_2,__open64_2@GLIBC_2.7");
__asm__(".symver __open_2,__open_2@GLIBC_2.7");
__asm__(".symver __openat64_2,__openat64_2@GLIBC_2.7");
__asm__(".symver __openat_2,__openat_2@GLIBC_2.7");
__asm__(".symver __overflow,__overflow@GLIBC_2.2.5");
__asm__(".symver __p_cdname,__p_cdname@GLIBC_2.2.5");
__asm__(".symver __p_cdnname,__p_cdnname@GLIBC_2.2.5");
__asm__(".symver __p_class,__p_class@GLIBC_2.2.5");
__asm__(".symver __p_class_syms,__p_class_syms@GLIBC_2.2.5");
__asm__(".symver __p_fqname,__p_fqname@GLIBC_2.2.5");
__asm__(".symver __p_fqnname,__p_fqnname@GLIBC_2.2.5");
__asm__(".symver __p_option,__p_option@GLIBC_2.2.5");
__asm__(".symver __p_query,__p_query@GLIBC_2.2.5");
__asm__(".symver __p_rcode,__p_rcode@GLIBC_2.3.2");
__asm__(".symver __p_secstodate,__p_secstodate@GLIBC_2.2.5");
__asm__(".symver __p_time,__p_time@GLIBC_2.2.5");
__asm__(".symver __p_type,__p_type@GLIBC_2.2.5");
__asm__(".symver __p_type_syms,__p_type_syms@GLIBC_2.2.5");
__asm__(".symver __pipe,__pipe@GLIBC_2.2.5");
__asm__(".symver __poll,__poll@GLIBC_2.2.5");
__asm__(".symver __poll_chk,__poll_chk@GLIBC_2.16");
__asm__(".symver __posix_getopt,__posix_getopt@GLIBC_2.10");
__asm__(".symver __pow_finite,__pow_finite@GLIBC_2.15");
__asm__(".symver __powf_finite,__powf_finite@GLIBC_2.15");
__asm__(".symver __powl_finite,__powl_finite@GLIBC_2.15");
__asm__(".symver __ppoll_chk,__ppoll_chk@GLIBC_2.16");
__asm__(".symver __pread64,__pread64@GLIBC_2.2.5");
__asm__(".symver __pread64_chk,__pread64_chk@GLIBC_2.4");
__asm__(".symver __pread_chk,__pread_chk@GLIBC_2.4");
__asm__(".symver __printf_chk,__printf_chk@GLIBC_2.3.4");
__asm__(".symver __printf_fp,__printf_fp@GLIBC_2.2.5");
__asm__(".symver __profile_frequency,__profile_frequency@GLIBC_2.2.5");
__asm__(".symver __progname,__progname@GLIBC_2.2.5");
__asm__(".symver __progname_full,__progname_full@GLIBC_2.2.5");
__asm__(
    ".symver __pthread_cleanup_routine,__pthread_cleanup_routine@GLIBC_2.3.3");
__asm__(".symver __pthread_getspecific,__pthread_getspecific@GLIBC_2.2.5");
#ifndef _GLIBCXX_SHARED
#ifndef IN_LIBGCC2
#ifdef _REENTRANT
__asm__(".symver __pthread_key_create,__pthread_key_create@GLIBC_2.2.5");
#endif
#endif
#endif
__asm__(".symver __pthread_mutex_destroy,__pthread_mutex_destroy@GLIBC_2.2.5");
__asm__(".symver __pthread_mutex_init,__pthread_mutex_init@GLIBC_2.2.5");
__asm__(".symver __pthread_mutex_lock,__pthread_mutex_lock@GLIBC_2.2.5");
__asm__(".symver __pthread_mutex_trylock,__pthread_mutex_trylock@GLIBC_2.2.5");
__asm__(".symver __pthread_mutex_unlock,__pthread_mutex_unlock@GLIBC_2.2.5");
__asm__(".symver "
        "__pthread_mutexattr_destroy,__pthread_mutexattr_destroy@GLIBC_2.2.5");
__asm__(
    ".symver __pthread_mutexattr_init,__pthread_mutexattr_init@GLIBC_2.2.5");
__asm__(".symver "
        "__pthread_mutexattr_settype,__pthread_mutexattr_settype@GLIBC_2.2.5");
__asm__(".symver __pthread_once,__pthread_once@GLIBC_2.2.5");
__asm__(
    ".symver __pthread_register_cancel,__pthread_register_cancel@GLIBC_2.3.3");
__asm__(".symver "
        "__pthread_register_cancel_defer,__pthread_register_cancel_defer@GLIBC_"
        "2.3.3");
__asm__(
    ".symver __pthread_rwlock_destroy,__pthread_rwlock_destroy@GLIBC_2.2.5");
__asm__(".symver __pthread_rwlock_init,__pthread_rwlock_init@GLIBC_2.2.5");
__asm__(".symver __pthread_rwlock_rdlock,__pthread_rwlock_rdlock@GLIBC_2.2.5");
__asm__(".symver "
        "__pthread_rwlock_tryrdlock,__pthread_rwlock_tryrdlock@GLIBC_2.2.5");
__asm__(".symver "
        "__pthread_rwlock_trywrlock,__pthread_rwlock_trywrlock@GLIBC_2.2.5");
__asm__(".symver __pthread_rwlock_unlock,__pthread_rwlock_unlock@GLIBC_2.2.5");
__asm__(".symver __pthread_rwlock_wrlock,__pthread_rwlock_wrlock@GLIBC_2.2.5");
__asm__(".symver __pthread_setspecific,__pthread_setspecific@GLIBC_2.2.5");
__asm__(".symver "
        "__pthread_unregister_cancel,__pthread_unregister_cancel@GLIBC_2.3.3");
__asm__(".symver "
        "__pthread_unregister_cancel_restore,__pthread_unregister_cancel_"
        "restore@GLIBC_2.3.3");
__asm__(".symver __pthread_unwind_next,__pthread_unwind_next@GLIBC_2.3.3");
__asm__(".symver __ptsname_r_chk,__ptsname_r_chk@GLIBC_2.4");
__asm__(".symver __putlong,__putlong@GLIBC_2.2.5");
__asm__(".symver __putshort,__putshort@GLIBC_2.2.5");
__asm__(".symver __pwrite64,__pwrite64@GLIBC_2.2.5");
__asm__(".symver __rawmemchr,__rawmemchr@GLIBC_2.2.5");
__asm__(".symver __rcmd_errstr,__rcmd_errstr@GLIBC_2.2.5");
__asm__(".symver __read,__read@GLIBC_2.2.5");
__asm__(".symver __read_chk,__read_chk@GLIBC_2.4");
__asm__(".symver __readlink_chk,__readlink_chk@GLIBC_2.4");
__asm__(".symver __readlinkat_chk,__readlinkat_chk@GLIBC_2.5");
__asm__(".symver __realloc_hook,__realloc_hook@GLIBC_2.2.5");
__asm__(".symver __realpath_chk,__realpath_chk@GLIBC_2.4");
__asm__(".symver __recv_chk,__recv_chk@GLIBC_2.4");
__asm__(".symver __recvfrom_chk,__recvfrom_chk@GLIBC_2.4");
#ifdef _REENTRANT
__asm__(".symver __register_atfork,__register_atfork@GLIBC_2.3.2");
#endif
__asm__(".symver __remainder_finite,__remainder_finite@GLIBC_2.15");
__asm__(".symver __remainderf_finite,__remainderf_finite@GLIBC_2.15");
__asm__(".symver __remainderl_finite,__remainderl_finite@GLIBC_2.15");
__asm__(".symver __res_close,__res_close@GLIBC_2.2.5");
__asm__(".symver __res_dnok,__res_dnok@GLIBC_2.2.5");
__asm__(".symver __res_hnok,__res_hnok@GLIBC_2.2.5");
__asm__(".symver __res_hostalias,__res_hostalias@GLIBC_2.2.5");
__asm__(".symver __res_init,__res_init@GLIBC_2.2.5");
__asm__(".symver __res_isourserver,__res_isourserver@GLIBC_2.2.5");
__asm__(".symver __res_mailok,__res_mailok@GLIBC_2.2.5");
__asm__(".symver __res_mkquery,__res_mkquery@GLIBC_2.2.5");
__asm__(".symver __res_nameinquery,__res_nameinquery@GLIBC_2.2.5");
__asm__(".symver __res_nclose,__res_nclose@GLIBC_2.2.5");
__asm__(".symver __res_ninit,__res_ninit@GLIBC_2.2.5");
__asm__(".symver __res_nmkquery,__res_nmkquery@GLIBC_2.2.5");
__asm__(".symver __res_nquery,__res_nquery@GLIBC_2.2.5");
__asm__(".symver __res_nquerydomain,__res_nquerydomain@GLIBC_2.2.5");
__asm__(".symver __res_nsearch,__res_nsearch@GLIBC_2.2.5");
__asm__(".symver __res_nsend,__res_nsend@GLIBC_2.2.5");
__asm__(".symver __res_ownok,__res_ownok@GLIBC_2.2.5");
__asm__(".symver __res_queriesmatch,__res_queriesmatch@GLIBC_2.2.5");
__asm__(".symver __res_query,__res_query@GLIBC_2.2.5");
__asm__(".symver __res_querydomain,__res_querydomain@GLIBC_2.2.5");
__asm__(".symver __res_randomid,__res_randomid@GLIBC_2.2.5");
__asm__(".symver __res_search,__res_search@GLIBC_2.2.5");
__asm__(".symver __res_send,__res_send@GLIBC_2.2.5");
__asm__(".symver __res_state,__res_state@GLIBC_2.2.5");
__asm__(".symver "
        "__rpc_thread_svc_max_pollfd,__rpc_thread_svc_max_pollfd@GLIBC_2.2.5");
__asm__(".symver __rpc_thread_svc_pollfd,__rpc_thread_svc_pollfd@GLIBC_2.2.5");
__asm__(".symver __sbrk,__sbrk@GLIBC_2.2.5");
__asm__(".symver __scalb_finite,__scalb_finite@GLIBC_2.15");
__asm__(".symver __scalbf_finite,__scalbf_finite@GLIBC_2.15");
__asm__(".symver __scalbl_finite,__scalbl_finite@GLIBC_2.15");
__asm__(".symver __sched_cpualloc,__sched_cpualloc@GLIBC_2.7");
__asm__(".symver __sched_cpucount,__sched_cpucount@GLIBC_2.6");
__asm__(".symver __sched_cpufree,__sched_cpufree@GLIBC_2.7");
__asm__(
    ".symver __sched_get_priority_max,__sched_get_priority_max@GLIBC_2.2.5");
__asm__(
    ".symver __sched_get_priority_min,__sched_get_priority_min@GLIBC_2.2.5");
__asm__(".symver __sched_getparam,__sched_getparam@GLIBC_2.2.5");
__asm__(".symver __sched_getscheduler,__sched_getscheduler@GLIBC_2.2.5");
__asm__(".symver __sched_setscheduler,__sched_setscheduler@GLIBC_2.2.5");
__asm__(".symver __sched_yield,__sched_yield@GLIBC_2.2.5");
__asm__(".symver __select,__select@GLIBC_2.2.5");
__asm__(".symver __send,__send@GLIBC_2.2.5");
__asm__(".symver __setmntent,__setmntent@GLIBC_2.2.5");
__asm__(".symver __setpgid,__setpgid@GLIBC_2.2.5");
__asm__(".symver __sigaction,__sigaction@GLIBC_2.2.5");
__asm__(".symver __sigaddset,__sigaddset@GLIBC_2.2.5");
__asm__(".symver __sigdelset,__sigdelset@GLIBC_2.2.5");
__asm__(".symver __sigismember,__sigismember@GLIBC_2.2.5");
__asm__(".symver __signbit,__signbit@GLIBC_2.2.5");
__asm__(".symver __signbitf,__signbitf@GLIBC_2.2.5");
__asm__(".symver __signbitl,__signbitl@GLIBC_2.2.5");
__asm__(".symver __sigpause,__sigpause@GLIBC_2.2.5");
__asm__(".symver __sigsetjmp,__sigsetjmp@GLIBC_2.2.5");
__asm__(".symver __sigsuspend,__sigsuspend@GLIBC_2.2.5");
__asm__(".symver __sinh_finite,__sinh_finite@GLIBC_2.15");
__asm__(".symver __sinhf_finite,__sinhf_finite@GLIBC_2.15");
__asm__(".symver __sinhl_finite,__sinhl_finite@GLIBC_2.15");
__asm__(".symver __snprintf_chk,__snprintf_chk@GLIBC_2.3.4");
__asm__(".symver __sprintf_chk,__sprintf_chk@GLIBC_2.3.4");
__asm__(".symver __sqrt_finite,__sqrt_finite@GLIBC_2.15");
__asm__(".symver __sqrtf_finite,__sqrtf_finite@GLIBC_2.15");
__asm__(".symver __sqrtl_finite,__sqrtl_finite@GLIBC_2.15");
__asm__(".symver __stack_chk_fail,__stack_chk_fail@GLIBC_2.4");
__asm__(".symver __statfs,__statfs@GLIBC_2.2.5");
__asm__(".symver __stpcpy,__stpcpy@GLIBC_2.2.5");
__asm__(".symver __stpcpy_chk,__stpcpy_chk@GLIBC_2.3.4");
__asm__(".symver __stpcpy_small,__stpcpy_small@GLIBC_2.2.5");
__asm__(".symver __stpncpy,__stpncpy@GLIBC_2.2.5");
__asm__(".symver __stpncpy_chk,__stpncpy_chk@GLIBC_2.4");
__asm__(".symver __strcasecmp,__strcasecmp@GLIBC_2.2.5");
__asm__(".symver __strcasecmp_l,__strcasecmp_l@GLIBC_2.2.5");
__asm__(".symver __strcasestr,__strcasestr@GLIBC_2.2.5");
__asm__(".symver __strcat_chk,__strcat_chk@GLIBC_2.3.4");
__asm__(".symver __strcoll_l,__strcoll_l@GLIBC_2.2.5");
__asm__(".symver __strcpy_chk,__strcpy_chk@GLIBC_2.3.4");
__asm__(".symver __strcpy_small,__strcpy_small@GLIBC_2.2.5");
__asm__(".symver __strcspn_c1,__strcspn_c1@GLIBC_2.2.5");
__asm__(".symver __strcspn_c2,__strcspn_c2@GLIBC_2.2.5");
__asm__(".symver __strcspn_c3,__strcspn_c3@GLIBC_2.2.5");
__asm__(".symver __strdup,__strdup@GLIBC_2.2.5");
__asm__(".symver __strerror_r,__strerror_r@GLIBC_2.2.5");
__asm__(".symver __strfmon_l,__strfmon_l@GLIBC_2.2.5");
__asm__(".symver __strftime_l,__strftime_l@GLIBC_2.3");
__asm__(".symver __strncasecmp_l,__strncasecmp_l@GLIBC_2.2.5");
__asm__(".symver __strncat_chk,__strncat_chk@GLIBC_2.3.4");
__asm__(".symver __strncpy_chk,__strncpy_chk@GLIBC_2.3.4");
__asm__(".symver __strndup,__strndup@GLIBC_2.2.5");
__asm__(".symver __strpbrk_c2,__strpbrk_c2@GLIBC_2.2.5");
__asm__(".symver __strpbrk_c3,__strpbrk_c3@GLIBC_2.2.5");
__asm__(".symver __strsep_1c,__strsep_1c@GLIBC_2.2.5");
__asm__(".symver __strsep_2c,__strsep_2c@GLIBC_2.2.5");
__asm__(".symver __strsep_3c,__strsep_3c@GLIBC_2.2.5");
__asm__(".symver __strsep_g,__strsep_g@GLIBC_2.2.5");
__asm__(".symver __strspn_c1,__strspn_c1@GLIBC_2.2.5");
__asm__(".symver __strspn_c2,__strspn_c2@GLIBC_2.2.5");
__asm__(".symver __strspn_c3,__strspn_c3@GLIBC_2.2.5");
__asm__(".symver __strtod_internal,__strtod_internal@GLIBC_2.2.5");
__asm__(".symver __strtod_l,__strtod_l@GLIBC_2.2.5");
__asm__(".symver __strtof_internal,__strtof_internal@GLIBC_2.2.5");
__asm__(".symver __strtof_l,__strtof_l@GLIBC_2.2.5");
__asm__(".symver __strtok_r,__strtok_r@GLIBC_2.2.5");
__asm__(".symver __strtok_r_1c,__strtok_r_1c@GLIBC_2.2.5");
__asm__(".symver __strtol_internal,__strtol_internal@GLIBC_2.2.5");
__asm__(".symver __strtol_l,__strtol_l@GLIBC_2.2.5");
__asm__(".symver __strtold_internal,__strtold_internal@GLIBC_2.2.5");
__asm__(".symver __strtold_l,__strtold_l@GLIBC_2.2.5");
__asm__(".symver __strtoll_internal,__strtoll_internal@GLIBC_2.2.5");
__asm__(".symver __strtoll_l,__strtoll_l@GLIBC_2.2.5");
__asm__(".symver __strtoul_internal,__strtoul_internal@GLIBC_2.2.5");
__asm__(".symver __strtoul_l,__strtoul_l@GLIBC_2.2.5");
__asm__(".symver __strtoull_internal,__strtoull_internal@GLIBC_2.2.5");
__asm__(".symver __strtoull_l,__strtoull_l@GLIBC_2.2.5");
__asm__(".symver __strverscmp,__strverscmp@GLIBC_2.2.5");
__asm__(".symver __strxfrm_l,__strxfrm_l@GLIBC_2.2.5");
__asm__(".symver __swprintf_chk,__swprintf_chk@GLIBC_2.4");
__asm__(".symver __sym_ntop,__sym_ntop@GLIBC_2.2.5");
__asm__(".symver __sym_ntos,__sym_ntos@GLIBC_2.2.5");
__asm__(".symver __sym_ston,__sym_ston@GLIBC_2.2.5");
__asm__(".symver __sysconf,__sysconf@GLIBC_2.2.5");
__asm__(".symver __sysctl,__sysctl@GLIBC_2.2.5");
__asm__(".symver __syslog_chk,__syslog_chk@GLIBC_2.4");
__asm__(".symver __sysv_signal,__sysv_signal@GLIBC_2.2.5");
__asm__(".symver __timezone,__timezone@GLIBC_2.2.5");
__asm__(".symver __tls_get_addr,__tls_get_addr@GLIBC_2.3");
__asm__(".symver __toascii_l,__toascii_l@GLIBC_2.2.5");
__asm__(".symver __tolower_l,__tolower_l@GLIBC_2.2.5");
__asm__(".symver __toupper_l,__toupper_l@GLIBC_2.2.5");
__asm__(".symver __towctrans,__towctrans@GLIBC_2.2.5");
__asm__(".symver __towctrans_l,__towctrans_l@GLIBC_2.2.5");
__asm__(".symver __towlower_l,__towlower_l@GLIBC_2.2.5");
__asm__(".symver __towupper_l,__towupper_l@GLIBC_2.2.5");
__asm__(".symver __ttyname_r_chk,__ttyname_r_chk@GLIBC_2.4");
__asm__(".symver __tzname,__tzname@GLIBC_2.2.5");
__asm__(".symver __uflow,__uflow@GLIBC_2.2.5");
__asm__(".symver __underflow,__underflow@GLIBC_2.2.5");
__asm__(".symver __uselocale,__uselocale@GLIBC_2.3");
__asm__(".symver __vasprintf_chk,__vasprintf_chk@GLIBC_2.8");
__asm__(".symver __vdprintf_chk,__vdprintf_chk@GLIBC_2.8");
__asm__(".symver __vfork,__vfork@GLIBC_2.2.5");
__asm__(".symver __vfprintf_chk,__vfprintf_chk@GLIBC_2.3.4");
__asm__(".symver __vfscanf,__vfscanf@GLIBC_2.2.5");
__asm__(".symver __vfwprintf_chk,__vfwprintf_chk@GLIBC_2.4");
__asm__(".symver __vprintf_chk,__vprintf_chk@GLIBC_2.3.4");
__asm__(".symver __vsnprintf,__vsnprintf@GLIBC_2.2.5");
__asm__(".symver __vsnprintf_chk,__vsnprintf_chk@GLIBC_2.3.4");
__asm__(".symver __vsprintf_chk,__vsprintf_chk@GLIBC_2.3.4");
__asm__(".symver __vsscanf,__vsscanf@GLIBC_2.2.5");
__asm__(".symver __vswprintf_chk,__vswprintf_chk@GLIBC_2.4");
__asm__(".symver __vsyslog_chk,__vsyslog_chk@GLIBC_2.4");
__asm__(".symver __vwprintf_chk,__vwprintf_chk@GLIBC_2.4");
__asm__(".symver __wait,__wait@GLIBC_2.2.5");
__asm__(".symver __waitpid,__waitpid@GLIBC_2.2.5");
__asm__(".symver __wcpcpy_chk,__wcpcpy_chk@GLIBC_2.4");
__asm__(".symver __wcpncpy_chk,__wcpncpy_chk@GLIBC_2.4");
__asm__(".symver __wcrtomb_chk,__wcrtomb_chk@GLIBC_2.4");
__asm__(".symver __wcscasecmp_l,__wcscasecmp_l@GLIBC_2.2.5");
__asm__(".symver __wcscat_chk,__wcscat_chk@GLIBC_2.4");
__asm__(".symver __wcscoll_l,__wcscoll_l@GLIBC_2.2.5");
__asm__(".symver __wcscpy_chk,__wcscpy_chk@GLIBC_2.4");
__asm__(".symver __wcsftime_l,__wcsftime_l@GLIBC_2.3");
__asm__(".symver __wcsncasecmp_l,__wcsncasecmp_l@GLIBC_2.2.5");
__asm__(".symver __wcsncat_chk,__wcsncat_chk@GLIBC_2.4");
__asm__(".symver __wcsncpy_chk,__wcsncpy_chk@GLIBC_2.4");
__asm__(".symver __wcsnrtombs_chk,__wcsnrtombs_chk@GLIBC_2.4");
__asm__(".symver __wcsrtombs_chk,__wcsrtombs_chk@GLIBC_2.4");
__asm__(".symver __wcstod_internal,__wcstod_internal@GLIBC_2.2.5");
__asm__(".symver __wcstod_l,__wcstod_l@GLIBC_2.2.5");
__asm__(".symver __wcstof_internal,__wcstof_internal@GLIBC_2.2.5");
__asm__(".symver __wcstof_l,__wcstof_l@GLIBC_2.2.5");
__asm__(".symver __wcstol_internal,__wcstol_internal@GLIBC_2.2.5");
__asm__(".symver __wcstol_l,__wcstol_l@GLIBC_2.2.5");
__asm__(".symver __wcstold_internal,__wcstold_internal@GLIBC_2.2.5");
__asm__(".symver __wcstold_l,__wcstold_l@GLIBC_2.2.5");
__asm__(".symver __wcstoll_internal,__wcstoll_internal@GLIBC_2.2.5");
__asm__(".symver __wcstoll_l,__wcstoll_l@GLIBC_2.2.5");
__asm__(".symver __wcstombs_chk,__wcstombs_chk@GLIBC_2.4");
__asm__(".symver __wcstoul_internal,__wcstoul_internal@GLIBC_2.2.5");
__asm__(".symver __wcstoul_l,__wcstoul_l@GLIBC_2.2.5");
__asm__(".symver __wcstoull_internal,__wcstoull_internal@GLIBC_2.2.5");
__asm__(".symver __wcstoull_l,__wcstoull_l@GLIBC_2.2.5");
__asm__(".symver __wcsxfrm_l,__wcsxfrm_l@GLIBC_2.2.5");
__asm__(".symver __wctomb_chk,__wctomb_chk@GLIBC_2.4");
__asm__(".symver __wctrans_l,__wctrans_l@GLIBC_2.2.5");
__asm__(".symver __wctype_l,__wctype_l@GLIBC_2.2.5");
__asm__(".symver __wmemcpy_chk,__wmemcpy_chk@GLIBC_2.4");
__asm__(".symver __wmemmove_chk,__wmemmove_chk@GLIBC_2.4");
__asm__(".symver __wmempcpy_chk,__wmempcpy_chk@GLIBC_2.4");
__asm__(".symver __wmemset_chk,__wmemset_chk@GLIBC_2.4");
__asm__(".symver __woverflow,__woverflow@GLIBC_2.2.5");
__asm__(".symver __wprintf_chk,__wprintf_chk@GLIBC_2.4");
__asm__(".symver __write,__write@GLIBC_2.2.5");
__asm__(".symver __wuflow,__wuflow@GLIBC_2.2.5");
__asm__(".symver __wunderflow,__wunderflow@GLIBC_2.2.5");
__asm__(".symver __xmknod,__xmknod@GLIBC_2.2.5");
__asm__(".symver __xmknodat,__xmknodat@GLIBC_2.4");
__asm__(".symver __xpg_basename,__xpg_basename@GLIBC_2.2.5");
__asm__(".symver __xpg_sigpause,__xpg_sigpause@GLIBC_2.2.5");
__asm__(".symver __xpg_strerror_r,__xpg_strerror_r@GLIBC_2.3.4");
__asm__(".symver __xstat,__xstat@GLIBC_2.2.5");
__asm__(".symver __xstat64,__xstat64@GLIBC_2.2.5");
__asm__(".symver __y0_finite,__y0_finite@GLIBC_2.15");
__asm__(".symver __y0f_finite,__y0f_finite@GLIBC_2.15");
__asm__(".symver __y0l_finite,__y0l_finite@GLIBC_2.15");
__asm__(".symver __y1_finite,__y1_finite@GLIBC_2.15");
__asm__(".symver __y1f_finite,__y1f_finite@GLIBC_2.15");
__asm__(".symver __y1l_finite,__y1l_finite@GLIBC_2.15");
__asm__(".symver __yn_finite,__yn_finite@GLIBC_2.15");
__asm__(".symver __ynf_finite,__ynf_finite@GLIBC_2.15");
__asm__(".symver __ynl_finite,__ynl_finite@GLIBC_2.15");
__asm__(".symver __yp_check,__yp_check@GLIBC_2.2.5");
__asm__(".symver _dl_mcount,_dl_mcount@GLIBC_2.2.5");
__asm__(".symver _dl_mcount_wrapper,_dl_mcount_wrapper@GLIBC_2.2.5");
__asm__(
    ".symver _dl_mcount_wrapper_check,_dl_mcount_wrapper_check@GLIBC_2.2.5");
__asm__(".symver _environ,_environ@GLIBC_2.2.5");
__asm__(".symver _exit,_exit@GLIBC_2.2.5");
__asm__(".symver _flushlbf,_flushlbf@GLIBC_2.2.5");
__asm__(".symver _gethtbyaddr,_gethtbyaddr@GLIBC_2.2.5");
__asm__(".symver _gethtbyname,_gethtbyname@GLIBC_2.2.5");
__asm__(".symver _gethtbyname2,_gethtbyname2@GLIBC_2.2.5");
__asm__(".symver _gethtent,_gethtent@GLIBC_2.2.5");
__asm__(".symver _getlong,_getlong@GLIBC_2.2.5");
__asm__(".symver _getshort,_getshort@GLIBC_2.2.5");
__asm__(".symver _libc_intl_domainname,_libc_intl_domainname@GLIBC_2.2.5");
__asm__(".symver _longjmp,_longjmp@GLIBC_2.2.5");
__asm__(".symver _mcleanup,_mcleanup@GLIBC_2.2.5");
__asm__(".symver _mcount,_mcount@GLIBC_2.2.5");
__asm__(".symver _nl_default_dirname,_nl_default_dirname@GLIBC_2.2.5");
__asm__(".symver _nl_domain_bindings,_nl_domain_bindings@GLIBC_2.2.5");
__asm__(".symver _nl_msg_cat_cntr,_nl_msg_cat_cntr@GLIBC_2.2.5");
__asm__(".symver _obstack_allocated_p,_obstack_allocated_p@GLIBC_2.2.5");
__asm__(".symver _obstack_begin,_obstack_begin@GLIBC_2.2.5");
__asm__(".symver _obstack_begin_1,_obstack_begin_1@GLIBC_2.2.5");
__asm__(".symver _obstack_free,_obstack_free@GLIBC_2.2.5");
__asm__(".symver _obstack_memory_used,_obstack_memory_used@GLIBC_2.2.5");
__asm__(".symver _obstack_newchunk,_obstack_newchunk@GLIBC_2.2.5");
__asm__(".symver _pthread_cleanup_pop,_pthread_cleanup_pop@GLIBC_2.2.5");
__asm__(
    ".symver "
    "_pthread_cleanup_pop_restore,_pthread_cleanup_pop_restore@GLIBC_2.2.5");
__asm__(".symver _pthread_cleanup_push,_pthread_cleanup_push@GLIBC_2.2.5");
__asm__(".symver "
        "_pthread_cleanup_push_defer,_pthread_cleanup_push_defer@GLIBC_2.2.5");
__asm__(".symver _r_debug,_r_debug@GLIBC_2.2.5");
__asm__(".symver _res_hconf,_res_hconf@GLIBC_2.2.5");
__asm__(".symver _res_opcodes,_res_opcodes@GLIBC_2.2.5");
__asm__(".symver _sethtent,_sethtent@GLIBC_2.2.5");
__asm__(".symver _setjmp,_setjmp@GLIBC_2.2.5");
__asm__(".symver _sys_errlist,_sys_errlist@GLIBC_2.12");
__asm__(".symver _sys_nerr,_sys_nerr@GLIBC_2.12");
__asm__(".symver _sys_siglist,_sys_siglist@GLIBC_2.3.3");
__asm__(".symver _tolower,_tolower@GLIBC_2.2.5");
__asm__(".symver _toupper,_toupper@GLIBC_2.2.5");
__asm__(".symver a64l,a64l@GLIBC_2.2.5");
__asm__(".symver abort,abort@GLIBC_2.2.5");
__asm__(".symver abs,abs@GLIBC_2.2.5");
__asm__(".symver accept,accept@GLIBC_2.2.5");
__asm__(".symver accept4,accept4@GLIBC_2.10");
__asm__(".symver access,access@GLIBC_2.2.5");
__asm__(".symver acct,acct@GLIBC_2.2.5");
__asm__(".symver acos,acos@GLIBC_2.2.5");
__asm__(".symver acosf,acosf@GLIBC_2.2.5");
__asm__(".symver acosh,acosh@GLIBC_2.2.5");
__asm__(".symver acoshf,acoshf@GLIBC_2.2.5");
__asm__(".symver acoshl,acoshl@GLIBC_2.2.5");
__asm__(".symver acosl,acosl@GLIBC_2.2.5");
__asm__(".symver addmntent,addmntent@GLIBC_2.2.5");
__asm__(".symver addseverity,addseverity@GLIBC_2.2.5");
__asm__(".symver adjtime,adjtime@GLIBC_2.2.5");
__asm__(".symver adjtimex,adjtimex@GLIBC_2.2.5");
__asm__(".symver advance,advance@GLIBC_2.2.5");
__asm__(".symver aio_cancel,aio_cancel@GLIBC_2.2.5");
__asm__(".symver aio_cancel64,aio_cancel64@GLIBC_2.2.5");
__asm__(".symver aio_error,aio_error@GLIBC_2.2.5");
__asm__(".symver aio_error64,aio_error64@GLIBC_2.2.5");
__asm__(".symver aio_fsync,aio_fsync@GLIBC_2.2.5");
__asm__(".symver aio_fsync64,aio_fsync64@GLIBC_2.2.5");
__asm__(".symver aio_init,aio_init@GLIBC_2.2.5");
__asm__(".symver aio_read,aio_read@GLIBC_2.2.5");
__asm__(".symver aio_read64,aio_read64@GLIBC_2.2.5");
__asm__(".symver aio_return,aio_return@GLIBC_2.2.5");
__asm__(".symver aio_return64,aio_return64@GLIBC_2.2.5");
__asm__(".symver aio_suspend,aio_suspend@GLIBC_2.2.5");
__asm__(".symver aio_suspend64,aio_suspend64@GLIBC_2.2.5");
__asm__(".symver aio_write,aio_write@GLIBC_2.2.5");
__asm__(".symver aio_write64,aio_write64@GLIBC_2.2.5");
__asm__(".symver alarm,alarm@GLIBC_2.2.5");
__asm__(".symver aligned_alloc,aligned_alloc@GLIBC_2.16");
__asm__(".symver alphasort,alphasort@GLIBC_2.2.5");
__asm__(".symver alphasort64,alphasort64@GLIBC_2.2.5");
__asm__(".symver arch_prctl,arch_prctl@GLIBC_2.2.5");
__asm__(".symver argp_err_exit_status,argp_err_exit_status@GLIBC_2.2.5");
__asm__(".symver argp_error,argp_error@GLIBC_2.2.5");
__asm__(".symver argp_failure,argp_failure@GLIBC_2.2.5");
__asm__(".symver argp_help,argp_help@GLIBC_2.2.5");
__asm__(".symver argp_parse,argp_parse@GLIBC_2.2.5");
__asm__(
    ".symver argp_program_bug_address,argp_program_bug_address@GLIBC_2.2.5");
__asm__(".symver argp_program_version,argp_program_version@GLIBC_2.2.5");
__asm__(
    ".symver argp_program_version_hook,argp_program_version_hook@GLIBC_2.2.5");
__asm__(".symver argp_state_help,argp_state_help@GLIBC_2.2.5");
__asm__(".symver argp_usage,argp_usage@GLIBC_2.2.5");
__asm__(".symver argz_add,argz_add@GLIBC_2.2.5");
__asm__(".symver argz_add_sep,argz_add_sep@GLIBC_2.2.5");
__asm__(".symver argz_append,argz_append@GLIBC_2.2.5");
__asm__(".symver argz_count,argz_count@GLIBC_2.2.5");
__asm__(".symver argz_create,argz_create@GLIBC_2.2.5");
__asm__(".symver argz_create_sep,argz_create_sep@GLIBC_2.2.5");
__asm__(".symver argz_delete,argz_delete@GLIBC_2.2.5");
__asm__(".symver argz_extract,argz_extract@GLIBC_2.2.5");
__asm__(".symver argz_insert,argz_insert@GLIBC_2.2.5");
__asm__(".symver argz_next,argz_next@GLIBC_2.2.5");
__asm__(".symver argz_replace,argz_replace@GLIBC_2.2.5");
__asm__(".symver argz_stringify,argz_stringify@GLIBC_2.2.5");
__asm__(".symver asctime,asctime@GLIBC_2.2.5");
__asm__(".symver asctime_r,asctime_r@GLIBC_2.2.5");
__asm__(".symver asin,asin@GLIBC_2.2.5");
__asm__(".symver asinf,asinf@GLIBC_2.2.5");
__asm__(".symver asinh,asinh@GLIBC_2.2.5");
__asm__(".symver asinhf,asinhf@GLIBC_2.2.5");
__asm__(".symver asinhl,asinhl@GLIBC_2.2.5");
__asm__(".symver asinl,asinl@GLIBC_2.2.5");
__asm__(".symver asprintf,asprintf@GLIBC_2.2.5");
__asm__(".symver atan,atan@GLIBC_2.2.5");
__asm__(".symver atan2,atan2@GLIBC_2.2.5");
__asm__(".symver atan2f,atan2f@GLIBC_2.2.5");
__asm__(".symver atan2l,atan2l@GLIBC_2.2.5");
__asm__(".symver atanf,atanf@GLIBC_2.2.5");
__asm__(".symver atanh,atanh@GLIBC_2.2.5");
__asm__(".symver atanhf,atanhf@GLIBC_2.2.5");
__asm__(".symver atanhl,atanhl@GLIBC_2.2.5");
__asm__(".symver atanl,atanl@GLIBC_2.2.5");
__asm__(".symver atof,atof@GLIBC_2.2.5");
__asm__(".symver atoi,atoi@GLIBC_2.2.5");
__asm__(".symver atol,atol@GLIBC_2.2.5");
__asm__(".symver atoll,atoll@GLIBC_2.2.5");
__asm__(".symver authdes_create,authdes_create@GLIBC_2.2.5");
__asm__(".symver authdes_pk_create,authdes_pk_create@GLIBC_2.2.5");
__asm__(".symver authunix_create_default,authunix_create_default@GLIBC_2.2.5");
__asm__(".symver backtrace,backtrace@GLIBC_2.2.5");
__asm__(".symver backtrace_symbols,backtrace_symbols@GLIBC_2.2.5");
__asm__(".symver backtrace_symbols_fd,backtrace_symbols_fd@GLIBC_2.2.5");
__asm__(".symver basename,basename@GLIBC_2.2.5");
__asm__(".symver bcmp,bcmp@GLIBC_2.2.5");
__asm__(".symver bcopy,bcopy@GLIBC_2.2.5");
__asm__(".symver bdflush,bdflush@GLIBC_2.2.5");
__asm__(".symver bind,bind@GLIBC_2.2.5");
__asm__(".symver bind_textdomain_codeset,bind_textdomain_codeset@GLIBC_2.2.5");
__asm__(".symver bindresvport,bindresvport@GLIBC_2.2.5");
__asm__(".symver bindtextdomain,bindtextdomain@GLIBC_2.2.5");
__asm__(".symver brk,brk@GLIBC_2.2.5");
__asm__(".symver bsd_signal,bsd_signal@GLIBC_2.2.5");
__asm__(".symver bsearch,bsearch@GLIBC_2.2.5");
__asm__(".symver btowc,btowc@GLIBC_2.2.5");
__asm__(".symver bzero,bzero@GLIBC_2.2.5");
__asm__(".symver c16rtomb,c16rtomb@GLIBC_2.16");
__asm__(".symver c32rtomb,c32rtomb@GLIBC_2.16");
__asm__(".symver cabs,cabs@GLIBC_2.2.5");
__asm__(".symver cabsf,cabsf@GLIBC_2.2.5");
__asm__(".symver cabsl,cabsl@GLIBC_2.2.5");
__asm__(".symver cacos,cacos@GLIBC_2.2.5");
__asm__(".symver cacosf,cacosf@GLIBC_2.2.5");
__asm__(".symver cacosh,cacosh@GLIBC_2.2.5");
__asm__(".symver cacoshf,cacoshf@GLIBC_2.2.5");
__asm__(".symver cacoshl,cacoshl@GLIBC_2.2.5");
__asm__(".symver cacosl,cacosl@GLIBC_2.2.5");
__asm__(".symver calloc,calloc@GLIBC_2.2.5");
__asm__(".symver canonicalize_file_name,canonicalize_file_name@GLIBC_2.2.5");
__asm__(".symver capget,capget@GLIBC_2.2.5");
__asm__(".symver capset,capset@GLIBC_2.2.5");
__asm__(".symver carg,carg@GLIBC_2.2.5");
__asm__(".symver cargf,cargf@GLIBC_2.2.5");
__asm__(".symver cargl,cargl@GLIBC_2.2.5");
__asm__(".symver casin,casin@GLIBC_2.2.5");
__asm__(".symver casinf,casinf@GLIBC_2.2.5");
__asm__(".symver casinh,casinh@GLIBC_2.2.5");
__asm__(".symver casinhf,casinhf@GLIBC_2.2.5");
__asm__(".symver casinhl,casinhl@GLIBC_2.2.5");
__asm__(".symver casinl,casinl@GLIBC_2.2.5");
__asm__(".symver catan,catan@GLIBC_2.2.5");
__asm__(".symver catanf,catanf@GLIBC_2.2.5");
__asm__(".symver catanh,catanh@GLIBC_2.2.5");
__asm__(".symver catanhf,catanhf@GLIBC_2.2.5");
__asm__(".symver catanhl,catanhl@GLIBC_2.2.5");
__asm__(".symver catanl,catanl@GLIBC_2.2.5");
__asm__(".symver catclose,catclose@GLIBC_2.2.5");
__asm__(".symver catgets,catgets@GLIBC_2.2.5");
__asm__(".symver catopen,catopen@GLIBC_2.2.5");
__asm__(".symver cbrt,cbrt@GLIBC_2.2.5");
__asm__(".symver cbrtf,cbrtf@GLIBC_2.2.5");
__asm__(".symver cbrtl,cbrtl@GLIBC_2.2.5");
__asm__(".symver ccos,ccos@GLIBC_2.2.5");
__asm__(".symver ccosf,ccosf@GLIBC_2.2.5");
__asm__(".symver ccosh,ccosh@GLIBC_2.2.5");
__asm__(".symver ccoshf,ccoshf@GLIBC_2.2.5");
__asm__(".symver ccoshl,ccoshl@GLIBC_2.2.5");
__asm__(".symver ccosl,ccosl@GLIBC_2.2.5");
__asm__(".symver ceil,ceil@GLIBC_2.2.5");
__asm__(".symver ceilf,ceilf@GLIBC_2.2.5");
__asm__(".symver ceill,ceill@GLIBC_2.2.5");
__asm__(".symver cexp,cexp@GLIBC_2.2.5");
__asm__(".symver cexpf,cexpf@GLIBC_2.2.5");
__asm__(".symver cexpl,cexpl@GLIBC_2.2.5");
__asm__(".symver cfgetispeed,cfgetispeed@GLIBC_2.2.5");
__asm__(".symver cfgetospeed,cfgetospeed@GLIBC_2.2.5");
__asm__(".symver cfmakeraw,cfmakeraw@GLIBC_2.2.5");
__asm__(".symver cfree,cfree@GLIBC_2.2.5");
__asm__(".symver cfsetispeed,cfsetispeed@GLIBC_2.2.5");
__asm__(".symver cfsetospeed,cfsetospeed@GLIBC_2.2.5");
__asm__(".symver cfsetspeed,cfsetspeed@GLIBC_2.2.5");
__asm__(".symver chdir,chdir@GLIBC_2.2.5");
__asm__(".symver chflags,chflags@GLIBC_2.2.5");
__asm__(".symver chmod,chmod@GLIBC_2.2.5");
__asm__(".symver chown,chown@GLIBC_2.2.5");
__asm__(".symver chroot,chroot@GLIBC_2.2.5");
__asm__(".symver cimag,cimag@GLIBC_2.2.5");
__asm__(".symver cimagf,cimagf@GLIBC_2.2.5");
__asm__(".symver cimagl,cimagl@GLIBC_2.2.5");
__asm__(".symver clearenv,clearenv@GLIBC_2.2.5");
__asm__(".symver clearerr,clearerr@GLIBC_2.2.5");
__asm__(".symver clearerr_unlocked,clearerr_unlocked@GLIBC_2.2.5");
__asm__(".symver clnt_create,clnt_create@GLIBC_2.2.5");
__asm__(".symver clnt_pcreateerror,clnt_pcreateerror@GLIBC_2.2.5");
__asm__(".symver clnt_perror,clnt_perror@GLIBC_2.2.5");
__asm__(".symver clnt_sperrno,clnt_sperrno@GLIBC_2.2.5");
__asm__(".symver clnttcp_create,clnttcp_create@GLIBC_2.2.5");
__asm__(".symver clntudp_create,clntudp_create@GLIBC_2.2.5");
__asm__(".symver clock,clock@GLIBC_2.2.5");
__asm__(".symver clock_adjtime,clock_adjtime@GLIBC_2.14");
__asm__(".symver clock_getcpuclockid,clock_getcpuclockid@GLIBC_2.17");
__asm__(".symver clock_getres,clock_getres@GLIBC_2.17");
__asm__(".symver clock_gettime,clock_gettime@GLIBC_2.17");
__asm__(".symver clock_nanosleep,clock_nanosleep@GLIBC_2.17");
__asm__(".symver clock_settime,clock_settime@GLIBC_2.17");
__asm__(".symver clog,clog@GLIBC_2.2.5");
__asm__(".symver clog10,clog10@GLIBC_2.2.5");
__asm__(".symver clog10f,clog10f@GLIBC_2.2.5");
__asm__(".symver clog10l,clog10l@GLIBC_2.2.5");
__asm__(".symver clogf,clogf@GLIBC_2.2.5");
__asm__(".symver clogl,clogl@GLIBC_2.2.5");
__asm__(".symver clone,clone@GLIBC_2.2.5");
__asm__(".symver close,close@GLIBC_2.2.5");
__asm__(".symver closedir,closedir@GLIBC_2.2.5");
__asm__(".symver closelog,closelog@GLIBC_2.2.5");
__asm__(".symver confstr,confstr@GLIBC_2.2.5");
__asm__(".symver conj,conj@GLIBC_2.2.5");
__asm__(".symver conjf,conjf@GLIBC_2.2.5");
__asm__(".symver conjl,conjl@GLIBC_2.2.5");
__asm__(".symver connect,connect@GLIBC_2.2.5");
__asm__(".symver copysign,copysign@GLIBC_2.2.5");
__asm__(".symver copysignf,copysignf@GLIBC_2.2.5");
__asm__(".symver copysignl,copysignl@GLIBC_2.2.5");
__asm__(".symver cos,cos@GLIBC_2.2.5");
__asm__(".symver cosf,cosf@GLIBC_2.2.5");
__asm__(".symver cosh,cosh@GLIBC_2.2.5");
__asm__(".symver coshf,coshf@GLIBC_2.2.5");
__asm__(".symver coshl,coshl@GLIBC_2.2.5");
__asm__(".symver cosl,cosl@GLIBC_2.2.5");
__asm__(".symver cpow,cpow@GLIBC_2.2.5");
__asm__(".symver cpowf,cpowf@GLIBC_2.2.5");
__asm__(".symver cpowl,cpowl@GLIBC_2.2.5");
__asm__(".symver cproj,cproj@GLIBC_2.2.5");
__asm__(".symver cprojf,cprojf@GLIBC_2.2.5");
__asm__(".symver cprojl,cprojl@GLIBC_2.2.5");
__asm__(".symver creal,creal@GLIBC_2.2.5");
__asm__(".symver crealf,crealf@GLIBC_2.2.5");
__asm__(".symver creall,creall@GLIBC_2.2.5");
__asm__(".symver creat,creat@GLIBC_2.2.5");
__asm__(".symver creat64,creat64@GLIBC_2.2.5");
__asm__(".symver create_module,create_module@GLIBC_2.2.5");
__asm__(".symver crypt,crypt@GLIBC_2.2.5");
__asm__(".symver crypt_r,crypt_r@GLIBC_2.2.5");
__asm__(".symver csin,csin@GLIBC_2.2.5");
__asm__(".symver csinf,csinf@GLIBC_2.2.5");
__asm__(".symver csinh,csinh@GLIBC_2.2.5");
__asm__(".symver csinhf,csinhf@GLIBC_2.2.5");
__asm__(".symver csinhl,csinhl@GLIBC_2.2.5");
__asm__(".symver csinl,csinl@GLIBC_2.2.5");
__asm__(".symver csqrt,csqrt@GLIBC_2.2.5");
__asm__(".symver csqrtf,csqrtf@GLIBC_2.2.5");
__asm__(".symver csqrtl,csqrtl@GLIBC_2.2.5");
__asm__(".symver ctan,ctan@GLIBC_2.2.5");
__asm__(".symver ctanf,ctanf@GLIBC_2.2.5");
__asm__(".symver ctanh,ctanh@GLIBC_2.2.5");
__asm__(".symver ctanhf,ctanhf@GLIBC_2.2.5");
__asm__(".symver ctanhl,ctanhl@GLIBC_2.2.5");
__asm__(".symver ctanl,ctanl@GLIBC_2.2.5");
__asm__(".symver ctermid,ctermid@GLIBC_2.2.5");
__asm__(".symver ctime,ctime@GLIBC_2.2.5");
__asm__(".symver ctime_r,ctime_r@GLIBC_2.2.5");
__asm__(".symver cuserid,cuserid@GLIBC_2.2.5");
__asm__(".symver daemon,daemon@GLIBC_2.2.5");
__asm__(".symver daylight,daylight@GLIBC_2.2.5");
__asm__(".symver dcgettext,dcgettext@GLIBC_2.2.5");
__asm__(".symver dcngettext,dcngettext@GLIBC_2.2.5");
__asm__(".symver delete_module,delete_module@GLIBC_2.2.5");
__asm__(".symver dgettext,dgettext@GLIBC_2.2.5");
__asm__(".symver difftime,difftime@GLIBC_2.2.5");
__asm__(".symver dirfd,dirfd@GLIBC_2.2.5");
__asm__(".symver dirname,dirname@GLIBC_2.2.5");
__asm__(".symver div,div@GLIBC_2.2.5");
__asm__(".symver dl_iterate_phdr,dl_iterate_phdr@GLIBC_2.2.5");
__asm__(".symver dladdr,dladdr@GLIBC_2.2.5");
__asm__(".symver dladdr1,dladdr1@GLIBC_2.3.3");
__asm__(".symver dlclose,dlclose@GLIBC_2.2.5");
__asm__(".symver dlerror,dlerror@GLIBC_2.2.5");
__asm__(".symver dlinfo,dlinfo@GLIBC_2.3.3");
__asm__(".symver dlmopen,dlmopen@GLIBC_2.3.4");
__asm__(".symver dlopen,dlopen@GLIBC_2.2.5");
__asm__(".symver dlsym,dlsym@GLIBC_2.2.5");
__asm__(".symver dlvsym,dlvsym@GLIBC_2.2.5");
__asm__(".symver dngettext,dngettext@GLIBC_2.2.5");
__asm__(".symver dprintf,dprintf@GLIBC_2.2.5");
__asm__(".symver drand48,drand48@GLIBC_2.2.5");
__asm__(".symver drand48_r,drand48_r@GLIBC_2.2.5");
__asm__(".symver drem,drem@GLIBC_2.2.5");
__asm__(".symver dremf,dremf@GLIBC_2.2.5");
__asm__(".symver dreml,dreml@GLIBC_2.2.5");
__asm__(".symver dup,dup@GLIBC_2.2.5");
__asm__(".symver dup2,dup2@GLIBC_2.2.5");
__asm__(".symver dup3,dup3@GLIBC_2.9");
__asm__(".symver duplocale,duplocale@GLIBC_2.3");
__asm__(".symver dysize,dysize@GLIBC_2.2.5");
__asm__(".symver eaccess,eaccess@GLIBC_2.4");
__asm__(".symver ecvt,ecvt@GLIBC_2.2.5");
__asm__(".symver ecvt_r,ecvt_r@GLIBC_2.2.5");
__asm__(".symver encrypt,encrypt@GLIBC_2.2.5");
__asm__(".symver encrypt_r,encrypt_r@GLIBC_2.2.5");
__asm__(".symver endaliasent,endaliasent@GLIBC_2.2.5");
__asm__(".symver endfsent,endfsent@GLIBC_2.2.5");
__asm__(".symver endgrent,endgrent@GLIBC_2.2.5");
__asm__(".symver endhostent,endhostent@GLIBC_2.2.5");
__asm__(".symver endmntent,endmntent@GLIBC_2.2.5");
__asm__(".symver endnetent,endnetent@GLIBC_2.2.5");
__asm__(".symver endnetgrent,endnetgrent@GLIBC_2.2.5");
__asm__(".symver endprotoent,endprotoent@GLIBC_2.2.5");
__asm__(".symver endpwent,endpwent@GLIBC_2.2.5");
__asm__(".symver endrpcent,endrpcent@GLIBC_2.2.5");
__asm__(".symver endservent,endservent@GLIBC_2.2.5");
__asm__(".symver endsgent,endsgent@GLIBC_2.10");
__asm__(".symver endspent,endspent@GLIBC_2.2.5");
__asm__(".symver endttyent,endttyent@GLIBC_2.2.5");
__asm__(".symver endusershell,endusershell@GLIBC_2.2.5");
__asm__(".symver endutent,endutent@GLIBC_2.2.5");
__asm__(".symver endutxent,endutxent@GLIBC_2.2.5");
__asm__(".symver environ,environ@GLIBC_2.2.5");
__asm__(".symver envz_add,envz_add@GLIBC_2.2.5");
__asm__(".symver envz_entry,envz_entry@GLIBC_2.2.5");
__asm__(".symver envz_get,envz_get@GLIBC_2.2.5");
__asm__(".symver envz_merge,envz_merge@GLIBC_2.2.5");
__asm__(".symver envz_remove,envz_remove@GLIBC_2.2.5");
__asm__(".symver envz_strip,envz_strip@GLIBC_2.2.5");
__asm__(".symver epoll_create,epoll_create@GLIBC_2.3.2");
__asm__(".symver epoll_create1,epoll_create1@GLIBC_2.9");
__asm__(".symver epoll_ctl,epoll_ctl@GLIBC_2.3.2");
__asm__(".symver epoll_pwait,epoll_pwait@GLIBC_2.6");
__asm__(".symver epoll_wait,epoll_wait@GLIBC_2.3.2");
__asm__(".symver erand48,erand48@GLIBC_2.2.5");
__asm__(".symver erand48_r,erand48_r@GLIBC_2.2.5");
__asm__(".symver erf,erf@GLIBC_2.2.5");
__asm__(".symver erfc,erfc@GLIBC_2.2.5");
__asm__(".symver erfcf,erfcf@GLIBC_2.2.5");
__asm__(".symver erfcl,erfcl@GLIBC_2.2.5");
__asm__(".symver erff,erff@GLIBC_2.2.5");
__asm__(".symver erfl,erfl@GLIBC_2.2.5");
__asm__(".symver err,err@GLIBC_2.2.5");
__asm__(".symver error,error@GLIBC_2.2.5");
__asm__(".symver error_at_line,error_at_line@GLIBC_2.2.5");
__asm__(".symver error_message_count,error_message_count@GLIBC_2.2.5");
__asm__(".symver error_one_per_line,error_one_per_line@GLIBC_2.2.5");
__asm__(".symver error_print_progname,error_print_progname@GLIBC_2.2.5");
__asm__(".symver errx,errx@GLIBC_2.2.5");
__asm__(".symver ether_aton,ether_aton@GLIBC_2.2.5");
__asm__(".symver ether_aton_r,ether_aton_r@GLIBC_2.2.5");
__asm__(".symver ether_hostton,ether_hostton@GLIBC_2.2.5");
__asm__(".symver ether_line,ether_line@GLIBC_2.2.5");
__asm__(".symver ether_ntoa,ether_ntoa@GLIBC_2.2.5");
__asm__(".symver ether_ntoa_r,ether_ntoa_r@GLIBC_2.2.5");
__asm__(".symver ether_ntohost,ether_ntohost@GLIBC_2.2.5");
__asm__(".symver euidaccess,euidaccess@GLIBC_2.2.5");
__asm__(".symver eventfd,eventfd@GLIBC_2.7");
__asm__(".symver eventfd_read,eventfd_read@GLIBC_2.7");
__asm__(".symver eventfd_write,eventfd_write@GLIBC_2.7");
__asm__(".symver execl,execl@GLIBC_2.2.5");
__asm__(".symver execle,execle@GLIBC_2.2.5");
__asm__(".symver execlp,execlp@GLIBC_2.2.5");
__asm__(".symver execv,execv@GLIBC_2.2.5");
__asm__(".symver execve,execve@GLIBC_2.2.5");
__asm__(".symver execvp,execvp@GLIBC_2.2.5");
__asm__(".symver execvpe,execvpe@GLIBC_2.11");
__asm__(".symver exit,exit@GLIBC_2.2.5");
__asm__(".symver exp,exp@GLIBC_2.2.5");
__asm__(".symver exp10,exp10@GLIBC_2.2.5");
__asm__(".symver exp10f,exp10f@GLIBC_2.2.5");
__asm__(".symver exp10l,exp10l@GLIBC_2.2.5");
__asm__(".symver exp2,exp2@GLIBC_2.2.5");
__asm__(".symver exp2f,exp2f@GLIBC_2.2.5");
__asm__(".symver exp2l,exp2l@GLIBC_2.2.5");
__asm__(".symver expf,expf@GLIBC_2.2.5");
__asm__(".symver expl,expl@GLIBC_2.2.5");
__asm__(".symver expm1,expm1@GLIBC_2.2.5");
__asm__(".symver expm1f,expm1f@GLIBC_2.2.5");
__asm__(".symver expm1l,expm1l@GLIBC_2.2.5");
__asm__(".symver fabs,fabs@GLIBC_2.2.5");
__asm__(".symver fabsf,fabsf@GLIBC_2.2.5");
__asm__(".symver fabsl,fabsl@GLIBC_2.2.5");
__asm__(".symver faccessat,faccessat@GLIBC_2.4");
__asm__(".symver fallocate,fallocate@GLIBC_2.10");
__asm__(".symver fallocate64,fallocate64@GLIBC_2.10");
__asm__(".symver fanotify_init,fanotify_init@GLIBC_2.13");
__asm__(".symver fanotify_mark,fanotify_mark@GLIBC_2.13");
__asm__(".symver fattach,fattach@GLIBC_2.2.5");
__asm__(".symver fchdir,fchdir@GLIBC_2.2.5");
__asm__(".symver fchflags,fchflags@GLIBC_2.2.5");
__asm__(".symver fchmod,fchmod@GLIBC_2.2.5");
__asm__(".symver fchmodat,fchmodat@GLIBC_2.4");
__asm__(".symver fchown,fchown@GLIBC_2.2.5");
__asm__(".symver fchownat,fchownat@GLIBC_2.4");
__asm__(".symver fclose,fclose@GLIBC_2.2.5");
__asm__(".symver fcloseall,fcloseall@GLIBC_2.2.5");
__asm__(".symver fcntl,fcntl@GLIBC_2.2.5");
__asm__(".symver fcrypt,fcrypt@GLIBC_2.2.5");
__asm__(".symver fcvt,fcvt@GLIBC_2.2.5");
__asm__(".symver fcvt_r,fcvt_r@GLIBC_2.2.5");
__asm__(".symver fdatasync,fdatasync@GLIBC_2.2.5");
__asm__(".symver fdetach,fdetach@GLIBC_2.2.5");
__asm__(".symver fdim,fdim@GLIBC_2.2.5");
__asm__(".symver fdimf,fdimf@GLIBC_2.2.5");
__asm__(".symver fdiml,fdiml@GLIBC_2.2.5");
__asm__(".symver fdopen,fdopen@GLIBC_2.2.5");
__asm__(".symver fdopendir,fdopendir@GLIBC_2.4");
__asm__(".symver feclearexcept,feclearexcept@GLIBC_2.2.5");
__asm__(".symver fedisableexcept,fedisableexcept@GLIBC_2.2.5");
__asm__(".symver feenableexcept,feenableexcept@GLIBC_2.2.5");
__asm__(".symver fegetenv,fegetenv@GLIBC_2.2.5");
__asm__(".symver fegetexcept,fegetexcept@GLIBC_2.2.5");
__asm__(".symver fegetexceptflag,fegetexceptflag@GLIBC_2.2.5");
__asm__(".symver fegetround,fegetround@GLIBC_2.2.5");
__asm__(".symver feholdexcept,feholdexcept@GLIBC_2.2.5");
__asm__(".symver feof,feof@GLIBC_2.2.5");
__asm__(".symver feof_unlocked,feof_unlocked@GLIBC_2.2.5");
__asm__(".symver feraiseexcept,feraiseexcept@GLIBC_2.2.5");
__asm__(".symver ferror,ferror@GLIBC_2.2.5");
__asm__(".symver ferror_unlocked,ferror_unlocked@GLIBC_2.2.5");
__asm__(".symver fesetenv,fesetenv@GLIBC_2.2.5");
__asm__(".symver fesetexceptflag,fesetexceptflag@GLIBC_2.2.5");
__asm__(".symver fesetround,fesetround@GLIBC_2.2.5");
__asm__(".symver fetestexcept,fetestexcept@GLIBC_2.2.5");
__asm__(".symver feupdateenv,feupdateenv@GLIBC_2.2.5");
__asm__(".symver fexecve,fexecve@GLIBC_2.2.5");
__asm__(".symver fflush,fflush@GLIBC_2.2.5");
__asm__(".symver fflush_unlocked,fflush_unlocked@GLIBC_2.2.5");
__asm__(".symver ffs,ffs@GLIBC_2.2.5");
__asm__(".symver ffsl,ffsl@GLIBC_2.2.5");
__asm__(".symver ffsll,ffsll@GLIBC_2.2.5");
__asm__(".symver fgetc,fgetc@GLIBC_2.2.5");
__asm__(".symver fgetc_unlocked,fgetc_unlocked@GLIBC_2.2.5");
__asm__(".symver fgetgrent,fgetgrent@GLIBC_2.2.5");
__asm__(".symver fgetgrent_r,fgetgrent_r@GLIBC_2.2.5");
__asm__(".symver fgetpos,fgetpos@GLIBC_2.2.5");
__asm__(".symver fgetpos64,fgetpos64@GLIBC_2.2.5");
__asm__(".symver fgetpwent,fgetpwent@GLIBC_2.2.5");
__asm__(".symver fgetpwent_r,fgetpwent_r@GLIBC_2.2.5");
__asm__(".symver fgets,fgets@GLIBC_2.2.5");
__asm__(".symver fgets_unlocked,fgets_unlocked@GLIBC_2.2.5");
__asm__(".symver fgetsgent,fgetsgent@GLIBC_2.10");
__asm__(".symver fgetsgent_r,fgetsgent_r@GLIBC_2.10");
__asm__(".symver fgetspent,fgetspent@GLIBC_2.2.5");
__asm__(".symver fgetspent_r,fgetspent_r@GLIBC_2.2.5");
__asm__(".symver fgetwc,fgetwc@GLIBC_2.2.5");
__asm__(".symver fgetwc_unlocked,fgetwc_unlocked@GLIBC_2.2.5");
__asm__(".symver fgetws,fgetws@GLIBC_2.2.5");
__asm__(".symver fgetws_unlocked,fgetws_unlocked@GLIBC_2.2.5");
__asm__(".symver fgetxattr,fgetxattr@GLIBC_2.3");
__asm__(".symver fileno,fileno@GLIBC_2.2.5");
__asm__(".symver fileno_unlocked,fileno_unlocked@GLIBC_2.2.5");
__asm__(".symver finite,finite@GLIBC_2.2.5");
__asm__(".symver finitef,finitef@GLIBC_2.2.5");
__asm__(".symver finitel,finitel@GLIBC_2.2.5");
__asm__(".symver flistxattr,flistxattr@GLIBC_2.3");
__asm__(".symver flock,flock@GLIBC_2.2.5");
__asm__(".symver flockfile,flockfile@GLIBC_2.2.5");
__asm__(".symver floor,floor@GLIBC_2.2.5");
__asm__(".symver floorf,floorf@GLIBC_2.2.5");
__asm__(".symver floorl,floorl@GLIBC_2.2.5");
__asm__(".symver fma,fma@GLIBC_2.2.5");
__asm__(".symver fmaf,fmaf@GLIBC_2.2.5");
__asm__(".symver fmal,fmal@GLIBC_2.2.5");
__asm__(".symver fmax,fmax@GLIBC_2.2.5");
__asm__(".symver fmaxf,fmaxf@GLIBC_2.2.5");
__asm__(".symver fmaxl,fmaxl@GLIBC_2.2.5");
__asm__(".symver fmemopen,fmemopen@GLIBC_2.2.5");
__asm__(".symver fmin,fmin@GLIBC_2.2.5");
__asm__(".symver fminf,fminf@GLIBC_2.2.5");
__asm__(".symver fminl,fminl@GLIBC_2.2.5");
__asm__(".symver fmod,fmod@GLIBC_2.2.5");
__asm__(".symver fmodf,fmodf@GLIBC_2.2.5");
__asm__(".symver fmodl,fmodl@GLIBC_2.2.5");
__asm__(".symver fmtmsg,fmtmsg@GLIBC_2.2.5");
__asm__(".symver fnmatch,fnmatch@GLIBC_2.2.5");
__asm__(".symver fopen,fopen@GLIBC_2.2.5");
__asm__(".symver fopen64,fopen64@GLIBC_2.2.5");
__asm__(".symver fopencookie,fopencookie@GLIBC_2.2.5");
__asm__(".symver fork,fork@GLIBC_2.2.5");
__asm__(".symver forkpty,forkpty@GLIBC_2.2.5");
__asm__(".symver fpathconf,fpathconf@GLIBC_2.2.5");
__asm__(".symver fprintf,fprintf@GLIBC_2.2.5");
__asm__(".symver fputc,fputc@GLIBC_2.2.5");
__asm__(".symver fputc_unlocked,fputc_unlocked@GLIBC_2.2.5");
__asm__(".symver fputs,fputs@GLIBC_2.2.5");
__asm__(".symver fputs_unlocked,fputs_unlocked@GLIBC_2.2.5");
__asm__(".symver fputwc,fputwc@GLIBC_2.2.5");
__asm__(".symver fputwc_unlocked,fputwc_unlocked@GLIBC_2.2.5");
__asm__(".symver fputws,fputws@GLIBC_2.2.5");
__asm__(".symver fputws_unlocked,fputws_unlocked@GLIBC_2.2.5");
__asm__(".symver fread,fread@GLIBC_2.2.5");
__asm__(".symver fread_unlocked,fread_unlocked@GLIBC_2.2.5");
__asm__(".symver free,free@GLIBC_2.2.5");
__asm__(".symver freeaddrinfo,freeaddrinfo@GLIBC_2.2.5");
__asm__(".symver freeifaddrs,freeifaddrs@GLIBC_2.3");
__asm__(".symver freelocale,freelocale@GLIBC_2.3");
__asm__(".symver fremovexattr,fremovexattr@GLIBC_2.3");
__asm__(".symver freopen,freopen@GLIBC_2.2.5");
__asm__(".symver freopen64,freopen64@GLIBC_2.2.5");
__asm__(".symver frexp,frexp@GLIBC_2.2.5");
__asm__(".symver frexpf,frexpf@GLIBC_2.2.5");
__asm__(".symver frexpl,frexpl@GLIBC_2.2.5");
__asm__(".symver fscanf,fscanf@GLIBC_2.2.5");
__asm__(".symver fseek,fseek@GLIBC_2.2.5");
__asm__(".symver fseeko,fseeko@GLIBC_2.2.5");
__asm__(".symver fseeko64,fseeko64@GLIBC_2.2.5");
__asm__(".symver fsetpos,fsetpos@GLIBC_2.2.5");
__asm__(".symver fsetpos64,fsetpos64@GLIBC_2.2.5");
__asm__(".symver fsetxattr,fsetxattr@GLIBC_2.3");
__asm__(".symver fstatfs,fstatfs@GLIBC_2.2.5");
__asm__(".symver fstatfs64,fstatfs64@GLIBC_2.2.5");
__asm__(".symver fstatvfs,fstatvfs@GLIBC_2.2.5");
__asm__(".symver fstatvfs64,fstatvfs64@GLIBC_2.2.5");
__asm__(".symver fsync,fsync@GLIBC_2.2.5");
__asm__(".symver ftell,ftell@GLIBC_2.2.5");
__asm__(".symver ftello,ftello@GLIBC_2.2.5");
__asm__(".symver ftello64,ftello64@GLIBC_2.2.5");
__asm__(".symver ftime,ftime@GLIBC_2.2.5");
__asm__(".symver ftok,ftok@GLIBC_2.2.5");
__asm__(".symver ftruncate,ftruncate@GLIBC_2.2.5");
__asm__(".symver ftruncate64,ftruncate64@GLIBC_2.2.5");
__asm__(".symver ftrylockfile,ftrylockfile@GLIBC_2.2.5");
__asm__(".symver fts_children,fts_children@GLIBC_2.2.5");
__asm__(".symver fts_close,fts_close@GLIBC_2.2.5");
__asm__(".symver fts_open,fts_open@GLIBC_2.2.5");
__asm__(".symver fts_read,fts_read@GLIBC_2.2.5");
__asm__(".symver fts_set,fts_set@GLIBC_2.2.5");
__asm__(".symver ftw,ftw@GLIBC_2.2.5");
__asm__(".symver ftw64,ftw64@GLIBC_2.2.5");
__asm__(".symver funlockfile,funlockfile@GLIBC_2.2.5");
__asm__(".symver futimens,futimens@GLIBC_2.6");
__asm__(".symver futimes,futimes@GLIBC_2.3");
__asm__(".symver futimesat,futimesat@GLIBC_2.4");
__asm__(".symver fwide,fwide@GLIBC_2.2.5");
__asm__(".symver fwprintf,fwprintf@GLIBC_2.2.5");
__asm__(".symver fwrite,fwrite@GLIBC_2.2.5");
__asm__(".symver fwrite_unlocked,fwrite_unlocked@GLIBC_2.2.5");
__asm__(".symver fwscanf,fwscanf@GLIBC_2.2.5");
__asm__(".symver gai_cancel,gai_cancel@GLIBC_2.2.5");
__asm__(".symver gai_error,gai_error@GLIBC_2.2.5");
__asm__(".symver gai_strerror,gai_strerror@GLIBC_2.2.5");
__asm__(".symver gai_suspend,gai_suspend@GLIBC_2.2.5");
__asm__(".symver gamma,gamma@GLIBC_2.2.5");
__asm__(".symver gammaf,gammaf@GLIBC_2.2.5");
__asm__(".symver gammal,gammal@GLIBC_2.2.5");
__asm__(".symver gcvt,gcvt@GLIBC_2.2.5");
__asm__(".symver get_avphys_pages,get_avphys_pages@GLIBC_2.2.5");
__asm__(".symver get_current_dir_name,get_current_dir_name@GLIBC_2.2.5");
__asm__(".symver get_kernel_syms,get_kernel_syms@GLIBC_2.2.5");
__asm__(".symver get_myaddress,get_myaddress@GLIBC_2.2.5");
__asm__(".symver get_nprocs,get_nprocs@GLIBC_2.2.5");
__asm__(".symver get_nprocs_conf,get_nprocs_conf@GLIBC_2.2.5");
__asm__(".symver get_phys_pages,get_phys_pages@GLIBC_2.2.5");
__asm__(".symver getaddrinfo,getaddrinfo@GLIBC_2.2.5");
__asm__(".symver getaddrinfo_a,getaddrinfo_a@GLIBC_2.2.5");
__asm__(".symver getaliasbyname,getaliasbyname@GLIBC_2.2.5");
__asm__(".symver getaliasbyname_r,getaliasbyname_r@GLIBC_2.2.5");
__asm__(".symver getaliasent,getaliasent@GLIBC_2.2.5");
__asm__(".symver getaliasent_r,getaliasent_r@GLIBC_2.2.5");
__asm__(".symver getauxval,getauxval@GLIBC_2.16");
__asm__(".symver getc,getc@GLIBC_2.2.5");
__asm__(".symver getc_unlocked,getc_unlocked@GLIBC_2.2.5");
__asm__(".symver getchar,getchar@GLIBC_2.2.5");
__asm__(".symver getchar_unlocked,getchar_unlocked@GLIBC_2.2.5");
__asm__(".symver getcontext,getcontext@GLIBC_2.2.5");
__asm__(".symver getcwd,getcwd@GLIBC_2.2.5");
__asm__(".symver getdate,getdate@GLIBC_2.2.5");
__asm__(".symver getdate_err,getdate_err@GLIBC_2.2.5");
__asm__(".symver getdate_r,getdate_r@GLIBC_2.2.5");
__asm__(".symver getdelim,getdelim@GLIBC_2.2.5");
__asm__(".symver getdirentries,getdirentries@GLIBC_2.2.5");
__asm__(".symver getdirentries64,getdirentries64@GLIBC_2.2.5");
__asm__(".symver getdomainname,getdomainname@GLIBC_2.2.5");
__asm__(".symver getdtablesize,getdtablesize@GLIBC_2.2.5");
__asm__(".symver getegid,getegid@GLIBC_2.2.5");
__asm__(".symver getenv,getenv@GLIBC_2.2.5");
__asm__(".symver geteuid,geteuid@GLIBC_2.2.5");
__asm__(".symver getfsent,getfsent@GLIBC_2.2.5");
__asm__(".symver getfsfile,getfsfile@GLIBC_2.2.5");
__asm__(".symver getfsspec,getfsspec@GLIBC_2.2.5");
__asm__(".symver getgid,getgid@GLIBC_2.2.5");
__asm__(".symver getgrent,getgrent@GLIBC_2.2.5");
__asm__(".symver getgrent_r,getgrent_r@GLIBC_2.2.5");
__asm__(".symver getgrgid,getgrgid@GLIBC_2.2.5");
__asm__(".symver getgrgid_r,getgrgid_r@GLIBC_2.2.5");
__asm__(".symver getgrnam,getgrnam@GLIBC_2.2.5");
__asm__(".symver getgrnam_r,getgrnam_r@GLIBC_2.2.5");
__asm__(".symver getgrouplist,getgrouplist@GLIBC_2.2.5");
__asm__(".symver getgroups,getgroups@GLIBC_2.2.5");
__asm__(".symver gethostbyaddr,gethostbyaddr@GLIBC_2.2.5");
__asm__(".symver gethostbyaddr_r,gethostbyaddr_r@GLIBC_2.2.5");
__asm__(".symver gethostbyname,gethostbyname@GLIBC_2.2.5");
__asm__(".symver gethostbyname2,gethostbyname2@GLIBC_2.2.5");
__asm__(".symver gethostbyname2_r,gethostbyname2_r@GLIBC_2.2.5");
__asm__(".symver gethostbyname_r,gethostbyname_r@GLIBC_2.2.5");
__asm__(".symver gethostent,gethostent@GLIBC_2.2.5");
__asm__(".symver gethostent_r,gethostent_r@GLIBC_2.2.5");
__asm__(".symver gethostid,gethostid@GLIBC_2.2.5");
__asm__(".symver gethostname,gethostname@GLIBC_2.2.5");
__asm__(".symver getifaddrs,getifaddrs@GLIBC_2.3");
__asm__(".symver getipv4sourcefilter,getipv4sourcefilter@GLIBC_2.3.4");
__asm__(".symver getitimer,getitimer@GLIBC_2.2.5");
__asm__(".symver getline,getline@GLIBC_2.2.5");
__asm__(".symver getloadavg,getloadavg@GLIBC_2.2.5");
__asm__(".symver getlogin,getlogin@GLIBC_2.2.5");
__asm__(".symver getlogin_r,getlogin_r@GLIBC_2.2.5");
__asm__(".symver getmntent,getmntent@GLIBC_2.2.5");
__asm__(".symver getmntent_r,getmntent_r@GLIBC_2.2.5");
__asm__(".symver getmsg,getmsg@GLIBC_2.2.5");
__asm__(".symver getnameinfo,getnameinfo@GLIBC_2.2.5");
__asm__(".symver getnetbyaddr,getnetbyaddr@GLIBC_2.2.5");
__asm__(".symver getnetbyaddr_r,getnetbyaddr_r@GLIBC_2.2.5");
__asm__(".symver getnetbyname,getnetbyname@GLIBC_2.2.5");
__asm__(".symver getnetbyname_r,getnetbyname_r@GLIBC_2.2.5");
__asm__(".symver getnetent,getnetent@GLIBC_2.2.5");
__asm__(".symver getnetent_r,getnetent_r@GLIBC_2.2.5");
__asm__(".symver getnetgrent,getnetgrent@GLIBC_2.2.5");
__asm__(".symver getnetgrent_r,getnetgrent_r@GLIBC_2.2.5");
__asm__(".symver getopt,getopt@GLIBC_2.2.5");
__asm__(".symver getopt_long,getopt_long@GLIBC_2.2.5");
__asm__(".symver getopt_long_only,getopt_long_only@GLIBC_2.2.5");
__asm__(".symver getpagesize,getpagesize@GLIBC_2.2.5");
__asm__(".symver getpass,getpass@GLIBC_2.2.5");
__asm__(".symver getpeername,getpeername@GLIBC_2.2.5");
__asm__(".symver getpgid,getpgid@GLIBC_2.2.5");
__asm__(".symver getpgrp,getpgrp@GLIBC_2.2.5");
__asm__(".symver getpid,getpid@GLIBC_2.2.5");
__asm__(".symver getpmsg,getpmsg@GLIBC_2.2.5");
__asm__(".symver getppid,getppid@GLIBC_2.2.5");
__asm__(".symver getpriority,getpriority@GLIBC_2.2.5");
__asm__(".symver getprotobyname,getprotobyname@GLIBC_2.2.5");
__asm__(".symver getprotobyname_r,getprotobyname_r@GLIBC_2.2.5");
__asm__(".symver getprotobynumber,getprotobynumber@GLIBC_2.2.5");
__asm__(".symver getprotobynumber_r,getprotobynumber_r@GLIBC_2.2.5");
__asm__(".symver getprotoent,getprotoent@GLIBC_2.2.5");
__asm__(".symver getprotoent_r,getprotoent_r@GLIBC_2.2.5");
__asm__(".symver getpt,getpt@GLIBC_2.2.5");
__asm__(".symver getpw,getpw@GLIBC_2.2.5");
__asm__(".symver getpwent,getpwent@GLIBC_2.2.5");
__asm__(".symver getpwent_r,getpwent_r@GLIBC_2.2.5");
__asm__(".symver getpwnam,getpwnam@GLIBC_2.2.5");
__asm__(".symver getpwnam_r,getpwnam_r@GLIBC_2.2.5");
__asm__(".symver getpwuid,getpwuid@GLIBC_2.2.5");
__asm__(".symver getpwuid_r,getpwuid_r@GLIBC_2.2.5");
__asm__(".symver getresgid,getresgid@GLIBC_2.2.5");
__asm__(".symver getresuid,getresuid@GLIBC_2.2.5");
__asm__(".symver getrlimit,getrlimit@GLIBC_2.2.5");
__asm__(".symver getrlimit64,getrlimit64@GLIBC_2.2.5");
__asm__(".symver getrpcbyname,getrpcbyname@GLIBC_2.2.5");
__asm__(".symver getrpcbyname_r,getrpcbyname_r@GLIBC_2.2.5");
__asm__(".symver getrpcbynumber,getrpcbynumber@GLIBC_2.2.5");
__asm__(".symver getrpcbynumber_r,getrpcbynumber_r@GLIBC_2.2.5");
__asm__(".symver getrpcent,getrpcent@GLIBC_2.2.5");
__asm__(".symver getrpcent_r,getrpcent_r@GLIBC_2.2.5");
__asm__(".symver getrpcport,getrpcport@GLIBC_2.2.5");
__asm__(".symver getrusage,getrusage@GLIBC_2.2.5");
__asm__(".symver gets,gets@GLIBC_2.2.5");
__asm__(".symver getservbyname,getservbyname@GLIBC_2.2.5");
__asm__(".symver getservbyname_r,getservbyname_r@GLIBC_2.2.5");
__asm__(".symver getservbyport,getservbyport@GLIBC_2.2.5");
__asm__(".symver getservbyport_r,getservbyport_r@GLIBC_2.2.5");
__asm__(".symver getservent,getservent@GLIBC_2.2.5");
__asm__(".symver getservent_r,getservent_r@GLIBC_2.2.5");
__asm__(".symver getsgent,getsgent@GLIBC_2.10");
__asm__(".symver getsgent_r,getsgent_r@GLIBC_2.10");
__asm__(".symver getsgnam,getsgnam@GLIBC_2.10");
__asm__(".symver getsgnam_r,getsgnam_r@GLIBC_2.10");
__asm__(".symver getsid,getsid@GLIBC_2.2.5");
__asm__(".symver getsockname,getsockname@GLIBC_2.2.5");
__asm__(".symver getsockopt,getsockopt@GLIBC_2.2.5");
__asm__(".symver getsourcefilter,getsourcefilter@GLIBC_2.3.4");
__asm__(".symver getspent,getspent@GLIBC_2.2.5");
__asm__(".symver getspent_r,getspent_r@GLIBC_2.2.5");
__asm__(".symver getspnam,getspnam@GLIBC_2.2.5");
__asm__(".symver getspnam_r,getspnam_r@GLIBC_2.2.5");
__asm__(".symver getsubopt,getsubopt@GLIBC_2.2.5");
__asm__(".symver gettext,gettext@GLIBC_2.2.5");
__asm__(".symver gettimeofday,gettimeofday@GLIBC_2.2.5");
__asm__(".symver getttyent,getttyent@GLIBC_2.2.5");
__asm__(".symver getttynam,getttynam@GLIBC_2.2.5");
__asm__(".symver getuid,getuid@GLIBC_2.2.5");
__asm__(".symver getusershell,getusershell@GLIBC_2.2.5");
__asm__(".symver getutent,getutent@GLIBC_2.2.5");
__asm__(".symver getutent_r,getutent_r@GLIBC_2.2.5");
__asm__(".symver getutid,getutid@GLIBC_2.2.5");
__asm__(".symver getutid_r,getutid_r@GLIBC_2.2.5");
__asm__(".symver getutline,getutline@GLIBC_2.2.5");
__asm__(".symver getutline_r,getutline_r@GLIBC_2.2.5");
__asm__(".symver getutmp,getutmp@GLIBC_2.2.5");
__asm__(".symver getutmpx,getutmpx@GLIBC_2.2.5");
__asm__(".symver getutxent,getutxent@GLIBC_2.2.5");
__asm__(".symver getutxid,getutxid@GLIBC_2.2.5");
__asm__(".symver getutxline,getutxline@GLIBC_2.2.5");
__asm__(".symver getw,getw@GLIBC_2.2.5");
__asm__(".symver getwc,getwc@GLIBC_2.2.5");
__asm__(".symver getwc_unlocked,getwc_unlocked@GLIBC_2.2.5");
__asm__(".symver getwchar,getwchar@GLIBC_2.2.5");
__asm__(".symver getwchar_unlocked,getwchar_unlocked@GLIBC_2.2.5");
__asm__(".symver getwd,getwd@GLIBC_2.2.5");
__asm__(".symver getxattr,getxattr@GLIBC_2.3");
__asm__(".symver glob,glob@GLIBC_2.2.5");
__asm__(".symver glob64,glob64@GLIBC_2.2.5");
__asm__(".symver glob_pattern_p,glob_pattern_p@GLIBC_2.2.5");
__asm__(".symver globfree,globfree@GLIBC_2.2.5");
__asm__(".symver globfree64,globfree64@GLIBC_2.2.5");
__asm__(".symver gmtime,gmtime@GLIBC_2.2.5");
__asm__(".symver gmtime_r,gmtime_r@GLIBC_2.2.5");
__asm__(".symver gnu_dev_major,gnu_dev_major@GLIBC_2.3.3");
__asm__(".symver gnu_dev_makedev,gnu_dev_makedev@GLIBC_2.3.3");
__asm__(".symver gnu_dev_minor,gnu_dev_minor@GLIBC_2.3.3");
__asm__(".symver gnu_get_libc_release,gnu_get_libc_release@GLIBC_2.2.5");
__asm__(".symver gnu_get_libc_version,gnu_get_libc_version@GLIBC_2.2.5");
__asm__(".symver grantpt,grantpt@GLIBC_2.2.5");
__asm__(".symver group_member,group_member@GLIBC_2.2.5");
__asm__(".symver gsignal,gsignal@GLIBC_2.2.5");
__asm__(".symver gtty,gtty@GLIBC_2.2.5");
__asm__(".symver h_errlist,h_errlist@GLIBC_2.2.5");
__asm__(".symver h_nerr,h_nerr@GLIBC_2.2.5");
__asm__(".symver hasmntopt,hasmntopt@GLIBC_2.2.5");
__asm__(".symver hcreate,hcreate@GLIBC_2.2.5");
__asm__(".symver hcreate_r,hcreate_r@GLIBC_2.2.5");
__asm__(".symver hdestroy,hdestroy@GLIBC_2.2.5");
__asm__(".symver hdestroy_r,hdestroy_r@GLIBC_2.2.5");
__asm__(".symver herror,herror@GLIBC_2.2.5");
__asm__(".symver host2netname,host2netname@GLIBC_2.2.5");
__asm__(".symver hsearch,hsearch@GLIBC_2.2.5");
__asm__(".symver hsearch_r,hsearch_r@GLIBC_2.2.5");
__asm__(".symver hstrerror,hstrerror@GLIBC_2.2.5");
__asm__(".symver htonl,htonl@GLIBC_2.2.5");
__asm__(".symver htons,htons@GLIBC_2.2.5");
__asm__(".symver hypot,hypot@GLIBC_2.2.5");
__asm__(".symver hypotf,hypotf@GLIBC_2.2.5");
__asm__(".symver hypotl,hypotl@GLIBC_2.2.5");
__asm__(".symver iconv,iconv@GLIBC_2.2.5");
__asm__(".symver iconv_close,iconv_close@GLIBC_2.2.5");
__asm__(".symver iconv_open,iconv_open@GLIBC_2.2.5");
__asm__(".symver if_freenameindex,if_freenameindex@GLIBC_2.2.5");
__asm__(".symver if_indextoname,if_indextoname@GLIBC_2.2.5");
__asm__(".symver if_nameindex,if_nameindex@GLIBC_2.2.5");
__asm__(".symver if_nametoindex,if_nametoindex@GLIBC_2.2.5");
__asm__(".symver ilogb,ilogb@GLIBC_2.2.5");
__asm__(".symver ilogbf,ilogbf@GLIBC_2.2.5");
__asm__(".symver ilogbl,ilogbl@GLIBC_2.2.5");
__asm__(".symver imaxabs,imaxabs@GLIBC_2.2.5");
__asm__(".symver imaxdiv,imaxdiv@GLIBC_2.2.5");
__asm__(".symver in6addr_any,in6addr_any@GLIBC_2.2.5");
__asm__(".symver in6addr_loopback,in6addr_loopback@GLIBC_2.2.5");
__asm__(".symver index,index@GLIBC_2.2.5");
__asm__(".symver inet6_opt_append,inet6_opt_append@GLIBC_2.5");
__asm__(".symver inet6_opt_find,inet6_opt_find@GLIBC_2.5");
__asm__(".symver inet6_opt_finish,inet6_opt_finish@GLIBC_2.5");
__asm__(".symver inet6_opt_get_val,inet6_opt_get_val@GLIBC_2.5");
__asm__(".symver inet6_opt_init,inet6_opt_init@GLIBC_2.5");
__asm__(".symver inet6_opt_next,inet6_opt_next@GLIBC_2.5");
__asm__(".symver inet6_opt_set_val,inet6_opt_set_val@GLIBC_2.5");
__asm__(".symver inet6_option_alloc,inet6_option_alloc@GLIBC_2.3.3");
__asm__(".symver inet6_option_append,inet6_option_append@GLIBC_2.3.3");
__asm__(".symver inet6_option_find,inet6_option_find@GLIBC_2.3.3");
__asm__(".symver inet6_option_init,inet6_option_init@GLIBC_2.3.3");
__asm__(".symver inet6_option_next,inet6_option_next@GLIBC_2.3.3");
__asm__(".symver inet6_option_space,inet6_option_space@GLIBC_2.3.3");
__asm__(".symver inet6_rth_add,inet6_rth_add@GLIBC_2.5");
__asm__(".symver inet6_rth_getaddr,inet6_rth_getaddr@GLIBC_2.5");
__asm__(".symver inet6_rth_init,inet6_rth_init@GLIBC_2.5");
__asm__(".symver inet6_rth_reverse,inet6_rth_reverse@GLIBC_2.5");
__asm__(".symver inet6_rth_segments,inet6_rth_segments@GLIBC_2.5");
__asm__(".symver inet6_rth_space,inet6_rth_space@GLIBC_2.5");
__asm__(".symver inet_addr,inet_addr@GLIBC_2.2.5");
__asm__(".symver inet_aton,inet_aton@GLIBC_2.2.5");
__asm__(".symver inet_lnaof,inet_lnaof@GLIBC_2.2.5");
__asm__(".symver inet_makeaddr,inet_makeaddr@GLIBC_2.2.5");
__asm__(".symver inet_net_ntop,inet_net_ntop@GLIBC_2.2.5");
__asm__(".symver inet_net_pton,inet_net_pton@GLIBC_2.2.5");
__asm__(".symver inet_neta,inet_neta@GLIBC_2.2.5");
__asm__(".symver inet_netof,inet_netof@GLIBC_2.2.5");
__asm__(".symver inet_network,inet_network@GLIBC_2.2.5");
__asm__(".symver inet_nsap_addr,inet_nsap_addr@GLIBC_2.2.5");
__asm__(".symver inet_nsap_ntoa,inet_nsap_ntoa@GLIBC_2.2.5");
__asm__(".symver inet_ntoa,inet_ntoa@GLIBC_2.2.5");
__asm__(".symver inet_ntop,inet_ntop@GLIBC_2.2.5");
__asm__(".symver inet_pton,inet_pton@GLIBC_2.2.5");
__asm__(".symver init_module,init_module@GLIBC_2.2.5");
__asm__(".symver initgroups,initgroups@GLIBC_2.2.5");
__asm__(".symver initstate,initstate@GLIBC_2.2.5");
__asm__(".symver initstate_r,initstate_r@GLIBC_2.2.5");
__asm__(".symver innetgr,innetgr@GLIBC_2.2.5");
__asm__(".symver inotify_add_watch,inotify_add_watch@GLIBC_2.4");
__asm__(".symver inotify_init,inotify_init@GLIBC_2.4");
__asm__(".symver inotify_init1,inotify_init1@GLIBC_2.9");
__asm__(".symver inotify_rm_watch,inotify_rm_watch@GLIBC_2.4");
__asm__(".symver insque,insque@GLIBC_2.2.5");
__asm__(".symver ioctl,ioctl@GLIBC_2.2.5");
__asm__(".symver ioperm,ioperm@GLIBC_2.2.5");
__asm__(".symver iopl,iopl@GLIBC_2.2.5");
__asm__(".symver iruserok,iruserok@GLIBC_2.2.5");
__asm__(".symver iruserok_af,iruserok_af@GLIBC_2.2.5");
__asm__(".symver isalnum,isalnum@GLIBC_2.2.5");
__asm__(".symver isalnum_l,isalnum_l@GLIBC_2.3");
__asm__(".symver isalpha,isalpha@GLIBC_2.2.5");
__asm__(".symver isalpha_l,isalpha_l@GLIBC_2.3");
__asm__(".symver isascii,isascii@GLIBC_2.2.5");
__asm__(".symver isastream,isastream@GLIBC_2.2.5");
__asm__(".symver isatty,isatty@GLIBC_2.2.5");
__asm__(".symver isblank,isblank@GLIBC_2.2.5");
__asm__(".symver isblank_l,isblank_l@GLIBC_2.3");
__asm__(".symver iscntrl,iscntrl@GLIBC_2.2.5");
__asm__(".symver iscntrl_l,iscntrl_l@GLIBC_2.3");
__asm__(".symver isctype,isctype@GLIBC_2.3");
__asm__(".symver isdigit,isdigit@GLIBC_2.2.5");
__asm__(".symver isdigit_l,isdigit_l@GLIBC_2.3");
__asm__(".symver isfdtype,isfdtype@GLIBC_2.2.5");
__asm__(".symver isgraph,isgraph@GLIBC_2.2.5");
__asm__(".symver isgraph_l,isgraph_l@GLIBC_2.3");
__asm__(".symver isinf,isinf@GLIBC_2.2.5");
__asm__(".symver isinff,isinff@GLIBC_2.2.5");
__asm__(".symver isinfl,isinfl@GLIBC_2.2.5");
__asm__(".symver islower,islower@GLIBC_2.2.5");
__asm__(".symver islower_l,islower_l@GLIBC_2.3");
__asm__(".symver isnan,isnan@GLIBC_2.2.5");
__asm__(".symver isnanf,isnanf@GLIBC_2.2.5");
__asm__(".symver isnanl,isnanl@GLIBC_2.2.5");
__asm__(".symver isprint,isprint@GLIBC_2.2.5");
__asm__(".symver isprint_l,isprint_l@GLIBC_2.3");
__asm__(".symver ispunct,ispunct@GLIBC_2.2.5");
__asm__(".symver ispunct_l,ispunct_l@GLIBC_2.3");
__asm__(".symver isspace,isspace@GLIBC_2.2.5");
__asm__(".symver isspace_l,isspace_l@GLIBC_2.3");
__asm__(".symver isupper,isupper@GLIBC_2.2.5");
__asm__(".symver isupper_l,isupper_l@GLIBC_2.3");
__asm__(".symver iswalnum,iswalnum@GLIBC_2.2.5");
__asm__(".symver iswalnum_l,iswalnum_l@GLIBC_2.3");
__asm__(".symver iswalpha,iswalpha@GLIBC_2.2.5");
__asm__(".symver iswalpha_l,iswalpha_l@GLIBC_2.3");
__asm__(".symver iswblank,iswblank@GLIBC_2.2.5");
__asm__(".symver iswblank_l,iswblank_l@GLIBC_2.3");
__asm__(".symver iswcntrl,iswcntrl@GLIBC_2.2.5");
__asm__(".symver iswcntrl_l,iswcntrl_l@GLIBC_2.3");
__asm__(".symver iswctype,iswctype@GLIBC_2.2.5");
__asm__(".symver iswctype_l,iswctype_l@GLIBC_2.3");
__asm__(".symver iswdigit,iswdigit@GLIBC_2.2.5");
__asm__(".symver iswdigit_l,iswdigit_l@GLIBC_2.3");
__asm__(".symver iswgraph,iswgraph@GLIBC_2.2.5");
__asm__(".symver iswgraph_l,iswgraph_l@GLIBC_2.3");
__asm__(".symver iswlower,iswlower@GLIBC_2.2.5");
__asm__(".symver iswlower_l,iswlower_l@GLIBC_2.3");
__asm__(".symver iswprint,iswprint@GLIBC_2.2.5");
__asm__(".symver iswprint_l,iswprint_l@GLIBC_2.3");
__asm__(".symver iswpunct,iswpunct@GLIBC_2.2.5");
__asm__(".symver iswpunct_l,iswpunct_l@GLIBC_2.3");
__asm__(".symver iswspace,iswspace@GLIBC_2.2.5");
__asm__(".symver iswspace_l,iswspace_l@GLIBC_2.3");
__asm__(".symver iswupper,iswupper@GLIBC_2.2.5");
__asm__(".symver iswupper_l,iswupper_l@GLIBC_2.3");
__asm__(".symver iswxdigit,iswxdigit@GLIBC_2.2.5");
__asm__(".symver iswxdigit_l,iswxdigit_l@GLIBC_2.3");
__asm__(".symver isxdigit,isxdigit@GLIBC_2.2.5");
__asm__(".symver isxdigit_l,isxdigit_l@GLIBC_2.3");
__asm__(".symver j0,j0@GLIBC_2.2.5");
__asm__(".symver j0f,j0f@GLIBC_2.2.5");
__asm__(".symver j0l,j0l@GLIBC_2.2.5");
__asm__(".symver j1,j1@GLIBC_2.2.5");
__asm__(".symver j1f,j1f@GLIBC_2.2.5");
__asm__(".symver j1l,j1l@GLIBC_2.2.5");
__asm__(".symver jn,jn@GLIBC_2.2.5");
__asm__(".symver jnf,jnf@GLIBC_2.2.5");
__asm__(".symver jnl,jnl@GLIBC_2.2.5");
__asm__(".symver jrand48,jrand48@GLIBC_2.2.5");
__asm__(".symver jrand48_r,jrand48_r@GLIBC_2.2.5");
__asm__(".symver key_gendes,key_gendes@GLIBC_2.2.5");
__asm__(".symver key_secretkey_is_set,key_secretkey_is_set@GLIBC_2.2.5");
__asm__(".symver kill,kill@GLIBC_2.2.5");
__asm__(".symver killpg,killpg@GLIBC_2.2.5");
__asm__(".symver klogctl,klogctl@GLIBC_2.2.5");
__asm__(".symver l64a,l64a@GLIBC_2.2.5");
__asm__(".symver labs,labs@GLIBC_2.2.5");
__asm__(".symver lchmod,lchmod@GLIBC_2.3.2");
__asm__(".symver lchown,lchown@GLIBC_2.2.5");
__asm__(".symver lckpwdf,lckpwdf@GLIBC_2.2.5");
__asm__(".symver lcong48,lcong48@GLIBC_2.2.5");
__asm__(".symver lcong48_r,lcong48_r@GLIBC_2.2.5");
__asm__(".symver ldexp,ldexp@GLIBC_2.2.5");
__asm__(".symver ldexpf,ldexpf@GLIBC_2.2.5");
__asm__(".symver ldexpl,ldexpl@GLIBC_2.2.5");
__asm__(".symver ldiv,ldiv@GLIBC_2.2.5");
__asm__(".symver lfind,lfind@GLIBC_2.2.5");
__asm__(".symver lgamma,lgamma@GLIBC_2.2.5");
__asm__(".symver lgamma_r,lgamma_r@GLIBC_2.2.5");
__asm__(".symver lgammaf,lgammaf@GLIBC_2.2.5");
__asm__(".symver lgammaf_r,lgammaf_r@GLIBC_2.2.5");
__asm__(".symver lgammal,lgammal@GLIBC_2.2.5");
__asm__(".symver lgammal_r,lgammal_r@GLIBC_2.2.5");
__asm__(".symver lgetxattr,lgetxattr@GLIBC_2.3");
__asm__(".symver link,link@GLIBC_2.2.5");
__asm__(".symver linkat,linkat@GLIBC_2.4");
__asm__(".symver lio_listio,lio_listio@GLIBC_2.4");
__asm__(".symver lio_listio64,lio_listio64@GLIBC_2.4");
__asm__(".symver listen,listen@GLIBC_2.2.5");
__asm__(".symver listxattr,listxattr@GLIBC_2.3");
__asm__(".symver llabs,llabs@GLIBC_2.2.5");
__asm__(".symver lldiv,lldiv@GLIBC_2.2.5");
__asm__(".symver llistxattr,llistxattr@GLIBC_2.3");
__asm__(".symver llrint,llrint@GLIBC_2.2.5");
__asm__(".symver llrintf,llrintf@GLIBC_2.2.5");
__asm__(".symver llrintl,llrintl@GLIBC_2.2.5");
__asm__(".symver llround,llround@GLIBC_2.2.5");
__asm__(".symver llroundf,llroundf@GLIBC_2.2.5");
__asm__(".symver llroundl,llroundl@GLIBC_2.2.5");
__asm__(".symver llseek,llseek@GLIBC_2.2.5");
__asm__(".symver loc1,loc1@GLIBC_2.2.5");
__asm__(".symver loc2,loc2@GLIBC_2.2.5");
__asm__(".symver localeconv,localeconv@GLIBC_2.2.5");
__asm__(".symver localtime,localtime@GLIBC_2.2.5");
__asm__(".symver localtime_r,localtime_r@GLIBC_2.2.5");
__asm__(".symver lockf,lockf@GLIBC_2.2.5");
__asm__(".symver lockf64,lockf64@GLIBC_2.2.5");
__asm__(".symver locs,locs@GLIBC_2.2.5");
__asm__(".symver log,log@GLIBC_2.2.5");
__asm__(".symver log10,log10@GLIBC_2.2.5");
__asm__(".symver log10f,log10f@GLIBC_2.2.5");
__asm__(".symver log10l,log10l@GLIBC_2.2.5");
__asm__(".symver log1p,log1p@GLIBC_2.2.5");
__asm__(".symver log1pf,log1pf@GLIBC_2.2.5");
__asm__(".symver log1pl,log1pl@GLIBC_2.2.5");
__asm__(".symver log2,log2@GLIBC_2.2.5");
__asm__(".symver log2f,log2f@GLIBC_2.2.5");
__asm__(".symver log2l,log2l@GLIBC_2.2.5");
__asm__(".symver logb,logb@GLIBC_2.2.5");
__asm__(".symver logbf,logbf@GLIBC_2.2.5");
__asm__(".symver logbl,logbl@GLIBC_2.2.5");
__asm__(".symver logf,logf@GLIBC_2.2.5");
__asm__(".symver login,login@GLIBC_2.2.5");
__asm__(".symver login_tty,login_tty@GLIBC_2.2.5");
__asm__(".symver logl,logl@GLIBC_2.2.5");
__asm__(".symver logout,logout@GLIBC_2.2.5");
__asm__(".symver logwtmp,logwtmp@GLIBC_2.2.5");
__asm__(".symver longjmp,longjmp@GLIBC_2.2.5");
__asm__(".symver lrand48,lrand48@GLIBC_2.2.5");
__asm__(".symver lrand48_r,lrand48_r@GLIBC_2.2.5");
__asm__(".symver lremovexattr,lremovexattr@GLIBC_2.3");
__asm__(".symver lrint,lrint@GLIBC_2.2.5");
__asm__(".symver lrintf,lrintf@GLIBC_2.2.5");
__asm__(".symver lrintl,lrintl@GLIBC_2.2.5");
__asm__(".symver lround,lround@GLIBC_2.2.5");
__asm__(".symver lroundf,lroundf@GLIBC_2.2.5");
__asm__(".symver lroundl,lroundl@GLIBC_2.2.5");
__asm__(".symver lsearch,lsearch@GLIBC_2.2.5");
__asm__(".symver lseek,lseek@GLIBC_2.2.5");
__asm__(".symver lseek64,lseek64@GLIBC_2.2.5");
__asm__(".symver lsetxattr,lsetxattr@GLIBC_2.3");
__asm__(".symver lutimes,lutimes@GLIBC_2.3");
__asm__(".symver madvise,madvise@GLIBC_2.2.5");
__asm__(".symver makecontext,makecontext@GLIBC_2.2.5");
__asm__(".symver mallinfo,mallinfo@GLIBC_2.2.5");
__asm__(".symver malloc,malloc@GLIBC_2.2.5");
__asm__(".symver malloc_get_state,malloc_get_state@GLIBC_2.2.5");
__asm__(".symver malloc_info,malloc_info@GLIBC_2.10");
__asm__(".symver malloc_set_state,malloc_set_state@GLIBC_2.2.5");
__asm__(".symver malloc_stats,malloc_stats@GLIBC_2.2.5");
__asm__(".symver malloc_trim,malloc_trim@GLIBC_2.2.5");
__asm__(".symver malloc_usable_size,malloc_usable_size@GLIBC_2.2.5");
__asm__(".symver mallopt,mallopt@GLIBC_2.2.5");
__asm__(".symver mallwatch,mallwatch@GLIBC_2.2.5");
__asm__(".symver matherr,matherr@GLIBC_2.2.5");
__asm__(".symver mblen,mblen@GLIBC_2.2.5");
__asm__(".symver mbrlen,mbrlen@GLIBC_2.2.5");
__asm__(".symver mbrtoc16,mbrtoc16@GLIBC_2.16");
__asm__(".symver mbrtoc32,mbrtoc32@GLIBC_2.16");
__asm__(".symver mbrtowc,mbrtowc@GLIBC_2.2.5");
__asm__(".symver mbsinit,mbsinit@GLIBC_2.2.5");
__asm__(".symver mbsnrtowcs,mbsnrtowcs@GLIBC_2.2.5");
__asm__(".symver mbsrtowcs,mbsrtowcs@GLIBC_2.2.5");
__asm__(".symver mbstowcs,mbstowcs@GLIBC_2.2.5");
__asm__(".symver mbtowc,mbtowc@GLIBC_2.2.5");
__asm__(".symver mcheck,mcheck@GLIBC_2.2.5");
__asm__(".symver mcheck_check_all,mcheck_check_all@GLIBC_2.2.5");
__asm__(".symver mcheck_pedantic,mcheck_pedantic@GLIBC_2.2.5");
__asm__(".symver mcount,mcount@GLIBC_2.2.5");
__asm__(".symver memalign,memalign@GLIBC_2.2.5");
__asm__(".symver memccpy,memccpy@GLIBC_2.2.5");
__asm__(".symver memchr,memchr@GLIBC_2.2.5");
__asm__(".symver memcmp,memcmp@GLIBC_2.2.5");
__asm__(".symver memcpy,memcpy@GLIBC_2.14");
__asm__(".symver memfrob,memfrob@GLIBC_2.2.5");
__asm__(".symver memmem,memmem@GLIBC_2.2.5");
__asm__(".symver memmove,memmove@GLIBC_2.2.5");
__asm__(".symver mempcpy,mempcpy@GLIBC_2.2.5");
__asm__(".symver memrchr,memrchr@GLIBC_2.2.5");
__asm__(".symver memset,memset@GLIBC_2.2.5");
__asm__(".symver mincore,mincore@GLIBC_2.2.5");
__asm__(".symver mkdir,mkdir@GLIBC_2.2.5");
__asm__(".symver mkdirat,mkdirat@GLIBC_2.4");
__asm__(".symver mkdtemp,mkdtemp@GLIBC_2.2.5");
__asm__(".symver mkfifo,mkfifo@GLIBC_2.2.5");
__asm__(".symver mkfifoat,mkfifoat@GLIBC_2.4");
__asm__(".symver mkostemp,mkostemp@GLIBC_2.7");
__asm__(".symver mkostemp64,mkostemp64@GLIBC_2.7");
__asm__(".symver mkostemps,mkostemps@GLIBC_2.11");
__asm__(".symver mkostemps64,mkostemps64@GLIBC_2.11");
__asm__(".symver mkstemp,mkstemp@GLIBC_2.2.5");
__asm__(".symver mkstemp64,mkstemp64@GLIBC_2.2.5");
__asm__(".symver mkstemps,mkstemps@GLIBC_2.11");
__asm__(".symver mkstemps64,mkstemps64@GLIBC_2.11");
__asm__(".symver mktemp,mktemp@GLIBC_2.2.5");
__asm__(".symver mktime,mktime@GLIBC_2.2.5");
__asm__(".symver mlock,mlock@GLIBC_2.2.5");
__asm__(".symver mlockall,mlockall@GLIBC_2.2.5");
__asm__(".symver mmap,mmap@GLIBC_2.2.5");
__asm__(".symver mmap64,mmap64@GLIBC_2.2.5");
__asm__(".symver modf,modf@GLIBC_2.2.5");
__asm__(".symver modff,modff@GLIBC_2.2.5");
__asm__(".symver modfl,modfl@GLIBC_2.2.5");
__asm__(".symver modify_ldt,modify_ldt@GLIBC_2.2.5");
__asm__(".symver moncontrol,moncontrol@GLIBC_2.2.5");
__asm__(".symver monstartup,monstartup@GLIBC_2.2.5");
__asm__(".symver mount,mount@GLIBC_2.2.5");
__asm__(".symver mprobe,mprobe@GLIBC_2.2.5");
__asm__(".symver mprotect,mprotect@GLIBC_2.2.5");
__asm__(".symver mq_close,mq_close@GLIBC_2.3.4");
__asm__(".symver mq_getattr,mq_getattr@GLIBC_2.3.4");
__asm__(".symver mq_notify,mq_notify@GLIBC_2.3.4");
__asm__(".symver mq_open,mq_open@GLIBC_2.3.4");
__asm__(".symver mq_receive,mq_receive@GLIBC_2.3.4");
__asm__(".symver mq_send,mq_send@GLIBC_2.3.4");
__asm__(".symver mq_setattr,mq_setattr@GLIBC_2.3.4");
__asm__(".symver mq_timedreceive,mq_timedreceive@GLIBC_2.3.4");
__asm__(".symver mq_timedsend,mq_timedsend@GLIBC_2.3.4");
__asm__(".symver mq_unlink,mq_unlink@GLIBC_2.3.4");
__asm__(".symver mrand48,mrand48@GLIBC_2.2.5");
__asm__(".symver mrand48_r,mrand48_r@GLIBC_2.2.5");
__asm__(".symver mremap,mremap@GLIBC_2.2.5");
__asm__(".symver msgctl,msgctl@GLIBC_2.2.5");
__asm__(".symver msgget,msgget@GLIBC_2.2.5");
__asm__(".symver msgrcv,msgrcv@GLIBC_2.2.5");
__asm__(".symver msgsnd,msgsnd@GLIBC_2.2.5");
__asm__(".symver msync,msync@GLIBC_2.2.5");
__asm__(".symver mtrace,mtrace@GLIBC_2.2.5");
__asm__(".symver munlock,munlock@GLIBC_2.2.5");
__asm__(".symver munlockall,munlockall@GLIBC_2.2.5");
__asm__(".symver munmap,munmap@GLIBC_2.2.5");
__asm__(".symver muntrace,muntrace@GLIBC_2.2.5");
__asm__(".symver name_to_handle_at,name_to_handle_at@GLIBC_2.14");
__asm__(".symver nan,nan@GLIBC_2.2.5");
__asm__(".symver nanf,nanf@GLIBC_2.2.5");
__asm__(".symver nanl,nanl@GLIBC_2.2.5");
__asm__(".symver nanosleep,nanosleep@GLIBC_2.2.5");
__asm__(".symver nearbyint,nearbyint@GLIBC_2.2.5");
__asm__(".symver nearbyintf,nearbyintf@GLIBC_2.2.5");
__asm__(".symver nearbyintl,nearbyintl@GLIBC_2.2.5");
__asm__(".symver newlocale,newlocale@GLIBC_2.3");
__asm__(".symver nextafter,nextafter@GLIBC_2.2.5");
__asm__(".symver nextafterf,nextafterf@GLIBC_2.2.5");
__asm__(".symver nextafterl,nextafterl@GLIBC_2.2.5");
__asm__(".symver nexttoward,nexttoward@GLIBC_2.2.5");
__asm__(".symver nexttowardf,nexttowardf@GLIBC_2.2.5");
__asm__(".symver nexttowardl,nexttowardl@GLIBC_2.2.5");
__asm__(".symver nfsservctl,nfsservctl@GLIBC_2.2.5");
__asm__(".symver nftw,nftw@GLIBC_2.3.3");
__asm__(".symver nftw64,nftw64@GLIBC_2.3.3");
__asm__(".symver ngettext,ngettext@GLIBC_2.2.5");
__asm__(".symver nice,nice@GLIBC_2.2.5");
__asm__(".symver nis_add,nis_add@GLIBC_2.2.5");
__asm__(".symver nis_add_entry,nis_add_entry@GLIBC_2.2.5");
__asm__(".symver nis_addmember,nis_addmember@GLIBC_2.2.5");
__asm__(".symver nis_checkpoint,nis_checkpoint@GLIBC_2.2.5");
__asm__(".symver nis_clone_directory,nis_clone_directory@GLIBC_2.2.5");
__asm__(".symver nis_clone_object,nis_clone_object@GLIBC_2.2.5");
__asm__(".symver nis_clone_result,nis_clone_result@GLIBC_2.2.5");
__asm__(".symver nis_creategroup,nis_creategroup@GLIBC_2.2.5");
__asm__(".symver nis_destroy_object,nis_destroy_object@GLIBC_2.2.5");
__asm__(".symver nis_destroygroup,nis_destroygroup@GLIBC_2.2.5");
__asm__(".symver nis_dir_cmp,nis_dir_cmp@GLIBC_2.2.5");
__asm__(".symver nis_domain_of,nis_domain_of@GLIBC_2.2.5");
__asm__(".symver nis_domain_of_r,nis_domain_of_r@GLIBC_2.2.5");
__asm__(".symver nis_first_entry,nis_first_entry@GLIBC_2.2.5");
__asm__(".symver nis_free_directory,nis_free_directory@GLIBC_2.2.5");
__asm__(".symver nis_free_object,nis_free_object@GLIBC_2.2.5");
__asm__(".symver nis_free_request,nis_free_request@GLIBC_2.2.5");
__asm__(".symver nis_freenames,nis_freenames@GLIBC_2.2.5");
__asm__(".symver nis_freeresult,nis_freeresult@GLIBC_2.2.5");
__asm__(".symver nis_freeservlist,nis_freeservlist@GLIBC_2.2.5");
__asm__(".symver nis_freetags,nis_freetags@GLIBC_2.2.5");
__asm__(".symver nis_getnames,nis_getnames@GLIBC_2.2.5");
__asm__(".symver nis_getservlist,nis_getservlist@GLIBC_2.2.5");
__asm__(".symver nis_ismember,nis_ismember@GLIBC_2.2.5");
__asm__(".symver nis_leaf_of,nis_leaf_of@GLIBC_2.2.5");
__asm__(".symver nis_leaf_of_r,nis_leaf_of_r@GLIBC_2.2.5");
__asm__(".symver nis_lerror,nis_lerror@GLIBC_2.2.5");
__asm__(".symver nis_list,nis_list@GLIBC_2.2.5");
__asm__(".symver nis_local_directory,nis_local_directory@GLIBC_2.2.5");
__asm__(".symver nis_local_group,nis_local_group@GLIBC_2.2.5");
__asm__(".symver nis_local_host,nis_local_host@GLIBC_2.2.5");
__asm__(".symver nis_local_principal,nis_local_principal@GLIBC_2.2.5");
__asm__(".symver nis_lookup,nis_lookup@GLIBC_2.2.5");
__asm__(".symver nis_mkdir,nis_mkdir@GLIBC_2.2.5");
__asm__(".symver nis_modify,nis_modify@GLIBC_2.2.5");
__asm__(".symver nis_modify_entry,nis_modify_entry@GLIBC_2.2.5");
__asm__(".symver nis_name_of,nis_name_of@GLIBC_2.2.5");
__asm__(".symver nis_name_of_r,nis_name_of_r@GLIBC_2.2.5");
__asm__(".symver nis_next_entry,nis_next_entry@GLIBC_2.2.5");
__asm__(".symver nis_perror,nis_perror@GLIBC_2.2.5");
__asm__(".symver nis_ping,nis_ping@GLIBC_2.2.5");
__asm__(".symver nis_print_directory,nis_print_directory@GLIBC_2.2.5");
__asm__(".symver nis_print_entry,nis_print_entry@GLIBC_2.2.5");
__asm__(".symver nis_print_group,nis_print_group@GLIBC_2.2.5");
__asm__(".symver nis_print_group_entry,nis_print_group_entry@GLIBC_2.2.5");
__asm__(".symver nis_print_link,nis_print_link@GLIBC_2.2.5");
__asm__(".symver nis_print_object,nis_print_object@GLIBC_2.2.5");
__asm__(".symver nis_print_result,nis_print_result@GLIBC_2.2.5");
__asm__(".symver nis_print_rights,nis_print_rights@GLIBC_2.2.5");
__asm__(".symver nis_print_table,nis_print_table@GLIBC_2.2.5");
__asm__(".symver nis_read_obj,nis_read_obj@GLIBC_2.2.5");
__asm__(".symver nis_remove,nis_remove@GLIBC_2.2.5");
__asm__(".symver nis_remove_entry,nis_remove_entry@GLIBC_2.2.5");
__asm__(".symver nis_removemember,nis_removemember@GLIBC_2.2.5");
__asm__(".symver nis_rmdir,nis_rmdir@GLIBC_2.2.5");
__asm__(".symver nis_servstate,nis_servstate@GLIBC_2.2.5");
__asm__(".symver nis_sperrno,nis_sperrno@GLIBC_2.2.5");
__asm__(".symver nis_sperror,nis_sperror@GLIBC_2.2.5");
__asm__(".symver nis_sperror_r,nis_sperror_r@GLIBC_2.2.5");
__asm__(".symver nis_stats,nis_stats@GLIBC_2.2.5");
__asm__(".symver nis_verifygroup,nis_verifygroup@GLIBC_2.2.5");
__asm__(".symver nis_write_obj,nis_write_obj@GLIBC_2.2.5");
__asm__(".symver nl_langinfo,nl_langinfo@GLIBC_2.2.5");
__asm__(".symver nl_langinfo_l,nl_langinfo_l@GLIBC_2.3");
__asm__(".symver nrand48,nrand48@GLIBC_2.2.5");
__asm__(".symver nrand48_r,nrand48_r@GLIBC_2.2.5");
__asm__(".symver ns_datetosecs,ns_datetosecs@GLIBC_2.9");
__asm__(".symver ns_format_ttl,ns_format_ttl@GLIBC_2.9");
__asm__(".symver ns_get16,ns_get16@GLIBC_2.9");
__asm__(".symver ns_get32,ns_get32@GLIBC_2.9");
__asm__(".symver ns_initparse,ns_initparse@GLIBC_2.9");
__asm__(".symver ns_makecanon,ns_makecanon@GLIBC_2.9");
__asm__(".symver ns_msg_getflag,ns_msg_getflag@GLIBC_2.9");
__asm__(".symver ns_name_compress,ns_name_compress@GLIBC_2.9");
__asm__(".symver ns_name_ntol,ns_name_ntol@GLIBC_2.9");
__asm__(".symver ns_name_ntop,ns_name_ntop@GLIBC_2.9");
__asm__(".symver ns_name_pack,ns_name_pack@GLIBC_2.9");
__asm__(".symver ns_name_pton,ns_name_pton@GLIBC_2.9");
__asm__(".symver ns_name_rollback,ns_name_rollback@GLIBC_2.9");
__asm__(".symver ns_name_skip,ns_name_skip@GLIBC_2.9");
__asm__(".symver ns_name_uncompress,ns_name_uncompress@GLIBC_2.9");
__asm__(".symver ns_name_unpack,ns_name_unpack@GLIBC_2.9");
__asm__(".symver ns_parse_ttl,ns_parse_ttl@GLIBC_2.9");
__asm__(".symver ns_parserr,ns_parserr@GLIBC_2.9");
__asm__(".symver ns_put16,ns_put16@GLIBC_2.9");
__asm__(".symver ns_put32,ns_put32@GLIBC_2.9");
__asm__(".symver ns_samedomain,ns_samedomain@GLIBC_2.9");
__asm__(".symver ns_samename,ns_samename@GLIBC_2.9");
__asm__(".symver ns_skiprr,ns_skiprr@GLIBC_2.9");
__asm__(".symver ns_sprintrr,ns_sprintrr@GLIBC_2.9");
__asm__(".symver ns_sprintrrf,ns_sprintrrf@GLIBC_2.9");
__asm__(".symver ns_subdomain,ns_subdomain@GLIBC_2.9");
__asm__(".symver ntohl,ntohl@GLIBC_2.2.5");
__asm__(".symver ntohs,ntohs@GLIBC_2.2.5");
__asm__(".symver ntp_adjtime,ntp_adjtime@GLIBC_2.2.5");
__asm__(".symver ntp_gettime,ntp_gettime@GLIBC_2.2.5");
__asm__(".symver ntp_gettimex,ntp_gettimex@GLIBC_2.12");
__asm__(
    ".symver "
    "obstack_alloc_failed_handler,obstack_alloc_failed_handler@GLIBC_2.2.5");
__asm__(".symver obstack_exit_failure,obstack_exit_failure@GLIBC_2.2.5");
__asm__(".symver obstack_free,obstack_free@GLIBC_2.2.5");
__asm__(".symver obstack_printf,obstack_printf@GLIBC_2.2.5");
__asm__(".symver obstack_vprintf,obstack_vprintf@GLIBC_2.2.5");
__asm__(".symver on_exit,on_exit@GLIBC_2.2.5");
__asm__(".symver open,open@GLIBC_2.2.5");
__asm__(".symver open64,open64@GLIBC_2.2.5");
__asm__(".symver open_by_handle_at,open_by_handle_at@GLIBC_2.14");
__asm__(".symver open_memstream,open_memstream@GLIBC_2.2.5");
__asm__(".symver open_wmemstream,open_wmemstream@GLIBC_2.4");
__asm__(".symver openat,openat@GLIBC_2.4");
__asm__(".symver openat64,openat64@GLIBC_2.4");
__asm__(".symver opendir,opendir@GLIBC_2.2.5");
__asm__(".symver openlog,openlog@GLIBC_2.2.5");
__asm__(".symver openpty,openpty@GLIBC_2.2.5");
__asm__(".symver optarg,optarg@GLIBC_2.2.5");
__asm__(".symver opterr,opterr@GLIBC_2.2.5");
__asm__(".symver optind,optind@GLIBC_2.2.5");
__asm__(".symver optopt,optopt@GLIBC_2.2.5");
__asm__(".symver parse_printf_format,parse_printf_format@GLIBC_2.2.5");
__asm__(".symver pathconf,pathconf@GLIBC_2.2.5");
__asm__(".symver pause,pause@GLIBC_2.2.5");
__asm__(".symver pclose,pclose@GLIBC_2.2.5");
__asm__(".symver perror,perror@GLIBC_2.2.5");
__asm__(".symver personality,personality@GLIBC_2.2.5");
__asm__(".symver pipe,pipe@GLIBC_2.2.5");
__asm__(".symver pipe2,pipe2@GLIBC_2.9");
__asm__(".symver pivot_root,pivot_root@GLIBC_2.2.5");
__asm__(".symver poll,poll@GLIBC_2.2.5");
__asm__(".symver popen,popen@GLIBC_2.2.5");
__asm__(".symver posix_fadvise,posix_fadvise@GLIBC_2.2.5");
__asm__(".symver posix_fadvise64,posix_fadvise64@GLIBC_2.2.5");
__asm__(".symver posix_fallocate,posix_fallocate@GLIBC_2.2.5");
__asm__(".symver posix_fallocate64,posix_fallocate64@GLIBC_2.2.5");
__asm__(".symver posix_madvise,posix_madvise@GLIBC_2.2.5");
__asm__(".symver posix_memalign,posix_memalign@GLIBC_2.2.5");
__asm__(".symver posix_openpt,posix_openpt@GLIBC_2.2.5");
__asm__(".symver posix_spawn,posix_spawn@GLIBC_2.15");
__asm__(".symver "
        "posix_spawn_file_actions_addclose,posix_spawn_file_actions_addclose@"
        "GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawn_file_actions_adddup2,posix_spawn_file_actions_adddup2@"
        "GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawn_file_actions_addopen,posix_spawn_file_actions_addopen@"
        "GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawn_file_actions_destroy,posix_spawn_file_actions_destroy@"
        "GLIBC_2.2.5");
__asm__(
    ".symver "
    "posix_spawn_file_actions_init,posix_spawn_file_actions_init@GLIBC_2.2.5");
__asm__(".symver posix_spawnattr_destroy,posix_spawnattr_destroy@GLIBC_2.2.5");
__asm__(
    ".symver posix_spawnattr_getflags,posix_spawnattr_getflags@GLIBC_2.2.5");
__asm__(
    ".symver posix_spawnattr_getpgroup,posix_spawnattr_getpgroup@GLIBC_2.2.5");
__asm__(
    ".symver "
    "posix_spawnattr_getschedparam,posix_spawnattr_getschedparam@GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawnattr_getschedpolicy,posix_spawnattr_getschedpolicy@GLIBC_2."
        "2.5");
__asm__(
    ".symver "
    "posix_spawnattr_getsigdefault,posix_spawnattr_getsigdefault@GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawnattr_getsigmask,posix_spawnattr_getsigmask@GLIBC_2.2.5");
__asm__(".symver posix_spawnattr_init,posix_spawnattr_init@GLIBC_2.2.5");
__asm__(
    ".symver posix_spawnattr_setflags,posix_spawnattr_setflags@GLIBC_2.2.5");
__asm__(
    ".symver posix_spawnattr_setpgroup,posix_spawnattr_setpgroup@GLIBC_2.2.5");
__asm__(
    ".symver "
    "posix_spawnattr_setschedparam,posix_spawnattr_setschedparam@GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawnattr_setschedpolicy,posix_spawnattr_setschedpolicy@GLIBC_2."
        "2.5");
__asm__(
    ".symver "
    "posix_spawnattr_setsigdefault,posix_spawnattr_setsigdefault@GLIBC_2.2.5");
__asm__(".symver "
        "posix_spawnattr_setsigmask,posix_spawnattr_setsigmask@GLIBC_2.2.5");
__asm__(".symver posix_spawnp,posix_spawnp@GLIBC_2.15");
__asm__(".symver pow,pow@GLIBC_2.2.5");
__asm__(".symver pow10,pow10@GLIBC_2.2.5");
__asm__(".symver pow10f,pow10f@GLIBC_2.2.5");
__asm__(".symver pow10l,pow10l@GLIBC_2.2.5");
__asm__(".symver powf,powf@GLIBC_2.2.5");
__asm__(".symver powl,powl@GLIBC_2.2.5");
__asm__(".symver ppoll,ppoll@GLIBC_2.4");
__asm__(".symver prctl,prctl@GLIBC_2.2.5");
__asm__(".symver pread,pread@GLIBC_2.2.5");
__asm__(".symver pread64,pread64@GLIBC_2.2.5");
__asm__(".symver preadv,preadv@GLIBC_2.10");
__asm__(".symver preadv64,preadv64@GLIBC_2.10");
__asm__(".symver printf,printf@GLIBC_2.2.5");
__asm__(".symver printf_size,printf_size@GLIBC_2.2.5");
__asm__(".symver printf_size_info,printf_size_info@GLIBC_2.2.5");
__asm__(".symver prlimit,prlimit@GLIBC_2.13");
__asm__(".symver prlimit64,prlimit64@GLIBC_2.13");
__asm__(".symver process_vm_readv,process_vm_readv@GLIBC_2.15");
__asm__(".symver process_vm_writev,process_vm_writev@GLIBC_2.15");
__asm__(".symver profil,profil@GLIBC_2.2.5");
__asm__(".symver program_invocation_name,program_invocation_name@GLIBC_2.2.5");
__asm__(
    ".symver "
    "program_invocation_short_name,program_invocation_short_name@GLIBC_2.2.5");
__asm__(".symver pselect,pselect@GLIBC_2.2.5");
__asm__(".symver psiginfo,psiginfo@GLIBC_2.10");
__asm__(".symver psignal,psignal@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_attr_destroy,pthread_attr_destroy@GLIBC_2.2.5");
#endif
__asm__(".symver "
        "pthread_attr_getaffinity_np,pthread_attr_getaffinity_np@GLIBC_2.3.4");
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_getdetachstate,pthread_attr_getdetachstate@GLIBC_2.2.5");
#endif
__asm__(
    ".symver pthread_attr_getguardsize,pthread_attr_getguardsize@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(
    ".symver "
    "pthread_attr_getinheritsched,pthread_attr_getinheritsched@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_getschedparam,pthread_attr_getschedparam@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_getschedpolicy,pthread_attr_getschedpolicy@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_attr_getscope,pthread_attr_getscope@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_attr_getstack,pthread_attr_getstack@GLIBC_2.2.5");
__asm__(
    ".symver pthread_attr_getstackaddr,pthread_attr_getstackaddr@GLIBC_2.2.5");
__asm__(
    ".symver pthread_attr_getstacksize,pthread_attr_getstacksize@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_attr_init,pthread_attr_init@GLIBC_2.2.5");
#endif
__asm__(".symver "
        "pthread_attr_setaffinity_np,pthread_attr_setaffinity_np@GLIBC_2.3.4");
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_setdetachstate,pthread_attr_setdetachstate@GLIBC_2.2.5");
#endif
__asm__(
    ".symver pthread_attr_setguardsize,pthread_attr_setguardsize@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(
    ".symver "
    "pthread_attr_setinheritsched,pthread_attr_setinheritsched@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_setschedparam,pthread_attr_setschedparam@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver "
        "pthread_attr_setschedpolicy,pthread_attr_setschedpolicy@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_attr_setscope,pthread_attr_setscope@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_attr_setstack,pthread_attr_setstack@GLIBC_2.2.5");
__asm__(
    ".symver pthread_attr_setstackaddr,pthread_attr_setstackaddr@GLIBC_2.2.5");
__asm__(
    ".symver pthread_attr_setstacksize,pthread_attr_setstacksize@GLIBC_2.2.5");
__asm__(".symver pthread_barrier_destroy,pthread_barrier_destroy@GLIBC_2.2.5");
__asm__(".symver pthread_barrier_init,pthread_barrier_init@GLIBC_2.2.5");
__asm__(".symver pthread_barrier_wait,pthread_barrier_wait@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_barrierattr_destroy,pthread_barrierattr_destroy@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_barrierattr_getpshared,pthread_barrierattr_getpshared@GLIBC_2."
        "3.3");
__asm__(
    ".symver pthread_barrierattr_init,pthread_barrierattr_init@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_barrierattr_setpshared,pthread_barrierattr_setpshared@GLIBC_2."
        "2.5");
__asm__(".symver pthread_cancel,pthread_cancel@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_cond_broadcast,pthread_cond_broadcast@GLIBC_2.3.2");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_cond_destroy,pthread_cond_destroy@GLIBC_2.3.2");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_cond_init,pthread_cond_init@GLIBC_2.3.2");
#endif
__asm__(".symver pthread_cond_signal,pthread_cond_signal@GLIBC_2.3.2");
#ifdef _REENTRANT
__asm__(".symver pthread_cond_timedwait,pthread_cond_timedwait@GLIBC_2.3.2");
#endif
__asm__(".symver pthread_cond_wait,pthread_cond_wait@GLIBC_2.3.2");
#ifdef _REENTRANT
__asm__(
    ".symver pthread_condattr_destroy,pthread_condattr_destroy@GLIBC_2.2.5");
#endif
__asm__(
    ".symver pthread_condattr_getclock,pthread_condattr_getclock@GLIBC_2.3.3");
__asm__(".symver "
        "pthread_condattr_getpshared,pthread_condattr_getpshared@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_condattr_init,pthread_condattr_init@GLIBC_2.2.5");
#endif
__asm__(
    ".symver pthread_condattr_setclock,pthread_condattr_setclock@GLIBC_2.3.3");
__asm__(".symver "
        "pthread_condattr_setpshared,pthread_condattr_setpshared@GLIBC_2.2.5");
#ifndef _GLIBCXX_SHARED
#ifdef _REENTRANT
__asm__(".symver pthread_create,pthread_create@GLIBC_2.2.5");
#endif
#endif
#ifndef _GLIBCXX_SHARED
#ifdef _REENTRANT
__asm__(".symver pthread_detach,pthread_detach@GLIBC_2.2.5");
#endif
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_equal,pthread_equal@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_exit,pthread_exit@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_getaffinity_np,pthread_getaffinity_np@GLIBC_2.3.4");
__asm__(".symver pthread_getattr_np,pthread_getattr_np@GLIBC_2.2.5");
__asm__(".symver pthread_getconcurrency,pthread_getconcurrency@GLIBC_2.2.5");
__asm__(".symver pthread_getcpuclockid,pthread_getcpuclockid@GLIBC_2.2.5");
__asm__(".symver pthread_getname_np,pthread_getname_np@GLIBC_2.12");
#ifdef _REENTRANT
__asm__(".symver pthread_getschedparam,pthread_getschedparam@GLIBC_2.2.5");
#endif
#ifndef _GLIBCXX_SHARED
#ifndef IN_LIBGCC2
#ifdef _REENTRANT
__asm__(".symver pthread_getspecific,pthread_getspecific@GLIBC_2.2.5");
#endif
#endif
#endif
#ifndef _GLIBCXX_SHARED
#ifdef _REENTRANT
__asm__(".symver pthread_join,pthread_join@GLIBC_2.2.5");
#endif
#endif
#ifndef _GLIBCXX_SHARED
#ifndef IN_LIBGCC2
#ifdef _REENTRANT
__asm__(".symver pthread_key_create,pthread_key_create@GLIBC_2.2.5");
#endif
#endif
#endif
#ifndef _GLIBCXX_SHARED
#ifdef _REENTRANT
__asm__(".symver pthread_key_delete,pthread_key_delete@GLIBC_2.2.5");
#endif
#endif
__asm__(".symver pthread_kill,pthread_kill@GLIBC_2.2.5");
__asm__(".symver pthread_mutex_consistent,pthread_mutex_consistent@GLIBC_2.12");
__asm__(".symver "
        "pthread_mutex_consistent_np,pthread_mutex_consistent_np@GLIBC_2.4");
#ifdef _REENTRANT
__asm__(".symver pthread_mutex_destroy,pthread_mutex_destroy@GLIBC_2.2.5");
#endif
__asm__(".symver "
        "pthread_mutex_getprioceiling,pthread_mutex_getprioceiling@GLIBC_2.4");
#ifdef _REENTRANT
__asm__(".symver pthread_mutex_init,pthread_mutex_init@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_mutex_lock,pthread_mutex_lock@GLIBC_2.2.5");
#endif
__asm__(".symver "
        "pthread_mutex_setprioceiling,pthread_mutex_setprioceiling@GLIBC_2.4");
__asm__(".symver pthread_mutex_timedlock,pthread_mutex_timedlock@GLIBC_2.2.5");
__asm__(".symver pthread_mutex_trylock,pthread_mutex_trylock@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_mutex_unlock,pthread_mutex_unlock@GLIBC_2.2.5");
#endif
__asm__(
    ".symver pthread_mutexattr_destroy,pthread_mutexattr_destroy@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_mutexattr_getkind_np,pthread_mutexattr_getkind_np@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_mutexattr_getprioceiling,pthread_mutexattr_getprioceiling@"
        "GLIBC_2.4");
__asm__(
    ".symver "
    "pthread_mutexattr_getprotocol,pthread_mutexattr_getprotocol@GLIBC_2.4");
__asm__(
    ".symver "
    "pthread_mutexattr_getpshared,pthread_mutexattr_getpshared@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_mutexattr_getrobust,pthread_mutexattr_getrobust@GLIBC_2.12");
__asm__(
    ".symver "
    "pthread_mutexattr_getrobust_np,pthread_mutexattr_getrobust_np@GLIBC_2.4");
__asm__(
    ".symver pthread_mutexattr_gettype,pthread_mutexattr_gettype@GLIBC_2.2.5");
__asm__(".symver pthread_mutexattr_init,pthread_mutexattr_init@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_mutexattr_setkind_np,pthread_mutexattr_setkind_np@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_mutexattr_setprioceiling,pthread_mutexattr_setprioceiling@"
        "GLIBC_2.4");
__asm__(
    ".symver "
    "pthread_mutexattr_setprotocol,pthread_mutexattr_setprotocol@GLIBC_2.4");
__asm__(
    ".symver "
    "pthread_mutexattr_setpshared,pthread_mutexattr_setpshared@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_mutexattr_setrobust,pthread_mutexattr_setrobust@GLIBC_2.12");
__asm__(
    ".symver "
    "pthread_mutexattr_setrobust_np,pthread_mutexattr_setrobust_np@GLIBC_2.4");
__asm__(
    ".symver pthread_mutexattr_settype,pthread_mutexattr_settype@GLIBC_2.2.5");
#ifndef _GLIBCXX_SHARED
#ifndef IN_LIBGCC2
#ifdef _REENTRANT
__asm__(".symver pthread_once,pthread_once@GLIBC_2.2.5");
#endif
#endif
#endif
__asm__(".symver pthread_rwlock_destroy,pthread_rwlock_destroy@GLIBC_2.2.5");
__asm__(".symver pthread_rwlock_init,pthread_rwlock_init@GLIBC_2.2.5");
__asm__(".symver pthread_rwlock_rdlock,pthread_rwlock_rdlock@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_rwlock_timedrdlock,pthread_rwlock_timedrdlock@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_rwlock_timedwrlock,pthread_rwlock_timedwrlock@GLIBC_2.2.5");
__asm__(
    ".symver pthread_rwlock_tryrdlock,pthread_rwlock_tryrdlock@GLIBC_2.2.5");
__asm__(
    ".symver pthread_rwlock_trywrlock,pthread_rwlock_trywrlock@GLIBC_2.2.5");
__asm__(".symver pthread_rwlock_unlock,pthread_rwlock_unlock@GLIBC_2.2.5");
__asm__(".symver pthread_rwlock_wrlock,pthread_rwlock_wrlock@GLIBC_2.2.5");
__asm__(".symver "
        "pthread_rwlockattr_destroy,pthread_rwlockattr_destroy@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_rwlockattr_getkind_np,pthread_rwlockattr_getkind_np@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_rwlockattr_getpshared,pthread_rwlockattr_getpshared@GLIBC_2.2.5");
__asm__(".symver pthread_rwlockattr_init,pthread_rwlockattr_init@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_rwlockattr_setkind_np,pthread_rwlockattr_setkind_np@GLIBC_2.2.5");
__asm__(
    ".symver "
    "pthread_rwlockattr_setpshared,pthread_rwlockattr_setpshared@GLIBC_2.2.5");
#ifdef _REENTRANT
__asm__(".symver pthread_self,pthread_self@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_setaffinity_np,pthread_setaffinity_np@GLIBC_2.3.4");
#ifdef _REENTRANT
__asm__(".symver pthread_setcancelstate,pthread_setcancelstate@GLIBC_2.2.5");
#endif
#ifdef _REENTRANT
__asm__(".symver pthread_setcanceltype,pthread_setcanceltype@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_setconcurrency,pthread_setconcurrency@GLIBC_2.2.5");
__asm__(".symver pthread_setname_np,pthread_setname_np@GLIBC_2.12");
#ifdef _REENTRANT
__asm__(".symver pthread_setschedparam,pthread_setschedparam@GLIBC_2.2.5");
#endif
__asm__(".symver pthread_setschedprio,pthread_setschedprio@GLIBC_2.3.4");
#ifndef _GLIBCXX_SHARED
#ifndef IN_LIBGCC2
#ifdef _REENTRANT
__asm__(".symver pthread_setspecific,pthread_setspecific@GLIBC_2.2.5");
#endif
#endif
#endif
__asm__(".symver pthread_sigmask,pthread_sigmask@GLIBC_2.2.5");
__asm__(".symver pthread_sigqueue,pthread_sigqueue@GLIBC_2.11");
__asm__(".symver pthread_spin_destroy,pthread_spin_destroy@GLIBC_2.2.5");
__asm__(".symver pthread_spin_init,pthread_spin_init@GLIBC_2.2.5");
__asm__(".symver pthread_spin_lock,pthread_spin_lock@GLIBC_2.2.5");
__asm__(".symver pthread_spin_trylock,pthread_spin_trylock@GLIBC_2.2.5");
__asm__(".symver pthread_spin_unlock,pthread_spin_unlock@GLIBC_2.2.5");
__asm__(".symver pthread_testcancel,pthread_testcancel@GLIBC_2.2.5");
__asm__(".symver pthread_timedjoin_np,pthread_timedjoin_np@GLIBC_2.3.3");
__asm__(".symver pthread_tryjoin_np,pthread_tryjoin_np@GLIBC_2.3.3");
__asm__(".symver pthread_yield,pthread_yield@GLIBC_2.2.5");
__asm__(".symver ptrace,ptrace@GLIBC_2.2.5");
__asm__(".symver ptsname,ptsname@GLIBC_2.2.5");
__asm__(".symver ptsname_r,ptsname_r@GLIBC_2.2.5");
__asm__(".symver putc,putc@GLIBC_2.2.5");
__asm__(".symver putc_unlocked,putc_unlocked@GLIBC_2.2.5");
__asm__(".symver putchar,putchar@GLIBC_2.2.5");
__asm__(".symver putchar_unlocked,putchar_unlocked@GLIBC_2.2.5");
__asm__(".symver putenv,putenv@GLIBC_2.2.5");
__asm__(".symver putgrent,putgrent@GLIBC_2.2.5");
__asm__(".symver putmsg,putmsg@GLIBC_2.2.5");
__asm__(".symver putpmsg,putpmsg@GLIBC_2.2.5");
__asm__(".symver putpwent,putpwent@GLIBC_2.2.5");
__asm__(".symver puts,puts@GLIBC_2.2.5");
__asm__(".symver putsgent,putsgent@GLIBC_2.10");
__asm__(".symver putspent,putspent@GLIBC_2.2.5");
__asm__(".symver pututline,pututline@GLIBC_2.2.5");
__asm__(".symver pututxline,pututxline@GLIBC_2.2.5");
__asm__(".symver putw,putw@GLIBC_2.2.5");
__asm__(".symver putwc,putwc@GLIBC_2.2.5");
__asm__(".symver putwc_unlocked,putwc_unlocked@GLIBC_2.2.5");
__asm__(".symver putwchar,putwchar@GLIBC_2.2.5");
__asm__(".symver putwchar_unlocked,putwchar_unlocked@GLIBC_2.2.5");
__asm__(".symver pvalloc,pvalloc@GLIBC_2.2.5");
__asm__(".symver pwrite,pwrite@GLIBC_2.2.5");
__asm__(".symver pwrite64,pwrite64@GLIBC_2.2.5");
__asm__(".symver pwritev,pwritev@GLIBC_2.10");
__asm__(".symver pwritev64,pwritev64@GLIBC_2.10");
__asm__(".symver qecvt,qecvt@GLIBC_2.2.5");
__asm__(".symver qecvt_r,qecvt_r@GLIBC_2.2.5");
__asm__(".symver qfcvt,qfcvt@GLIBC_2.2.5");
__asm__(".symver qfcvt_r,qfcvt_r@GLIBC_2.2.5");
__asm__(".symver qgcvt,qgcvt@GLIBC_2.2.5");
__asm__(".symver qsort,qsort@GLIBC_2.2.5");
__asm__(".symver qsort_r,qsort_r@GLIBC_2.8");
__asm__(".symver query_module,query_module@GLIBC_2.2.5");
__asm__(".symver quick_exit,quick_exit@GLIBC_2.10");
__asm__(".symver quotactl,quotactl@GLIBC_2.2.5");
__asm__(".symver raise,raise@GLIBC_2.2.5");
__asm__(".symver rand,rand@GLIBC_2.2.5");
__asm__(".symver rand_r,rand_r@GLIBC_2.2.5");
__asm__(".symver random,random@GLIBC_2.2.5");
__asm__(".symver random_r,random_r@GLIBC_2.2.5");
__asm__(".symver rawmemchr,rawmemchr@GLIBC_2.2.5");
__asm__(".symver rcmd,rcmd@GLIBC_2.2.5");
__asm__(".symver rcmd_af,rcmd_af@GLIBC_2.2.5");
__asm__(".symver re_comp,re_comp@GLIBC_2.2.5");
__asm__(".symver re_compile_fastmap,re_compile_fastmap@GLIBC_2.2.5");
__asm__(".symver re_compile_pattern,re_compile_pattern@GLIBC_2.2.5");
__asm__(".symver re_exec,re_exec@GLIBC_2.2.5");
__asm__(".symver re_match,re_match@GLIBC_2.2.5");
__asm__(".symver re_match_2,re_match_2@GLIBC_2.2.5");
__asm__(".symver re_max_failures,re_max_failures@GLIBC_2.2.5");
__asm__(".symver re_search,re_search@GLIBC_2.2.5");
__asm__(".symver re_search_2,re_search_2@GLIBC_2.2.5");
__asm__(".symver re_set_registers,re_set_registers@GLIBC_2.2.5");
__asm__(".symver re_set_syntax,re_set_syntax@GLIBC_2.2.5");
__asm__(".symver re_syntax_options,re_syntax_options@GLIBC_2.2.5");
__asm__(".symver read,read@GLIBC_2.2.5");
__asm__(".symver readColdStartFile,readColdStartFile@GLIBC_2.2.5");
__asm__(".symver readahead,readahead@GLIBC_2.3");
__asm__(".symver readdir,readdir@GLIBC_2.2.5");
__asm__(".symver readdir64,readdir64@GLIBC_2.2.5");
__asm__(".symver readdir64_r,readdir64_r@GLIBC_2.2.5");
__asm__(".symver readdir_r,readdir_r@GLIBC_2.2.5");
__asm__(".symver readlink,readlink@GLIBC_2.2.5");
__asm__(".symver readlinkat,readlinkat@GLIBC_2.4");
__asm__(".symver readv,readv@GLIBC_2.2.5");
__asm__(".symver realloc,realloc@GLIBC_2.2.5");
__asm__(".symver realpath,realpath@GLIBC_2.3");
__asm__(".symver reboot,reboot@GLIBC_2.2.5");
__asm__(".symver recv,recv@GLIBC_2.2.5");
__asm__(".symver recvfrom,recvfrom@GLIBC_2.2.5");
__asm__(".symver recvmmsg,recvmmsg@GLIBC_2.12");
__asm__(".symver recvmsg,recvmsg@GLIBC_2.2.5");
__asm__(".symver regcomp,regcomp@GLIBC_2.2.5");
__asm__(".symver regerror,regerror@GLIBC_2.2.5");
__asm__(".symver regexec,regexec@GLIBC_2.3.4");
__asm__(".symver regfree,regfree@GLIBC_2.2.5");
__asm__(
    ".symver register_printf_function,register_printf_function@GLIBC_2.2.5");
__asm__(".symver register_printf_modifier,register_printf_modifier@GLIBC_2.10");
__asm__(
    ".symver register_printf_specifier,register_printf_specifier@GLIBC_2.10");
__asm__(".symver register_printf_type,register_printf_type@GLIBC_2.10");
__asm__(".symver remainder,remainder@GLIBC_2.2.5");
__asm__(".symver remainderf,remainderf@GLIBC_2.2.5");
__asm__(".symver remainderl,remainderl@GLIBC_2.2.5");
__asm__(".symver remap_file_pages,remap_file_pages@GLIBC_2.3.3");
__asm__(".symver remove,remove@GLIBC_2.2.5");
__asm__(".symver removexattr,removexattr@GLIBC_2.3");
__asm__(".symver remque,remque@GLIBC_2.2.5");
__asm__(".symver remquo,remquo@GLIBC_2.2.5");
__asm__(".symver remquof,remquof@GLIBC_2.2.5");
__asm__(".symver remquol,remquol@GLIBC_2.2.5");
__asm__(".symver rename,rename@GLIBC_2.2.5");
__asm__(".symver renameat,renameat@GLIBC_2.4");
__asm__(".symver res_gethostbyaddr,res_gethostbyaddr@GLIBC_2.2.5");
__asm__(".symver res_gethostbyname,res_gethostbyname@GLIBC_2.2.5");
__asm__(".symver res_gethostbyname2,res_gethostbyname2@GLIBC_2.2.5");
__asm__(".symver res_send_setqhook,res_send_setqhook@GLIBC_2.2.5");
__asm__(".symver res_send_setrhook,res_send_setrhook@GLIBC_2.2.5");
__asm__(".symver revoke,revoke@GLIBC_2.2.5");
__asm__(".symver rewind,rewind@GLIBC_2.2.5");
__asm__(".symver rewinddir,rewinddir@GLIBC_2.2.5");
__asm__(".symver rexec,rexec@GLIBC_2.2.5");
__asm__(".symver rexec_af,rexec_af@GLIBC_2.2.5");
__asm__(".symver rexecoptions,rexecoptions@GLIBC_2.2.5");
__asm__(".symver rindex,rindex@GLIBC_2.2.5");
__asm__(".symver rint,rint@GLIBC_2.2.5");
__asm__(".symver rintf,rintf@GLIBC_2.2.5");
__asm__(".symver rintl,rintl@GLIBC_2.2.5");
__asm__(".symver rmdir,rmdir@GLIBC_2.2.5");
__asm__(".symver round,round@GLIBC_2.2.5");
__asm__(".symver roundf,roundf@GLIBC_2.2.5");
__asm__(".symver roundl,roundl@GLIBC_2.2.5");
__asm__(".symver rpc_createerr,rpc_createerr@GLIBC_2.2.5");
__asm__(".symver rpmatch,rpmatch@GLIBC_2.2.5");
__asm__(".symver rresvport,rresvport@GLIBC_2.2.5");
__asm__(".symver rresvport_af,rresvport_af@GLIBC_2.2.5");
__asm__(".symver ruserok,ruserok@GLIBC_2.2.5");
__asm__(".symver ruserok_af,ruserok_af@GLIBC_2.2.5");
__asm__(".symver ruserpass,ruserpass@GLIBC_2.2.5");
__asm__(".symver sbrk,sbrk@GLIBC_2.2.5");
__asm__(".symver scalb,scalb@GLIBC_2.2.5");
__asm__(".symver scalbf,scalbf@GLIBC_2.2.5");
__asm__(".symver scalbl,scalbl@GLIBC_2.2.5");
__asm__(".symver scalbln,scalbln@GLIBC_2.2.5");
__asm__(".symver scalblnf,scalblnf@GLIBC_2.2.5");
__asm__(".symver scalblnl,scalblnl@GLIBC_2.2.5");
__asm__(".symver scalbn,scalbn@GLIBC_2.2.5");
__asm__(".symver scalbnf,scalbnf@GLIBC_2.2.5");
__asm__(".symver scalbnl,scalbnl@GLIBC_2.2.5");
__asm__(".symver scandir,scandir@GLIBC_2.2.5");
__asm__(".symver scandir64,scandir64@GLIBC_2.2.5");
__asm__(".symver scandirat,scandirat@GLIBC_2.15");
__asm__(".symver scandirat64,scandirat64@GLIBC_2.15");
__asm__(".symver scanf,scanf@GLIBC_2.2.5");
__asm__(".symver sched_get_priority_max,sched_get_priority_max@GLIBC_2.2.5");
__asm__(".symver sched_get_priority_min,sched_get_priority_min@GLIBC_2.2.5");
__asm__(".symver sched_getaffinity,sched_getaffinity@GLIBC_2.3.4");
__asm__(".symver sched_getcpu,sched_getcpu@GLIBC_2.6");
__asm__(".symver sched_getparam,sched_getparam@GLIBC_2.2.5");
__asm__(".symver sched_getscheduler,sched_getscheduler@GLIBC_2.2.5");
__asm__(".symver sched_rr_get_interval,sched_rr_get_interval@GLIBC_2.2.5");
__asm__(".symver sched_setaffinity,sched_setaffinity@GLIBC_2.3.4");
__asm__(".symver sched_setparam,sched_setparam@GLIBC_2.2.5");
__asm__(".symver sched_setscheduler,sched_setscheduler@GLIBC_2.2.5");
__asm__(".symver sched_yield,sched_yield@GLIBC_2.2.5");
__asm__(".symver secure_getenv,secure_getenv@GLIBC_2.17");
__asm__(".symver seed48,seed48@GLIBC_2.2.5");
__asm__(".symver seed48_r,seed48_r@GLIBC_2.2.5");
__asm__(".symver seekdir,seekdir@GLIBC_2.2.5");
__asm__(".symver select,select@GLIBC_2.2.5");
__asm__(".symver sem_close,sem_close@GLIBC_2.2.5");
__asm__(".symver sem_destroy,sem_destroy@GLIBC_2.2.5");
__asm__(".symver sem_getvalue,sem_getvalue@GLIBC_2.2.5");
__asm__(".symver sem_init,sem_init@GLIBC_2.2.5");
__asm__(".symver sem_open,sem_open@GLIBC_2.2.5");
__asm__(".symver sem_post,sem_post@GLIBC_2.2.5");
__asm__(".symver sem_timedwait,sem_timedwait@GLIBC_2.2.5");
__asm__(".symver sem_trywait,sem_trywait@GLIBC_2.2.5");
__asm__(".symver sem_unlink,sem_unlink@GLIBC_2.2.5");
__asm__(".symver sem_wait,sem_wait@GLIBC_2.2.5");
__asm__(".symver semctl,semctl@GLIBC_2.2.5");
__asm__(".symver semget,semget@GLIBC_2.2.5");
__asm__(".symver semop,semop@GLIBC_2.2.5");
__asm__(".symver semtimedop,semtimedop@GLIBC_2.3.3");
__asm__(".symver send,send@GLIBC_2.2.5");
__asm__(".symver sendfile,sendfile@GLIBC_2.2.5");
__asm__(".symver sendfile64,sendfile64@GLIBC_2.3");
__asm__(".symver sendmmsg,sendmmsg@GLIBC_2.14");
__asm__(".symver sendmsg,sendmsg@GLIBC_2.2.5");
__asm__(".symver sendto,sendto@GLIBC_2.2.5");
__asm__(".symver setaliasent,setaliasent@GLIBC_2.2.5");
__asm__(".symver setbuf,setbuf@GLIBC_2.2.5");
__asm__(".symver setbuffer,setbuffer@GLIBC_2.2.5");
__asm__(".symver setcontext,setcontext@GLIBC_2.2.5");
__asm__(".symver setdomainname,setdomainname@GLIBC_2.2.5");
__asm__(".symver setegid,setegid@GLIBC_2.2.5");
__asm__(".symver setenv,setenv@GLIBC_2.2.5");
__asm__(".symver seteuid,seteuid@GLIBC_2.2.5");
__asm__(".symver setfsent,setfsent@GLIBC_2.2.5");
__asm__(".symver setfsgid,setfsgid@GLIBC_2.2.5");
__asm__(".symver setfsuid,setfsuid@GLIBC_2.2.5");
__asm__(".symver setgid,setgid@GLIBC_2.2.5");
__asm__(".symver setgrent,setgrent@GLIBC_2.2.5");
__asm__(".symver setgroups,setgroups@GLIBC_2.2.5");
__asm__(".symver sethostent,sethostent@GLIBC_2.2.5");
__asm__(".symver sethostid,sethostid@GLIBC_2.2.5");
__asm__(".symver sethostname,sethostname@GLIBC_2.2.5");
__asm__(".symver setipv4sourcefilter,setipv4sourcefilter@GLIBC_2.3.4");
__asm__(".symver setitimer,setitimer@GLIBC_2.2.5");
__asm__(".symver setjmp,setjmp@GLIBC_2.2.5");
__asm__(".symver setkey,setkey@GLIBC_2.2.5");
__asm__(".symver setkey_r,setkey_r@GLIBC_2.2.5");
__asm__(".symver setlinebuf,setlinebuf@GLIBC_2.2.5");
__asm__(".symver setlocale,setlocale@GLIBC_2.2.5");
__asm__(".symver setlogin,setlogin@GLIBC_2.2.5");
__asm__(".symver setlogmask,setlogmask@GLIBC_2.2.5");
__asm__(".symver setmntent,setmntent@GLIBC_2.2.5");
__asm__(".symver setnetent,setnetent@GLIBC_2.2.5");
__asm__(".symver setnetgrent,setnetgrent@GLIBC_2.2.5");
__asm__(".symver setns,setns@GLIBC_2.14");
__asm__(".symver setpgid,setpgid@GLIBC_2.2.5");
__asm__(".symver setpgrp,setpgrp@GLIBC_2.2.5");
__asm__(".symver setpriority,setpriority@GLIBC_2.2.5");
__asm__(".symver setprotoent,setprotoent@GLIBC_2.2.5");
__asm__(".symver setpwent,setpwent@GLIBC_2.2.5");
__asm__(".symver setregid,setregid@GLIBC_2.2.5");
__asm__(".symver setresgid,setresgid@GLIBC_2.2.5");
__asm__(".symver setresuid,setresuid@GLIBC_2.2.5");
__asm__(".symver setreuid,setreuid@GLIBC_2.2.5");
__asm__(".symver setrlimit,setrlimit@GLIBC_2.2.5");
__asm__(".symver setrlimit64,setrlimit64@GLIBC_2.2.5");
__asm__(".symver setrpcent,setrpcent@GLIBC_2.2.5");
__asm__(".symver setservent,setservent@GLIBC_2.2.5");
__asm__(".symver setsgent,setsgent@GLIBC_2.10");
__asm__(".symver setsid,setsid@GLIBC_2.2.5");
__asm__(".symver setsockopt,setsockopt@GLIBC_2.2.5");
__asm__(".symver setsourcefilter,setsourcefilter@GLIBC_2.3.4");
__asm__(".symver setspent,setspent@GLIBC_2.2.5");
__asm__(".symver setstate,setstate@GLIBC_2.2.5");
__asm__(".symver setstate_r,setstate_r@GLIBC_2.2.5");
__asm__(".symver settimeofday,settimeofday@GLIBC_2.2.5");
__asm__(".symver setttyent,setttyent@GLIBC_2.2.5");
__asm__(".symver setuid,setuid@GLIBC_2.2.5");
__asm__(".symver setusershell,setusershell@GLIBC_2.2.5");
__asm__(".symver setutent,setutent@GLIBC_2.2.5");
__asm__(".symver setutxent,setutxent@GLIBC_2.2.5");
__asm__(".symver setvbuf,setvbuf@GLIBC_2.2.5");
__asm__(".symver setxattr,setxattr@GLIBC_2.3");
__asm__(".symver sgetsgent,sgetsgent@GLIBC_2.10");
__asm__(".symver sgetsgent_r,sgetsgent_r@GLIBC_2.10");
__asm__(".symver sgetspent,sgetspent@GLIBC_2.2.5");
__asm__(".symver sgetspent_r,sgetspent_r@GLIBC_2.2.5");
__asm__(".symver shm_open,shm_open@GLIBC_2.2.5");
__asm__(".symver shm_unlink,shm_unlink@GLIBC_2.2.5");
__asm__(".symver shmat,shmat@GLIBC_2.2.5");
__asm__(".symver shmctl,shmctl@GLIBC_2.2.5");
__asm__(".symver shmdt,shmdt@GLIBC_2.2.5");
__asm__(".symver shmget,shmget@GLIBC_2.2.5");
__asm__(".symver shutdown,shutdown@GLIBC_2.2.5");
__asm__(".symver sigaction,sigaction@GLIBC_2.2.5");
__asm__(".symver sigaddset,sigaddset@GLIBC_2.2.5");
__asm__(".symver sigaltstack,sigaltstack@GLIBC_2.2.5");
__asm__(".symver sigandset,sigandset@GLIBC_2.2.5");
__asm__(".symver sigblock,sigblock@GLIBC_2.2.5");
__asm__(".symver sigdelset,sigdelset@GLIBC_2.2.5");
__asm__(".symver sigemptyset,sigemptyset@GLIBC_2.2.5");
__asm__(".symver sigfillset,sigfillset@GLIBC_2.2.5");
__asm__(".symver siggetmask,siggetmask@GLIBC_2.2.5");
__asm__(".symver sighold,sighold@GLIBC_2.2.5");
__asm__(".symver sigignore,sigignore@GLIBC_2.2.5");
__asm__(".symver siginterrupt,siginterrupt@GLIBC_2.2.5");
__asm__(".symver sigisemptyset,sigisemptyset@GLIBC_2.2.5");
__asm__(".symver sigismember,sigismember@GLIBC_2.2.5");
__asm__(".symver siglongjmp,siglongjmp@GLIBC_2.2.5");
__asm__(".symver signal,signal@GLIBC_2.2.5");
__asm__(".symver signalfd,signalfd@GLIBC_2.7");
__asm__(".symver signgam,signgam@GLIBC_2.2.5");
__asm__(".symver significand,significand@GLIBC_2.2.5");
__asm__(".symver significandf,significandf@GLIBC_2.2.5");
__asm__(".symver significandl,significandl@GLIBC_2.2.5");
__asm__(".symver sigorset,sigorset@GLIBC_2.2.5");
__asm__(".symver sigpause,sigpause@GLIBC_2.2.5");
__asm__(".symver sigpending,sigpending@GLIBC_2.2.5");
__asm__(".symver sigprocmask,sigprocmask@GLIBC_2.2.5");
__asm__(".symver sigqueue,sigqueue@GLIBC_2.2.5");
__asm__(".symver sigrelse,sigrelse@GLIBC_2.2.5");
__asm__(".symver sigreturn,sigreturn@GLIBC_2.2.5");
__asm__(".symver sigset,sigset@GLIBC_2.2.5");
__asm__(".symver sigsetmask,sigsetmask@GLIBC_2.2.5");
__asm__(".symver sigstack,sigstack@GLIBC_2.2.5");
__asm__(".symver sigsuspend,sigsuspend@GLIBC_2.2.5");
__asm__(".symver sigtimedwait,sigtimedwait@GLIBC_2.2.5");
__asm__(".symver sigvec,sigvec@GLIBC_2.2.5");
__asm__(".symver sigwait,sigwait@GLIBC_2.2.5");
__asm__(".symver sigwaitinfo,sigwaitinfo@GLIBC_2.2.5");
__asm__(".symver sin,sin@GLIBC_2.2.5");
__asm__(".symver sincos,sincos@GLIBC_2.2.5");
__asm__(".symver sincosf,sincosf@GLIBC_2.2.5");
__asm__(".symver sincosl,sincosl@GLIBC_2.2.5");
__asm__(".symver sinf,sinf@GLIBC_2.2.5");
__asm__(".symver sinh,sinh@GLIBC_2.2.5");
__asm__(".symver sinhf,sinhf@GLIBC_2.2.5");
__asm__(".symver sinhl,sinhl@GLIBC_2.2.5");
__asm__(".symver sinl,sinl@GLIBC_2.2.5");
__asm__(".symver sleep,sleep@GLIBC_2.2.5");
__asm__(".symver snprintf,snprintf@GLIBC_2.2.5");
__asm__(".symver sockatmark,sockatmark@GLIBC_2.2.5");
__asm__(".symver socket,socket@GLIBC_2.2.5");
__asm__(".symver socketpair,socketpair@GLIBC_2.2.5");
__asm__(".symver splice,splice@GLIBC_2.5");
__asm__(".symver sprintf,sprintf@GLIBC_2.2.5");
__asm__(".symver sprofil,sprofil@GLIBC_2.2.5");
__asm__(".symver sqrt,sqrt@GLIBC_2.2.5");
__asm__(".symver sqrtf,sqrtf@GLIBC_2.2.5");
__asm__(".symver sqrtl,sqrtl@GLIBC_2.2.5");
__asm__(".symver srand,srand@GLIBC_2.2.5");
__asm__(".symver srand48,srand48@GLIBC_2.2.5");
__asm__(".symver srand48_r,srand48_r@GLIBC_2.2.5");
__asm__(".symver srandom,srandom@GLIBC_2.2.5");
__asm__(".symver srandom_r,srandom_r@GLIBC_2.2.5");
__asm__(".symver sscanf,sscanf@GLIBC_2.2.5");
__asm__(".symver ssignal,ssignal@GLIBC_2.2.5");
__asm__(".symver sstk,sstk@GLIBC_2.2.5");
__asm__(".symver statfs,statfs@GLIBC_2.2.5");
__asm__(".symver statfs64,statfs64@GLIBC_2.2.5");
__asm__(".symver statvfs,statvfs@GLIBC_2.2.5");
__asm__(".symver statvfs64,statvfs64@GLIBC_2.2.5");
__asm__(".symver stderr,stderr@GLIBC_2.2.5");
__asm__(".symver stdin,stdin@GLIBC_2.2.5");
__asm__(".symver stdout,stdout@GLIBC_2.2.5");
__asm__(".symver step,step@GLIBC_2.2.5");
__asm__(".symver stime,stime@GLIBC_2.2.5");
__asm__(".symver stpcpy,stpcpy@GLIBC_2.2.5");
__asm__(".symver stpncpy,stpncpy@GLIBC_2.2.5");
__asm__(".symver strcasecmp,strcasecmp@GLIBC_2.2.5");
__asm__(".symver strcasecmp_l,strcasecmp_l@GLIBC_2.3");
//__asm__(".symver strcasestr,strcasestr@GLIBC_2.2.5");
__asm__(".symver strcat,strcat@GLIBC_2.2.5");
__asm__(".symver strchr,strchr@GLIBC_2.2.5");
__asm__(".symver strchrnul,strchrnul@GLIBC_2.2.5");
__asm__(".symver strcmp,strcmp@GLIBC_2.2.5");
__asm__(".symver strcoll,strcoll@GLIBC_2.2.5");
__asm__(".symver strcoll_l,strcoll_l@GLIBC_2.3");
__asm__(".symver strcpy,strcpy@GLIBC_2.2.5");
__asm__(".symver strcspn,strcspn@GLIBC_2.2.5");
__asm__(".symver strdup,strdup@GLIBC_2.2.5");
__asm__(".symver strerror,strerror@GLIBC_2.2.5");
__asm__(".symver strerror_l,strerror_l@GLIBC_2.6");
__asm__(".symver strerror_r,strerror_r@GLIBC_2.2.5");
__asm__(".symver strfmon,strfmon@GLIBC_2.2.5");
__asm__(".symver strfmon_l,strfmon_l@GLIBC_2.3");
__asm__(".symver strfry,strfry@GLIBC_2.2.5");
__asm__(".symver strftime,strftime@GLIBC_2.2.5");
__asm__(".symver strftime_l,strftime_l@GLIBC_2.3");
__asm__(".symver strlen,strlen@GLIBC_2.2.5");
__asm__(".symver strncasecmp,strncasecmp@GLIBC_2.2.5");
__asm__(".symver strncasecmp_l,strncasecmp_l@GLIBC_2.3");
__asm__(".symver strncat,strncat@GLIBC_2.2.5");
__asm__(".symver strncmp,strncmp@GLIBC_2.2.5");
__asm__(".symver strncpy,strncpy@GLIBC_2.2.5");
__asm__(".symver strndup,strndup@GLIBC_2.2.5");
__asm__(".symver strnlen,strnlen@GLIBC_2.2.5");
__asm__(".symver strpbrk,strpbrk@GLIBC_2.2.5");
__asm__(".symver strptime,strptime@GLIBC_2.2.5");
__asm__(".symver strptime_l,strptime_l@GLIBC_2.3.2");
__asm__(".symver strrchr,strrchr@GLIBC_2.2.5");
__asm__(".symver strsep,strsep@GLIBC_2.2.5");
__asm__(".symver strsignal,strsignal@GLIBC_2.2.5");
__asm__(".symver strspn,strspn@GLIBC_2.2.5");
__asm__(".symver strstr,strstr@GLIBC_2.2.5");
__asm__(".symver strtod,strtod@GLIBC_2.2.5");
__asm__(".symver strtod_l,strtod_l@GLIBC_2.3");
__asm__(".symver strtof,strtof@GLIBC_2.2.5");
__asm__(".symver strtof_l,strtof_l@GLIBC_2.3");
__asm__(".symver strtoimax,strtoimax@GLIBC_2.2.5");
__asm__(".symver strtok,strtok@GLIBC_2.2.5");
__asm__(".symver strtok_r,strtok_r@GLIBC_2.2.5");
__asm__(".symver strtol,strtol@GLIBC_2.2.5");
__asm__(".symver strtol_l,strtol_l@GLIBC_2.3");
__asm__(".symver strtold,strtold@GLIBC_2.2.5");
__asm__(".symver strtold_l,strtold_l@GLIBC_2.3");
__asm__(".symver strtoll,strtoll@GLIBC_2.2.5");
__asm__(".symver strtoll_l,strtoll_l@GLIBC_2.3.3");
__asm__(".symver strtoq,strtoq@GLIBC_2.2.5");
__asm__(".symver strtoul,strtoul@GLIBC_2.2.5");
__asm__(".symver strtoul_l,strtoul_l@GLIBC_2.3");
__asm__(".symver strtoull,strtoull@GLIBC_2.2.5");
__asm__(".symver strtoull_l,strtoull_l@GLIBC_2.3.3");
__asm__(".symver strtoumax,strtoumax@GLIBC_2.2.5");
__asm__(".symver strtouq,strtouq@GLIBC_2.2.5");
__asm__(".symver strverscmp,strverscmp@GLIBC_2.2.5");
__asm__(".symver strxfrm,strxfrm@GLIBC_2.2.5");
__asm__(".symver strxfrm_l,strxfrm_l@GLIBC_2.3");
__asm__(".symver stty,stty@GLIBC_2.2.5");
__asm__(".symver svc_fdset,svc_fdset@GLIBC_2.2.5");
__asm__(".symver svc_getreq_poll,svc_getreq_poll@GLIBC_2.2.5");
__asm__(".symver svc_max_pollfd,svc_max_pollfd@GLIBC_2.2.5");
__asm__(".symver svc_pollfd,svc_pollfd@GLIBC_2.2.5");
__asm__(".symver svc_register,svc_register@GLIBC_2.2.5");
__asm__(".symver svc_sendreply,svc_sendreply@GLIBC_2.2.5");
__asm__(".symver svcauthdes_stats,svcauthdes_stats@GLIBC_2.2.5");
__asm__(".symver svcerr_decode,svcerr_decode@GLIBC_2.2.5");
__asm__(".symver svcerr_noproc,svcerr_noproc@GLIBC_2.2.5");
__asm__(".symver svcerr_systemerr,svcerr_systemerr@GLIBC_2.2.5");
__asm__(".symver svctcp_create,svctcp_create@GLIBC_2.2.5");
__asm__(".symver svcudp_bufcreate,svcudp_bufcreate@GLIBC_2.2.5");
__asm__(".symver swab,swab@GLIBC_2.2.5");
__asm__(".symver swapcontext,swapcontext@GLIBC_2.2.5");
__asm__(".symver swapoff,swapoff@GLIBC_2.2.5");
__asm__(".symver swapon,swapon@GLIBC_2.2.5");
__asm__(".symver swprintf,swprintf@GLIBC_2.2.5");
__asm__(".symver swscanf,swscanf@GLIBC_2.2.5");
__asm__(".symver symlink,symlink@GLIBC_2.2.5");
__asm__(".symver symlinkat,symlinkat@GLIBC_2.4");
__asm__(".symver sync,sync@GLIBC_2.2.5");
__asm__(".symver sync_file_range,sync_file_range@GLIBC_2.6");
__asm__(".symver syncfs,syncfs@GLIBC_2.14");
__asm__(".symver sys_errlist,sys_errlist@GLIBC_2.12");
__asm__(".symver sys_nerr,sys_nerr@GLIBC_2.12");
__asm__(".symver sys_sigabbrev,sys_sigabbrev@GLIBC_2.3.3");
__asm__(".symver sys_siglist,sys_siglist@GLIBC_2.3.3");
__asm__(".symver syscall,syscall@GLIBC_2.2.5");
__asm__(".symver sysconf,sysconf@GLIBC_2.2.5");
__asm__(".symver sysctl,sysctl@GLIBC_2.2.5");
__asm__(".symver sysinfo,sysinfo@GLIBC_2.2.5");
__asm__(".symver syslog,syslog@GLIBC_2.2.5");
__asm__(".symver system,system@GLIBC_2.2.5");
__asm__(".symver sysv_signal,sysv_signal@GLIBC_2.2.5");
__asm__(".symver tan,tan@GLIBC_2.2.5");
__asm__(".symver tanf,tanf@GLIBC_2.2.5");
__asm__(".symver tanh,tanh@GLIBC_2.2.5");
__asm__(".symver tanhf,tanhf@GLIBC_2.2.5");
__asm__(".symver tanhl,tanhl@GLIBC_2.2.5");
__asm__(".symver tanl,tanl@GLIBC_2.2.5");
__asm__(".symver tcdrain,tcdrain@GLIBC_2.2.5");
__asm__(".symver tcflow,tcflow@GLIBC_2.2.5");
__asm__(".symver tcflush,tcflush@GLIBC_2.2.5");
__asm__(".symver tcgetattr,tcgetattr@GLIBC_2.2.5");
__asm__(".symver tcgetpgrp,tcgetpgrp@GLIBC_2.2.5");
__asm__(".symver tcgetsid,tcgetsid@GLIBC_2.2.5");
__asm__(".symver tcsendbreak,tcsendbreak@GLIBC_2.2.5");
__asm__(".symver tcsetattr,tcsetattr@GLIBC_2.2.5");
__asm__(".symver tcsetpgrp,tcsetpgrp@GLIBC_2.2.5");
__asm__(".symver td_init,td_init@GLIBC_2.2.5");
__asm__(".symver td_log,td_log@GLIBC_2.2.5");
__asm__(".symver td_symbol_list,td_symbol_list@GLIBC_2.2.5");
__asm__(".symver td_ta_clear_event,td_ta_clear_event@GLIBC_2.2.5");
__asm__(".symver td_ta_delete,td_ta_delete@GLIBC_2.2.5");
__asm__(".symver td_ta_enable_stats,td_ta_enable_stats@GLIBC_2.2.5");
__asm__(".symver td_ta_event_addr,td_ta_event_addr@GLIBC_2.2.5");
__asm__(".symver td_ta_event_getmsg,td_ta_event_getmsg@GLIBC_2.2.5");
__asm__(".symver td_ta_get_nthreads,td_ta_get_nthreads@GLIBC_2.2.5");
__asm__(".symver td_ta_get_ph,td_ta_get_ph@GLIBC_2.2.5");
__asm__(".symver td_ta_get_stats,td_ta_get_stats@GLIBC_2.2.5");
__asm__(".symver td_ta_map_id2thr,td_ta_map_id2thr@GLIBC_2.2.5");
__asm__(".symver td_ta_map_lwp2thr,td_ta_map_lwp2thr@GLIBC_2.2.5");
__asm__(".symver td_ta_new,td_ta_new@GLIBC_2.2.5");
__asm__(".symver td_ta_reset_stats,td_ta_reset_stats@GLIBC_2.2.5");
__asm__(".symver td_ta_set_event,td_ta_set_event@GLIBC_2.2.5");
__asm__(".symver td_ta_setconcurrency,td_ta_setconcurrency@GLIBC_2.2.5");
__asm__(".symver td_ta_thr_iter,td_ta_thr_iter@GLIBC_2.2.5");
__asm__(".symver td_ta_tsd_iter,td_ta_tsd_iter@GLIBC_2.2.5");
__asm__(".symver td_thr_clear_event,td_thr_clear_event@GLIBC_2.2.5");
__asm__(".symver td_thr_dbresume,td_thr_dbresume@GLIBC_2.2.5");
__asm__(".symver td_thr_dbsuspend,td_thr_dbsuspend@GLIBC_2.2.5");
__asm__(".symver td_thr_event_enable,td_thr_event_enable@GLIBC_2.2.5");
__asm__(".symver td_thr_event_getmsg,td_thr_event_getmsg@GLIBC_2.2.5");
__asm__(".symver td_thr_get_info,td_thr_get_info@GLIBC_2.2.5");
__asm__(".symver td_thr_getfpregs,td_thr_getfpregs@GLIBC_2.2.5");
__asm__(".symver td_thr_getgregs,td_thr_getgregs@GLIBC_2.2.5");
__asm__(".symver td_thr_getxregs,td_thr_getxregs@GLIBC_2.2.5");
__asm__(".symver td_thr_getxregsize,td_thr_getxregsize@GLIBC_2.2.5");
__asm__(".symver td_thr_set_event,td_thr_set_event@GLIBC_2.2.5");
__asm__(".symver td_thr_setfpregs,td_thr_setfpregs@GLIBC_2.2.5");
__asm__(".symver td_thr_setgregs,td_thr_setgregs@GLIBC_2.2.5");
__asm__(".symver td_thr_setprio,td_thr_setprio@GLIBC_2.2.5");
__asm__(".symver td_thr_setsigpending,td_thr_setsigpending@GLIBC_2.2.5");
__asm__(".symver td_thr_setxregs,td_thr_setxregs@GLIBC_2.2.5");
__asm__(".symver td_thr_sigsetmask,td_thr_sigsetmask@GLIBC_2.2.5");
__asm__(".symver td_thr_tls_get_addr,td_thr_tls_get_addr@GLIBC_2.3");
__asm__(".symver td_thr_tlsbase,td_thr_tlsbase@GLIBC_2.3.3");
__asm__(".symver td_thr_tsd,td_thr_tsd@GLIBC_2.2.5");
__asm__(".symver td_thr_validate,td_thr_validate@GLIBC_2.2.5");
__asm__(".symver tdelete,tdelete@GLIBC_2.2.5");
__asm__(".symver tdestroy,tdestroy@GLIBC_2.2.5");
__asm__(".symver tee,tee@GLIBC_2.5");
__asm__(".symver telldir,telldir@GLIBC_2.2.5");
__asm__(".symver tempnam,tempnam@GLIBC_2.2.5");
__asm__(".symver textdomain,textdomain@GLIBC_2.2.5");
__asm__(".symver tfind,tfind@GLIBC_2.2.5");
__asm__(".symver tgamma,tgamma@GLIBC_2.2.5");
__asm__(".symver tgammaf,tgammaf@GLIBC_2.2.5");
__asm__(".symver tgammal,tgammal@GLIBC_2.2.5");
__asm__(".symver time,time@GLIBC_2.2.5");
__asm__(".symver timegm,timegm@GLIBC_2.2.5");
__asm__(".symver timelocal,timelocal@GLIBC_2.2.5");
__asm__(".symver timer_create,timer_create@GLIBC_2.3.3");
__asm__(".symver timer_delete,timer_delete@GLIBC_2.3.3");
__asm__(".symver timer_getoverrun,timer_getoverrun@GLIBC_2.3.3");
__asm__(".symver timer_gettime,timer_gettime@GLIBC_2.3.3");
__asm__(".symver timer_settime,timer_settime@GLIBC_2.3.3");
__asm__(".symver timerfd_create,timerfd_create@GLIBC_2.8");
__asm__(".symver timerfd_gettime,timerfd_gettime@GLIBC_2.8");
__asm__(".symver timerfd_settime,timerfd_settime@GLIBC_2.8");
__asm__(".symver times,times@GLIBC_2.2.5");
__asm__(".symver timespec_get,timespec_get@GLIBC_2.16");
__asm__(".symver timezone,timezone@GLIBC_2.2.5");
__asm__(".symver tmpfile,tmpfile@GLIBC_2.2.5");
__asm__(".symver tmpfile64,tmpfile64@GLIBC_2.2.5");
__asm__(".symver tmpnam,tmpnam@GLIBC_2.2.5");
__asm__(".symver tmpnam_r,tmpnam_r@GLIBC_2.2.5");
__asm__(".symver toascii,toascii@GLIBC_2.2.5");
__asm__(".symver tolower,tolower@GLIBC_2.2.5");
__asm__(".symver tolower_l,tolower_l@GLIBC_2.3");
__asm__(".symver toupper,toupper@GLIBC_2.2.5");
__asm__(".symver toupper_l,toupper_l@GLIBC_2.3");
__asm__(".symver towctrans,towctrans@GLIBC_2.2.5");
__asm__(".symver towctrans_l,towctrans_l@GLIBC_2.3");
__asm__(".symver towlower,towlower@GLIBC_2.2.5");
__asm__(".symver towlower_l,towlower_l@GLIBC_2.3");
__asm__(".symver towupper,towupper@GLIBC_2.2.5");
__asm__(".symver towupper_l,towupper_l@GLIBC_2.3");
__asm__(".symver tr_break,tr_break@GLIBC_2.2.5");
__asm__(".symver trunc,trunc@GLIBC_2.2.5");
__asm__(".symver truncate,truncate@GLIBC_2.2.5");
__asm__(".symver truncate64,truncate64@GLIBC_2.2.5");
__asm__(".symver truncf,truncf@GLIBC_2.2.5");
__asm__(".symver truncl,truncl@GLIBC_2.2.5");
__asm__(".symver tsearch,tsearch@GLIBC_2.2.5");
__asm__(".symver ttyname,ttyname@GLIBC_2.2.5");
__asm__(".symver ttyname_r,ttyname_r@GLIBC_2.2.5");
__asm__(".symver ttyslot,ttyslot@GLIBC_2.2.5");
__asm__(".symver twalk,twalk@GLIBC_2.2.5");
__asm__(".symver tzname,tzname@GLIBC_2.2.5");
__asm__(".symver tzset,tzset@GLIBC_2.2.5");
__asm__(".symver ualarm,ualarm@GLIBC_2.2.5");
__asm__(".symver ulckpwdf,ulckpwdf@GLIBC_2.2.5");
__asm__(".symver ulimit,ulimit@GLIBC_2.2.5");
__asm__(".symver umask,umask@GLIBC_2.2.5");
__asm__(".symver umount,umount@GLIBC_2.2.5");
__asm__(".symver umount2,umount2@GLIBC_2.2.5");
__asm__(".symver uname,uname@GLIBC_2.2.5");
__asm__(".symver ungetc,ungetc@GLIBC_2.2.5");
__asm__(".symver ungetwc,ungetwc@GLIBC_2.2.5");
__asm__(".symver unlink,unlink@GLIBC_2.2.5");
__asm__(".symver unlinkat,unlinkat@GLIBC_2.4");
__asm__(".symver unlockpt,unlockpt@GLIBC_2.2.5");
__asm__(".symver unsetenv,unsetenv@GLIBC_2.2.5");
__asm__(".symver unshare,unshare@GLIBC_2.4");
__asm__(".symver updwtmp,updwtmp@GLIBC_2.2.5");
__asm__(".symver updwtmpx,updwtmpx@GLIBC_2.2.5");
__asm__(".symver uselib,uselib@GLIBC_2.2.5");
__asm__(".symver uselocale,uselocale@GLIBC_2.3");
__asm__(".symver usleep,usleep@GLIBC_2.2.5");
__asm__(".symver ustat,ustat@GLIBC_2.2.5");
__asm__(".symver utime,utime@GLIBC_2.2.5");
__asm__(".symver utimensat,utimensat@GLIBC_2.6");
__asm__(".symver utimes,utimes@GLIBC_2.2.5");
__asm__(".symver utmpname,utmpname@GLIBC_2.2.5");
__asm__(".symver utmpxname,utmpxname@GLIBC_2.2.5");
__asm__(".symver valloc,valloc@GLIBC_2.2.5");
__asm__(".symver vasprintf,vasprintf@GLIBC_2.2.5");
__asm__(".symver vdprintf,vdprintf@GLIBC_2.2.5");
__asm__(".symver verr,verr@GLIBC_2.2.5");
__asm__(".symver verrx,verrx@GLIBC_2.2.5");
__asm__(".symver versionsort,versionsort@GLIBC_2.2.5");
__asm__(".symver versionsort64,versionsort64@GLIBC_2.2.5");
__asm__(".symver vfork,vfork@GLIBC_2.2.5");
__asm__(".symver vfprintf,vfprintf@GLIBC_2.2.5");
__asm__(".symver vfscanf,vfscanf@GLIBC_2.2.5");
__asm__(".symver vfwprintf,vfwprintf@GLIBC_2.2.5");
__asm__(".symver vfwscanf,vfwscanf@GLIBC_2.2.5");
__asm__(".symver vhangup,vhangup@GLIBC_2.2.5");
__asm__(".symver vlimit,vlimit@GLIBC_2.2.5");
__asm__(".symver vmsplice,vmsplice@GLIBC_2.5");
__asm__(".symver vprintf,vprintf@GLIBC_2.2.5");
__asm__(".symver vscanf,vscanf@GLIBC_2.2.5");
__asm__(".symver vsnprintf,vsnprintf@GLIBC_2.2.5");
__asm__(".symver vsprintf,vsprintf@GLIBC_2.2.5");
__asm__(".symver vsscanf,vsscanf@GLIBC_2.2.5");
__asm__(".symver vswprintf,vswprintf@GLIBC_2.2.5");
__asm__(".symver vswscanf,vswscanf@GLIBC_2.2.5");
__asm__(".symver vsyslog,vsyslog@GLIBC_2.2.5");
__asm__(".symver vtimes,vtimes@GLIBC_2.2.5");
__asm__(".symver vwarn,vwarn@GLIBC_2.2.5");
__asm__(".symver vwarnx,vwarnx@GLIBC_2.2.5");
__asm__(".symver vwprintf,vwprintf@GLIBC_2.2.5");
__asm__(".symver vwscanf,vwscanf@GLIBC_2.2.5");
__asm__(".symver wait,wait@GLIBC_2.2.5");
__asm__(".symver wait3,wait3@GLIBC_2.2.5");
__asm__(".symver wait4,wait4@GLIBC_2.2.5");
__asm__(".symver waitid,waitid@GLIBC_2.2.5");
__asm__(".symver waitpid,waitpid@GLIBC_2.2.5");
__asm__(".symver warn,warn@GLIBC_2.2.5");
__asm__(".symver warnx,warnx@GLIBC_2.2.5");
__asm__(".symver wcpcpy,wcpcpy@GLIBC_2.2.5");
__asm__(".symver wcpncpy,wcpncpy@GLIBC_2.2.5");
__asm__(".symver wcrtomb,wcrtomb@GLIBC_2.2.5");
__asm__(".symver wcscasecmp,wcscasecmp@GLIBC_2.2.5");
__asm__(".symver wcscasecmp_l,wcscasecmp_l@GLIBC_2.3");
__asm__(".symver wcscat,wcscat@GLIBC_2.2.5");
__asm__(".symver wcschr,wcschr@GLIBC_2.2.5");
__asm__(".symver wcschrnul,wcschrnul@GLIBC_2.2.5");
__asm__(".symver wcscmp,wcscmp@GLIBC_2.2.5");
__asm__(".symver wcscoll,wcscoll@GLIBC_2.2.5");
__asm__(".symver wcscoll_l,wcscoll_l@GLIBC_2.3");
__asm__(".symver wcscpy,wcscpy@GLIBC_2.2.5");
__asm__(".symver wcscspn,wcscspn@GLIBC_2.2.5");
__asm__(".symver wcsdup,wcsdup@GLIBC_2.2.5");
__asm__(".symver wcsftime,wcsftime@GLIBC_2.2.5");
__asm__(".symver wcsftime_l,wcsftime_l@GLIBC_2.3");
__asm__(".symver wcslen,wcslen@GLIBC_2.2.5");
__asm__(".symver wcsncasecmp,wcsncasecmp@GLIBC_2.2.5");
__asm__(".symver wcsncasecmp_l,wcsncasecmp_l@GLIBC_2.3");
__asm__(".symver wcsncat,wcsncat@GLIBC_2.2.5");
__asm__(".symver wcsncmp,wcsncmp@GLIBC_2.2.5");
__asm__(".symver wcsncpy,wcsncpy@GLIBC_2.2.5");
__asm__(".symver wcsnlen,wcsnlen@GLIBC_2.2.5");
__asm__(".symver wcsnrtombs,wcsnrtombs@GLIBC_2.2.5");
__asm__(".symver wcspbrk,wcspbrk@GLIBC_2.2.5");
__asm__(".symver wcsrchr,wcsrchr@GLIBC_2.2.5");
__asm__(".symver wcsrtombs,wcsrtombs@GLIBC_2.2.5");
__asm__(".symver wcsspn,wcsspn@GLIBC_2.2.5");
__asm__(".symver wcsstr,wcsstr@GLIBC_2.2.5");
__asm__(".symver wcstod,wcstod@GLIBC_2.2.5");
__asm__(".symver wcstod_l,wcstod_l@GLIBC_2.3");
__asm__(".symver wcstof,wcstof@GLIBC_2.2.5");
__asm__(".symver wcstof_l,wcstof_l@GLIBC_2.3");
__asm__(".symver wcstoimax,wcstoimax@GLIBC_2.2.5");
__asm__(".symver wcstok,wcstok@GLIBC_2.2.5");
__asm__(".symver wcstol,wcstol@GLIBC_2.2.5");
__asm__(".symver wcstol_l,wcstol_l@GLIBC_2.3");
__asm__(".symver wcstold,wcstold@GLIBC_2.2.5");
__asm__(".symver wcstold_l,wcstold_l@GLIBC_2.3");
__asm__(".symver wcstoll,wcstoll@GLIBC_2.2.5");
__asm__(".symver wcstoll_l,wcstoll_l@GLIBC_2.3");
__asm__(".symver wcstombs,wcstombs@GLIBC_2.2.5");
__asm__(".symver wcstoq,wcstoq@GLIBC_2.2.5");
__asm__(".symver wcstoul,wcstoul@GLIBC_2.2.5");
__asm__(".symver wcstoul_l,wcstoul_l@GLIBC_2.3");
__asm__(".symver wcstoull,wcstoull@GLIBC_2.2.5");
__asm__(".symver wcstoull_l,wcstoull_l@GLIBC_2.3");
__asm__(".symver wcstoumax,wcstoumax@GLIBC_2.2.5");
__asm__(".symver wcstouq,wcstouq@GLIBC_2.2.5");
__asm__(".symver wcswcs,wcswcs@GLIBC_2.2.5");
__asm__(".symver wcswidth,wcswidth@GLIBC_2.2.5");
__asm__(".symver wcsxfrm,wcsxfrm@GLIBC_2.2.5");
__asm__(".symver wcsxfrm_l,wcsxfrm_l@GLIBC_2.3");
__asm__(".symver wctob,wctob@GLIBC_2.2.5");
__asm__(".symver wctomb,wctomb@GLIBC_2.2.5");
__asm__(".symver wctrans,wctrans@GLIBC_2.2.5");
__asm__(".symver wctrans_l,wctrans_l@GLIBC_2.3");
__asm__(".symver wctype,wctype@GLIBC_2.2.5");
__asm__(".symver wctype_l,wctype_l@GLIBC_2.3");
__asm__(".symver wcwidth,wcwidth@GLIBC_2.2.5");
__asm__(".symver wmemchr,wmemchr@GLIBC_2.2.5");
__asm__(".symver wmemcmp,wmemcmp@GLIBC_2.2.5");
__asm__(".symver wmemcpy,wmemcpy@GLIBC_2.2.5");
__asm__(".symver wmemmove,wmemmove@GLIBC_2.2.5");
__asm__(".symver wmempcpy,wmempcpy@GLIBC_2.2.5");
__asm__(".symver wmemset,wmemset@GLIBC_2.2.5");
__asm__(".symver wordexp,wordexp@GLIBC_2.2.5");
__asm__(".symver wordfree,wordfree@GLIBC_2.2.5");
__asm__(".symver wprintf,wprintf@GLIBC_2.2.5");
__asm__(".symver write,write@GLIBC_2.2.5");
__asm__(".symver writeColdStartFile,writeColdStartFile@GLIBC_2.2.5");
__asm__(".symver writev,writev@GLIBC_2.2.5");
__asm__(".symver wscanf,wscanf@GLIBC_2.2.5");
__asm__(".symver xdecrypt,xdecrypt@GLIBC_2.2.5");
__asm__(".symver xdr_array,xdr_array@GLIBC_2.2.5");
__asm__(".symver xdr_bool,xdr_bool@GLIBC_2.2.5");
__asm__(".symver xdr_bytes,xdr_bytes@GLIBC_2.2.5");
__asm__(".symver xdr_cback_data,xdr_cback_data@GLIBC_2.2.5");
__asm__(".symver xdr_domainname,xdr_domainname@GLIBC_2.2.5");
__asm__(".symver xdr_enum,xdr_enum@GLIBC_2.2.5");
__asm__(".symver xdr_free,xdr_free@GLIBC_2.2.5");
__asm__(".symver xdr_int,xdr_int@GLIBC_2.2.5");
__asm__(".symver xdr_keydat,xdr_keydat@GLIBC_2.2.5");
__asm__(".symver xdr_mapname,xdr_mapname@GLIBC_2.2.5");
__asm__(".symver xdr_netobj,xdr_netobj@GLIBC_2.2.5");
__asm__(".symver xdr_obj_p,xdr_obj_p@GLIBC_2.2.5");
__asm__(".symver xdr_opaque,xdr_opaque@GLIBC_2.2.5");
__asm__(".symver xdr_peername,xdr_peername@GLIBC_2.2.5");
__asm__(".symver xdr_pointer,xdr_pointer@GLIBC_2.2.5");
__asm__(".symver xdr_sizeof,xdr_sizeof@GLIBC_2.2.5");
__asm__(".symver xdr_string,xdr_string@GLIBC_2.2.5");
__asm__(".symver xdr_u_char,xdr_u_char@GLIBC_2.2.5");
__asm__(".symver xdr_u_int,xdr_u_int@GLIBC_2.2.5");
__asm__(".symver xdr_uint32_t,xdr_uint32_t@GLIBC_2.2.5");
__asm__(".symver xdr_valdat,xdr_valdat@GLIBC_2.2.5");
__asm__(".symver xdr_void,xdr_void@GLIBC_2.2.5");
__asm__(".symver xdr_yp_buf,xdr_yp_buf@GLIBC_2.2.5");
__asm__(".symver xdr_ypall,xdr_ypall@GLIBC_2.2.5");
__asm__(".symver xdr_ypbind_binding,xdr_ypbind_binding@GLIBC_2.2.5");
__asm__(".symver xdr_ypbind_resp,xdr_ypbind_resp@GLIBC_2.2.5");
__asm__(".symver xdr_ypbind_resptype,xdr_ypbind_resptype@GLIBC_2.2.5");
__asm__(".symver xdr_ypbind_setdom,xdr_ypbind_setdom@GLIBC_2.2.5");
__asm__(".symver xdr_ypdelete_args,xdr_ypdelete_args@GLIBC_2.2.5");
__asm__(".symver xdr_ypmap_parms,xdr_ypmap_parms@GLIBC_2.2.5");
__asm__(".symver xdr_ypmaplist,xdr_ypmaplist@GLIBC_2.2.5");
__asm__(".symver xdr_yppush_status,xdr_yppush_status@GLIBC_2.2.5");
__asm__(".symver xdr_yppushresp_xfr,xdr_yppushresp_xfr@GLIBC_2.2.5");
__asm__(".symver xdr_ypreq_key,xdr_ypreq_key@GLIBC_2.2.5");
__asm__(".symver xdr_ypreq_nokey,xdr_ypreq_nokey@GLIBC_2.2.5");
__asm__(".symver xdr_ypreq_xfr,xdr_ypreq_xfr@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_all,xdr_ypresp_all@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_key_val,xdr_ypresp_key_val@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_maplist,xdr_ypresp_maplist@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_master,xdr_ypresp_master@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_order,xdr_ypresp_order@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_val,xdr_ypresp_val@GLIBC_2.2.5");
__asm__(".symver xdr_ypresp_xfr,xdr_ypresp_xfr@GLIBC_2.2.5");
__asm__(".symver xdr_ypstat,xdr_ypstat@GLIBC_2.2.5");
__asm__(".symver xdr_ypupdate_args,xdr_ypupdate_args@GLIBC_2.2.5");
__asm__(".symver xdr_ypxfrstat,xdr_ypxfrstat@GLIBC_2.2.5");
__asm__(".symver xdrmem_create,xdrmem_create@GLIBC_2.2.5");
__asm__(".symver xdrstdio_create,xdrstdio_create@GLIBC_2.2.5");
__asm__(".symver xprt_unregister,xprt_unregister@GLIBC_2.2.5");
__asm__(".symver y0,y0@GLIBC_2.2.5");
__asm__(".symver y0f,y0f@GLIBC_2.2.5");
__asm__(".symver y0l,y0l@GLIBC_2.2.5");
__asm__(".symver y1,y1@GLIBC_2.2.5");
__asm__(".symver y1f,y1f@GLIBC_2.2.5");
__asm__(".symver y1l,y1l@GLIBC_2.2.5");
__asm__(".symver yn,yn@GLIBC_2.2.5");
__asm__(".symver ynf,ynf@GLIBC_2.2.5");
__asm__(".symver ynl,ynl@GLIBC_2.2.5");
__asm__(".symver yp_all,yp_all@GLIBC_2.2.5");
__asm__(".symver yp_bind,yp_bind@GLIBC_2.2.5");
__asm__(".symver yp_first,yp_first@GLIBC_2.2.5");
__asm__(".symver yp_get_default_domain,yp_get_default_domain@GLIBC_2.2.5");
__asm__(".symver yp_maplist,yp_maplist@GLIBC_2.2.5");
__asm__(".symver yp_master,yp_master@GLIBC_2.2.5");
__asm__(".symver yp_match,yp_match@GLIBC_2.2.5");
__asm__(".symver yp_next,yp_next@GLIBC_2.2.5");
__asm__(".symver yp_order,yp_order@GLIBC_2.2.5");
__asm__(".symver yp_unbind,yp_unbind@GLIBC_2.2.5");
__asm__(".symver yp_update,yp_update@GLIBC_2.2.5");
__asm__(".symver ypbinderr_string,ypbinderr_string@GLIBC_2.2.5");
__asm__(".symver yperr_string,yperr_string@GLIBC_2.2.5");
__asm__(".symver ypprot_err,ypprot_err@GLIBC_2.2.5");
__asm__(".symver "
        "_ZGVbN2v_cos,_ZGVbN2v_cos@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN2v_exp,_ZGVbN2v_exp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN2v_log,_ZGVbN2v_log@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN2v_sin,_ZGVbN2v_sin@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN2vv_pow,_ZGVbN2vv_pow@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN2vvv_sincos,_ZGVbN2vvv_sincos@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4v_cosf,_ZGVbN4v_cosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4v_expf,_ZGVbN4v_expf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4v_logf,_ZGVbN4v_logf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4v_sinf,_ZGVbN4v_sinf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4vv_powf,_ZGVbN4vv_powf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVbN4vvv_sincosf,_ZGVbN4vvv_sincosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4v_cos,_ZGVcN4v_cos@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4v_exp,_ZGVcN4v_exp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4v_log,_ZGVcN4v_log@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4v_sin,_ZGVcN4v_sin@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4vv_pow,_ZGVcN4vv_pow@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN4vvv_sincos,_ZGVcN4vvv_sincos@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8v_cosf,_ZGVcN8v_cosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8v_expf,_ZGVcN8v_expf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8v_logf,_ZGVcN8v_logf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8v_sinf,_ZGVcN8v_sinf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8vv_powf,_ZGVcN8vv_powf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVcN8vvv_sincosf,_ZGVcN8vvv_sincosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4v_cos,_ZGVdN4v_cos@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4v_exp,_ZGVdN4v_exp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4v_log,_ZGVdN4v_log@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4v_sin,_ZGVdN4v_sin@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4vv_pow,_ZGVdN4vv_pow@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN4vvv_sincos,_ZGVdN4vvv_sincos@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8v_cosf,_ZGVdN8v_cosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8v_expf,_ZGVdN8v_expf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8v_logf,_ZGVdN8v_logf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8v_sinf,_ZGVdN8v_sinf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8vv_powf,_ZGVdN8vv_powf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVdN8vvv_sincosf,_ZGVdN8vvv_sincosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16v_cosf,_ZGVeN16v_cosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16v_expf,_ZGVeN16v_expf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16v_logf,_ZGVeN16v_logf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16v_sinf,_ZGVeN16v_sinf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16vv_powf,_ZGVeN16vv_powf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN16vvv_sincosf,_ZGVeN16vvv_sincosf@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8v_cos,_ZGVeN8v_cos@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8v_exp,_ZGVeN8v_exp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8v_log,_ZGVeN8v_log@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8v_sin,_ZGVeN8v_sin@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8vv_pow,_ZGVeN8vv_pow@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_ZGVeN8vvv_sincos,_ZGVeN8vvv_sincos@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__acosf128_finite,__acosf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__acoshf128_finite,__acoshf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__asinf128_finite,__asinf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__atan2f128_finite,__atan2f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__atanhf128_finite,__atanhf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__coshf128_finite,__coshf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__cxa_thread_atexit_impl,__cxa_thread_atexit_impl@GLIBC_WRAP_ERROR_"
        "SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__exp10f128_finite,__exp10f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__exp2f128_finite,__exp2f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__expf128_finite,__expf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__explicit_bzero_chk,__explicit_bzero_chk@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__finitef128,__finitef128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__fmodf128_finite,__fmodf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__fpclassifyf128,__fpclassifyf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__gammaf128_r_finite,__gammaf128_r_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__hypotf128_finite,__hypotf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__iscanonicall,__iscanonicall@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__iseqsig,__iseqsig@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "__iseqsigf,__iseqsigf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__iseqsigf128,__iseqsigf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__iseqsigl,__iseqsigl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__isinff128,__isinff128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__isnanf128,__isnanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__issignaling,__issignaling@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__issignalingf,__issignalingf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__issignalingf128,__issignalingf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__issignalingl,__issignalingl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__j0f128_finite,__j0f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__j1f128_finite,__j1f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__jnf128_finite,__jnf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__lgammaf128_r_finite,__lgammaf128_r_finite@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__log10f128_finite,__log10f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__log2f128_finite,__log2f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__logf128_finite,__logf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__powf128_finite,__powf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__remainderf128_finite,__remainderf128_finite@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__rpc_thread_createerr,__rpc_thread_createerr@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__rpc_thread_svc_fdset,__rpc_thread_svc_fdset@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__secure_getenv,__secure_getenv@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__signbitf128,__signbitf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "__signgam,__signgam@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "__sinhf128_finite,__sinhf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__sqrtf128_finite,__sqrtf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__strtof128_internal,__strtof128_internal@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__wcstof128_internal,__wcstof128_internal@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "__y0f128_finite,__y0f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__y1f128_finite,__y1f128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "__ynf128_finite,__ynf128_finite@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "_authenticate,_authenticate@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_null_auth,_null_auth@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "_rpc_dtablesize,_rpc_dtablesize@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "_seterr_reply,_seterr_reply@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "acosf128,acosf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "acosf32,acosf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "acosf32x,acosf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "acosf64,acosf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "acosf64x,acosf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "acoshf128,acoshf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "acoshf32,acoshf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "acoshf32x,acoshf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "acoshf64,acoshf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "acoshf64x,acoshf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinf128,asinf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "asinf32,asinf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "asinf32x,asinf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "asinf64,asinf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "asinf64x,asinf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinhf128,asinhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinhf32,asinhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinhf32x,asinhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinhf64,asinhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "asinhf64x,asinhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atan2f128,atan2f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atan2f32,atan2f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atan2f32x,atan2f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atan2f64,atan2f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atan2f64x,atan2f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanf128,atanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "atanf32,atanf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "atanf32x,atanf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "atanf64,atanf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "atanf64x,atanf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanhf128,atanhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanhf32,atanhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanhf32x,atanhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanhf64,atanhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "atanhf64x,atanhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "authdes_getucred,authdes_getucred@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "authnone_create,authnone_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "authunix_create,authunix_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "cabsf128,cabsf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cabsf32,cabsf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cabsf32x,cabsf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cabsf64,cabsf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cabsf64x,cabsf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacosf128,cacosf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacosf32,cacosf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacosf32x,cacosf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacosf64,cacosf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacosf64x,cacosf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacoshf128,cacoshf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "cacoshf32,cacoshf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacoshf32x,cacoshf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "cacoshf64,cacoshf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cacoshf64x,cacoshf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "callrpc,callrpc@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalize,canonicalize@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef,canonicalizef@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef128,canonicalizef128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef32,canonicalizef32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef32x,canonicalizef32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef64,canonicalizef64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizef64x,canonicalizef64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "canonicalizel,canonicalizel@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "cargf128,cargf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cargf32,cargf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cargf32x,cargf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cargf64,cargf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cargf64x,cargf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinf128,casinf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinf32,casinf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinf32x,casinf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinf64,casinf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinf64x,casinf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinhf128,casinhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "casinhf32,casinhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinhf32x,casinhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "casinhf64,casinhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "casinhf64x,casinhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "catanf128,catanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanf32,catanf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanf32x,catanf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanf64,catanf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanf64x,catanf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanhf128,catanhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "catanhf32,catanhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanhf32x,catanhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "catanhf64,catanhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "catanhf64x,catanhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "cbc_crypt,cbc_crypt@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cbrtf128,cbrtf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cbrtf32,cbrtf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cbrtf32x,cbrtf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cbrtf64,cbrtf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cbrtf64x,cbrtf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccosf128,ccosf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ccosf32,ccosf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ccosf32x,ccosf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ccosf64,ccosf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ccosf64x,ccosf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccoshf128,ccoshf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccoshf32,ccoshf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccoshf32x,ccoshf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccoshf64,ccoshf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ccoshf64x,ccoshf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ceilf128,ceilf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ceilf32,ceilf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ceilf32x,ceilf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ceilf64,ceilf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ceilf64x,ceilf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cexpf128,cexpf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cexpf32,cexpf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cexpf32x,cexpf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cexpf64,cexpf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cexpf64x,cexpf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cimagf128,cimagf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cimagf32,cimagf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cimagf32x,cimagf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cimagf64,cimagf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cimagf64x,cimagf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "clnt_broadcast,clnt_broadcast@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clnt_perrno,clnt_perrno@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clnt_spcreateerror,clnt_spcreateerror@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "clnt_sperror,clnt_sperror@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clntraw_create,clntraw_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clntudp_bufcreate,clntudp_bufcreate@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "clntunix_create,clntunix_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "clog10f128,clog10f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clog10f32,clog10f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "clog10f32x,clog10f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clog10f64,clog10f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "clog10f64x,clog10f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "clogf128,clogf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "clogf32,clogf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "clogf32x,clogf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "clogf64,clogf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "clogf64x,clogf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "conjf128,conjf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "conjf32,conjf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "conjf32x,conjf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "conjf64,conjf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "conjf64x,conjf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "copy_file_range,copy_file_range@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "copysignf128,copysignf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "copysignf32,copysignf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "copysignf32x,copysignf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "copysignf64,copysignf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "copysignf64x,copysignf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "cosf128,cosf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "cosf32,cosf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "cosf32x,cosf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "cosf64,cosf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "cosf64x,cosf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "coshf128,coshf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "coshf32,coshf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "coshf32x,coshf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "coshf64,coshf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "coshf64x,coshf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cpowf128,cpowf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cpowf32,cpowf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cpowf32x,cpowf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "cpowf64,cpowf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "cpowf64x,cpowf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cprojf128,cprojf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cprojf32,cprojf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cprojf32x,cprojf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cprojf64,cprojf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "cprojf64x,cprojf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "crealf128,crealf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "crealf32,crealf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "crealf32x,crealf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "crealf64,crealf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "crealf64x,crealf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinf128,csinf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "csinf32,csinf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "csinf32x,csinf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "csinf64,csinf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "csinf64x,csinf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinhf128,csinhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinhf32,csinhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinhf32x,csinhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinhf64,csinhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csinhf64x,csinhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csqrtf128,csqrtf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csqrtf32,csqrtf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csqrtf32x,csqrtf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csqrtf64,csqrtf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "csqrtf64x,csqrtf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanf128,ctanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ctanf32,ctanf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ctanf32x,ctanf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ctanf64,ctanf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ctanf64x,ctanf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanhf128,ctanhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanhf32,ctanhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanhf32x,ctanhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanhf64,ctanhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ctanhf64x,ctanhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "des_setparity,des_setparity@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ecb_crypt,ecb_crypt@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "erfcf128,erfcf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "erfcf32,erfcf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "erfcf32x,erfcf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "erfcf64,erfcf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "erfcf64x,erfcf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "erff128,erff128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "erff32,erff32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "erff32x,erff32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "erff64,erff64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "erff64x,erff64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "exp10f128,exp10f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "exp10f32,exp10f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "exp10f32x,exp10f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "exp10f64,exp10f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "exp10f64x,exp10f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "exp2f128,exp2f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "exp2f32,exp2f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "exp2f32x,exp2f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "exp2f64,exp2f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "exp2f64x,exp2f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "expf128,expf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "expf32,expf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "expf32x,expf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "expf64,expf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "expf64x,expf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "explicit_bzero,explicit_bzero@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "expm1f128,expm1f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "expm1f32,expm1f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "expm1f32x,expm1f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "expm1f64,expm1f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "expm1f64x,expm1f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fabsf128,fabsf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fabsf32,fabsf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fabsf32x,fabsf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fabsf64,fabsf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fabsf64x,fabsf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fdimf128,fdimf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fdimf32,fdimf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fdimf32x,fdimf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fdimf64,fdimf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fdimf64x,fdimf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fegetmode,fegetmode@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fesetexcept,fesetexcept@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fesetmode,fesetmode@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fetestexceptflag,fetestexceptflag@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "floorf128,floorf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "floorf32,floorf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "floorf32x,floorf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "floorf64,floorf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "floorf64x,floorf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmaf128,fmaf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fmaf32,fmaf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fmaf32x,fmaf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fmaf64,fmaf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fmaf64x,fmaf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmaxf128,fmaxf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmaxf32,fmaxf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmaxf32x,fmaxf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmaxf64,fmaxf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmaxf64x,fmaxf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmaxmag,fmaxmag@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagf,fmaxmagf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fmaxmagf128,fmaxmagf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagf32,fmaxmagf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagf32x,fmaxmagf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagf64,fmaxmagf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagf64x,fmaxmagf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fmaxmagl,fmaxmagl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fminf128,fminf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fminf32,fminf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fminf32x,fminf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fminf64,fminf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fminf64x,fminf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fminmag,fminmag@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fminmagf,fminmagf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fminmagf128,fminmagf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fminmagf32,fminmagf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fminmagf32x,fminmagf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fminmagf64,fminmagf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fminmagf64x,fminmagf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fminmagl,fminmagl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fmodf128,fmodf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmodf32,fmodf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmodf32x,fmodf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fmodf64,fmodf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fmodf64x,fmodf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "frexpf128,frexpf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "frexpf32,frexpf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "frexpf32x,frexpf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "frexpf64,frexpf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "frexpf64x,frexpf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "fromfp,fromfp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fromfpf,fromfpf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fromfpf128,fromfpf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpf32,fromfpf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fromfpf32x,fromfpf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpf64,fromfpf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fromfpf64x,fromfpf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "fromfpl,fromfpl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "fromfpx,fromfpx@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxf,fromfpxf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fromfpxf128,fromfpxf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxf32,fromfpxf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxf32x,fromfpxf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxf64,fromfpxf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxf64x,fromfpxf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fromfpxl,fromfpxl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "fts64_children,fts64_children@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fts64_close,fts64_close@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fts64_open,fts64_open@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fts64_read,fts64_read@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "fts64_set,fts64_set@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "getentropy,getentropy@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getnetname,getnetname@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayload,getpayload@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf,getpayloadf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf128,getpayloadf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf32,getpayloadf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf32x,getpayloadf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf64,getpayloadf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadf64x,getpayloadf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpayloadl,getpayloadl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getpublickey,getpublickey@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "getrandom,getrandom@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "getsecretkey,getsecretkey@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "hypotf128,hypotf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "hypotf32,hypotf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "hypotf32x,hypotf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "hypotf64,hypotf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "hypotf64x,hypotf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ilogbf128,ilogbf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ilogbf32,ilogbf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ilogbf32x,ilogbf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ilogbf64,ilogbf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ilogbf64x,ilogbf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "j0f128,j0f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "j0f32,j0f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "j0f32x,j0f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "j0f64,j0f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "j0f64x,j0f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "j1f128,j1f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "j1f32,j1f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "j1f32x,j1f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "j1f64,j1f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "j1f64x,j1f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "jnf128,jnf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "jnf32,jnf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "jnf32x,jnf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "jnf64,jnf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "jnf64x,jnf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "key_decryptsession,key_decryptsession@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "key_decryptsession_pk,key_decryptsession_pk@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "key_encryptsession,key_encryptsession@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "key_encryptsession_pk,key_encryptsession_pk@GLIBC_WRAP_ERROR_SYMBOL_"
        "NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "key_get_conv,key_get_conv@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "key_setnet,key_setnet@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "key_setsecret,key_setsecret@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ldexpf128,ldexpf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ldexpf32,ldexpf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ldexpf32x,ldexpf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ldexpf64,ldexpf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ldexpf64x,ldexpf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lgammaf128,lgammaf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf128_r,lgammaf128_r@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf32,lgammaf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lgammaf32_r,lgammaf32_r@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf32x,lgammaf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf32x_r,lgammaf32x_r@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf64,lgammaf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lgammaf64_r,lgammaf64_r@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf64x,lgammaf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lgammaf64x_r,lgammaf64x_r@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llogb,llogb@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "llogbf,llogbf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "llogbf128,llogbf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llogbf32,llogbf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llogbf32x,llogbf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llogbf64,llogbf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llogbf64x,llogbf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "llogbl,llogbl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "llrintf128,llrintf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llrintf32,llrintf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llrintf32x,llrintf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llrintf64,llrintf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "llrintf64x,llrintf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llroundf128,llroundf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llroundf32,llroundf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llroundf32x,llroundf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llroundf64,llroundf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "llroundf64x,llroundf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "log10f128,log10f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log10f32,log10f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log10f32x,log10f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log10f64,log10f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log10f64x,log10f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log1pf128,log1pf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log1pf32,log1pf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log1pf32x,log1pf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log1pf64,log1pf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log1pf64x,log1pf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "log2f128,log2f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "log2f32,log2f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "log2f32x,log2f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "log2f64,log2f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "log2f64x,log2f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "logbf128,logbf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "logbf32,logbf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "logbf32x,logbf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "logbf64,logbf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "logbf64x,logbf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "logf128,logf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "logf32,logf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "logf32x,logf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "logf64,logf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "logf64x,logf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "lrintf128,lrintf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lrintf32,lrintf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lrintf32x,lrintf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lrintf64,lrintf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lrintf64x,lrintf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lroundf128,lroundf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lroundf32,lroundf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lroundf32x,lroundf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "lroundf64,lroundf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "lroundf64x,lroundf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "memfd_create,memfd_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "mlock2,mlock2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "modff128,modff128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "modff32,modff32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "modff32x,modff32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "modff64,modff64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "modff64x,modff64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "nanf128,nanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "nanf32,nanf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "nanf32x,nanf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "nanf64,nanf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "nanf64x,nanf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "nearbyintf128,nearbyintf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nearbyintf32,nearbyintf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nearbyintf32x,nearbyintf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nearbyintf64,nearbyintf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nearbyintf64x,nearbyintf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "netname2host,netname2host@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "netname2user,netname2user@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextafterf128,nextafterf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextafterf32,nextafterf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextafterf32x,nextafterf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextafterf64,nextafterf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextafterf64x,nextafterf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdown,nextdown@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "nextdownf,nextdownf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "nextdownf128,nextdownf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdownf32,nextdownf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdownf32x,nextdownf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdownf64,nextdownf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdownf64x,nextdownf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextdownl,nextdownl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "nextup,nextup@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "nextupf,nextupf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "nextupf128,nextupf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextupf32,nextupf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "nextupf32x,nextupf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "nextupf64,nextupf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "nextupf64x,nextupf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "nextupl,nextupl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "passwd2des,passwd2des@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pkey_alloc,pkey_alloc@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pkey_free,pkey_free@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "pkey_get,pkey_get@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "pkey_mprotect,pkey_mprotect@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pkey_set,pkey_set@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "pmap_getmaps,pmap_getmaps@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pmap_getport,pmap_getport@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pmap_rmtcall,pmap_rmtcall@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pmap_set,pmap_set@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "pmap_unset,pmap_unset@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "powf128,powf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "powf32,powf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "powf32x,powf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "powf64,powf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "powf64x,powf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "preadv2,preadv2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "preadv64v2,preadv64v2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "pthread_getattr_default_np,pthread_getattr_default_np@GLIBC_WRAP_"
        "ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "pthread_setattr_default_np,pthread_setattr_default_np@GLIBC_WRAP_"
        "ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "pwritev2,pwritev2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "pwritev64v2,pwritev64v2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "reallocarray,reallocarray@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "registerrpc,registerrpc@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remainderf128,remainderf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remainderf32,remainderf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remainderf32x,remainderf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remainderf64,remainderf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remainderf64x,remainderf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remquof128,remquof128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remquof32,remquof32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "remquof32x,remquof32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "remquof64,remquof64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "remquof64x,remquof64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "rintf128,rintf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "rintf32,rintf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "rintf32x,rintf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "rintf64,rintf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "rintf64x,rintf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundeven,roundeven@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundevenf,roundevenf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenf128,roundevenf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenf32,roundevenf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenf32x,roundevenf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenf64,roundevenf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenf64x,roundevenf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundevenl,roundevenl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "roundf128,roundf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundf32,roundf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundf32x,roundf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundf64,roundf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "roundf64x,roundf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "rtime,rtime@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "scalblnf128,scalblnf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalblnf32,scalblnf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalblnf32x,scalblnf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalblnf64,scalblnf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalblnf64x,scalblnf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalbnf128,scalbnf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalbnf32,scalbnf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "scalbnf32x,scalbnf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "scalbnf64,scalbnf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "scalbnf64x,scalbnf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayload,setpayload@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf,setpayloadf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf128,setpayloadf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf32,setpayloadf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf32x,setpayloadf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf64,setpayloadf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadf64x,setpayloadf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadl,setpayloadl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsig,setpayloadsig@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf,setpayloadsigf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf128,setpayloadsigf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf32,setpayloadsigf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf32x,setpayloadsigf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf64,setpayloadsigf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigf64x,setpayloadsigf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "setpayloadsigl,setpayloadsigl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "sincosf128,sincosf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "sincosf32,sincosf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "sincosf32x,sincosf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "sincosf64,sincosf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "sincosf64x,sincosf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "sinf128,sinf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "sinf32,sinf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "sinf32x,sinf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "sinf64,sinf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "sinf64x,sinf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "sinhf128,sinhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "sinhf32,sinhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "sinhf32x,sinhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "sinhf64,sinhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "sinhf64x,sinhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "sqrtf128,sqrtf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "sqrtf32,sqrtf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "sqrtf32x,sqrtf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "sqrtf64,sqrtf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "sqrtf64x,sqrtf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strfromd,strfromd@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strfromf,strfromf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strfromf128,strfromf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strfromf32,strfromf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strfromf32x,strfromf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strfromf64,strfromf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strfromf64x,strfromf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strfroml,strfroml@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof128,strtof128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof128_l,strtof128_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strtof32,strtof32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof32_l,strtof32_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strtof32x,strtof32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof32x_l,strtof32x_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strtof64,strtof64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof64_l,strtof64_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "strtof64x,strtof64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "strtof64x_l,strtof64x_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svc_exit,svc_exit@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "svc_getreq,svc_getreq@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svc_getreq_common,svc_getreq_common@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "svc_getreqset,svc_getreqset@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "svc_run,svc_run@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "svc_unregister,svc_unregister@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcerr_auth,svcerr_auth@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcerr_noprog,svcerr_noprog@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcerr_progvers,svcerr_progvers@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "svcerr_weakauth,svcerr_weakauth@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "svcfd_create,svcfd_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcraw_create,svcraw_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcudp_create,svcudp_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcudp_enablecache,svcudp_enablecache@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "svcunix_create,svcunix_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "svcunixfd_create,svcunixfd_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "tanf128,tanf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "tanf32,tanf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "tanf32x,tanf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "tanf64,tanf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "tanf64x,tanf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "tanhf128,tanhf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "tanhf32,tanhf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "tanhf32x,tanhf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "tanhf64,tanhf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "tanhf64x,tanhf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "tgammaf128,tgammaf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "tgammaf32,tgammaf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "tgammaf32x,tgammaf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "tgammaf64,tgammaf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "tgammaf64x,tgammaf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorder,totalorder@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf,totalorderf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf128,totalorderf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf32,totalorderf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf32x,totalorderf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf64,totalorderf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderf64x,totalorderf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalorderl,totalorderl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalordermag,totalordermag@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf,totalordermagf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf128,totalordermagf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf32,totalordermagf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf32x,totalordermagf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf64,totalordermagf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagf64x,totalordermagf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "totalordermagl,totalordermagl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "truncf128,truncf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "truncf32,truncf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "truncf32x,truncf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "truncf64,truncf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "truncf64x,truncf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(
    ".symver "
    "ufromfp,ufromfp@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpf,ufromfpf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ufromfpf128,ufromfpf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpf32,ufromfpf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpf32x,ufromfpf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpf64,ufromfpf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpf64x,ufromfpf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpl,ufromfpl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ufromfpx,ufromfpx@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ufromfpxf,ufromfpxf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "ufromfpxf128,ufromfpxf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpxf32,ufromfpxf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpxf32x,ufromfpxf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpxf64,ufromfpxf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpxf64x,ufromfpxf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "ufromfpxl,ufromfpxl@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "user2netname,user2netname@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "wcstof128,wcstof128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "wcstof128_l,wcstof128_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "wcstof32,wcstof32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "wcstof32_l,wcstof32_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "wcstof32x,wcstof32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "wcstof32x_l,wcstof32x_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "wcstof64,wcstof64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "wcstof64_l,wcstof64_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "wcstof64x,wcstof64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "wcstof64x_l,wcstof64x_l@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_accepted_reply,xdr_accepted_reply@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_authdes_cred,xdr_authdes_cred@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_authdes_verf,xdr_authdes_verf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_authunix_parms,xdr_authunix_parms@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_callhdr,xdr_callhdr@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_callmsg,xdr_callmsg@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_char,xdr_char@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_cryptkeyarg,xdr_cryptkeyarg@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_cryptkeyarg2,xdr_cryptkeyarg2@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_cryptkeyres,xdr_cryptkeyres@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_des_block,xdr_des_block@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_double,xdr_double@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_float,xdr_float@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_getcredres,xdr_getcredres@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_hyper,xdr_hyper@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_int16_t,xdr_int16_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_int32_t,xdr_int32_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_int64_t,xdr_int64_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_int8_t,xdr_int8_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_key_netstarg,xdr_key_netstarg@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_key_netstres,xdr_key_netstres@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_keybuf,xdr_keybuf@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_keystatus,xdr_keystatus@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_long,xdr_long@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_longlong_t,xdr_longlong_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_netnamestr,xdr_netnamestr@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_opaque_auth,xdr_opaque_auth@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_pmap,xdr_pmap@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_pmaplist,xdr_pmaplist@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_quad_t,xdr_quad_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_reference,xdr_reference@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_rejected_reply,xdr_rejected_reply@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_replymsg,xdr_replymsg@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_rmtcall_args,xdr_rmtcall_args@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_rmtcallres,xdr_rmtcallres@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_short,xdr_short@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_u_hyper,xdr_u_hyper@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_u_long,xdr_u_long@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_u_longlong_t,xdr_u_longlong_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_"
        "IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdr_u_quad_t,xdr_u_quad_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_u_short,xdr_u_short@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_uint16_t,xdr_uint16_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_uint64_t,xdr_uint64_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_uint8_t,xdr_uint8_t@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_union,xdr_union@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xdr_unixcred,xdr_unixcred@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_vector,xdr_vector@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdr_wrapstring,xdr_wrapstring@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdrrec_create,xdrrec_create@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdrrec_endofrecord,xdrrec_endofrecord@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "xdrrec_eof,xdrrec_eof@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(".symver "
        "xdrrec_skiprecord,xdrrec_skiprecord@GLIBC_WRAP_ERROR_SYMBOL_NOT_"
        "PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "xencrypt,xencrypt@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_"
        "VERSION");
__asm__(".symver "
        "xprt_register,xprt_register@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_"
        "REQUESTED_VERSION");
__asm__(
    ".symver "
    "y0f128,y0f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "y0f32,y0f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "y0f32x,y0f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "y0f64,y0f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "y0f64x,y0f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "y1f128,y1f128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "y1f32,y1f32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "y1f32x,y1f32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "y1f64,y1f64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "y1f64x,y1f64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "ynf128,ynf128@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ynf32,ynf32@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "ynf32x,ynf32x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(".symver "
        "ynf64,ynf64@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
__asm__(
    ".symver "
    "ynf64x,ynf64x@GLIBC_WRAP_ERROR_SYMBOL_NOT_PRESENT_IN_REQUESTED_VERSION");
#endif