import Std.Time
open Std.Time

-- Reference date: Sunday, July 14, 2002 23:13:12.324354679 UTC+09:00 (Q3, week 28, day 195)
def td := zoned("2002-07-14T23:13:12.324354679+09:00")

-- Same date/time at UTC (for UTC timezone name tests)
def tdUTC := zoned("2002-07-14T23:13:12.324354679+00:00")

-- AM hour (09:13:12 for AM/PM tests)
def tdAM := zoned("2002-07-14T09:13:12.000000000+09:00")

-- Named timezone (for z/V name tests)
def tokyoTZ : TimeZone := { offset := { second := 32400 }, name := "Asia/Tokyo", abbreviation := "JST", isDST := false }

def tdNamed := ZonedDateTime.ofPlainDateTime td.toPlainDateTime (TimeZone.ZoneRules.ofTimeZone tokyoTZ)

-- Week-based year boundary: Dec 31, 2018 is in ISO week 1 of 2019
def tdWeekBound := ZonedDateTime.ofPlainDateTime datetime("2018-12-31T12:00:00") (TimeZone.ZoneRules.ofTimeZone TimeZone.UTC)

-- ─────────────────────────────────────────────────────────────────────────────
-- G  Era
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "CE CE CE Common Era C"
-/
#guard_msgs in
#eval td.format "G GG GGG GGGG GGGGG"

-- ─────────────────────────────────────────────────────────────────────────────
-- y  Year of era
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "2002 02 2002 02002 000002002"
-/
#guard_msgs in
#eval td.format "y yy yyyy yyyyy yyyyyyyyy"

-- ─────────────────────────────────────────────────────────────────────────────
-- Y  Week-based year
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "2002 02 2002 02002 000002002"
-/
#guard_msgs in
#eval td.format "Y YY YYYY YYYYY YYYYYYYYY"

-- Boundary: Dec 31, 2018 belongs to ISO week 1 of 2019
/--
info: "2019 19 2019"
-/
#guard_msgs in
#eval tdWeekBound.format "Y YY YYYY"

-- ─────────────────────────────────────────────────────────────────────────────
-- u  Extended year (signed, no era flip)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "2002 02 2002 02002 000002002"
-/
#guard_msgs in
#eval td.format "u uu uuuu uuuuu uuuuuuuuu"

-- ─────────────────────────────────────────────────────────────────────────────
-- Q / q  Quarter (Q = formatting, q = standalone — same output here)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "3 03 Q3 3rd quarter 3"
-/
#guard_msgs in
#eval td.format "Q QQ QQQ QQQQ QQQQQ"

/--
info: "3 03 Q3 3rd quarter 3"
-/
#guard_msgs in
#eval td.format "q qq qqq qqqq qqqqq"

-- ─────────────────────────────────────────────────────────────────────────────
-- M / L  Month (M = formatting, L = standalone — same output here)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "7 07 Jul July J"
-/
#guard_msgs in
#eval td.format "M MM MMM MMMM MMMMM"

/--
info: "7 07 Jul July J"
-/
#guard_msgs in
#eval td.format "L LL LLL LLLL LLLLL"

-- ─────────────────────────────────────────────────────────────────────────────
-- w  Week of week-based year
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "28 28 028 0028"
-/
#guard_msgs in
#eval td.format "w ww www wwww"

-- ─────────────────────────────────────────────────────────────────────────────
-- W  Week of month
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "2 02 002 0002"
-/
#guard_msgs in
#eval td.format "W WW WWW WWWW"

-- ─────────────────────────────────────────────────────────────────────────────
-- d  Day of month
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "14 14 014 0014 00014"
-/
#guard_msgs in
#eval td.format "d dd ddd dddd ddddd"

-- ─────────────────────────────────────────────────────────────────────────────
-- D  Day of year
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "195 195 195"
-/
#guard_msgs in
#eval td.format "D DD DDD"

-- ─────────────────────────────────────────────────────────────────────────────
-- F  Day of week in month
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "2 02 002 0002"
-/
#guard_msgs in
#eval td.format "F FF FFF FFFF"

-- ─────────────────────────────────────────────────────────────────────────────
-- E  Day of week (text only; count 6 = two-letter short)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "Sun Sun Sun Sunday S Su"
-/
#guard_msgs in
#eval td.format "E EE EEE EEEE EEEEE EEEEEE"

-- ─────────────────────────────────────────────────────────────────────────────
-- e  Localized day of week (count 1-2 = numeric ordinal, 3-6 = text)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "7 07 Sun Sunday S Su"
-/
#guard_msgs in
#eval td.format "e ee eee eeee eeeee eeeeee"

-- ─────────────────────────────────────────────────────────────────────────────
-- c  Standalone day of week (same output as e here)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "7 07 Sun Sunday S Su"
-/
#guard_msgs in
#eval td.format "c cc ccc cccc ccccc cccccc"

-- ─────────────────────────────────────────────────────────────────────────────
-- a  AM/PM marker (counts 1-4 = short, 5 = narrow)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "PM PM PM PM p"
-/
#guard_msgs in
#eval td.format "a aa aaa aaaa aaaaa"

/--
info: "AM AM AM AM a"
-/
#guard_msgs in
#eval tdAM.format "a aa aaa aaaa aaaaa"

-- ─────────────────────────────────────────────────────────────────────────────
-- H  Hour of day (0-23)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "23 23 023 0023 00023"
-/
#guard_msgs in
#eval td.format "H HH HHH HHHH HHHHH"

-- ─────────────────────────────────────────────────────────────────────────────
-- h  Clock hour of AM/PM (1-12)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "11 11 011 0011 0011"
-/
#guard_msgs in
#eval td.format "h hh hhh hhhh hhhh"

