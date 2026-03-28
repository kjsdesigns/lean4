import Std.Time
open Std.Time

def RFC1123 : Format Awareness.any := datespec("eee, dd MMM uuuu HH:mm:ss ZZZ")
def ShortDate : Format Awareness.any := datespec("MM/dd/uuuu")
def LongDate : Format Awareness.any := datespec("MMMM D, uuuu")
def ShortDateTime : Format Awareness.any := datespec("MM/dd/uuuu HH:mm:ss")
def LongDateTime : Format Awareness.any := datespec("MMMM D, uuuu h:mm a")
def Time24Hour : Format Awareness.any := datespec("HH:mm:ss")
def Time12Hour : Format Awareness.any := datespec("hh:mm:ss a")
def FullDayTimeZone : Format Awareness.any := datespec("EEEE, MMMM dd, uuuu HH:mm:ss ZZZ")
def CustomDayTime : Format Awareness.any := datespec("EEE dd MMM uuuu HH:mm")
def EraDate : Format Awareness.any := datespec("MM D, uuuu G")
def DateSmall : Format Awareness.any := datespec("uu-MM-dd")

-- Dates

def brTZ : TimeZone := timezone("America/Sao_Paulo -03:00")
def jpTZ : TimeZone := timezone("Asia/Tokyo +09:00")

def date₁ := zoned("2014-06-16T03:03:03-03:00")

def time₁ := time("14:11:01")
def time₂ := time("03:11:01")

/--
info: "Monday, June 16, 2014 03:03:03 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format date₁

def tm := date₁.toTimestamp
def date₂ := DateTime.ofTimestamp tm brTZ

/--
info: "Monday, June 16, 2014 03:03:03 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format date₂

def tm₃ := date₁.toTimestamp
def date₃ := DateTime.ofTimestamp tm₃ brTZ

/--
info: "Monday, June 16, 2014 03:03:03 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format date₃

-- Section for testing timezone conversion.

-- the timestamp is always related to UTC.

/--
Timestamp: 1723739292
GMT: Thursday, 15 August 2024 16:28:12
BR: 15 August 2024 13:28:12 GMT-03:00
-/
def tm₄ : Second.Offset := 1723739292

def dateBR := DateTime.ofTimestamp (Timestamp.ofSecondsSinceUnixEpoch tm₄) brTZ
def dateJP := DateTime.ofTimestamp (Timestamp.ofSecondsSinceUnixEpoch tm₄) jpTZ
def dateUTC := DateTime.ofTimestamp (Timestamp.ofSecondsSinceUnixEpoch tm₄) .UTC

/--
info: "Thursday, August 15, 2024 13:28:12 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateBR

/--
info: "Friday, August 16, 2024 01:28:12 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateJP

/--
info: "Thursday, August 15, 2024 13:28:12 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateUTC.convertTimeZone brTZ)

/--
info: "Thursday, August 15, 2024 13:28:12 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateJP.convertTimeZone brTZ)

/--
info: "Thursday, August 15, 2024 16:28:12 +0000"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateUTC

/--
info: "Thursday, August 15, 2024 16:28:12 +0000"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateBR.convertTimeZone .UTC)

/--
info: "Thursday, August 15, 2024 16:28:12 +0000"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateJP.convertTimeZone .UTC)

/--
info: "Friday, August 16, 2024 01:28:12 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateJP

/--
info: "Friday, August 16, 2024 01:28:12 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateBR.convertTimeZone jpTZ)

/--
info: "Friday, August 16, 2024 01:28:12 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateUTC.convertTimeZone jpTZ)

/--
TM: 1723730627
GMT: Thursday, 15 August 2024 14:03:47
Your time zone: 15 August 2024 11:03:47 GMT-03:00
-/
def localTm : Second.Offset := 1723730627

/--
This PlainDate is relative to the local time.
-/
def PlainDate : PlainDateTime := Timestamp.toPlainDateTimeAssumingUTC (Timestamp.ofSecondsSinceUnixEpoch localTm)

