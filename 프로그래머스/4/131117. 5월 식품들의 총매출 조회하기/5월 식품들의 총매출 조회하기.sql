select p.product_id,p.product_name,sum(amount * price) as TOTAL_SALES from food_order as o
inner join food_product as p on o.product_id = p.product_id 
where PRODUCE_DATE >= "2022-05-01" and PRODUCE_DATE < "2022-06-01"
group by p.product_id
order by TOTAL_SALES desc, p.product_id;