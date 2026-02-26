select c.CAR_ID,c.CAR_TYPE,round((DAILY_FEE * (1- discount_rate/100) * 30)) as FEE 
from car_rental_company_car as c inner join car_rental_company_discount_plan as p 
on c.car_type = p.car_type and p.duration_type = "30일 이상" 
where (c.car_type = "SUV" or c.car_type = "세단")
and c.car_id not in 
(select car_id from car_rental_company_rental_history where start_date <= "2022-11-30" and end_date >= "2022-11-01") 
having FEE >= 500000 and FEE < 2000000
order by FEE desc,c.CAR_TYPE,c.CAR_ID desc;