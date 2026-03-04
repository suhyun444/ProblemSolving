SELECT a.AUTHOR_ID,a.AUTHOR_NAME,b.CATEGORY,sum(b.PRICE * s.SALES) as TOTAL_SALES from book as b 
inner join author as a on b.author_id = a.author_id
inner join book_sales as s on b.book_id = s.book_id
where s.sales_date >= "2022-01-01" and s.sales_date < "2022-02-01"
group by a.AUTHOR_ID,b.CATEGORY
order by a.AUTHOR_ID, b.CATEGORY desc;