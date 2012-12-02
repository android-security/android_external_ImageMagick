/*
  Copyright 2012 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.
  obtain a copy of the License at

    http://www.imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickConfig not autogenerated (fixed stuff)
*/
#ifndef _MAGICKCORE_MAGICK_CONFIG_H
#define _MAGICKCORE_MAGICK_CONFIG_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "MagickCore/magick-baseconfig.h"

#if defined __CYGWIN32__ && !defined __CYGWIN__
   /* For backwards compatibility with Cygwin b19 and
      earlier, we define __CYGWIN__ here, so that
      we can rely on checking just for that macro. */
#  define __CYGWIN__  __CYGWIN32__
#endif

/*! stringify */
#define MAGICKCORE_STRING_QUOTE(str) #str
#define MAGICKCORE_STRING_XQUOTE(str) MAGICKCORE_STRING_QUOTE(str)

/*  ABI SUFFIX */
#ifndef MAGICKCORE_HDRI_SUPPORT
#define MAGICKCORE_ABI_SUFFIX  "Q" MAGICKCORE_STRING_XQUOTE(MAGICKCORE_QUANTUM_DEPTH)
#else 
#define MAGICKCORE_ABI_SUFFIX "Q" MAGICKCORE_STRING_XQUOTE(MAGICKCORE_QUANTUM_DEPTH) "-HDRI"
#endif 

/* some path game */
#if !defined __CYGWIN__
# if defined (_WIN32) || defined (_WIN64) || defined (__MSDOS__) || defined (__DJGPP__) || defined (__OS2__)
   /* Use Windows separators on all _WIN32 defining
      environments, except Cygwin. */
#  define MAGICKCORE_DIR_SEPARATOR_CHAR		'\\'
#  define MAGICKCORE_DIR_SEPARATOR		"\\"
#  define MAGICKCORE_PATH_SEPARATOR_CHAR	';'
#  define MAGICKCORE_PATH_SEPARATOR		";"
# endif
#endif
 
/* posix */
#ifndef MAGICKCORE_DIR_SEPARATOR_CHAR
   /* Assume that not having this is an indicator that all
      are missing. */
#  define MAGICKCORE_DIR_SEPARATOR_CHAR		'/'
#  define MAGICKCORE_DIR_SEPARATOR		"/"
#  define MAGICKCORE_PATH_SEPARATOR_CHAR	':'
#  define MAGICKCORE_PATH_SEPARATOR		":"
#endif /* !DIR_SEPARATOR_CHAR */
 
/* module dir */
#ifndef MAGICKCORE_MODULES_DIRNAME
# define MAGICKCORE_MODULES_DIRNAME MAGICKCORE_MODULES_BASEDIRNAME "-" MAGICKCORE_ABI_SUFFIX
#endif
 
#ifndef MAGICKCORE_MODULES_PATH
#  define MAGICKCORE_MODULES_PATH MAGICKCORE_LIBRARY_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_MODULES_DIRNAME
#endif
 
#ifndef MAGICKCORE_MODULES_RELATIVE_PATH
#define MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_LIBRARY_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_MODULES_DIRNAME
#endif
 
/* Subdirectory under lib to place ImageMagick coder module files */
#ifndef MAGICKCORE_CODER_PATH
# if defined(vms)
#  define MAGICKCORE_CODER_PATH "sys$login:"
# else
#  define MAGICKCORE_CODER_PATH MAGICKCORE_MODULES_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_CODER_DIRNAME
# endif
#endif
 
#ifndef MAGICKCORE_CODER_RELATIVE_PATH
# define MAGICKCORE_CODER_RELATIVE_PATH MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_CODER_DIRNAME
#endif
 
/* subdirectory under lib to place ImageMagick filter module files */
#ifndef MAGICKCORE_FILTER_PATH
# if defined(vms)
#  define MAGICKCORE_FILTER_PATH  "sys$login:"
# else
#  define MAGICKCORE_FILTER_PATH MAGICKCORE_MODULES_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_FILTER_DIRNAME
# endif
#endif
 
#ifndef MAGICKCORE_FILTER_RELATIVE_PATH
# define MAGICKCORE_FILTER_RELATIVE_PATH MAGICKCORE_MODULES_RELATIVE_PATH MAGICKCORE_DIR_SEPARATOR MAGICKCORE_FILTER_DIRNAME
#endif
 
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif
 
#endif