def dateBR₁ := DateTime.ofPlainDateTime PlainDate brTZ
def dateJP₁ := DateTime.ofPlainDateTime PlainDate jpTZ
def dateUTC₁ := DateTime.ofPlainDateTime PlainDate .UTC

/--
info: "Thursday, August 15, 2024 14:03:47 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateBR₁

/--
info: "Thursday, August 15, 2024 14:03:47 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format dateJP₁

/--
info: "Thursday, August 15, 2024 23:03:47 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateUTC₁.convertTimeZone jpTZ)

/--
info: "Friday, August 16, 2024 02:03:47 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateBR₁.convertTimeZone jpTZ)

/--
info: "Thursday, August 15, 2024 14:03:47 +0900"
-/
#guard_msgs in
#eval FullDayTimeZone.format (dateJP₁.convertTimeZone jpTZ)

/--
info: "Monday, June 16, 2014 03:03:03 -0300"
-/
#guard_msgs in
#eval FullDayTimeZone.format date₂

/--
info: "14:11:01"
-/
#guard_msgs in
#eval Time24Hour.formatBuilder time₁.hour time₁.minute time₁.second

def l := Time12Hour.formatBuilder time₁.hour.toRelative time₁.minute time₁.second (if time₁.hour.val > 12 then HourMarker.pm else HourMarker.am)

/--
info: "02:11:01 PM"
-/
#guard_msgs in
#eval l
/--
info: "03:11:01 AM"
-/
#guard_msgs in
#eval Time12Hour.formatBuilder time₂.hour.toRelative time₂.minute time₂.second (if time₂.hour.val > 12 then HourMarker.pm else HourMarker.am)

/--
info: "2024-08-15T14:03:47-03:00"
-/
#guard_msgs in
#eval Formats.iso8601.format dateBR₁

/--
info: "2024-08-15T14:03:47Z"
-/
#guard_msgs in
#eval Formats.iso8601.format dateUTC₁

/--
info: "06/16/2014"
-/
#guard_msgs in
#eval ShortDate.formatBuilder date₁.month date₁.day date₁.year

/--
info: "0053-06-19"
-/
#guard_msgs in
#eval Formats.sqlDate.format (DateTime.ofPlainDate (PlainDate.ofDaysSinceUNIXEpoch ⟨-700000⟩) .UTC)

/--
info: "-0002-09-16"
-/
#guard_msgs in
#eval Formats.sqlDate.format (DateTime.ofPlainDate (PlainDate.ofDaysSinceUNIXEpoch ⟨-720000⟩) .UTC)

/--
info: "-0084-07-28"
-/
#guard_msgs in
#eval Formats.sqlDate.format (DateTime.ofPlainDate (PlainDate.ofDaysSinceUNIXEpoch ⟨-750000⟩) .UTC)

/--
info: "-0221-09-04"
-/
#guard_msgs in
#eval Formats.sqlDate.format (DateTime.ofPlainDate (PlainDate.ofDaysSinceUNIXEpoch ⟨-800000⟩) .UTC)

/--
info: date("-0221-09-04")
-/
#guard_msgs in
#eval PlainDate.ofDaysSinceUNIXEpoch ⟨-800000⟩

/--
info: date("-0221-09-04")
-/
#guard_msgs in
#eval PlainDate.ofDaysSinceUNIXEpoch ⟨-800000⟩

/--
info: date("2002-07-14")
-/
#guard_msgs in
#eval date("2002-07-14")

/--
info: time("14:13:12.000000000")
-/
#guard_msgs in
#eval time("14:13:12")

/--
info: zoned("2002-07-14T14:13:12.000000000Z")
-/
#guard_msgs in
#eval zoned("2002-07-14T14:13:12Z")

/--
info: zoned("2002-07-14T14:13:12.000000000+09:00")
-/
#guard_msgs in
#eval zoned("2002-07-14T14:13:12+09:00")

/--
info: "2002-07-14"
-/
#guard_msgs in
#eval zoned("2002-07-14T14:13:12+09:00").format "uuuu-MM-dd"

