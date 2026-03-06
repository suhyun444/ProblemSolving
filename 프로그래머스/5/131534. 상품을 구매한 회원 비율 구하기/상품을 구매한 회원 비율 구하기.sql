select YEAR(SALES_DATE) as YEAR,MONTH(SALES_DATE) as MONTH, count(distinct s.user_id) as PURCHASED_USERS, 
round(count(distinct s.user_id) / q.USERCOUNT,1) as PURCHASED_RATIO
from online_sale as s inner join user_info as i on s.user_id = i.user_id,
(select count(*) as USERCOUNT from user_info where joined >= "2021-01-01" and joined < "2022-01-01") as q
where i.joined >= "2021-01-01" and i.joined < "2022-01-01" 
group by YEAR,MONTH
order by YEAR,MONTH