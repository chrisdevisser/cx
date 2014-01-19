#pragma once
#ifndef CX_CONFIG_H
#define CX_CONFIG_H

#ifdef CX_NO_STATIC_FUNCTIONS
    #define CX_STATIC
#else
    #define CX_STATIC static
#endif

#endif