/--
info: "14-13-12"
-/
#guard_msgs in
#eval zoned("2002-07-14T14:13:12+09:00").format "HH-mm-ss"

/-
Format
-/

def time₄ := time("23:13:12.324354679")
def date₄ := date("2002-07-14")
def datetime₅ := PlainDateTime.mk (PlainDate.ofYearMonthDayClip (-2000) 3 4) (PlainTime.mk 12 23 12 0)
def datetime₄ := datetime("2002-07-14T23:13:12.324354679")
def zoned₄ := zoned("2002-07-14T23:13:12.324354679+09:00")
def zoned₅ := zoned("2002-07-14T23:13:12.324354679+00:00")
def tz : TimeZone := { offset := { second := -3600 }, name := "America/Sao_Paulo", abbreviation := "BRT", isDST := false}
def zoned₆ := ZonedDateTime.ofPlainDateTime (zoned₄.toPlainDateTime) (TimeZone.ZoneRules.ofTimeZone tz)

/--
info: "AD AD AD Anno Domini A"
-/
#guard_msgs in
#eval zoned₄.format "G GG GGG GGGG GGGGG"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval zoned₄.format "yy yyyy yyyyyyyyy"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval zoned₄.format "uu uuuu uuuuuuuuu"

/--
info: "195 195 195"
-/
#guard_msgs in
#eval zoned₄.format "D DD DDD"

/--
info: "14 14"
-/
#guard_msgs in
#eval zoned₄.format "d dd"

/--
info: "7 07 Jul July J"
-/
#guard_msgs in
#eval zoned₄.format "M MM MMM MMMM MMMMM"

/--
info: "3 03 3rd quarter 3"
-/
#guard_msgs in
#eval zoned₄.format "Q QQ QQQQ QQQQQ"

/--
info: "28 28"
-/
#guard_msgs in
#eval zoned₄.format "w ww"

/--
info: "2"
-/
#guard_msgs in
#eval zoned₄.format "W"

/--
info: "Sun Sun Sun Sunday S"
-/
#guard_msgs in
#eval zoned₄.format "E EE EEE EEEE EEEEE"

/--
info: "7 07 Sun Sunday S"
-/
#guard_msgs in
#eval zoned₄.format "e ee eee eeee eeeee"

/--
info: "2"
-/
#guard_msgs in
#eval zoned₄.format "F"

/--
info: "11 11"
-/
#guard_msgs in
#eval zoned₄.format "h hh"

/--
info: "11 11"
-/
#guard_msgs in
#eval zoned₄.format "K KK"

/--
info: "23 23"
-/
#guard_msgs in
#eval zoned₄.format "k kk"

/--
info: "23 23"
-/
#guard_msgs in
#eval zoned₄.format "H HH"

/--
info: "13 13"
-/
#guard_msgs in
#eval zoned₄.format "m mm"

/--
info: "12 12"
-/
#guard_msgs in
#eval zoned₄.format "s ss"


/--
info: "3 32 324 3243 32435"
-/#guard_msgs in
#eval zoned₄.format "S SS SSS SSSS SSSSS"

/--
info: "83592324 83592324 83592324 83592324 083592324"
-/
#guard_msgs in
#eval zoned₄.format "A AA AAA AAAA AAAAAAAAA"

/--
info: "324354679 324354679 324354679 324354679 324354679"
-/
#guard_msgs in
#eval zoned₄.format "n nn nnn nnnn nnnnnnnnn"

/--
info: "83592324354679 83592324354679 83592324354679 83592324354679 83592324354679"
-/
#guard_msgs in
#eval zoned₄.format "N NN NNN NNNN NNNNNNNNN"

/--
info: "+09:00"
-/
#guard_msgs in
#eval zoned₄.format "VV"

/--
info: "+09:00 +09:00 +09:00 +09:00"
-/
#guard_msgs in
#eval zoned₄.format "z zz zzzz zzzz"

