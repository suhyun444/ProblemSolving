with recursive gen as (
    select id,1 as generation from ecoli_data where parent_id is null
    union all
    select e.id,generation + 1 as generation from gen as g inner join ecoli_data as e on g.id = e.parent_id 
)

select count(distinct g.id) as COUNT,generation from gen as g left join ecoli_data as e on g.id = e.parent_id where e.id is null group by generation order by generation