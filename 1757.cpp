//1757. Recyclable and Low Fat Products
/*
Write a solution to find the ids of products that are both low fat and recyclable.
Return the result table in any order.
The result format is in the following example.
*/
select product_id from Products where low_fats = 'Y' and recyclable = 'Y';