/--
info: "UTC UTC Coordinated Universal Time Coordinated Universal Time"
-/
#guard_msgs in
#eval zoned₅.format "z zz zzzz zzzz"

/--
info: "GMT+9 GMT+09:00"
-/
#guard_msgs in
#eval zoned₄.format "O OOOO"

/--
info: "+09 +0900 +09:00 +0900 +09:00"
-/
#guard_msgs in
#eval zoned₄.format "X XX XXX XXXX XXXXX"

/--
info: "+09 +0900 +09:00 +0900 +09:00"
-/
#guard_msgs in
#eval zoned₄.format "x xx xxx xxxx xxxxx"

/--
info: "Z Z Z Z Z"
-/
#guard_msgs in
#eval zoned₅.format "X XX XXX XXXX XXXXX"

/--
info: "+00 +0000 +00:00 +0000 +00:00"
-/
#guard_msgs in
#eval zoned₅.format "x xx xxx xxxx xxxxx"

/--
info: "+0900 +0900 +0900 GMT+09:00 +09:00"
-/
#guard_msgs in
#eval zoned₄.format "Z ZZ ZZZ ZZZZ ZZZZZ"

/--
info: "AD AD AD Anno Domini A"
-/
#guard_msgs in
#eval datetime₄.format "G GG GGG GGGG GGGGG"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval datetime₄.format "yy yyyy yyyyyyyyy"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval datetime₄.format "uu uuuu uuuuuuuuu"

/--
info: "195 195 195"
-/
#guard_msgs in
#eval datetime₄.format "D DD DDD"

/--
info: "7 07 Jul J"
-/
#guard_msgs in
#eval datetime₄.format "M MM MMM MMMMM"

/--
info: "14 14"
-/
#guard_msgs in
#eval datetime₄.format "d dd"

/--
info: "7 07 Jul July J"
-/
#guard_msgs in
#eval datetime₄.format "M MM MMM MMMM MMMMM"

/--
info: "14 14"
-/#guard_msgs in
#eval datetime₄.format "d dd"

/--
info: "3 03 3rd quarter 3"
-/
#guard_msgs in
#eval datetime₄.format "Q QQ QQQQ QQQQQ"

/--
info: "28 28"
-/
#guard_msgs in
#eval datetime₄.format "w ww"

/--
info: "2"
-/
#guard_msgs in
#eval datetime₄.format "W"

/--
info: "Sun Sun Sun Sunday S"
-/
#guard_msgs in
#eval datetime₄.format "E EE EEE EEEE EEEEE"

/--
info: "7 07 Sun Sunday S"
-/
#guard_msgs in
#eval datetime₄.format "e ee eee eeee eeeee"

/--
info: "2"
-/
#guard_msgs in
#eval datetime₄.format "F"

/--
info: "11 11"
-/
#guard_msgs in
#eval datetime₄.format "h hh"

/--
info: "11 11"
-/
#guard_msgs in
#eval datetime₄.format "K KK"

/--
info: "23 23"
-/
#guard_msgs in
#eval datetime₄.format "k kk"

/--
info: "23 23"
-/
#guard_msgs in
#eval datetime₄.format "H HH"

/--
info: "13 13"
-/
#guard_msgs in
#eval datetime₄.format "m mm"

/--
info: "12 12"
-/
#guard_msgs in
#eval datetime₄.format "s ss"


/--
info: "3 32 324 3243 32435"
-/#guard_msgs in
#eval datetime₄.format "S SS SSS SSSS SSSSS"

/--
info: "3 32 324 3243 324354679"
-/
#guard_msgs in
#eval datetime₄.format "S SS SSS SSSS SSSSSSSSS"

/--
info: "83592324 83592324 83592324 83592324 083592324"
-/
#guard_msgs in
#eval datetime₄.format "A AA AAA AAAA AAAAAAAAA"

/--
info: "324354679 324354679 324354679 324354679 324354679"
-/
#guard_msgs in
#eval datetime₄.format "n nn nnn nnnn nnnnnnnnn"

