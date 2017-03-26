DATETIME TYPEDEF QWORD    ; A DATETIME is a FILETIME in disguise

EXTERNDEF qwDaysAsFileTime:QWORD
EXTERNDEF qwHoursAsFileTime:QWORD
EXTERNDEF qwMinutesAsFileTime:QWORD
EXTERNDEF qwSecondsAsFileTime:QWORD

CompareDateTime                 EQU <CompareFileTime>
CopyDateTime                    PROTO pdtSource:PTR DATETIME, pdtDest:PTR DATETIME
CurrentTimeZoneName             PROTO pszTZName:PTR BYTE
CurrentUtcOffsetInHours         PROTO pdblOffset:PTR REAL8
CurrentUtcOffsetInMinutes       PROTO psdwOffset:PTR SDWORD
DateAdd                         PROTO pszInterval:PTR BYTE, plNumber:PTR SDWORD, pdt1:PTR DATETIME, pdt2:PTR DATETIME
DateDiff                        PROTO pszInterval:PTR BYTE, pdt1:PTR DATETIME, pdt2:PTR DATETIME, plNumber:PTR SDWORD
DateDiffTotal                   PROTO pszInterval:PTR BYTE, pdt1:PTR DATETIME, pdt2:PTR DATETIME, pdblNumber:PTR REAL8
DateTimeToDateString            PROTO pdt:PTR DATETIME, pszDate:PTR BYTE
DateTimeToDateStringLong        PROTO pdt:PTR DATETIME, pszDateLong:PTR BYTE
DateTimeToDateStringShort       PROTO pdt:PTR DATETIME, pszDateShort:PTR BYTE
DateTimeToString                PROTO pdt:PTR DATETIME, pszDateTime:PTR BYTE
DateTimeToStringFormat          PROTO pdt:PTR DATETIME, pszDateFormat:PTR BYTE, pszTimeFormat:PTR BYTE, pszFormatted:PTR BYTE
DateTimeToStringLong            PROTO pdt:PTR DATETIME, pszLong:PTR BYTE
DateTimeToStringLong12          PROTO pdt:PTR DATETIME, pszLong12:PTR BYTE
DateTimeToStringLong24          PROTO pdt:PTR DATETIME, pszLong24:PTR BYTE
DateTimeToStringShort           PROTO pdt:PTR DATETIME, pszShort:PTR BYTE
DateTimeToStringShort12         PROTO pdt:PTR DATETIME, pszShort12:PTR BYTE
DateTimeToStringShort24         PROTO pdt:PTR DATETIME, pszShort24:PTR BYTE
DateTimeToTimeString            PROTO pdt:PTR DATETIME, pszTime:PTR BYTE
DateTimeToTimeString12          PROTO pdt:PTR DATETIME, pszTime12:PTR BYTE
DateTimeToTimeString24          PROTO pdt:PTR DATETIME, pszTime24:PTR BYTE
DateTimeToYMDHMS                PROTO pdt:PTR DATETIME, pdwYear:PTR DWORD, pdwMonth:PTR DWORD, pdwDay:PTR DWORD, pdwHour:PTR DWORD, pdwMinute:PTR DWORD, pdwSecond:PTR DWORD
Day                             PROTO pdt:PTR DATETIME
DaylightSavingTimeEndDateTime   PROTO dwYear:DWORD, pdt:PTR DATETIME
DaylightSavingTimeStartDateTime PROTO dwYear:DWORD, pdt:PTR DATETIME
DayOfWeek                       PROTO pdt:PTR DATETIME
DayOfWeekName                   PROTO pdt:PTR DATETIME, pszDayOfWeek:PTR BYTE
DayOfYear                       PROTO pdt:PTR DATETIME
DaysInMonth                     PROTO pdt:PTR DATETIME
GetLocalDateTime                PROTO pdt:PTR DATETIME
GetUtcDateTime                  PROTO pdt:PTR DATETIME
Hour                            PROTO pdt:PTR DATETIME
IsDaylightSavingTime            PROTO pdt:PTR DATETIME, pdwIsDST:PTR DWORD
IsLeapYear                      PROTO dwYear:DWORD
Minute                          PROTO pdt:PTR DATETIME
Month                           PROTO pdt:PTR DATETIME
MonthName                       PROTO pdt:PTR DATETIME, pszMonthName:PTR BYTE
Second                          PROTO pdt:PTR DATETIME
StringToDateTime                PROTO pszDateTimeString:PTR BYTE, pdt:PTR DATETIME
TziDateToDateTime               PROTO pst:PTR SYSTEMTIME, pdt:PTR DATETIME
Year                            PROTO pdt:PTR DATETIME
YMDHMSToDateTime                PROTO dwYear:DWORD, dwMonth:DWORD, dwDay:DWORD, dwHour:DWORD, dwMinute:DWORD, dwSecond:DWORD, pdt:PTR DATETIME
