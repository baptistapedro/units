/*
Copyright � 2019,
Lawrence Livermore National Security, LLC;
See the top-level NOTICE for additional details. All rights reserved.
SPDX-License-Identifier: BSD-3-Clause
*/
#pragma once

#include "units_decl.hpp"
#include <limits>

namespace units
{
/// Constants used in definitions of units
namespace constants
{
    constexpr double pi = 3.141592653589793;
    constexpr double tau = 2.0 * pi;
    constexpr double invalid_conversion = std::numeric_limits<double>::signaling_NaN();
    constexpr double infinity = std::numeric_limits<double>::infinity();
}  // namespace constants

/// basic commodity definitions
namespace commodities
{
    // https://en.wikipedia.org/wiki/List_of_traded_commodities
    enum commodity : uint32_t
    {
        water = 1,
        // metals
        gold = 2,
        copper = 4,
        silver = 6,
        platinum = 7,
        palladium = 8,
        zinc = 9,
        tin = 10,
        lead = 11,
        aluminum = 12,
        alluminum_alloy = 13,
        nickel = 14,
        cobolt = 15,
        molybdenum = 16,

        // energy
        oil = 101,
        heat_oil = 102,
        nat_gas = 103,
        brent_crude = 104,
        ethanol = 105,
        propane = 107,
        // grains
        wheat = 404,
        corn = 405,
        soybeans = 406,
        soybean_meal = 407,
        soybean_oil = 408,
        oats = 409,
        rice = 410,
        red_wheat = 411,
        spring_wheat = 412,
        canola = 413,
        rough_rice = 414,
        rapeseed = 415,
        adzuci = 418,
        barley = 420,
        // meats
        live_cattle = 601,
        feeder_cattle = 602,
        lean_hogs = 603,
        milk = 604,

        // soft
        cotton = 945,
        orange_juice = 947,
        sugar = 948,
        sugar_11 = 949,
        sugar_14 = 950,
        coffee = 952,
        cocoa = 961,
        palm_oil = 971,
        rubber = 999,
        wool = 946,
        lumber = 5007,

        // other common unit blocks
        people = 115125,
        particles = 117463,
        cars = 43567,
        flop = 215262,
        instruction = 452255,

        // clinical
        tissue = 4622626,
        cell = 45236884,
        embryo = 52632253,
        Hahnemann = 2352622,
        Korsakov = 262626562,
        protein = 325255,
        creatinine = 2566225,