/--
info: "83592324354679 83592324354679 83592324354679 83592324354679 83592324354679"
-/
#guard_msgs in
#eval datetime₄.format "N NN NNN NNNN NNNNNNNNN"

/--
info: "11 11"
-/
#guard_msgs in
#eval time₄.format "h hh"

/--
info: "11 11"
-/
#guard_msgs in
#eval time₄.format "K KK"

/--
info: "23 23"
-/
#guard_msgs in
#eval time₄.format "k kk"

/--
info: "23 23"
-/
#guard_msgs in
#eval time₄.format "H HH"

/--
info: "13 13"
-/
#guard_msgs in
#eval time₄.format "m mm"

/--
info: "12 12"
-/
#guard_msgs in
#eval time₄.format "s ss"


/--
info: "3 32 324 3243 32435"
-/#guard_msgs in
#eval time₄.format "S SS SSS SSSS SSSSS"

/--
info: "3 32 324 3243 324354679"
-/
#guard_msgs in
#eval time₄.format "S SS SSS SSSS SSSSSSSSS"

/--
info: "83592324 83592324 83592324 83592324 083592324"
-/
#guard_msgs in
#eval time₄.format "A AA AAA AAAA AAAAAAAAA"

/--
info: "324354679 324354679 324354679 324354679 324354679"
-/
#guard_msgs in
#eval time₄.format "n nn nnn nnnn nnnnnnnnn"

/--
info: "83592324354679 83592324354679 83592324354679 83592324354679 83592324354679"
-/
#guard_msgs in
#eval time₄.format "N NN NNN NNNN NNNNNNNNN"

/--
info: "AD AD AD Anno Domini A"
-/
#guard_msgs in
#eval date₄.format "G GG GGG GGGG GGGGG"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval date₄.format "yy yyyy yyyyyyyyy"

/--
info: "02 2002 000002002"
-/
#guard_msgs in
#eval date₄.format "uu uuuu uuuuuuuuu"

/--
info: "195 195 195"
-/
#guard_msgs in
#eval date₄.format "D DD DDD"

/--
info: "7 07 Jul J"
-/
#guard_msgs in
#eval date₄.format "M MM MMM MMMMM"

/--
info: "14 14"
-/
#guard_msgs in
#eval date₄.format "d dd"

/--
info: "7 07 Jul July J"
-/
#guard_msgs in
#eval date₄.format "M MM MMM MMMM MMMMM"

/--
info: "14 14"
-/#guard_msgs in
#eval date₄.format "d dd"

/--
info: "3 03 3rd quarter 3"
-/
#guard_msgs in
#eval date₄.format "Q QQ QQQQ QQQQQ"

/--
info: "28 28"
-/
#guard_msgs in
#eval date₄.format "w ww"

/--
info: "2"
-/
#guard_msgs in
#eval date₄.format "W"

/--
info: "Sun Sun Sun Sunday S"
-/
#guard_msgs in
#eval date₄.format "E EE EEE EEEE EEEEE"

/--
info: "7 07 Sun Sunday S"
-/
#guard_msgs in
#eval date₄.format "e ee eee eeee eeeee"

/--
info: "2"
-/
#guard_msgs in
#eval date₄.format "F"

/--
info: "-2000 2001 BC"
-/
#guard_msgs in
#eval datetime₅.format "uuuu yyyy G"

/--
info: "2002 2002 AD"
-/
#guard_msgs in
#eval datetime₄.format "uuuu yyyy G"

/--
info: "BRT BRT BRT America/Sao_Paulo America/Sao_Paulo"
-/
#guard_msgs in
#eval zoned₆.format "z zz zzz zzzz zzzz"

/--
info: 1
-/
#guard_msgs in
#eval
  let t : ZonedDateTime := .ofPlainDateTime datetime("2018-12-31T12:00:00") (TimeZone.ZoneRules.ofTimeZone TimeZone.UTC)
  IO.println s!"{t.format "w"}"