-- ─────────────────────────────────────────────────────────────────────────────
-- K  Hour of AM/PM (0-11)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "11 11 011 0011 000011"
-/
#guard_msgs in
#eval td.format "K KK KKK KKKK KKKKKK"

-- ─────────────────────────────────────────────────────────────────────────────
-- k  Clock hour of day (1-24)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "23 23 023 0023 000023"
-/
#guard_msgs in
#eval td.format "k kk kkk kkkk kkkkkk"

-- ─────────────────────────────────────────────────────────────────────────────
-- m  Minute
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "13 13 013 0013 00013"
-/
#guard_msgs in
#eval td.format "m mm mmm mmmm mmmmm"

-- ─────────────────────────────────────────────────────────────────────────────
-- s  Second
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "12 12 012 0012 00012"
-/
#guard_msgs in
#eval td.format "s ss sss ssss sssss"

-- ─────────────────────────────────────────────────────────────────────────────
-- S  Fractional seconds (truncated from nanoseconds)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "3 32 324 3243 324354679"
-/
#guard_msgs in
#eval td.format "S SS SSS SSSS SSSSSSSSS"

-- ─────────────────────────────────────────────────────────────────────────────
-- A  Milliseconds since midnight
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "83592324 83592324 83592324 83592324 083592324"
-/
#guard_msgs in
#eval td.format "A AA AAA AAAA AAAAAAAAA"

-- ─────────────────────────────────────────────────────────────────────────────
-- n  Nanosecond (Lean extension)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "324354679 324354679 324354679 324354679 324354679"
-/
#guard_msgs in
#eval td.format "n nn nnn nnnn nnnnnnnnn"

-- ─────────────────────────────────────────────────────────────────────────────
-- N  Nanoseconds since midnight (Lean extension)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "83592324354679 83592324354679 83592324354679 83592324354679 83592324354679"
-/
#guard_msgs in
#eval td.format "N NN NNN NNNN NNNNNNNNN"

-- ─────────────────────────────────────────────────────────────────────────────
-- z  Time zone name (short = abbreviation/id, full = long name)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "+09:00 +09:00 +09:00 +09:00"
-/
#guard_msgs in
#eval td.format "z zz zzz zzzz"

/--
info: "UTC UTC UTC Coordinated Universal Time"
-/
#guard_msgs in
#eval tdUTC.format "z zz zzz zzzz"

/--
info: "JST JST JST Asia/Tokyo"
-/
#guard_msgs in
#eval tdNamed.format "z zz zzz zzzz"

-- ─────────────────────────────────────────────────────────────────────────────
-- Z  Zone offset
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "+0900 +0900 +0900 GMT+09:00 +09:00"
-/
#guard_msgs in
#eval td.format "Z ZZ ZZZ ZZZZ ZZZZZ"

/--
info: "+0000 +0000 +0000 GMT Z"
-/
#guard_msgs in
#eval tdUTC.format "Z ZZ ZZZ ZZZZ ZZZZZ"

-- ─────────────────────────────────────────────────────────────────────────────
-- O  Localized GMT offset
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "GMT+9 GMT+09:00"
-/
#guard_msgs in
#eval td.format "O OOOO"

/--
info: "GMT GMT"
-/
#guard_msgs in
#eval tdUTC.format "O OOOO"

-- ─────────────────────────────────────────────────────────────────────────────
-- V  Zone ID (VV+ = raw timezone ID; single V unsupported, like Java)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "+09:00 +09:00 +09:00"
-/
#guard_msgs in
#eval td.format "VV VVV VVVV"

-- UTC offset-only zone: raw "+00:00", not normalized to "UTC"
/--
info: "+00:00 +00:00 +00:00"
-/
#guard_msgs in
#eval tdUTC.format "VV VVV VVVV"

/--
info: "Asia/Tokyo Asia/Tokyo Asia/Tokyo"
-/
#guard_msgs in
#eval tdNamed.format "VV VVV VVVV"

-- ─────────────────────────────────────────────────────────────────────────────
-- v  Generic timezone name (no DST distinction; short = abbreviation, full = name)
-- ─────────────────────────────────────────────────────────────────────────────

-- offset-only zone: short = raw offset, full = raw offset (same as z)
/--
info: "+09:00 +09:00"
-/
#guard_msgs in
#eval td.format "v vvvv"

-- UTC offset-only: normalized to "UTC"/"Coordinated Universal Time" (same as z)
/--
info: "UTC Coordinated Universal Time"
-/
#guard_msgs in
#eval tdUTC.format "v vvvv"

-- named zone: short = abbreviation, full = IANA name
/--
info: "JST Asia/Tokyo"
-/
#guard_msgs in
#eval tdNamed.format "v vvvv"

-- ─────────────────────────────────────────────────────────────────────────────
-- X  ISO 8601 offset (uses Z for UTC)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "+09 +0900 +09:00 +0900 +09:00"
-/
#guard_msgs in
#eval td.format "X XX XXX XXXX XXXXX"

/--
info: "Z Z Z Z Z"
-/
#guard_msgs in
#eval tdUTC.format "X XX XXX XXXX XXXXX"

-- ─────────────────────────────────────────────────────────────────────────────
-- x  ISO 8601 offset (no Z for UTC)
-- ─────────────────────────────────────────────────────────────────────────────

/--
info: "+09 +0900 +09:00 +0900 +09:00"
-/
#guard_msgs in
#eval td.format "x xx xxx xxxx xxxxx"

/--
info: "+00 +0000 +00:00 +0000 +00:00"
-/
#guard_msgs in
#eval tdUTC.format "x xx xxx xxxx xxxxx"
