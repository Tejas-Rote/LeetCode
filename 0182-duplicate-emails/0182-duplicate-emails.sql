
select p.email
from Person p
group by email
having count(distinct id)>1