/--
info: Except.error "offset 0: condition not satisfied"
-/
#guard_msgs in
#eval DateSmall.parse "-23-12-12"

/-
Truncation Test
-/

/--
info: ("19343232432-01-04T01:04:03.000000000",
 Except.error "offset 4: expected: -",
 datetime("1932-01-02T05:04:03.000000000"))
-/
#guard_msgs in
#eval
  let r := PlainDateTime.mk (PlainDate.ofYearMonthDayClip 19343232432 1 4) (PlainTime.mk 25 64 3 0)
  let s := r.format "uuuu-MM-dd'T'HH:mm:ss.SSSSSSSSS"
  let r := PlainDateTime.parse s
  (s, r, datetime("1932-01-02T05:04:03.000000000"))

def tuple2Mk (a : f) (b : g) := some (a, b)
def tuple3Mk (a : f) (b : g) (c : h) := some (a, b, c)
def tuple4Mk (a : f) (b : g) (c : h) (d : i) := some (a, b, c, d)
def tuple5Mk (a : f) (b : g) (c : h) (d : i) (e : j) := some (a, b, c, d, e)
def tuple6Mk (a : f) (b : g) (c : h) (d : i) (e : j) (k : z) := some (a, b, c, d, e, k)


/-
Parsing Length Tests
-/

def uFormat : Format Awareness.any := datespec("u uu uuuu uuuuu")

#eval do assert! (uFormat.parseBuilder tuple4Mk "1 11 1211 12311" |>.isOk)
#eval do assert! (uFormat.parseBuilder tuple4Mk "12 11 1211 12311" |>.isOk)
#eval do assert! (uFormat.parseBuilder tuple4Mk "123443 11 1211 12311" |>.isOk)
#eval do assert! (uFormat.parseBuilder tuple4Mk "-1 11 1211 12311" |>.isOk)
#eval do assert! (uFormat.parseBuilder tuple4Mk "1 11 -1211 12311" |>.isOk)
#eval do assert! (uFormat.parseBuilder tuple4Mk "1 11 1211 -12311" |>.isOk)

#eval do assert! (not <| uFormat.parseBuilder tuple4Mk "1 -11 1211 12311" |>.isOk)
#eval do assert! (not <| uFormat.parseBuilder tuple4Mk "11 1211 12134" |>.isOk)
#eval do assert! (not <| uFormat.parseBuilder tuple4Mk "1 1 12 1234" |>.isOk)
#eval do assert! (not <| uFormat.parseBuilder tuple4Mk "1 11 1213 111123" |>.isOk)
#eval do assert! (not <| uFormat.parseBuilder tuple4Mk "1 367 1211 12311" |>.isOk)

def yFormat : Format Awareness.any := datespec("y yy yyyy yyyyy")

#eval do assert! (yFormat.parseBuilder tuple4Mk "1 11 1211 12311" |>.isOk)
#eval do assert! (yFormat.parseBuilder tuple4Mk "12 11 1211 12311" |>.isOk)
#eval do assert! (yFormat.parseBuilder tuple4Mk "123443 11 1211 12311" |>.isOk)

#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "-1 11 1211 12311" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 -11 1211 12311" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 11 -1211 12311" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 11 1211 -12311" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "11 1211 12134" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 1 12 1234" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 11 1213 111123" |>.isOk)
#eval do assert! (not <| yFormat.parseBuilder tuple4Mk "1 367 1211 12311" |>.isOk)

def dFormat : Format Awareness.any := datespec("D DD DDD")

#eval do assert! (dFormat.parseBuilder tuple3Mk "1 12 123" |>.isOk)
#eval do assert! (dFormat.parseBuilder tuple3Mk "323 12 123" |>.isOk)

#eval do assert! (not <| dFormat.parseBuilder tuple3Mk "1 12 1234" |>.isOk)
#eval do assert! (not <| dFormat.parseBuilder tuple3Mk "1 123 123" |>.isOk)
#eval do assert! (not <| dFormat.parseBuilder tuple3Mk "367 12 123" |>.isOk)

