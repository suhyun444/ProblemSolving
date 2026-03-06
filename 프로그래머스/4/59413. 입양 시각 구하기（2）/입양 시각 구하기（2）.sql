with recursive timetable as(
select 0 as HOUR
union all
select HOUR + 1 as HOUR from timetable where HOUR < 23
)

select t.HOUR,count(ANIMAL_ID) as COUNT from timetable as t left join animal_outs as o on t.HOUR = HOUR(o.DATETIME)
group by t.HOUR order by t.HOUR