        // computer
        pixel = 516115414,
        voxel = 516115415,
    };
}  // namespace commodities

// SI units:
namespace precise
{
    constexpr precise_unit meter(detail::unit_data(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit m = meter;
    constexpr precise_unit kilogram(detail::unit_data(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit kg = kilogram;
    constexpr precise_unit second(detail::unit_data(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit s = second;

    constexpr precise_unit Ampere(detail::unit_data(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit A = Ampere;

    constexpr precise_unit Kelvin(detail::unit_data(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit K = Kelvin;
    constexpr precise_unit mol(detail::unit_data(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit cd(detail::unit_data(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0));

    constexpr precise_unit currency(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit count(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0));
    constexpr precise_unit pu(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0));
    constexpr precise_unit flag(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0));
    constexpr precise_unit eflag(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0));
    constexpr precise_unit rad(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0));
    // define a specialized default unit
    constexpr precise_unit defunit(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0));
    constexpr precise_unit invalid(detail::unit_data(nullptr), constants::invalid_conversion);

    /// Define a unitless number
    constexpr precise_unit one;
    constexpr precise_unit hundred = precise_unit(100.0, one);
    constexpr precise_unit ten = precise_unit(10.0, one);
    constexpr precise_unit percent(0.01, one);
    constexpr precise_unit ratio = one;
    constexpr precise_unit error(detail::unit_data(nullptr));
    constexpr precise_unit
      infinite(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), constants::infinity);
    constexpr precise_unit
      nan(detail::unit_data(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), constants::invalid_conversion);
    // SI prefixes as units
    constexpr precise_unit milli(1e-3, one);
    constexpr precise_unit micro(1e-6, one);
    constexpr precise_unit nano(1e-9, one);
    constexpr precise_unit pico(1e-12, one);
    constexpr precise_unit femto(1e-15, one);
    constexpr precise_unit atto(1e-18, one);
    constexpr precise_unit kilo(1e3, one);
    constexpr precise_unit mega(1e6, one);
    constexpr precise_unit giga(1e9, one);
    constexpr precise_unit tera(1e12, one);
    constexpr precise_unit peta(1e15, one);
    constexpr precise_unit exa(1e18, one);

    constexpr precise_unit kibi(1024, one);
    constexpr precise_unit mebi = kibi * kibi;
    constexpr precise_unit gibi = mebi * kibi;
    constexpr precise_unit tebi = gibi * kibi;
    constexpr precise_unit pebi = tebi * kibi;
    constexpr precise_unit exbi = pebi * kibi;

    // Derived units:
    constexpr precise_unit Hz(detail::unit_data(0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));

    constexpr precise_unit volt(detail::unit_data(2, 1, -3, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit V = volt;

    constexpr precise_unit newton(detail::unit_data(1, 1, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit pascal(detail::unit_data(-1, 1, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit joule(detail::unit_data(2, 1, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit watt(detail::unit_data(2, 1, -3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit coulomb(detail::unit_data(0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit farad(detail::unit_data(-2, -1, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit ohm(detail::unit_data(2, 1, -3, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit siemens(detail::unit_data(-2, -1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit weber(detail::unit_data(2, 1, -2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit tesla(detail::unit_data(0, 1, -2, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit henry(detail::unit_data(2, 1, -2, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit lumen(detail::unit_data(0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0));
    constexpr precise_unit lux(detail::unit_data(-2, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0));
    constexpr precise_unit becquerel(detail::unit_data(0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0));
    constexpr precise_unit gray(detail::unit_data(2, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit sievert(detail::unit_data(2, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    constexpr precise_unit katal(detail::unit_data(0, 0, -1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0));

    constexpr precise_unit N = newton;
    constexpr precise_unit Pa = pascal;
    constexpr precise_unit J = joule;
    constexpr precise_unit W = watt;
    constexpr precise_unit C = coulomb;
    constexpr precise_unit F = farad;
    constexpr precise_unit S = siemens;
    constexpr precise_unit Wb = weber;
    constexpr precise_unit T = tesla;
    constexpr precise_unit H = henry;
    constexpr precise_unit lm = lumen;
    constexpr precise_unit lx = lux;
    constexpr precise_unit Bq = becquerel;
    constexpr precise_unit Gy = gray;
    constexpr precise_unit Sv = sievert;
    constexpr precise_unit kat = katal;
    constexpr precise_unit sr = rad * rad;

    // Extra SI units
    constexpr precise_unit bar(100000.0, Pa);

    // Distance units
    constexpr precise_unit cm(0.01, m);
    constexpr precise_unit km(1000.0, m);
    constexpr precise_unit mm(0.001, m);
    constexpr precise_unit nm(1e-9, m);

    // Volume units
    constexpr precise_unit L{0.001, m *m *m};
    constexpr precise_unit mL{0.001, L};
    // mass units
    constexpr precise_unit g(0.001, kg);
    constexpr precise_unit mg(0.001, g);

    /// Units from the cgs system
    namespace cgs
    {
        constexpr double c_const = 29979245800.0;  // speed of light in cm/s
        constexpr precise_unit erg(1e-7, J);
        constexpr precise_unit dyn(1e-5, N);
        constexpr precise_unit barye(0.1, Pa);
        constexpr precise_unit gal = cm / s.pow(2);
        constexpr precise_unit poise{0.1, Pa *s};
        constexpr precise_unit stokes{1e-4, m.pow(2) / s};
        constexpr precise_unit kayser = one / cm;
        constexpr precise_unit oersted{1000.0 / 4.0 / constants::pi, A / m};
        constexpr precise_unit gauss{1e-4, T};
        constexpr precise_unit debye{1.0 / (c_const * 1e20), C *m};
        constexpr precise_unit maxwell{1e-8, Wb};
        constexpr precise_unit biot{10.0, A};
        constexpr precise_unit gilbert = oersted * cm;
        constexpr precise_unit stilb = cd / cm.pow(2);
        constexpr precise_unit lambert{1.0 / constants::pi, cd / cm.pow(2)};
        constexpr precise_unit phot{10000, lx};
        constexpr precise_unit curie(3.7e10, Bq);
        constexpr precise_unit roentgen{2.58e-4, C / kg};
        constexpr precise_unit REM{0.01, precise::Sv};
        constexpr precise_unit RAD{100, erg / g};
        constexpr precise_unit emu{0.001, A *m *m};
        constexpr precise_unit langley{41840.0, J / m.pow(2)};
        constexpr precise_unit unitpole{1.256637061436e-7, Wb};
        constexpr precise_unit statC_charge{10.0 / c_const, C};
        constexpr precise_unit statC_flux{10.0 / (4.0 * constants::pi * c_const), V *m};
        constexpr precise_unit abOhm{1e-9, ohm};
        constexpr precise_unit abFarad{1e9, F};
        constexpr precise_unit abHenry{1e-9, H};
        constexpr precise_unit abVolt{1e-8, V};
        constexpr precise_unit statV{c_const, abVolt};
        constexpr precise_unit statT{c_const * 1e-4, T};
        constexpr precise_unit statHenry{c_const * c_const, abHenry};
        constexpr precise_unit statOhm{c_const * c_const, abOhm};
        constexpr precise_unit statFarad{1.0 / (c_const * c_const), abFarad};

    }  // namespace cgs

    namespace gm
    {
        constexpr precise_unit pond{980.665, cgs::dyn};
        constexpr precise_unit hyl{9.80665, kg};
        constexpr precise_unit at{98066.5, Pa};
        constexpr precise_unit poncelet{980.665, W};
        constexpr precise_unit PS{735.49875, W};  // metric horsepower

    }  // namespace gm

    /// Meter tonne second system of units
    namespace MTS
    {
        constexpr precise_unit sthene{1000.0, N};
        constexpr precise_unit pieze{1000.0, Pa};
        constexpr precise_unit thermie{4.186, mega *J};

    }  // namespace MTS

    /// Units of time
    namespace time
    {
        // Time unit
        constexpr precise_unit min(60.0, s);
        constexpr precise_unit ms(0.001, s);
        constexpr precise_unit ns(1e-9, s);
        constexpr precise_unit hr(60.0, min);
        constexpr precise_unit day(24.0, hr);
        constexpr precise_unit week(7.0, day);
        constexpr precise_unit yr(8760.0, hr);  // median calendar year;
        constexpr precise_unit fortnight(14, day);

        constexpr precise_unit sday{365.24 / 366.24, day};  // sidereal day
        constexpr precise_unit syr(365.256363004, day);  // sidereal year
        constexpr precise_unit at{365.24219, day *flag};  // mean tropical year
        constexpr precise_unit aj{365.25, day};  // julian year
        constexpr precise_unit ag{365.2425, day};  // gregorian year
        constexpr precise_unit year = aj;  // standard year
        constexpr precise_unit mos{29.53059, day};  // synodal month
        constexpr precise_unit moj{1.0 / 12.0, aj};  // mean julian month
        constexpr precise_unit mog{1.0 / 12.0, ag};  // mean gregorian month
    }  // namespace time

    constexpr precise_unit min = time::min;
    constexpr precise_unit ms = time::ms;
    constexpr precise_unit ns = time::ns;
    constexpr precise_unit hr = time::hr;
    constexpr precise_unit yr = time::yr;

    // International units
    namespace i
    {
        constexpr precise_unit grain{64.79891, mg};

        constexpr precise_unit point(127.0 / 360.0, mm);
        constexpr precise_unit pica(127.0 / 30.0, mm);
        constexpr precise_unit inch(0.0254, m);
        constexpr precise_unit foot(0.3048, m);

        constexpr precise_unit yard(0.9144, m);
        constexpr precise_unit mile(1609.344, m);
        constexpr precise_unit league(3.0, mile);
        constexpr precise_unit hand(4.0, inch);

        constexpr precise_unit cord{128.0, foot.pow(3)};
        constexpr precise_unit board_foot{144, inch.pow(3)};
        constexpr precise_unit mil = milli * inch;
        constexpr precise_unit circ_mil = {constants::pi / 4.0, mil.pow(2)};

    }  // namespace i

    constexpr precise_unit in = i::inch;

    constexpr precise_unit ft = i::foot;
    constexpr precise_unit yd = i::yard;
    constexpr precise_unit mile = i::mile;

    // https://en.wikipedia.org/wiki/United_States_customary_units

    // Avoirdupois units, common international standard
    namespace av
    {
        constexpr precise_unit dram{1.7718451953125, g};
        constexpr precise_unit ounce{16.0, dram};
        constexpr precise_unit pound{453.59237, g};
        constexpr precise_unit hundredweight{100.0, pound};
        constexpr precise_unit longhundredweight{112, pound};
        constexpr precise_unit ton{2000.0, pound};
        constexpr precise_unit longton{2240.0, pound};
        constexpr precise_unit stone{14.0, pound};
        constexpr precise_unit lbf = precise_unit(4.4482216152605, precise::N);
        constexpr precise_unit ozf{1.0 / 16.0, lbf};
        constexpr precise_unit slug = lbf * s.pow(2) / ft;
        constexpr precise_unit poundal{0.138254954376, N};
    }  // namespace av

    constexpr precise_unit lb = av::pound;
    constexpr precise_unit ton = av::ton;
    constexpr precise_unit oz = av::ounce;
    constexpr precise_unit lbf = av::lbf;
    // troy units
    namespace troy
    {
        constexpr precise_unit pennyweight{24.0, i::grain};
        constexpr precise_unit oz{31.1034768, g};
        constexpr precise_unit pound{12.0, oz};
    }  // namespace troy

    // US customary units (survey)
    namespace us
    {
        constexpr precise_unit foot{1200.0 / 3937.0, m};
        constexpr precise_unit inch{1.0 / 12.0, foot};
        constexpr precise_unit mil{0.001, inch};
        constexpr precise_unit yard(3.0, foot);
        constexpr precise_unit rod(16.5, foot);
        constexpr precise_unit chain(4.0, rod);
        constexpr precise_unit link(0.01, chain);
        constexpr precise_unit furlong(10.0, chain);
        constexpr precise_unit mile(8.0, furlong);
        constexpr precise_unit league(3.0, mile);
        namespace engineers
        {
            constexpr precise_unit chain(100.0, foot);
            constexpr precise_unit link(0.01, chain);
        }  // namespace engineers
        // area
        constexpr precise_unit acre(43560.0, foot.pow(2));
        constexpr precise_unit homestead(160.0, acre);
        constexpr precise_unit section(640.0, acre);
        constexpr precise_unit township(36.0, section);
        // volume
        constexpr precise_unit minim{61.611519921875, micro *L};
        constexpr precise_unit dram{60.0, minim};
        constexpr precise_unit floz{29.5735295625e-6, m *m *m};
        constexpr precise_unit tbsp{0.5, floz};
        constexpr precise_unit tsp{1.0 / 6.0, floz};
        constexpr precise_unit pinch{0.125, tsp};
        constexpr precise_unit dash{0.5, pinch};
        constexpr precise_unit shot{3.0, tbsp};
        constexpr precise_unit gill{4.0, floz};
        constexpr precise_unit cup{8.0, floz};
        constexpr precise_unit pint{2.0, cup};
        constexpr precise_unit quart{2.0, pint};
        constexpr precise_unit gallon{3.785411784, L};
        constexpr precise_unit flbarrel{31.5, gallon};
        constexpr precise_unit barrel{42.0, gallon};
        constexpr precise_unit hogshead{63.0, gallon};
        constexpr precise_unit cord{128.0, i::foot.pow(3)};
        constexpr precise_unit fifth{0.2, gallon};

        /// Us customary dry measurements
        namespace dry
        {
            constexpr precise_unit pint{0.5506104713575, L};
            constexpr precise_unit quart{2.0, pint};
            constexpr precise_unit gallon{4.0, quart};
            constexpr precise_unit peck{2.0, gallon};
            constexpr precise_unit bushel{35.23907016688, L};
            constexpr precise_unit barrel{7056, i::inch.pow(3)};
            constexpr precise_unit sack{3.0, bushel};
            constexpr precise_unit strike{2.0, bushel};
        }  // namespace dry
        namespace grain
        {
            constexpr precise_unit bushel_corn{56.0, av::pound};
            constexpr precise_unit bushel_wheat{60.0, av::pound};
            constexpr precise_unit bushel_barley{48.0, av::pound};
            constexpr precise_unit bushel_oats{32.0, av::pound};
        }  // namespace grain

    }  // namespace us

    // Volume units
    constexpr precise_unit gal = us::gallon;

    /// FDA specific volume units in metric
    namespace metric
    {
        constexpr precise_unit tbsp{15.0, mL};
        constexpr precise_unit tsp{5.0, mL};
        constexpr precise_unit floz{30.0, mL};
        constexpr precise_unit cup{250.0, mL};
        constexpr precise_unit cup_uslegal{240.0, mL};
        constexpr precise_unit carat{0.2, g};
    }  // namespace metric

    /// Some Canada specific variants on the us units
    namespace canada
    {
        constexpr precise_unit tbsp{15.0, mL};
        constexpr precise_unit tsp{5.0, mL};
        constexpr precise_unit cup{250.0, mL};
        constexpr precise_unit cup_trad{227.3045, mL};
        namespace grain
        {
            constexpr precise_unit bushel_oats{34.0, av::pound};
        }
    }  // namespace canada

    /// Some Canada specific variants on the us units
    namespace australia
    {
        constexpr precise_unit tbsp{20.0, mL};
        constexpr precise_unit tsp{5.0, mL};
        constexpr precise_unit cup{250.0, mL};
    }  // namespace australia

    /// Imperial system units (British)
    namespace imp
    {
        constexpr precise_unit inch{2.539998, cm *flag};
        constexpr precise_unit foot{12.0, inch};

        constexpr precise_unit thou{0.0254, mm};
        constexpr precise_unit barleycorn{1.0 / 3.0, inch};
        constexpr precise_unit rod{16.5, foot};
        constexpr precise_unit chain(4.0, rod);
        constexpr precise_unit link{0.01, chain};
        constexpr precise_unit pace{2.5, foot};
        constexpr precise_unit yard{3.0, foot};
        constexpr precise_unit furlong(201.168, m);
        constexpr precise_unit league(4828.032, m);
        constexpr precise_unit mile{5280.0, foot};
        constexpr precise_unit nautical_mile{6080, foot};
        constexpr precise_unit knot = nautical_mile / hr;
        constexpr precise_unit acre{4840.0, yard.pow(2)};

        // area
        constexpr precise_unit perch{25.29285264, m *m};
        constexpr precise_unit rood{1011.7141056, m *m};
        // volume
        constexpr precise_unit gallon{4546.09, mL};
        constexpr precise_unit quart{0.25, gallon};
        constexpr precise_unit pint{0.5, quart};
        constexpr precise_unit gill{0.25, pint};
        constexpr precise_unit cup{0.5, pint};
        constexpr precise_unit floz{0.1, cup};
        constexpr precise_unit tbsp{0.5, floz};
        constexpr precise_unit tsp{1.0 / 3.0, tbsp};

        constexpr precise_unit barrel{36.0, gallon};
        constexpr precise_unit peck{2.0, gallon};
        constexpr precise_unit bushel{4.0, peck};
        constexpr precise_unit dram{1.0 / 8.0, floz};
        constexpr precise_unit minim{1.0 / 60.0, dram};
        // weight
        constexpr precise_unit drachm{1.7718451953125, g};
        constexpr precise_unit stone{6350.29318, g};
        constexpr precise_unit hundredweight{112.0, av::pound};
        constexpr precise_unit ton{2240.0, av::pound};
        constexpr precise_unit slug{14.59390294, kg};
    }  // namespace imp

    namespace apothecaries
    {
        constexpr precise_unit floz = imp::floz;
        constexpr precise_unit minim{59.1938802083333333333, milli *mL};
        constexpr precise_unit scruple{20.0, i::grain};
        constexpr precise_unit drachm{3.0, scruple};
        constexpr precise_unit ounce{8.0, drachm};
        constexpr precise_unit pound{12.0, ounce};
        constexpr precise_unit pint = imp::pint;
        constexpr precise_unit gallon = imp::gallon;
        constexpr precise_unit metric_ounce{28.0, g};
    }  // namespace apothecaries

    // Nautical units
    namespace nautical
    {
        constexpr precise_unit fathom(2.0, i::yard);
        constexpr precise_unit cable(120, fathom);
        constexpr precise_unit mile(1.852, km);
        constexpr precise_unit knot = mile / hr;
        constexpr precise_unit league(3.0, mile);
    }  // namespace nautical

    // Some historical Japanese units
    namespace japan
    {
        constexpr precise_unit shaku{10.0 / 33.0, m};
        constexpr precise_unit sun{0.1, shaku};
        constexpr precise_unit ken{1.0 + 9.0 / 11.0, m};
        constexpr precise_unit tsubo{100.0 / 30.25, m *m};
        constexpr precise_unit sho{2401.0 / 1331.0, L};
        constexpr precise_unit kan{15.0 / 4.0, kg};
        constexpr precise_unit go{2401.0 / 13310, L};
        constexpr precise_unit cup{200.0, mL};
    }  // namespace japan

    namespace chinese
    {
        constexpr precise_unit jin{0.5, kg};
        constexpr precise_unit liang{0.1, g};
        constexpr precise_unit qian{0.01, g};

        constexpr precise_unit li{500, m};
        constexpr precise_unit cun{10.0 / 300.0, m};
        constexpr precise_unit chi{10.0, cun};
        constexpr precise_unit zhang{10.0, chi};

    }  // namespace chinese

    /// Typographic units
    namespace typographic
    {
        namespace american
        {
            constexpr precise_unit line{1.0 / 12.0, i::inch};
            constexpr precise_unit point{1.0 / 6.0, line};
            constexpr precise_unit pica{12.0, point};
            constexpr precise_unit twip{1.0 / 20.0, point};

        }  // namespace american
        namespace printers
        {
            constexpr precise_unit point{0.013837, i::inch};
            constexpr precise_unit pica{12.0, point};
        }  // namespace printers

        namespace french
        {
            constexpr precise_unit point{15625.0 / 41559.0, mm};
            constexpr precise_unit ligne{6.0, point};
            constexpr precise_unit pouce{12.0, ligne};
            constexpr precise_unit didot = point;
            constexpr precise_unit cicero{12.0, didot};
            constexpr precise_unit pied{12.0, pouce};
            constexpr precise_unit toise{6.0, pied};

        }  // namespace french

        namespace metric
        {
            constexpr precise_unit point{375.0, micro *m};
            constexpr precise_unit quart{0.25, mm};

        }  // namespace metric

    }  // namespace typographic

    namespace distance
    {
        constexpr precise_unit ly(9.4607304725808e15, m);
        constexpr precise_unit au(149597870700.0, m);
        constexpr precise_unit angstrom(1e-10, m);
        constexpr precise_unit parsec{3.085678e16, m};
        constexpr precise_unit smoot{67.0, precise::i::inch};
        constexpr precise_unit cubit{18.0, precise::i::inch};
        constexpr precise_unit longcubit{21.0, precise::i::inch};
        constexpr precise_unit arpent_us{58.47131, m};
        constexpr precise_unit arpent_fr{71.46466, m};
        constexpr precise_unit xu{0.1, precise::pico *precise::m};

    }  // namespace distance
       //  Area units
    constexpr precise_unit acre = us::acre;
    /// Additional Area units
    namespace area
    {
        constexpr precise_unit are{100.0, m *m};
        constexpr precise_unit hectare(100.0, are);
        constexpr precise_unit barn{1e-28, m *m};
        constexpr precise_unit arpent{0.84628, acre};
    }  // namespace area

    namespace mass
    {
        constexpr precise_unit quintal{100.0, kg};
        constexpr precise_unit ton_assay{29.0 + 1. / 6.0, g};
        constexpr precise_unit longton_assay{32.0 + 2.0 / 3.0, g};
    }  // namespace mass
    /// some extra volume units
    namespace volume
    {
        constexpr precise_unit stere = m.pow(3);
        constexpr precise_unit acre_foot = acre * us::foot;
        constexpr precise_unit drum{55.0, us::gallon};
    }  // namespace volume

    // angle measure
    namespace angle
    {
        constexpr precise_unit deg(constants::pi / 180.0, rad);
        constexpr precise_unit gon{0.9, deg};
        constexpr precise_unit grad(constants::pi / 200.0, rad);
        constexpr precise_unit arcmin(1.0 / 60.0, deg);
        constexpr precise_unit arcsec(1.0 / 60.0, arcmin);
        constexpr precise_unit brad(constants::tau / 256.0, rad);  // binary radian
    }  // namespace angle
    constexpr precise_unit deg = angle::deg;

    // temperature
    namespace temperature
    {
        constexpr precise_unit celsius{1.0, K *flag};
        constexpr precise_unit degC = celsius;

        constexpr precise_unit fahrenheit{5.0 / 9.0, celsius};
        constexpr precise_unit degF = fahrenheit;

        constexpr precise_unit rankine{5.0 / 9.0, K};
        constexpr precise_unit degR = rankine;

        constexpr precise_unit reaumur{5.0 / 4.0, celsius};

    }  // namespace temperature

    constexpr precise_unit degC = temperature::celsius;
    constexpr precise_unit degF = temperature::fahrenheit;

    // others
    constexpr precise_unit rpm{constants::pi / 30.0, rad *Hz};
    constexpr precise_unit CFM(ft *ft *ft / min);

    constexpr precise_unit MegaBuck(1000000.0, currency);
    constexpr precise_unit GigaBuck(1000.0, MegaBuck);

    namespace pressure
    {
        constexpr precise_unit psi{6894.757293168, Pa};
        constexpr precise_unit inHg{3376.849669, Pa};  // at 60 degF
        constexpr precise_unit mmHg{133.322387415, Pa};
        constexpr precise_unit torr{101325.0 / 760.0, Pa *flag};  // this is really close to mmHg
        constexpr precise_unit inH2O{248.843004, Pa};  // at 60 degF
        constexpr precise_unit mmH2O{1.0 / 25.4, inH2O};  // at 60 degF
        constexpr precise_unit atm(101325.0, Pa);
        constexpr precise_unit att = gm::at;  //!< technical atmosphere same as gravitational metric system
    }  // namespace pressure

    // Power system units
    constexpr precise_unit MW(1000000.0, W);
    constexpr precise_unit MVA = MW;
    constexpr precise_unit kW(1000.0, W);
    constexpr precise_unit mW(0.001, W);
    constexpr precise_unit puMW = MW * pu;
    constexpr precise_unit puV = pu * V;
    constexpr precise_unit puHz = pu * Hz;
    constexpr precise_unit MJ(1000000.0, J);
    constexpr precise_unit puOhm = ohm * pu;
    constexpr precise_unit puA = A * pu;
    constexpr precise_unit kV(1000.0, V);
    constexpr precise_unit mV(0.001, V);
    constexpr precise_unit mA(0.001, A);

    /// Power units
    namespace power
    {
        constexpr precise_unit hpE(746.0, W);  // electric horsepower
        constexpr precise_unit hpI(745.69987158227022, W);  // mechanical horsepower
        constexpr precise_unit hpS(9812.5, W);  // Boiler horsepower
        constexpr precise_unit hpM(735.49875, W);  // Boiler horsepower

    }  // namespace power

    constexpr precise_unit hp = power::hpI;

    // Speed units
    constexpr precise_unit mph(mile / hr);
    constexpr precise_unit mps(m / s);

    // Energy units

    namespace energy
    {
        constexpr precise_unit kWh(3600000.0, J);
        constexpr precise_unit MWh(1000.0, kWh);
        constexpr precise_unit eV(1.602176634e-19, J);

        constexpr precise_unit kcal(4184.0, J);
        constexpr precise_unit cal_4(4.204, J);
        constexpr precise_unit cal_15(4.18580, J);  // calorie at 15 degC
        constexpr precise_unit cal_20(4.18190, J);  // calorie at 20 degC
        constexpr precise_unit cal_mean(4.19002, J);  // mean calorie
        constexpr precise_unit cal_it(4.1868, J);  // international table calorie
        constexpr precise_unit cal_th(4.184, J);  // thermochemical calorie

        constexpr precise_unit btu_th{1054.350, J};  // thermochemical btu
        constexpr precise_unit btu_39{1059.67, J};
        constexpr precise_unit btu_59{1054.80, J};
        constexpr precise_unit btu_60{1054.68, J};
        constexpr precise_unit btu_mean{1055.87, J};
        constexpr precise_unit btu_it{1055.05585, J};  // international table btu
        constexpr precise_unit btu_iso{1055.06, J};  // rounded btu_it
        constexpr precise_unit quad(1055.05585262, J);
        constexpr precise_unit tonc(12000.0, btu_th / hr);

        constexpr precise_unit therm_us(100000.0, btu_59);
        constexpr precise_unit therm_br(105505585.257, J);
        constexpr precise_unit therm_ec(100000, btu_iso);
        constexpr precise_unit EER(btu_th / W / hr);  // Energy efficiency ratio
        constexpr precise_unit SG(lb / ft.pow(3) * pu);  // Specific gravity

        constexpr precise_unit ton_tnt{4.184, precise::giga *precise::J};
        constexpr precise_unit boe{5.8e6, btu_59};
        constexpr precise_unit foeb{6.05e6, btu_59};
        constexpr precise_unit hartree{4.35974465054e-18, J};
        constexpr precise_unit tonhour{3.5168528421, kWh};

    }  // namespace energy
    constexpr precise_unit btu = energy::btu_it;
    constexpr precise_unit cal = energy::cal_th;
    constexpr precise_unit kWh = energy::kWh;
    constexpr precise_unit MWh = energy::MWh;
    namespace custom
    {
        constexpr int bShift(unsigned short val, int bit) { return (((val >> bit) & 0x1) > 0) ? 1 : 0; }
        constexpr unsigned int bShiftu(unsigned short val, int bit)
        {
            return (((val >> bit) & 0x1) > 0) ? 1u : 0u;
        }

        /** Construct a custom unit of a specific number
        @details the only valid operation is a custom unit/time
        custom units cannot be inverted or multiplied by other units without undefined behavior
        something will happen but it may not be consistent,  there are 1024 possible custom units
        */
        constexpr detail::unit_data custom_unit(unsigned short customX)
        {
            return {7 - 4 * bShift(customX, 8),  // 3 or 7
                    -2 + 3 * bShift(customX, 7),  //-3 or -4
                    7 * bShift(customX, 9),  // 7 or 0  sometimes custom unit/time is used
                    -3 - bShift(customX, 6),  //-3 or -4  //this is probably the most important for isolating it
                    3 * bShift(customX, 4),
                    -2,
                    -2 + 2 * bShift(customX, 5),
                    -2 * bShift(customX, 3),
                    0,
                    0,
                    bShiftu(customX, 2),
                    bShiftu(customX, 1),
                    bShiftu(customX, 0),
                    0};
        }
        /// Check if the unit is a custom unit
        inline bool is_custom_unit(detail::unit_data UT)
        {
            if (UT.mole() != -2)
            {
                return false;
            }
            if (std::abs(UT.ampere()) < 2)
            {
                return false;
            }
            return true;
        }

        inline int custom_unit_number(detail::unit_data UT)
        {
            int num = (UT.has_e_flag() ? 1 : 0) + (UT.is_flag() ? 2 : 0) + (UT.is_per_unit() ? 4 : 0);
            num += (std::abs(UT.meter()) < 4) ? 256 : 0;
            num += (std::abs(UT.second()) >= 6) ? 512 : 0;
            num += (std::abs(UT.kg()) <= 1) ? 128 : 0;
            num += (std::abs(UT.kelvin()) == 3) ? 16 : 0;
            num += (UT.ampere() == -4) ? 64 : 0;
            num += (std::abs(UT.candela()) >= 2) ? 0 : 32;
            num += (std::abs(UT.currency()) >= 2) ? 8 : 0;
            return num;
        }
        /// check if 1/custom unit
        inline bool is_custom_unit_inverted(detail::unit_data UT)
        {
            int key = UT.meter();
            if (key < 0)
            {
                return true;
            }
            if (key > 0)
            {
                return false;
            }
            key = UT.kg();
            switch (key)
            {
            case 1:
            case -2:
            case -3:
                return false;
            case -1:
            case 2:
            case 3:
                return true;
            }
            key = UT.second();
            switch (key)
            {
            case 1:
            case -7:
            case -6:
                return true;
            case -1:
            case 7:
            case 6:
                return false;
            }
            return (UT.ampere() == 3);
        }
        /** Construct a custom counting unit
        @details a counting unit is a custom unit that can be divided into meter/kg/s and inverted
        there are only 16 (0-15) available custom counting units due to the stringent requirement on extra
        operations
        */
        constexpr detail::unit_data custom_count_unit(unsigned short customX)
        {
            return {0,
                    0,
                    0,
                    3,  // detection codes
                    -3,  // detection codes
                    0,
                    -1 * bShift(customX, 3),
                    0,
                    0,
                    0,
                    bShiftu(customX, 2),
                    bShiftu(customX, 1),
                    bShiftu(customX, 0),
                    0};
        }

        /// Check if the unit is a custom count unit
        inline bool is_custom_count_unit(detail::unit_data UT)
        {
            if ((UT.kelvin() == -3) && (UT.ampere() == 3))
            {
                return (UT.mole() != -2);
            }
            if ((UT.kelvin() == 3) && (UT.ampere() == -3))
            {
                return (UT.mole() != -2);
            }
            return false;
        }
        /// Get the number code for the custom count unit
        inline int custom_count_unit_number(detail::unit_data UT)
        {
            int num = (UT.has_e_flag() ? 1 : 0) + (UT.is_flag() ? 2 : 0) + (UT.is_per_unit() ? 4 : 0);
            num += (UT.candela() == 0) ? 0 : 8;
            return num;
        }
        /// check if 1/custom unit
        inline bool is_custom_count_unit_inverted(detail::unit_data UT)
        {
            return ((UT.kelvin() == 3) && (UT.ampere() == -3));
        }

        /** Construct an equation unit
        @details an equation unit triggers the equation flag and an index 0-31
        */
        constexpr detail::unit_data equation_unit(unsigned short equation_number)
        {
            return {0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    bShift(equation_number, 3),
                    bShift(equation_number, 4),  // switched on purpose so radian is the high bit
                    bShiftu(equation_number, 2),
                    bShiftu(equation_number, 1),
                    bShiftu(equation_number, 0),
                    1};
        }
        /// Generate the equation type used the unit
        inline constexpr int eq_type(detail::unit_data UT)
        {
            return ((UT.radian() != 0) ? 16 : 0) + ((UT.count() != 0) ? 8 : 0) + (UT.is_per_unit() ? 4 : 0) +
                   (UT.is_flag() ? 2 : 0) + (UT.has_e_flag() ? 1 : 0);
        }
    }  // namespace custom

    /// Generate a custom unit from a code number
    constexpr precise_unit generate_custom_unit(unsigned short code)
    {
        return precise_unit(custom::custom_unit(code));
    }
    /// Generate a custom counting unit from a code number
    constexpr precise_unit generate_custom_count_unit(unsigned short code)
    {
        return precise_unit(custom::custom_count_unit(code));
    }

    namespace log
    {
        // natural logarithm
        constexpr precise_unit neper = precise_unit(custom::equation_unit(1));
        // base 10 logarithm
        constexpr precise_unit logbase10 = precise_unit(custom::equation_unit(0));
        // base 10 logarithm bel auto detect power
        constexpr precise_unit bel = precise_unit(custom::equation_unit(2));
        // base 10 logarithm of Power levels (assume power always)
        constexpr precise_unit belP = precise_unit(custom::equation_unit(0));
        // base 10 logarithm of Power levels (assume power always)
        constexpr precise_unit dBP = precise_unit(custom::equation_unit(11));
        // base 2 logarithm
        constexpr precise_unit logbase2 = precise_unit(custom::equation_unit(8));
        // 10*base10 logarithm
        constexpr precise_unit dB = precise_unit(custom::equation_unit(3));
        // -base10 logarithm
        constexpr precise_unit neglog10 = precise_unit(custom::equation_unit(4));
        // -base100 logarithm
        constexpr precise_unit neglog100 = precise_unit(custom::equation_unit(5));
        // -base1000 logarithm
        constexpr precise_unit neglog1000 = precise_unit(custom::equation_unit(6));
        // -base50000 logarithm
        constexpr precise_unit neglog50000 = precise_unit(custom::equation_unit(7));

        constexpr precise_unit B_SPL{2 * 1e-5, precise::pascal *bel};
        constexpr precise_unit B_V = bel * V;
        constexpr precise_unit B_mV = bel * mV;
        constexpr precise_unit B_uV = bel * precise::micro * V;
        constexpr precise_unit B_10nV = bel * precise::ten * precise::nano * V;
        constexpr precise_unit B_W = bel * W;
        constexpr precise_unit B_kW = bel * kW;
        constexpr precise_unit dB_SPL{2 * 1e-5, precise::pascal *dB};
        constexpr precise_unit dB_V = dB * V;
        constexpr precise_unit dB_mV = dB * mV;
        constexpr precise_unit dB_uV = dB * precise::micro * V;
        constexpr precise_unit dB_10nV = dB * precise::ten * precise::nano * V;
        constexpr precise_unit dB_W = dB * W;
        constexpr precise_unit dB_kW = dB * kW;
    }  // namespace log
    namespace equations
    {
        /// Detect if the unit is a unit of power
        inline bool is_power_unit(detail::unit_data UT)
        {
            return ((precise::W.base_units().has_same_base(UT)) || (UT.count() == -2));
        }

        inline double convert_equnit_to_value(double val, detail::unit_data UT)
        {
            if (!UT.is_equation())
            {
                return val;
            }
            int logtype = custom::eq_type(UT);
            switch (logtype)
            {
            case 0:
            case 10:
                return pow(10.0, val);
            case 1:
                return exp(val) * ((is_power_unit(UT)) ? 2.0 : 1.0);
            case 2:
                return pow(10.0, val / ((is_power_unit(UT)) ? 1.0 : 2.0));
            case 3:
                return pow(10.0, val / ((is_power_unit(UT)) ? 10.0 : 20.0));
            case 4:
                return pow(10.0, -val);
            case 5:
                return pow(100.0, -val);
            case 6:
                return pow(1000.0, -val);
            case 7:
                return pow(50000.0, -val);
            case 8:
                return exp2(val);
            case 9:
                return exp(val);
            case 11:
                return pow(10.0, val) / 10.0;
            case 12:
                return pow(10.0, val) / 2.0;
            case 13:
                return pow(10.0, val) / 20.0;
            case 14:
                return pow(3.0, val);
            case 22:  // saffir simpson hurricane wind scale
            {
                double out = -0.17613636364;
                out = std::fma(out, val, 2.88510101010);
                out = std::fma(out, val, -14.95265151515);
                out = std::fma(out, val, 47.85191197691);
                out = std::fma(out, val, 38.90151515152);
                return out;
            }
            case 23:
            {  // Beaufort wind scale
                double out = 0.00177396133;
                out = std::fma(out, val, -0.05860071301);
                out = std::fma(out, val, 0.93621452077);
                out = std::fma(out, val, 0.24246097040);
                out = std::fma(out, val, -0.12475759535);
                return out;
            }
            case 24:  // Fujita scale
                return 141.0 * pow(val + 2.0, 1.5);
            case 27:  // prism diopter
                return atan(val / 100.0);
            case 29:  // moment magnitude scale
                return pow(10.0, (val + 10.7) * 1.5);
            case 30:
                return pow(10.0, (val + 3.2) * 1.5);
            default:
                return val;
            }
        }
        inline double convert_value_to_equnit(double val, detail::unit_data UT)
        {
            if (!UT.is_equation())
            {
                return val;
            }
            int logtype = custom::eq_type(UT);
            if ((logtype < 16) && (val <= 0.0))
            {
                return constants::invalid_conversion;
            }

            switch (logtype)
            {
            case 0:
            case 10:
                return log10(val);
            case 1:
                return ((is_power_unit(UT)) ? 0.5 : 1.0) * (std::log)(val);
            case 2:
                return ((is_power_unit(UT)) ? 1.0 : 2.0) * log10(val);
            case 3:
                return ((is_power_unit(UT)) ? 10.0 : 20.0) * log10(val);
            case 4:
                return -log10(val);
            case 5:
                return -log10(val) / 2.0;
            case 6:
                return -log10(val) / 3.0;
            case 7:
                return -log10(val) / log10(50000);
            case 8:
                return (std::log2)(val);
            case 9:
                return (std::log)(val);
            case 11:
                return 10.0 * log10(val);
            case 14:
                return log10(val) / log10(3);
            case 22:  // saffir simpson hurricane scale from wind speed
            {  // using horners method on polynomial approximation of saffir-simpson wind speed scale
                double out = 1.75748569529e-10;
                out = std::fma(out, val, -9.09204303833e-08);
                out = std::fma(out, val, 1.52274455780e-05);
                out = std::fma(out, val, -7.73787973277e-04);
                out = std::fma(out, val, 2.81978682167e-02);
                out = std::fma(out, val, -6.67563481438e-01);
                return out;
            }
            case 23:
            {  // Beaufort wind scale
                double out = 2.18882896425e-08;
                out = std::fma(out, val, -4.78236313769e-06);
                out = std::fma(out, val, 3.91121840061e-04);
                out = std::fma(out, val, -1.52427367162e-02);
                out = std::fma(out, val, 4.24089585061e-01);
                out = std::fma(out, val, 4.99241689370e-01);
                return out;
            }
            case 24:  // fujita scale
                return pow(val / 141.0, 2.0 / 3.0) - 2.0;
            case 27:
                return 100.0 * tan(val);
            case 29:  // moment magnitude scale
                return 2.0 / 3.0 * log10(val) - 10.7;
            case 30:  // energy magnitude scale
                return 2.0 / 3.0 * log10(val) - 3.2;
            default:
                return val;
            }
        }
    }  // namespace equations

    /// Units used in the textile industry
    namespace textile
    {
        constexpr precise_unit tex = g / km;
        constexpr precise_unit denier{1.0 / 9.0, tex};
        constexpr precise_unit span{0.2286, m};
        constexpr precise_unit finger{0.1143, m};
        constexpr precise_unit nail{0.5, finger};
    }  // namespace textile

    /// Units used in clinical medicine
    namespace clinical
    {
        constexpr precise_unit pru =
          precise::pressure::mmHg * precise::s / precise::mL;  //!< peripheral vascular resistance unit
        constexpr precise_unit woodu = precise::pressure::mmHg * precise::min / precise::L;  //!< wood unit
        constexpr precise_unit diopter = m.inv();
        constexpr precise_unit prism_diopter(custom::equation_unit(27));
        constexpr precise_unit mesh = i::inch.inv();
        constexpr precise_unit charriere{1.0 / 3.0, mm};
        constexpr precise_unit drop{0.05, mL};
        constexpr precise_unit met = precise_unit{3.5, mL / min / kg};  //!< metabolic equivalent
        constexpr precise_unit hounsfield = generate_custom_unit(37);

    }  // namespace clinical

    /// Units used in chemical and biological laboratories
    namespace laboratory
    {
        constexpr precise_unit svedberg{1e-13, precise::s};
        constexpr precise_unit HPF = precise_unit(custom::custom_count_unit(5));
        constexpr precise_unit LPF{100.0, HPF};
        constexpr precise_unit enzyme_unit = precise::micro * precise::mol / precise::min;
        // International Unit
        constexpr precise_unit IU = precise_unit(custom::custom_count_unit(2));
        // Arbitrary Unit
        constexpr precise_unit arbU = precise_unit(custom::custom_count_unit(1));
        // index of reactivity
        constexpr precise_unit IR = precise_unit(custom::custom_count_unit(3));
        // limit of flocculation
        constexpr precise_unit Lf = precise_unit(custom::custom_count_unit(4));

        constexpr precise_unit PFU = precise_unit(1.0, precise::count, commodities::tissue);
        constexpr precise_unit pH = precise::mol / precise::L * precise::log::neglog10;
        constexpr precise_unit molarity = precise::mol / precise::L;
        constexpr precise_unit molality = precise::mol / precise::kg;
    }  // namespace laboratory
    // Weight units

    constexpr precise_unit tonne(1000.0, kg);
    constexpr precise_unit t = tonne;
    constexpr precise_unit Da(1.6605388628e-27, kg);
    constexpr precise_unit u = Da;

    // data sizes
    namespace data
    {
        constexpr precise_unit bit = count;
        constexpr precise_unit nibble(4, count);
        constexpr precise_unit byte(8, count);
        constexpr precise_unit kB(1000.0, byte);
        constexpr precise_unit MB(1000.0, kB);
        constexpr precise_unit GB(1000.0, MB);

        constexpr precise_unit kiB(1024.0, count);
        constexpr precise_unit MiB(1024.0, kB);
        constexpr precise_unit GiB(1024.0, MB);

        constexpr precise_unit bit_s = log::logbase2;
        constexpr precise_unit shannon = bit_s;
        constexpr precise_unit hartley = precise::log::bel * precise::count;
        constexpr precise_unit ban = hartley;
        constexpr precise_unit dit = hartley;
        constexpr precise_unit deciban = precise::log::dB * precise::count;
        constexpr precise_unit nat = precise::log::neper * precise::count;

        constexpr precise_unit trit = precise_unit(precise::custom::equation_unit(14));
    }  // namespace data

    constexpr precise_unit bit = data::bit;
    constexpr precise_unit B = data::byte;
    constexpr precise_unit kB = data::kB;
    constexpr precise_unit MB = data::MB;
    constexpr precise_unit GB = data::GB;

    namespace computation
    {
        constexpr precise_unit flop = precise_unit(1.0, precise::count, commodities::flop);
        constexpr precise_unit flops{flop / s};
        constexpr precise_unit mips = precise_unit(1.0, precise::count / precise::s, commodities::instruction);
    }  // namespace computation

    // concentrations
    constexpr precise_unit ppm(1e-6, count);
    constexpr precise_unit ppb(1e-9, count);

    // other special units
    namespace special
    {
        // Amplitude spectral density
        constexpr precise_unit ASD = precise_unit(detail::unit_data(1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0));
        // Moment magnitude scale for earthquakes
        constexpr precise_unit moment_magnitude =
          precise_unit(custom::equation_unit(29)) * precise::cgs::dyn * precise::cm;
        constexpr precise_unit moment_energy = precise_unit(custom::equation_unit(30)) * precise::J;
        // Saffir Simpson hurricane wind scale
        constexpr precise_unit sshws = precise_unit(custom::equation_unit(22)) * precise::mph;
        // Beaufort wind scale
        constexpr precise_unit beaufort = precise_unit(custom::equation_unit(23)) * precise::mph;
        // Fujita tornado scale using original specification and approximation
        // https://en.wikipedia.org/wiki/Fujita_scale
        constexpr precise_unit fujita = precise_unit(custom::equation_unit(24)) * precise::mph;
        // mach number
        constexpr precise_unit mach = m / s * pu;
        // square root of Hertz
        constexpr precise_unit rootHertz =
          precise_unit(detail::unit_data(0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0));

    }  // namespace special

    constexpr precise_unit candle{0.981, cd};
    constexpr precise_unit faraday{9.648533289e4, C};
}  // namespace precise

constexpr unit meter = unit_cast(precise::meter);
constexpr unit m = meter;
constexpr unit kilogram = unit_cast(precise::kg);
constexpr unit kg = kilogram;
constexpr unit second = unit_cast(precise::second);
constexpr unit s = second;

constexpr unit Ampere = unit_cast(precise::Ampere);
constexpr unit A = Ampere;

constexpr unit Kelvin = unit_cast(precise::Kelvin);
constexpr unit K = Kelvin;
constexpr unit mol = unit_cast(precise::mol);
constexpr unit cd = unit_cast(precise::cd);

constexpr unit currency = unit_cast(precise::currency);
constexpr unit count = unit_cast(precise::count);
constexpr unit pu = unit_cast(precise::pu);
constexpr unit rad = unit_cast(precise::rad);

constexpr unit defunit = unit_cast(precise::defunit);
constexpr unit invalid(detail::unit_data(nullptr), constants::invalid_conversion);
/// Define a unitless number
constexpr unit one;
constexpr unit infinite = unit_cast(precise::infinite);
constexpr unit error = unit_cast(precise::error);
constexpr unit ratio = one;
constexpr unit percent = unit_cast(precise::percent);

// SI prefixes as units
constexpr unit milli(1e-3, one);
constexpr unit micro(1e-6, one);
constexpr unit nano(1e-9, one);
constexpr unit pico(1e-12, one);
constexpr unit femto(1e-15, one);
constexpr unit atto(1e-18, one);
constexpr unit kilo(1e3, one);
constexpr unit mega(1e6, one);
constexpr unit giga(1e9, one);
constexpr unit tera(1e12, one);
constexpr unit peta(1e15, one);
constexpr unit exa(1e18, one);

// SI Derived units:
constexpr unit Hz = unit_cast(precise::Hz);

constexpr unit volt = unit_cast(precise::volt);
constexpr unit V = volt;
constexpr unit newton = unit_cast(precise::newton);
constexpr unit pascal = unit_cast(precise::pascal);
constexpr unit joule = unit_cast(precise::joule);
constexpr unit watt = unit_cast(precise::watt);
constexpr unit coulomb = unit_cast(precise::coulomb);
constexpr unit farad = unit_cast(precise::farad);
constexpr unit ohm = unit_cast(precise::ohm);
constexpr unit siemens = unit_cast(precise::siemens);
constexpr unit weber = unit_cast(precise::weber);
constexpr unit tesla = unit_cast(precise::tesla);
constexpr unit henry = unit_cast(precise::henry);
constexpr unit lumen = unit_cast(precise::lumen);
constexpr unit lux = unit_cast(precise::lux);
constexpr unit becquerel = unit_cast(precise::becquerel);
constexpr unit gray = unit_cast(precise::gray);
constexpr unit sievert = unit_cast(precise::sievert);
constexpr unit katal = unit_cast(precise::katal);

constexpr unit N = newton;
constexpr unit Pa = pascal;
constexpr unit J = joule;
constexpr unit W = watt;
constexpr unit C = coulomb;
constexpr unit F = farad;
constexpr unit S = siemens;
constexpr unit Wb = weber;
constexpr unit T = tesla;
constexpr unit H = henry;
constexpr unit lm = lumen;
constexpr unit lx = lux;
constexpr unit Bq = becquerel;
constexpr unit Gy = gray;
constexpr unit Sv = sievert;
constexpr unit kat = katal;
constexpr unit sr = rad * rad;

// Extra SI units

constexpr unit bar = unit_cast(precise::bar);
// Distance units
constexpr unit inch = unit_cast(precise::in);
constexpr unit in = inch;
constexpr unit foot = unit_cast(precise::ft);
constexpr unit ft = foot;

constexpr unit yard = unit_cast(precise::yd);
constexpr unit yd = yard;
constexpr unit mile = unit_cast(precise::mile);
constexpr unit cm = unit_cast(precise::cm);
constexpr unit km = unit_cast(precise::km);
constexpr unit mm = unit_cast(precise::mm);
constexpr unit nm = unit_cast(precise::nm);

//  Area units
constexpr unit acre = unit_cast(precise::acre);
// Time unit
constexpr unit min = unit_cast(precise::min);
constexpr unit ms = unit_cast(precise::ms);
constexpr unit ns = unit_cast(precise::ns);
constexpr unit hr = unit_cast(precise::hr);
constexpr unit yr = unit_cast(precise::yr);
// angle measure
constexpr unit deg = unit_cast(precise::deg);
// temperature
constexpr unit degC = unit_cast(precise::degC);
constexpr unit degF = unit_cast(precise::degF);
// others
constexpr unit rpm = unit_cast(precise::rpm);
constexpr unit CFM = unit_cast(precise::CFM);
constexpr unit MegaBuck = unit_cast(precise::MegaBuck);
constexpr unit GigaBuck = unit_cast(precise::GigaBuck);

// Power system units
constexpr unit MW = unit_cast(precise::MW);
constexpr unit MVA = MW;
constexpr unit kW = unit_cast(precise::kW);
constexpr unit mW = unit_cast(precise::mW);
constexpr unit puMW = unit_cast(precise::puMW);
constexpr unit puV = unit_cast(precise::puV);
constexpr unit puHz = unit_cast(precise::puHz);
constexpr unit puOhm = unit_cast(precise::puOhm);
constexpr unit puA = unit_cast(precise::puA);
constexpr unit kV = unit_cast(precise::kV);
constexpr unit mV = unit_cast(precise::mV);
constexpr unit mA = unit_cast(precise::mA);
// Power units
constexpr unit hp = unit_cast(precise::hp);
constexpr unit mph = unit_cast(precise::mph);

// Energy units
constexpr unit kcal = unit_cast(precise::energy::kcal);
constexpr unit btu = unit_cast(precise::btu);
constexpr unit kWh = unit_cast(precise::kWh);
constexpr unit MWh = unit_cast(precise::MWh);
// Volume units
constexpr unit L = unit_cast(precise::L);
constexpr unit gal = unit_cast(precise::gal);
// Weight units

constexpr unit g = unit_cast(precise::g);
constexpr unit mg = unit_cast(precise::mg);
constexpr unit lb = unit_cast(precise::lb);
constexpr unit ton = unit_cast(precise::ton);
constexpr unit oz = unit_cast(precise::oz);
constexpr unit tonne = unit_cast(precise::tonne);
constexpr unit t = unit_cast(precise::t);
constexpr unit Da = unit_cast(precise::Da);
constexpr unit u = unit_cast(precise::u);

// data sizes
constexpr unit bit = unit_cast(precise::bit);
constexpr unit B = unit_cast(precise::B);
constexpr unit kB = unit_cast(precise::kB);
constexpr unit MB = unit_cast(precise::MB);
constexpr unit GB = unit_cast(precise::GB);

// concentrations
constexpr unit ppm = unit_cast(precise::ppm);
constexpr unit ppb = unit_cast(precise::ppb);

}  // namespace units