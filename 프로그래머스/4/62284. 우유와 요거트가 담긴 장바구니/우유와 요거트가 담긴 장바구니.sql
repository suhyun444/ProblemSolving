select m.cart_id from 
(select cart_id from cart_products where name = "Milk") as m
inner join (select cart_id from cart_products where name = "Yogurt") as y
on m.cart_id = y.cart_id
where m.cart_id is not null and y.cart_id is not null order by m.cart_id;