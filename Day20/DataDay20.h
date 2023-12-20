#pragma once

#include <iterator>

//#define USE_TEST_DATA

#ifdef USE_TEST_DATA

constexpr const char* s_Data2[] =
{
"broadcaster -> a",
"%a -> inv, con",
"&inv -> b",
"%b -> con",
"&con -> output"
};

constexpr const char* s_Data[] =
{
    "broadcaster -> a, b, c",
    "%a -> b",
    "%b -> c",
    "%c -> inv",
    "&inv -> a"
    };

#else

constexpr const char* s_Data[] =
{
    "%sf -> pz, gj",
    "%zh -> bc, st",
    "%hk -> bc",
    "&bc -> mn, zl, xb, mm, dh, hv, gz",
    "%st -> bc, mm",
    "%gv -> xf, qq",
    "%hv -> xb",
    "%nd -> gj, tr",
    "%zx -> bx, ms",
    "%sc -> ks, gj",
    "%gr -> hn",
    "%pl -> qq, rh",
    "%qc -> sf, gj",
    "%xr -> sc, gj",
    "%zl -> zh",
    "&gj -> ks, ld, sg, xr",
    "%dg -> ll, bx",
    "%nf -> bc, tg",
    "%lz -> cv, qq",
    "%nq -> dg, bx",
    "%rh -> qq, lp",
    "%xf -> qq, qj",
    "%ms -> bx, xh",
    "%mn -> bc, hv",
    "&jm -> rx",
    "%xh -> vt, bx",
    "%pz -> gj",
    "%vq -> bt",
    "%gz -> nf",
    "%bt -> gr",
    "&sg -> jm",
    "%fr -> bx, tb",
    "&lm -> jm",
    "%ld -> cl",
    "%cv -> vq",
    "%cl -> gj, jf",
    "%tr -> gj, sz",
    "%sz -> gj, ld",
    "%dx -> hk, bc",
    "%lr -> bx, fr",
    "%vt -> lr, bx",
    "%ll -> zx",
    "broadcaster -> pl, xr, mn, xc",
    "%lp -> lz",
    "%mm -> gz",
    "&qq -> lm, gr, cv, vq, lp, pl, bt",
    "%xb -> zl",
    "&bx -> ll, xc, db",
    "%tb -> bx",
    "%hn -> gv, qq",
    "%jf -> qc, gj",
    "%qj -> qq",
    "%xc -> bx, pm",
    "%tg -> bc, dx",
    "&dh -> jm",
    "%ks -> nd",
    "&db -> jm",
    "%pm -> bx, nq"
};

#endif

constexpr int NUM_ROWS = std::size(s_Data);
