--
-- @lc app=leetcode.cn id=184 lang=mysql
--
-- [184] 部门工资最高的员工
--
-- @lc code=start
# Write your MySQL query statement below
select Department.Name as 'Department',
    Employee.Name as 'Employee',
    Salary
from Employee,
    Department
where DepartmentId = Department.Id
    and (Salary, DepartmentId) in (
        select max(Salary),
            DepartmentId
        from Employee
        group by DepartmentId
    );
-- @lc code=end