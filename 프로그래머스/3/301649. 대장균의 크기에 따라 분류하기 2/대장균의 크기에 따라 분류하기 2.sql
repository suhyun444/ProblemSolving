select ID, case ntile(4) over(order by size_of_colony) when 1 then "LOW" when 2 then "MEDIUM" when 3 then "HIGH" when 4 then "CRITICAL" end as COLONY_NAME 
from ecoli_data
order by id