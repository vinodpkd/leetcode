#2884. Modify Columns
#Write a solution to modify the salary column by multiplying each salary by 2.
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    for i in range(employees.shape[0]):
        employees.iloc[i,1] *= 2

    return employees
    