def dayOfMonthFormat : Format Awareness.any := datespec("d dd")

#eval do assert! (dayOfMonthFormat.parseBuilder tuple2Mk "1 12" |>.isOk)
#eval do assert! (dayOfMonthFormat.parseBuilder tuple2Mk "31 31" |>.isOk)

#eval do assert! (not <| dayOfMonthFormat.parseBuilder tuple2Mk "1 123" |>.isOk)
#eval do assert! (not <| dayOfMonthFormat.parseBuilder tuple2Mk "32 31" |>.isOk)

def wFormat : Format Awareness.any := datespec("w ww")

#eval do assert! (wFormat.parseBuilder tuple2Mk "1 01" |>.isOk)
#eval do assert! (wFormat.parseBuilder tuple2Mk "2 01" |>.isOk)

#eval do assert! (not <| wFormat.parseBuilder tuple2Mk "2 031" |>.isOk)
#eval do assert! (not <| wFormat.parseBuilder tuple2Mk "54 01" |>.isOk)

def qFormat : Format Awareness.any := datespec("q qq")

#eval do assert! (qFormat.parseBuilder tuple2Mk "1 02" |>.isOk)
#eval do assert! (qFormat.parseBuilder tuple2Mk "3 03" |>.isOk)

#eval do assert! (not <| qFormat.parseBuilder tuple2Mk "12 32" |>.isOk)
#eval do assert! (not <| qFormat.parseBuilder tuple2Mk "000001 003" |>.isOk)

def WFormat : Format Awareness.any := datespec("W")

#eval do assert! (WFormat.parseBuilder some "1" |>.isOk)
#eval do assert! (WFormat.parseBuilder some "3" |>.isOk)

#eval do assert! (not <| WFormat.parseBuilder some "12" |>.isOk)

def eFormat : Format Awareness.any := datespec("e ee")

#eval do assert! (eFormat.parseBuilder tuple2Mk "1 07" |>.isOk)
#eval do assert! (eFormat.parseBuilder tuple2Mk "3 03" |>.isOk)

#eval do assert! (not <| eFormat.parseBuilder tuple2Mk "12 32" |>.isOk)
#eval do assert! (not <| eFormat.parseBuilder tuple2Mk "000001 003" |>.isOk)

def FFormat : Format Awareness.any := datespec("F")

#eval do assert! (FFormat.parseBuilder some "1" |>.isOk)
#eval do assert! (FFormat.parseBuilder some "3" |>.isOk)

#eval do assert! (not <| FFormat.parseBuilder some "12" |>.isOk)
#eval do assert! (not <| FFormat.parseBuilder some "6" |>.isOk)

def hFormat : Format Awareness.any := datespec("h hh")

#eval do assert! (hFormat.parseBuilder tuple2Mk "1 09" |>.isOk)
#eval do assert! (hFormat.parseBuilder tuple2Mk "12 12" |>.isOk)

#eval do assert! (not <| hFormat.parseBuilder tuple2Mk "12 32" |>.isOk)
#eval do assert! (not <| hFormat.parseBuilder tuple2Mk "000001 003" |>.isOk)

/-
Error tests with some formats.
-/

/--
info: zoned("2002-07-14T14:13:12.000000000+23:59")
-/
#guard_msgs in
#eval zoned("2002-07-14T14:13:12+23:59")

/--
info: Except.error "offset 22: invalid hour offset: 24. Must be between 0 and 23."
-/
#guard_msgs in
#eval Formats.leanDateTimeWithZoneAlt.parse "2002-07-14T14:13:12+24:59"

/--
info: Except.error "offset 25: invalid minute offset: 60. Must be between 0 and 59."
-/
#guard_msgs in
#eval Formats.leanDateTimeWithZoneAlt.parse "2002-07-14T14:13:12+23:60"

/--
info: Except.ok (zoned("2002-07-14T14:13:12.000000000Z"))
-/
#guard_msgs in
#eval Formats.leanDateTimeWithZoneAlt.parse "2002-07-14T14:13:12+00:00"
