with recursive gen as(
    select id, 1 as generation from ecoli_data where parent_id is null
    union all
    select d.id,generation + 1 as generation from gen as r 
    inner join ecoli_data as d
    on r.id = d.parent_id
)

select ID from gen where generation = 3 order by id